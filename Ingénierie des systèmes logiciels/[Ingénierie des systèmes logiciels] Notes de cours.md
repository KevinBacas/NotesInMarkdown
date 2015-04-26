# [Ingénierie des systèmes logiciels] Notes de cours

## Cycle en V
Le *Cycle en V* représente 80 % des développements.

* Avantages :
  * Découpage du développement de façon *traditionnelle, logique et stable*.
  * *Identification claire* des documents à produire et des des rôles.
  * Convient aux *grosses équipes*.
  * Nécessaire au *developpement de logiciels "critiques"*.
* Inconvéniants :
  * L'utilisateur résiste à *l'emmergence du besoin*.
  * *Découverte tardive des erreurs* de spec (Conception par le client)
  * Manque de *souplesse* :
    * Le client ne peut pas changer ses objectifs en cours de route.
    * *Effet tunnel*.

Un *système* est un *ensemble de composants* en *interaction* entre eux et avec l'environnement destiné à *remplir une fonction* ou *un service* donné.
La *description logique* explique ce que le système doit faire et sous quelles conditions. **QUOI**
La *description physique* explique ce que sont les composants. **Comment**

*Système complexe* :
  * Comporte de nombreux éléments
  * Interactions non homogènes
  * Fait apparaitre des boucles de rétroaction

Il y a *différentes phases de tests* dans le *Cycle en V* :
  * *Unitaires* : Erreurs d'implémentation
  * *Intégration* : Cohérence de deux composants
  * *Recette fonctionnelle* : valide les exigences
  * *Recette utilisateur* Vérifie le process métier

Afin de limiter *l'effet tunnel*, a été mis en place le *Cycle en W*. Cette solution permet aussi de présenter un premier prototype avant de commencer la réalisation.

* Inconvéniants :
  * La conception d'un prototype n'est pas toujours possible (Coût).
  * Augmentation du coût global du projet.

Il est toujours possible d'alléger le prototype en ne faisant que des maquettes.

Rapid Application Developpment (RAD)
  * Cycles itératifs
  * Plus grande souplesse
  * L'utilsateur suit la construction du système
  * Limite globalement les risques projet

Méthodes agiles
  * Nécessite un environnement favorable
    * Culture d'entreprise
  * Bonne connaissance de l'architecture des Système d'information.

## Recueil du besoin
L'utilisateur n'exprime pas naturellement son besoin. *Il exprime son idée de la solution*.

* Quel est le périmètre fonctionnel du projet ?
* Quels sont les processus métier en jeu ?
* Quel rôle pour le système ?
* Quels échanges avec le système ?

## Démarche d'ubanisation du système d'information
On distingue 3 niveaux d'architecture :
  * Architecture fonctionnelle
    * Décrit le découpage du système en blocs fonctionnels cohérents
  * Architecture applicative
    * Décrit le découpage du système en "outils" couvrant un périmètre fonctionnel donné sur une plateforme technique donnée
  * Architecture technique
    * Pour une application donnée, décrit l'infrastructure névessaire au fonctionnement des applications

## Organisation en pair-programming
* Principe :
  * On constitue des binômes de développement
  * Ce que l'un code, lautre le relit et/ou le test
  * Les binômes doivent changer régulièrement
* Objectif :
  * Déceler plus tôt les bugs par revue de code
  * Valider le respect des normes développement
* Effet psychologique :
  * Favorise l'échange entre développeurs
  * Favorise la formalisation des problèmes
  * Favorise un codage lisible et documenté

**Particulièrement mis en oeuvre dans les méthodes agiles**

## Les tests et la recette
Les tests de vérification sont effectués afin de valider la construction d'un système (*respect de la spec*).
Les test des validation sont effectués afin de valider sur la solution répond bien au besoin de l'utilisateur.
**Ces tests s'appliquent à chaque étape du développement**
