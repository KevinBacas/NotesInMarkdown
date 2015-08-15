# [Cryptographie] Notes
# Cours 1 : Introduction
## A quoi sert la cryptographie ?
- Confidentialité : Seules les personnes autorisées pourront accéder à l'information.
- Intégrité : Assurer que les données n'ont pas été modifiées
- Non-répudiation : immossibilité de nier un accord électronique
- Authentification : Prouve l'origine des données
- Identification : Prouve l'identité

## Définition d'un système cryptographique
Un système cryptographique st la donnée de :
- L'ensemble fini M des messages clairs
- L'ensemble fini C des messages chiffrés
- L'ensemble fini K des clés
- Pout tout kc € K et m € M, une fonction de chiffrement Ekc(m)
- Pour tout kd # K et c € C, une fonction de déchiffrement Dkd(m)

La sécurité repose _uniquement_ sur le secret des clés. Les fonctions de chiffrement sont connues.

## Cryptanalyse
Plusieurs types d'attaques:
- **Attaque à chiffré seul** : L'attanquant possède un ou plusieurs messages chiffrés et essaie de retrouver la clé.
- **Attaques à messages clairs connus** : L'attanquant possède un ou plusieurs couples message clairs/chiffrés et essaie de retoruver la clé.
- **Attaques à messages clairs choisis** : L'attanquant peut choisir tous les messages clairs qui sont chiffrés, afin de retrouver la clé.

En particulier, le crypto-système doit résister à une attque par **recherche exhaustive**, où toutes les clés sont testées.

### Modèles de sécurité
#### Sécurité inconditionnelle
L'adversaire a des ressources illimités. On va alors se rapprocher de la théorie de l'information et des probabilités.

#### Sécurité calculatoire
L'adversaire a des capacités de calcul limitées (en temps polynomial). On se rapproche alors de la théorie de la complexité.

#### Sécurité ad-hoc
Analyse ou argumentation variées expliquant pourquoi le cryptosystème est difficile à attaquer, sans preuve de sécurité.

#### Sécurité par l'obscurité
Aucune sécurité. Possibilité de _reverse engineering_, algorithmes cassés dès leur publication.

# Cours 2 : Chiffrement par blocs
## Le chiffrement symétrique
Le **chiffrement symétrique** est aussi connu sous le nom de **chiffrement à clé secrète**. On note Ek et Dk les fonctions de chiffrement et de déchiffrement, où k est la clé secrète. La clé de chiffrement est la même que la clé de déchiffrement.

### Avantages
Le chiffrement et le déchiffrement sont rapides et les clés sont courtes (ex : 128 bits = 16 octets pour l'AES-128)

### Inconvénients
La clé secrète doit être partagée par les utilisateurs. De multiples clés sont nécessaires dans un groupe de plusieurs utilisateurs.

### Son fonctionnement
1. _Alice_ chiffre le message _m_ avec la clé _k_ et envoie `c = Ek(m)` à _Bob_ sur un canal non sécurisé
2. _Bob_ déchiffre le message `m = Dk(c)`

Le chiffrement assure la confidentialité du message.

## Les familles de chiffrement symétrique
Il existe deux grande familles de chiffrement symétrique :
- Le chiffrement _par blocs_ et le chiffrement _à flot_.

### Le chiffrement par blocs
Il consiste à diviser le message clair en plusieurs blocs de mêmes tailles. On peut éventullement utiliser le _padding_ pour le dernier bloc. Un algorithme de chiffrement par blocs chiffre un message m par blocs de taille fixe (ex : 128 bits pour l'AES-128). Le bloc chiffré doit sembler totalement aléatoire à quelqu'un ne connaissant pas la clé, quelque soit le bloc de texte clair. Ainsi, si on modifie un bit du message clair, le message chiffré correspondant doit être modifié dans sa totalité.

#### Algorithmes
Transformation de Feistel : Un bloc de 2n bits est coupé en deux blocs de n bits chacun. A l'issue de la transformation, `Li+1 = Ri` et `Ri+1 = Li ^ F(Ri, K)`

Elle est à l'origine de nombreux algorithmes de chiffrement par blocs utilisent des schémas de Feistel: **DES**, **Blowfish**, **Twofish**, **RC5**, ...

#### DES
Le DES (Data Encryption Standard) est proposé pas le NBS (Aujourd'hui appelé le NIST) et standardisé en 1977. Il est basé sur le schéma de Feistel sur 16 tours et élaboré à partir de l'algorithme Lucifer (IBM). Le DES transforme un bloc de 64 bits en un bloc de 64 bloc de 64 bits, avec une clé de 56 bits (sous clés de 48 bits) : `|M| = 2^64, |K| = 2^56, |C| = 2^64`.

Il résiste bien aux cryptanalyses différentielle et linéeaire mais l'espace des clés est trop petit.

#### Double DES
Permet d'augmenter la taille de l'espace des clés en utilisant deux clés différentes k1 et k2 de 56 bits. Mais il est vulnérable à une attaque à messages clairs connus

#### Triple DES
Le triple DES permet d'augmanter la taille de l'espace des clés en utilisant deux clés de 56 bits également. Le problème du 3-DES est qu'il est 3 fois plus lent que le DES.

Le chiffrement d'un message _m_ utilise deux chiffrement et un déchiffrement DES, dans l'ordre suivant : `Ek1,k2(m) = DESk1(DESk2^-1(DESk1(m)))`

#### AES
L'AES (Advanced Encryption Standard) est la réponse à un appel à candidature lancé par le NIST en 1997 pour un nouveau standard destiné à remplacer le 3-DES.

Spécifications :
- Taille de blocs : 128 bits
- Taille de la clé : 128, 192 ou 256 bits
- Nombre de tours : 10, 12 ou 14 selon la taille de la clé

Il n'y a pas d'attaques connues sur l'AES. Le 3-DES n'est plus recommandé alors que l'AES est confirme au RGS.

# Course 3 : Mode opératoire et chiffrement à flot
Les chiffrements par blocs posent le probème suivant : Comment gérer les blocs ? Nous utilisons alors les mode opératoires.

Le NIST a standardisé plusieurs modes, dont **ECB**, **CBC**, **OFB**, **CFB** et **CTF**.
