# [Graphes et Automates] Notes
## Graphes
### Définition
Un graphe `G = (V,E)` est définit par un ensemble `V` de sommets (= vertex/node) et un ensemble `E` de paires de coordonnées de sommets distincts.

Chaque paire `e = {u,v}` de sommets est une arête de G.

On écrira `e = uv` et dira que `u` et `v` sont adjacents.

On dira que l'arête `e` et le sommet `u` sont **incidents** (idem pour `e` et `v`)

Si deux arêtes sont incidentes à un même sommet, on dira qu'elles sont adjacentes.

Un _graphe_ avec `p` sommets et `q` arêtes sera nommé un `(p,q)` graphe.

### Premières variétés de graphes
Un _multiraphe_ est un graphe dans lequel deux sommets peuvent être joints par plusieurs arêtes.

Un _pseudo graphe_ est un multigraphe comportant également des boucles.

Un _graphe dirigé_ (ou digraphe) est un ensemble de sommets `V` muni d'un ensemble de paires ordonnées de sommets distincts définissant ces arêtes.

Les arêtes d'un _digraphe_ sont communément appelées des _arcs_.

Un graphe orienté `D = (V,E)` est un digraphe tel que `(u,v) € E => (v,u) €/ E`.

Un graphe est _labelisé_ lorsque chacun de ces sommets est attaché à une valeur distincte.

### Isomorphisme
Deux graphes `G1 = (V1,E1)` et `G2 = (V2,E2)` sont dits isomorphes lorsqu'il existe une bijection `f` de `V1` dans `V2` telle que `uv € E1` si et seulement si `f(u)f(v) € E2`.

Un invariant d'un graphe est une quantité qui a la même valeur pour deux graphes isomorphes (ex: Nombre de sommets, d'arêtes, degré des sommets...).

### Sous graphe
Un sous graphe de `G = (V,E)` est un graphe dont les arêtes et les sommets sont respectivements inclus dans `V` et `E`. Si `G1` est un sous graphe de `G` alors `G` est un _supergraphe_ de `G1`.

Un sous graphe recouvrant est un sous graphe de `G` recouvrant tous ses sommets.

### Opération élémentaires sur les graphes
La suppression d'un sommet d'un graphe `G = (V,E)` `G - v` est définie par le sous graphe de `G` définit sur `V - {v}` sommets et possédant toutes les arrêtes `E` à l'exception de celles incidentes à `v`.

La suppression d'une arête `G - e` est définie par le couple `(V, E - {e})`

L'addition de l'arête `e` est définie comme le plus petit super graphe de `G` contenant `e`.

### Chemins
Un chemin est un suite de sommets 2 à 2 adjacents.

Un chemin est _fermé_ si `v0 = vn`. Un chemin _simple_ est un chemin ne passant pas deux fois par la même arête. Un chemin _élémentaire_ est une chemin ne passant pas deux fois par le même sommet (et donc pas la même arête). Un chemin élémentaire fermé avec `n>3` est appelé un _cycle_.

### Connexité
Un chemin et un cycle de longueur `n` sont respectivement notés `Pn` et `Cn`.

Un graphe est connexe si toute parie de sommet peut être reliée par un chemin élémentaire. Un sous graphe connexe maximal est appelé une composante connexe.

Un graphe complet Kp est le grape de p sommets tous adjacents entre eux.

La distance `d(u,v)` entre deux sommets `u` et `v`est définie comme le plus court chemin joignant `u` et `v` s'il sont connectés. `d(u,v) = Infinity` sinon. La distance ainsi définie est une métrique : `d(u,v) >= 0` avec `d(u,v) = 0` si et seulement si `u = v` et `d(u,v) <= d(u,w) + d(w,v)`

### Degrés
Le degré d'un sommet `vi`, noté `di` ou `deg(vi)` correspond au nombre d'arêtes incidentes à `vi`. Le degré minimum d'un graphe `G` est noté `Gamma(G)` et son degré maximum `delta(G)`. Si `Gamma(G) = delta(G) = r`, on dit que le grape est régulier de degré `r`.

