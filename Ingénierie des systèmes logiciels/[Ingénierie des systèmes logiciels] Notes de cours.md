# [Ingénierie des systèmes logiciels] Notes de cours
## Cycle en V
Le _Cycle en V_ représente 80 % des développements.
- Avantages :
  - Découpage du développement de façon _traditionnelle, logique et stable_.
  - _Identification claire_ des documents à produire et des des rôles.
  - Convient aux _grosses équipes_.
  - Nécessaire au _developpement de logiciels "critiques"_.

- Inconvéniants :
  - L'utilisateur résiste à _l'emmergence du besoin_.
  - _Découverte tardive des erreurs_ de spec (Conception par le client)
  - Manque de _souplesse_ :
    - Le client ne peut pas changer ses objectifs en cours de route.
    - _Effet tunnel_.

Un _système_ est un _ensemble de composants_ en _interaction_ entre eux et avec l'environnement destiné à _remplir une fonction_ ou _un service_ donné. La _description logique_ explique ce que le système doit faire et sous quelles conditions. **QUOI** La _description physique_ explique ce que sont les composants. **Comment**

_Système complexe_ :
- Comporte de nombreux éléments
- Interactions non homogènes
- Fait apparaitre des boucles de rétroaction

Il y a _différentes phases de tests_ dans le _Cycle en V_ :
- _Unitaires_ : Erreurs d'implémentation
- _Intégration_ : Cohérence de deux composants
- _Recette fonctionnelle_ : valide les exigences
- _Recette utilisateur_ Vérifie le process métier

Afin de limiter _l'effet tunnel_, a été mis en place le _Cycle en W_. Cette solution permet aussi de présenter un premier prototype avant de commencer la réalisation.
- Inconvéniants :
  - La conception d'un prototype n'est pas toujours possible (Coût).
  - Augmentation du coût global du projet.

Il est toujours possible d'alléger le prototype en ne faisant que des maquettes.

Rapid Application Developpment (RAD)
- Cycles itératifs
- Plus grande souplesse
- L'utilsateur suit la construction du système
- Limite globalement les risques projet

Méthodes agiles
- Nécessite un environnement favorable
  - Culture d'entreprise

- Bonne connaissance de l'architecture des Système d'information.

## Recueil du besoin
L'utilisateur n'exprime pas naturellement son besoin. _Il exprime son idée de la solution_.
- Quel est le périmètre fonctionnel du projet ?
- Quels sont les processus métier en jeu ?
- Quel rôle pour le système ?
- Quels échanges avec le système ?

## Démarche d'ubanisation du système d'information
On distingue 3 niveaux d'architecture :
- Architecture fonctionnelle
  - Décrit le découpage du système en blocs fonctionnels cohérents

- Architecture applicative
  - Décrit le découpage du système en "outils" couvrant un périmètre fonctionnel donné sur une plateforme technique donnée

- Architecture technique
  - Pour une application donnée, décrit l'infrastructure névessaire au fonctionnement des applications

## Organisation en pair-programming
- Principe :
  - On constitue des binômes de développement
  - Ce que l'un code, lautre le relit et/ou le test
  - Les binômes doivent changer régulièrement

- Objectif :
  - Déceler plus tôt les bugs par revue de code
  - Valider le respect des normes développement

- Effet psychologique :
  - Favorise l'échange entre développeurs
  - Favorise la formalisation des problèmes
  - Favorise un codage lisible et documenté

**Particulièrement mis en oeuvre dans les méthodes agiles**

## Les tests et la recette
Les tests de vérification sont effectués afin de valider la construction d'un système (_respect de la spec_). Les test des validation sont effectués afin de valider sur la solution répond bien au besoin de l'utilisateur. **Ces tests s'appliquent à chaque étape du développement**
