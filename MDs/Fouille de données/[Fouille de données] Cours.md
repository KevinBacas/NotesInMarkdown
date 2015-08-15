# [Fouille de données] Cours
# Introduction
## Trois principales tâches d'apprentissage
- Régression : déterminer une fonction `h` telle que : `h(xi) ~= f(xi) = y` (salaire = 1500 + 100*ancienneté)
- Apprentissage de classificaton : déterminer la fonction `f` telle que : `y = f<(xi, ui)>, i=1:n` (La voiture est une ferrari)
- Apprentissage de concepts : déterminer la fonction `f` telle que : `y = f<(xi, ui)>, i=1:n` (Le mail est un spam)

## Analyse statistique
2 type de variables peuvent décrire une individu
- Quantitative
  - continue : valeurs numériques
  - disjonctive : attributs booléens

- Qualitative
  - Catégorie non ordonnée : couleur
  - catégorie ordonnée : classement

## Facteur de correlation linéaire de Pearson
`Pij = COV(Xi, Xj) / VARIANCE(Xi)*VARIANCE(Xj)`

Mesure la dépendance linéaire de 2 variables. `Pij € [-1,1]`. Si `Xi` et `Xj` sont indépendantes, alors `Pij = 0`.

## Régression
Décrire une variable à partir d'une autre

### Linéaire
Ecrire une variable comme une combinaison linéaire d'une autre. `Vi = a*Vj + b`

### Non linéaire
`Vi = F(Vj)`

## Analyse en composantes principales (ACP)
### Principe
- Calcul des valeurs propres de cette matrice
  - Solutions de `P(x) = Déterminant(Cov - x.Id)`

- Tri dans l'ordre décroissant des valeurs propres
  - La variable de valeur propre maximale est la plus explicative

- Détermination des vecteurs propres associés
  - Résolution de l'équation `Cov - xi.Id = 0`
  - Les vecteurs propres associés au valeurs propres maximales sont appelés axes principaux

## Test du Ki2
### Principe
Comparaison des effectifs réels de deux variables qualitatives avec les effectifs théoriques qu'on devrait obtenir dans le cas d'indépendance de ces deux variables.

Pour cela on construit un indice D mesrant l'écart constaté entre les effectifs réels et les effectifs théoriques.

`D = SOMME((nij - n.pij)^2 / n.pij)` où nij = effectif observé des individus possédant la modalité i de la 1° variable et la modalité j de la 2° variable, n = effectif total observé, pij = probabilité d'obtenir une observation possédant la modalité i de la 1° variable et la modalité j de la 2° variable lorsqu'elles sont indépendantes, n.pij = effectif théorique des individus possédant la modalité i de la 1° variable de la modalité j de la 2° variable.

### Hypothèses
`H0` = Les deux variables qualitatives sont indépendantes.<br>`H1` = Les deux variables qualitativess sont dépendantes.

### Règle de décision
D > h on rejette H0<br>D < h on ne peut pas rejeter H0

### Déterminer le seuil critique
a = P [rejeter H0 quand H0 vraie] = P [D > h quand H0 vraie] = P[Ki2(c-1)(b-1) > h]

### Décision
Il ne reste plus qu'à comparer D avec h pour prendre une décision en fonction de la règle de décision.

# Processus de fouille de données
8 étapes :

## 1. Poser le problème
- Formulation
- Typologie (classificaton ou concept)
- Résultats attendus

## 2. Recherche de données
- Investiguation
- Réduction des données
  - Corrélation de Pearson
  - test du Ki2

## 3. Sélection des données pertinentes
- Apprentissage

## 4. Nettoyage de données
- Valeurs aberrantes
- Valeurs manquantes

## 5. Actions sur les variables
- Normalisation
- Transformation logarithmique
- Les rations
- Les combinaisons

## 6. Recherche du modèle
- Méthodes explicatives
- Méthodes de classification

## 7. Evaluation du résultat
- Evaluation du résultat
  - Matrice de confusion
  - Taux de reconnaissance

## 8. Intégration de la connaissance
- Desser un bilan
  - Remise en cause des données
  - Remise en cause du modèle
  - prise en compte d'une variable pertinente

# Les modèles explicatifs
La définition d'un modèle se base du des règles conditionnelles

Les enjeux :
- Optimisation des stocks
- Merchandising
- Identification de facteurs d'un risque

## Algorithme ID3
Technique de découpage de l'ensemble d'exemples en recherchant à chaque niveau la variable la plus discriminante
- Extraction automatique des règles
- Mise en évidence de variables iportantes
- Formalisme simple

**Metrique de Hamming(hd)** & **Pseudo-distance de hamming (pm)**.

## Réseau Bayésiens
C'est la définition d'une probabilité d'apparition d'un événement, étant donnée la connaissance de certains autres évènements. C'est un graphe orienté où les noeuds sont des variables et les arcs des dépendances.

### Règle de Bayes
`P(X/Y) = P(X,Y) / P(Y)`

### Mesure d'entropie
`H(X) = -SOMME(P(X).log(P(X)))`

### Information mutuelle
`H(X/Y) = -SOMME(P(X,Y).log(P(X/Y)))`

### Construction du réseau bayésien
1. Préparation des variables : distinction des variables continues et discrètes et découpage des variables continues.
2. Sélection des variables (information mutuelle) : distinction des variables d'entrée et de sortie. Une variable de sortie ne peut pas être une variable d'entrée pour une autre.
3. Identification des dépendances : tri par ordre décroissant des dépendances entre variables
4. Matrice des probabilités : comptage des occurrences entre les différents noeuds.

## Algorithmes génétiques
Méthode d'optimisation par un système artificiel s'appuyant sur la théorie de l'évolution de Darwin (1859) et sur les méthodes de combinaison des gènes par Mendel.

### Analogie avec la sélection naturelle dans le monde vivant
L'évolution dans le monde vivant a permis l'émergence de d'organismes étonnamment adaptés à leurs environnements

### Le point clef
Le hasard (théorie du chaos) expliquant des variations individuelles
