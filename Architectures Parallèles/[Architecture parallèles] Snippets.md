# [Architectures parallèles] Snippets

## OpenMP
```cpp
template< typename InputIterator, typename UnaryPredicate >
static typename std::iterator_traits< InputIterator >::difference_type
strategyA(const InputIterator& first,
const InputIterator& last,
const UnaryPredicate& pred,
const int& threads) {

// Taille d'un tronçon fixée arbitrairement.
const int taille = 128 * threads;

// Obtention du type des éléments du conteneur.
typedef std::iterator_traits< InputIterator > Traits;
typedef typename Traits::value_type Elt;

// Tronçon constitué de pointeurs vers les éléments du conteneur.
std::vector< const Elt* > troncon(taille);

// Nombre d'éléments physiquement présents dans le dernier tronçon.
int combien;

// Itérateur permettant d'avancer dans le conteneur à tronçonner.
InputIterator iter = first;

// Compteur des éléments satisfaisant le prédicat.
typename std::iterator_traits< InputIterator >::difference_type acc = 0;

// Nous encageons le tout dans une région parallèle et nous évitons
// le omp parallel for afin de garantir que les threads existent tout
// le temps d'exécution de la boucle. Dans le cas contraire, le choix
// sera laissé à l'implémentation qui pourrait alors les créer puis les
// détruire à chaque itération de la boucle while.
#pragma omp parallel reduction(+ : acc)
{
  // Flag indiquant que tous les éléments du conteneur n'ont pas encore
  // été traités (privé).
  bool encore = true;

  // Boucle de traitement des éléments du conteneur.
  while (encore) {

    // Tronçonnage effectué par un seul et unique thread. Les autres
    // attendent à la barrière de synchronisation du single.
    #pragma omp single
    {
      // Tronçonnage jusqu'à remplir complètement le tronçon ou bien
      // atteindre la fin du conteneur. Toutes les données manipulées
      // ici sont partagées par l'ensemble des threads disponibles.
      combien = 0;
      while (iter != last && combien != taille) {
        troncon[combien] = &(*iter);
        iter ++;
        combien ++;
      }

    } // omp single (barrière de synchronisation implicite).

    // Le tronçonnage est terminé : nous lançons tous les threads
    // disponibles pour traiter les éléments du nouveau tronçon. La
    // clause d'ordonnancement est auto, ce qui laisse à
    // l'implémentation la liberté de choisir le meilleur scheduling.
    #pragma omp for schedule(auto)
    for (int i = 0; i < combien; i ++) {
      if (pred(*troncon[i])) {
        acc ++;
      }
    } // omp par (barrière de synchronisation implicite).

    // Y'a t-il d'autres tronçons à traiter par la suite ?
    encore = iter != last;

    // Barrière de synchronisation explicite permettant d'éviter qu'un
    // thread entre dans la partie single et modifie l'itérateur partagé
    // iter alors qu'un autre thread met encore à jour son flag encore.
    #pragma omp barrier

  } // while

} // omp parallel (barrière de synchronisation implicite).

// C'est terminé.
return acc;

} // strategyA

/**
 * Implémentation toujours basée sur l'idée d'un découpage du conteneur
 * en tronçons mais cette fois-ci, nous allons utiliser la notion de
 * tâches afin d'éviter les recopies de pointeurs dans un tableau. La
 * La contrepartie est un scheduling au niveau des tâches, scheduling sur
 * lequel nous avons peu de prise.
 *
 * @param[in] first - itérateur repérant le premier élément à traiter.
 * @param[in] last - itérateur repérant l'élément situé juste  derrière le
 *   dernier élément à traiter.
 * @param[in] pred - prédicat unaire.
 * @param[in] threads - le nombre de threads disponibles.
 * @return le nombre d'éléments de l'intervalle @c [first, last[
 *   satisfaisant @c pred.
 *
 * @note Cette implémentation s'apparente à la clause de scheduling
 *   schedule(dynamic, size).
 */
template< typename InputIterator, typename UnaryPredicate >
static
typename std::iterator_traits< InputIterator >::difference_type
strategyB(const InputIterator& first,
const InputIterator& last,
const UnaryPredicate& pred,
const int& threads) {

// Taille d'un tronçon fixée arbitrairement.
const int taille = 128;

// Compteur des éléments satisfaisant le prédicat.
typename std::iterator_traits< InputIterator >::difference_type acc = 0;

// Toutes les tâches sont créés à l'intérieur d'une région parallèle.
#pragma omp parallel
{

  // Ces tâches sont créées par un seul et unique thread. La barrière
  // de synchronisation implicite est levée afin que les autres threads
  // se précipitent immédiatement sur le pool de tâches à exécuter en
  // cours de constitution.
  #pragma omp single nowait
  {

    // Nombre d'éléments physiquement présent dans le dernier tronçon
    // produit (privé).
    int combien;

    // Itérateur permettant de marquer le début d'un tronçon (privé).
    InputIterator from = first;

    // Flag indiquant si le tronçonnage doit ou non se poursuivre
    // (privé).
    bool encore = true;

    // Boucle de traitement des éléments du conteneur.
    while (encore) {
      // Création d'un nouveau tronçon.
      InputIterator iter = from;
      combien = 0;
      while (iter != last && combien != taille) {
        iter ++;
        combien ++;
      }

      // Création de la tâche chargée de traiter ce tronçon (les
      // itérateurs from et iter font implicitement l'objet d'une
      // clause firstprivate). Nous ajoutons la clause untied afin
      // que le thread qui créée les tâches puisse lui-même participer
      // à leur exécution lorsque le nombre de tâches en attente devient
      // trop important.
      #pragma omp task shared(pred, acc) untied
      {
        // La clause reduction ne peut être accolée au constructeur
        // task. Par conséquent, nous employons la directive atomic car
        // le compteur global est partagé par toutes les tâches.
        #pragma omp atomic
        acc += std::count_if(from, iter, pred);

      } // omp task

      // Mise à jour des itérateurs pour le prochain tronçonnage.
      from = iter;
      encore = from != last;

    } // while

  } // omp single (barrière de synchronisation implicite levée).

} // omp parallel (barrière de synchronisation implicite).

// C'est terminé.
return acc;

} // strategyB

/**
 * Implémentation basée sur l'idée d'une répartition cyclique des
 * éléments du conteneur entre les différents threads disponibles.
 *
 * @param[in] first - itérateur repérant le premier élément à traiter.
 * @param[in] last - itérateur repérant l'élément situé juste derrière le
 *   dernier élément à traiter.
 * @param[in] pred - prédicat unaire.
 * @param[in] threads - le nombre de threads disponibles.
 * @return le nombre d'éléments de l'intervalle @c [first, last[
 *   satisfaisant @c pred.
 *
 * @note Cette implémentation s'apparente à la clause de scheduling
 *   schedule(static).
 */
template< typename InputIterator, typename UnaryPredicate >
static
typename std::iterator_traits< InputIterator >::difference_type
strategyC(const InputIterator& first,
const InputIterator& last,
const UnaryPredicate& pred,
const int& threads) {

// Compteur des éléments satisfaisant le prédicat.
typename std::iterator_traits< InputIterator >::difference_type acc = 0;

#pragma omp parallel reduction(+ : acc)
{
  // Itérateur repérant le premier élément (privé) affecté à ce thread.
  InputIterator here = first;

  // Flag indiquant que l'avancée de ce thread doit se poursuivre
  // (privé).
  bool encore;

  // Tentative de positionnement sur le premier élément affecté à ce
  // thread.
  {
    const int id = omp_get_thread_num();
    int combien = 0;
    while (here != last && combien != id) {
      here ++;
      combien ++;
    }
    encore = here != last;
  }

  // Boucle de traitement des éléments affectés à ce thread.
  while (encore) {
    // Traitement de l'élément courant.
    if (pred(*here)) {
      acc ++;
    }
    // Tentative de positionnement sur l'élément suivant : le nombre de
    // threads disponible fait office de stride.
    int combien = 0;
    while (here != last && combien != threads) {
      here ++;
      combien ++;
    }
    encore = here != last;
  } // while

} // omp parallel

// C'est terminé.
return acc;

} // strategyC
```