### Graphe biparti
Un _graphe biparti_ est un graphe dont l'ensemble des sommets `V` peut être partitionné en deux sous ensembles `V1` et `V2` tels que toute arête `E` de `G` connecte `V1` à `V2`. Si chaque sommet de `V1` est adjacent à tous les sommets de `V2` et vice versa, on parle alors de _graphe biparti complet_.

### Opérations sur les graphes
Soient `G1` et `G2` deux graphes avec `intersect(V1,V2) = /O`. L'union de `G1` et `G2`, `G1 U G2` est le graphé défini sur `V1 U V2` avec l'ensemble d'arêtes `E1 U E2`. La jointure de `G1` et `G2`, `G1 + G2` est le graphe `G1 U G2` auquel on ajoute l'ensemble des arêtes reliant `V1` à `V2`.

Le graphe produit `G1 x G2` a pour ensemble de sommets `V1 x V2`. La composition de `G1` et `G2`, `G1[G2]` a également `V1 x V2` comme ensemble de sommets, mais `u` est adjacent à `v` si et seulement si `u1v1 € E1` ou `u1 = v1` et `u2v2 € E2`.

### Définitions
- _Point d'articulation_ : Un sommet dont la suppression modifies le nombre de composantes connexes du graphe.
- _Pont_ : Une arête dont la suppression modifies le nombre de composantes connexes du graphe.
- _Graphe non séparable_ : Graphe connexe et n'a pas de point d'articulation.
- _Block_ : ous graphe non séparable de taille maximale. Si G est non séparable, on dit qu'il est un block.
- _Graphe acyclique_ : Graphe ne possedant pas de cycle.
- _Arbre_ : Graphe acyclique connexe.
- Un _graphe acyclique_ non connexe est une forêt. Toute composante connexe d'une forêt est un arbre.

### Caratérisation des arbres
- `G` est un _arbre_
- Tout couple de sommets de `G` est lié par un chemin élémentaire unique
- `G` est connexe et `|V| = |E| + 1`
- `G` est acyclique et `|V| = |E| + 1`
- `G` est acyclique et si deux sommets non adjacents de `G` sont reliés par une arête `e`, alors `G | e` a exactement 1 cycle
- `G` n'est pas `K3 U K1` ni `K3 U K2`, `|V| = |E| + 1` et si deux sommets non adjacents de `G` sont reliés par une arête `e`, alors `G | e` a exactement 1 cycle

### Connexité au sens des sommets et des arêtes
La connexité de G au sens des sommets K(G) est le nombre minimal de sommets que l'on peut supprimer avant de déconnecter le graphe ou d'obtenir un arbre trivial.<br>La connexité de G au sens des arêtes, alpha(G) est le nomre minimal d'arêtes que l'on peut supprimer de G sans le déconnecter ou obtenir un graphe trivial.

### Théorème de Menger et ses variations
- Deux chemins de u à v sont dirs disjoints (ou sommet-disjoint) s'ils ne partagent pas d'autres sommets que u et v. Ils sont dits arête disjoints s'ils ne partagent pas d'arête.
- Un sous graphe S sépare u et v, si u et v sont dans différentes composantes connexes de G - S.
- Théorème 1 : Le nombre minimum de sommets séparant deux sommets non adjacents s et t est le nombre maximum de chemins disjoints entre s et t.
- Théorème 2 : Pour tout couple de sommets, le nombre maximum de chemins arête-disjoint joignant ces deux points est égal au nombre minimum d'arêtes que les séparent.

## Compilation
### Analyse lexicale
Objectifs :
- Transformation d'un ensemble de caractères en concepts
- On distingue 3 concepts :
  - Unité lexicale : correspond à une entité renvoyée par l'analyseur lexical. Ex : <,>,<=,>= sont des opérateurs relationnels
  - Lexème : Instance d'unité lexicale. Par exemple, 6.28 est une instance d'unité lexicale.
  - Modèle : associe des lexèmes à leur unité lexicale.
