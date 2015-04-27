# [Cryptographie Appliquée] Notes de cours

## Cryptographie à clé secrètre
C'est un chiffrement par bloc opérant sur des données de N bits avec une clé de k bits. Il est composé de deux fonctions:
* Ek : {0, 1}^N x {0, 1}^k -> {0, 1}^N **Chiffrement**
* Dk : {0, 1}^N x {0, 1}^k -> {0, 1}^N **Déchiffrement**

Les *tailles de clés* et *blocs recommandées* sont de *128 bits* avec *Ek et Dk des permutations pseudo-aléatoires*. C'est-à-dire que si on change 1bit d'un message, les deux chiffrés sont *indépendants*.

Afin de chiffrer une *taille quelconque* de message on a recours à un mode *opératoire de chiffrement*.

## Fonction de hachage
C'est une *fonction à sens unique* qui se doit d'être *résistante aux collisions*. Ce n'est pas un cryptosystème car il n'y a *pas de clé*.

## Mac
C'est une *fonction pseudo-aléatoire* dont la taille est indépendante de celle du message. On s'en sert généralement pour le *contrôle d'intégrité*.

## Sécurité des mots de passe
* Objectif d'un attaquant : Récupérer un couple identifiant/mot de passe pour faire de l'usurpation d'identité
* Techniques de bases actuelles : Phishing, Sniffing, Keylogger ou virus variés.
* Modèle de sécurité du cours : Les mots de passe sont hachés et l'empreinte est stockée dans un fichier pouvant être récupéré par un attaquant qui possède un cluster de calcul et une grande capacité de stockage.

### L’attaque par force brute
Elle consiste à *essayer toutes les possibilités jusqu’à retrouver l’empreinte*. Cette méthode
nécessite *beaucoup de temps mais pas de mémoire*.
### L’attaque par dictionnaire
Elle consiste à *précalculer toutes les empreintes de tous les mots de passe* et de stocker les paires. Cette méthode nécessite *très peu de temps* (le temps de retrouver le bon mot de passe) mais *beaucoup de mémoire*.
### Les attaques par compromis temps/mémoire
Elles nécessitent *moins de temps que la force brute* et *moins de mémoire qu’une attaque par dictionaire* sont les attaques les *plus puissantes*.