## TBB
```cpp
/**
 * Implémentation parallèle.
 *
 * @param[in] first1 - un itérateur repérant le premier élément du premier
 *   sous-conteneur concerné par la fusion ;
 * @param[in] last1 - un itérateur repérant l'élément situé juste derrière
 *   le dernier élément du premier sous-conteneur concerné par la fusion ;
 * @param[in] first2 - un itérateur repérant le premier élément du second
 *   sous-conteneur concerné par la fusion ;
 * @param[in] last2 - un itérateur repérant l'élément situé juste derrière
 *   le dernier élément du second sous-conteneur concerné par la fusion ;
 * @param[in] result - un itérateur repérant la position ou récopier le
 *   premier élément résultant de la fusion ;
 * @param[in] comp - un comparateur binaire représentant la relation d'ordre
 *   total régissant les sous-conteneurs ;
 * @param[in] threads - le nombre de threads disponibles.
 * @return un itérateur repérant la fin de la zone de fusion dans le
 *   conteneur cible.
 */
template< typename InputRandomAccessIterator1,
    typename InputRandomAccessIterator2,
    typename OutputRandomAccessIterator,
    typename Compare >
static OutputRandomAccessIterator
apply(const InputRandomAccessIterator1& first1,
const InputRandomAccessIterator1& last1,
const InputRandomAccessIterator2& first2,
const InputRandomAccessIterator2& last2,
const OutputRandomAccessIterator& result,
const Compare& comp,
const int& threads) {

  // Types synonymes permettant de ne rien préjuger des types entiers
  // manipulés.
  typedef std::iterator_traits< InputRandomAccessIterator1 > TraitsInput1;
  typedef std::iterator_traits< InputRandomAccessIterator2 > TraitsInput2;
  typedef std::iterator_traits< OutputRandomAccessIterator > TraitsOutput;
  typedef typename TraitsInput1::difference_type InputSize1;
  typedef typename TraitsInput2::difference_type InputSize2;
  typedef typename TraitsOutput::difference_type OutputSize;

  // Tailles respectives des deux conteneurs à fusionner.
  const InputSize1  m = last1 - first1;
  const InputSize2 n = last2 - first2;

  // Calcul de la taille du conteneur accueillant la fusion.
  const OutputSize mpn = m + n;

  // Calcul de la taille des fragments dans le conteneur cible de la fusion.
  const OutputSize taille = std::ceil(mpn * 1.0 / threads);

  // Boucle parallèle sur les fragments.
  tbb::parallel_for(static_cast< OutputSize >(0), // Borne inférieure.
                          mpn,                    // Borne supérieure.
                          taille,                 // Pas.
            [&](const OutputSize& ir) -> void {  // Fonction.

    // Calcul du couple (j_{r}, k_{r}) correspondant au
    // rang i_{r} dans le conteneur cible.
    InputSize1 jr;
    InputSize2 kr;
    coRank(ir, first1, m, first2, n, comp, jr, kr);

    // Calcul de la valeur de i_{r+1} qu'il faut éventu-
    // ellement ajuster.
    OutputSize irp1 = ir + taille;
    if (irp1 > mpn) {
      irp1 = mpn;
    }

    // Calcul du couple (j_{r+1}, k_{r+1}) correspondant
    // au rang i_{r+1} dans le conteneur cible.
    InputSize1 jrp1;
    InputSize2 krp1;
    coRank(irp1,
       first1,
       m,
       first2,
       n,
       comp,
       jrp1,
       krp1);

    // Nous disposons de toutes les infos pour réaliser
    // la fusion dont le fragment courant est la cible.
    // Cette opération est réalisée via l'algorithme
    // merge de la bibliothèque standard.
    std::merge(first1 + jr,
           first1 + jrp1,
           first2 + kr,
           first2 + krp1,
           result + ir,
           comp);

  });

  // Respect de la sémantique de l'algorithme merge.
  return result + mpn;

} // apply
```

