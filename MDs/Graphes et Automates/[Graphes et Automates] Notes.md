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

### Opération élémentaites sur les graphes
La suppression d'un sommet d'un graphe `G = (V,E)` `G - v` est définie par le sous graphe de `G` définit sur `V - {v}` sommets et possédant toutes les arrêtes `E` à l'exception de celles incidentes à `v`.

La suppression d'une arête `G - e` est définie par le couple `(V, E - {e})`

L'addition de l'arête `e` est définie comme le plus petit super graphe de `G` contenant `e`.