## Compromis temps/mémoire
Méthode pour retrouver des clés avec des tables précalculées (crées à partir de chaînes), proposée par Hellman (1980).
> Les compromis temps-mémoire sont utilisés en cryptanalyse pour récupérer des clés à partir de leur trace chiffrée, en s'appuyant sur des tables précalculées. Cette méthode a été formalisée par Martin Hellman dans son article A cryptanalytic time-memory trade-off publié en 1980.
> Comme son nom le suggère, cette méthode probabiliste se trouve à mi-chemin entre une recherche exhaustive à la demande (demandant un temps excessif) et un stockage complet préalable de toutes les solutions possibles en mémoire par un annuaire inverse (demandant une capacité de stockage irréaliste).
> La méthode utilise des tables précalculées (souvent plusieurs jours de calcul) pour accélérer considérablement un cassage de clé "à la demande" en fonction des caractéristiques de la clé brouillée.
> **Source : [Wikipédia](http://fr.wikipedia.org/wiki/Compromis_temps-m%C3%A9moire)**

## Table arc-en-ciel (Rainbow Table)
> Une rainbow table (littéralement table arc-en-ciel) est, en cryptanalyse, une structure de données créée en 2003 par Philippe Oechslin de l'EPFL pour retrouver un mot de passe à partir de son empreinte. Il s'agit d'une amélioration des compromis temps-mémoire proposés par Martin Hellman dans les années 1980.
> La table, qui ne dépend que de la fonction de hashage considérée, est constituée d'une grande quantité de paires de mots de passe. Pour obtenir chacune de ces paires, on part d'un mot de passe, et on calcule son empreinte. Une « fonction de réduction » qui varie selon la position dans la table permet de recréer un nouveau mot de passe à partir de cette empreinte. On itère ce processus, et après un nombre fixe d'itérations, on obtient un mot de passe qui forme le deuxième élément de la paire. La table, créee une fois pour toutes, permet la recherche d'un mot de passe, connaissant son empreinte par la fonction de hashage considérée.
> L'algorithme développé par Oechslin optimise la détection des collisions et le parcours dans la table. Des solutions pour réduire la taille de la table ont également été proposées. Plusieurs tables peuvent être produites pour améliorer les chances de réussite.
> **Source : [Wikipédia](http://fr.wikipedia.org/wiki/Rainbow_table)**

## Chiffrement asymétrique
Un chiffrement asymétrique travaille sur des blocs de N bits, avec un couple (clé publique /clé privée) et deux fonctions :
* Une fonction de chiffrement qui prend en entrée un message et la clé publique et renvoie un message chiffré.
* Une fonction de déchiffrement qui prend en entrée un message chiffré et la clé privée et renvoie le message clair.

> Exemples : les crypto-systèmes RSA et El-Gamal qui ont des tailles de clés variant entre 1024, 2048 ou 4096 bits. Il est recommandé d’utiliser un modulus N (pour RSA) ou un corps fini Fq (pour El Gamal) d’au moins 2048 bits, voir 3072 bits.

## Schéma de signature
Un schéma de signature travaille sur des blocs de N bits, avec un couple (clé publique /clé privée) et deux fonctions :
* Une fonction de signature prend en entrée un message et la clé privée et renvoie la signature du message.
* Une fonction de vérification qui prend en entrée un message, la signature correspondante et la clé publique et vérifie si la signature est bonne en renvoyant oui ou non.

> Exemples : les schémas RSA, DSA, qui ont des tailles de clés
variant entre 1024, 2048 ou 4096 bits. Il est recommandé
d’utiliser un modulus N (pour RSA) ou un corps fini Fq (pour
DSA) d’au moins 2048 bits, voir 3072 bits.

## Infrascructure à clé publique (PKI)
Une infrastructure à clé publique (PKI) est un ensemble d’entités et de procédures pour la gestion des clés avec la création, le stockage, l’utilisation et la révocation de certificats.
Principe : plutôt que de distribuer des clés publiques à des entités, on distribue des certificats qui contiennent ces clés.
Ce certificat permet de lier une clé publique avec l’entité (personne physique ou serveur) qui prétend posséder cette clé.
Deux acteurs principaux interviennent dans cette infrastructure (en plus du détenteur du certificat et de ceux qui vont l’utiliser pour y récupérer des informations) :
* L’autorité de certification qui est l’autorité de confiance
qui émet des certificats, gère les listes de révocation (peut
être délégué ) et est l’entité juridique de la PKI.
* L’autorité d’enregistrement qui enregistre les entité dans
l’infrastructure à clé publique et s’assure que la clé est bien
reliée à l’entité qui lui a été assignée.

*X.509* est le principal *standard pour les PKI* (certificats, listes de révocation et attributs), apparu en 1998, modifiée en 1996.
Structure du certificat X.509 :
* Version du certificat et numéro de serie.
* Émetteur (nom de l’autorité generant le certificat).
* Période de validité (début et fin).
* Nom (et informations) du sujet et clé publique du sujet.
* Nom de l’algorithme utilisant cette clé publique.

> Ce certificat est signé par l’autorité de certification avec sa propre clé privée : le certificat contient en plus l’algorithme de signature du certificat et la signature du certificat.

Génération d’un certificat :
* L’autorité d’enregistrement génère une paire clé publique/clé privée. La clé privée est envoyée à l’entité et la clé publique est envoyée à l’autorité de certification.
* L’autorité de certification vérifie la clé privée avec un protocole challenge/réponse.
* L’autorité de certification crée le certificat, qui inclue la clé publique de l’entité, en la signant avec sa propre clé privée.

Vérification d’un certificat :
* Verification de la date de validité du certificat et comparaison avec la liste de révocation.
* Les données du certificat sont hachées par le vérificateur et la signature est ensuite vérifiée avec la clé publique de l’autorité de certification (pour s’assurer de l’intégrité).