### Pipeline logiciel
```cpp
/**
 * Implémentation pipeline de l'algorithme du bubble sort.
 *
 * @param[in] first - un itérateur repérant le premier élément de la séquence
 *   à trier.
 * @param[in] last - un itérateur repérant l'élément situé juste derrière le
 *   dernier élément de la séquence à trier.
 * @param[in] comp - un comparateur binaire permettant d'ordonner deux
 *   éléments.
 * @param[in] chunks - nombre de tronçons maximum en circulation dans le
 *   pipeline à un instant donné.
 */
template< typename RandomAccessIterator, typename Compare >
static void pipelinedBubbleSort(const RandomAccessIterator& first,
        const RandomAccessIterator& last,
        const Compare& comp,
        const size_t& chunks) {

  // Type synonyme pour le type des éléments du conteneur.
  typedef std::iterator_traits< RandomAccessIterator > Traits;
  typedef typename Traits::value_type value_type;

  /**
   * Type synonyme pour un tronçon d'éléments.
   */
  typedef std::vector< value_type > Troncon;

  /**
   * Classe représentant un étage d'entrée. Ce dernier tronçonne le conteneur
   * à trier en petit vecteurs qui sont envoyés à l'étage intermédiaire. Le
   * mode de fonctionnement de cet étage est séquentiel, l'ordre de traitement
   * des tronçons n'ayant aucune importance.
   */
  class InputStage: public tbb::filter {
  public:

    /**
     * Constructeur logique.
     *
     * @param[in] first - la valeur initiale de @ref it_.
     * @param[in] last - la valeur de @ref last_.
     */
    InputStage(const RandomAccessIterator& first,
    const RandomAccessIterator& last):
      tbb::filter(tbb::filter::serial_out_of_order),
      it_(first),
      last_(last) { }

  public:
    void* operator()(void*) override {
      // Le conteneur à trier a été tronçonné : il n'y a plus rien à faire.
      if (it_ == last_) {
        return NULL;
      }

      // Taille maximum d'un tronçon.
      const size_t tailleMax = 8;

      // Calcul de la taille du prochain tronçon.
      size_t taille = last_ - it_;
      if (taille > tailleMax) {
        taille = tailleMax;
      }

      // Allocation d'un tronçon.
      Troncon* ptrTroncon = new Troncon(it_, it_ + taille);

      // Ajuster l'itérateur repère pour le prochain tronçon.
      it_ += taille;

      // Passer le troncon courant à l'étage intermédiaire.
      return ptrTroncon;
    }

  protected:

    /**
     * Itérateur repérant le premier élément du prochain tronçon dans le
     * conteneur à trier.
     */
    RandomAccessIterator it_;

    /**
     * Itérateur repérant l'élément situé juste derrière le dernier élément
     * concerné par le tri.
     */
    const RandomAccessIterator last_;

  }; // InputStage

  // Instanciation d'un premier étage.
  InputStage input(first, last);

  /**
   * Classe représentant un étage intermédiaire chargé de trier les tronçons.
   * La taille de ces derniers étant faible, nous utilisons une version
   * séquentielle du bubble sort. Le mode de fonctionnement de cet étage est
   * parallèle.
   */
  class MiddleStage: public tbb::filter {
  public:
    /**
     * Constructeur logique.
     *
     * @param[in] comp - la valeur de @ref comp_.
     */
    MiddleStage(const Compare& comp):
    tbb::filter(tbb::filter::parallel),
    comp_(comp) {}
    void* operator()(void* item) override {
      // Conversion de l'argument en un pointeur de tronçon.
      Troncon* ptrTroncon = static_cast< Troncon* >(item);

      // Trier le tronçon avec une version séquentielle du bubble sort.
      bubbleSort(ptrTroncon->begin(), ptrTroncon->end(), comp_);

      // Passer le tronçon trié au dernier étage.
      return ptrTroncon;
    }
  protected:
    /**
     * Comparateur binaire représentant la relation d'ordre total.
     */
    const Compare comp_;
  }; // MiddleStage

  // Instanciation d'un second étage.
  MiddleStage middle(comp);
  /**
   * Classe représentant un dernier étage. Ce dernier fusionne la partie déjà
   * triée du conteneur avec le tronçon fraichement arrivé. Le mode de
   * fonctionnement de cet étage est séquentiel, l'ordre de traitement des
   * tronçons n'ayant aucune importance.
   */
  class OutputStage: public tbb::filter {
  public:
    /**
     * Constructeur logique.
     *
     * @param[in] first - la valeur de @ref first_.
     * @param[in] comp - la valeur de @ref comp_.
     */
    OutputStage(const RandomAccessIterator& first,
    const Compare& comp):
    tbb::filter(tbb::filter::serial_out_of_order),
    first_(first),
    comp_(comp),
    it_(first) {}
    void* operator()(void* item) override {
      // Conversion de l'argument en un pointeur de tronçon.
      Troncon* ptrTroncon = static_cast< Troncon* >(item);

      // Obtention de sa taille.
      const auto taille = ptrTroncon->size();

      // Copier le tronçon à la fin du conteneur déjà trié.
      std::copy(ptrTroncon->begin(), ptrTroncon->end(), it_);

      // Fusionner sur place (in place) les deux sous-conteneurs.
      std::inplace_merge(first_, it_, it_ + taille);

      // Mettre à jour le marqueur de fin de la zone déjà triée.
      it_ += taille;

      // Désallouer le tronçon.
      delete ptrTroncon;

      // Rien à retourner.
      return NULL;
    }
  protected:
    /**
     * Itérateur repérant le premier élément de la partie déjà triée du
     * conteneur.
     */
    const RandomAccessIterator first_;
    /**
     * Comparateur permettant de fusionner un tronçon avec la partie du
     * conteneur déjà triée.
     */
    const Compare comp_;
    /**
     * Itérateur repérant l'élément situé juste derrière le dernier élément de
     * la zone du contenu déjà triée.
     */
    RandomAccessIterator it_;
  }; // OutputStage

  // Instanciation d'un troisième étage.
  OutputStage output(first, comp);

  // Instanciation du pipeline.
  tbb::pipeline pipeline;
  pipeline.add_filter(input);
  pipeline.add_filter(middle);
  pipeline.add_filter(output);

  // Démarrage du pipeline.
  pipeline.run(chunks);

  // Nettoyage du pipline.
  pipeline.clear();

} // pipelinedBubbleSort
```
