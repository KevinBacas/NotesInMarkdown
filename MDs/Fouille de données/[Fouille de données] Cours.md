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
