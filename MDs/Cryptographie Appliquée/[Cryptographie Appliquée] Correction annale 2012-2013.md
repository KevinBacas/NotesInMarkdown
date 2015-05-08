# [Cryptographie Appliquée] Correction de l'annale 2012-2013
## Exercice 1
- **Correction par Jad <3**

  > La sécurité des mots de passe dépend de la taille du hash jusqu'à un certain point(128/256 bits largement suffisant).
    - Pour une attaque par force brute : _2^(128/256)_ essais pour une pré-image jusqu'à 2^80.
    - 128 bits suffisent pour une attaque par force brute.
      - Pour trouver des collisions _2^(N/2)_. Pour atteindre _2^80 (Infaisable à l'heure actuelle)_ il nous faut 160 bits. Cependant les collisions sont peu interessantes pour les mots de passe.

    - Pour une attaque par dictionnaire, supposons qu'on a un hash de 128 bits
      - Supposons que l'on veuille stocker au moins 2^48 hash de mot de passe
      - 2^48 x 128bits = _64TBytes_ !

  > **Conclusion :** La sécurité du mot de passe dépend surtout du mot de passe (_Notion d'entropie_)

- **Correction par Jad <3**

  > Le serveur stocke les mots de passe crypté (3-DES _à éviter pour des mots de passe de moins de 8 octets_, AES). Pour envoyer le mot de passe, il sera crypté avec le même algortihme et comparé avec celui stocké dans le serveur.

  > Le MAC est généralement envoyé en complément avec un différente clé du chiffré afin de vérifier l'intégrité des données.

- Le principe des tables arc-en-ciel est quasiment le même que le compromis temps/mémoire. On va alterner une fonction de hachage et une fonction de réduction (qui elle produit un mot de passe à partir d'un haché). On va donc stocker beaucoup moins de mots de passe. En pratique on utilise t fonctions de réduction différentes pour réduite les fusions. En somme, les tables arc-en-ciel sont simplement un type de stockage optimisé dérivié du compromis temps/mémoire.

## Exercice 2
- Les modes opératoires standards (_or CBC_) ne sont pas adaptés car il ne permettent pas de modifier une section du mot chiffré. Si on chiffre un fichier de 2Go, on devra rechiffrer ce dernier dans son intégralité même si on ne change qu'un seul bit.
- Il est plus adapté car son mode de chiffrement permet de délimiter des "secteurs" afin de pouvoir recrypter qu'une partie du fichier si on modifie ce dernier.
- On va itérer sur les différents secteurs et appliquer la fonction de déchiffrement sur chacun d'eux.

## Exercice 3
  - Version du certificat
  - Numéro de série
  - Emetteur
  - Période de validité
  - Nom et informations au sujet de la clé publique du sujet
  - Nom de l'algorithme utilisant cette clé publique

1. Dans ce cas, l'utilisation d'un certificat va servir à identifier une carte, être sûr que c'est bien la bonne et réaliser l'authentification en étant sûr du demandeur.
2. Tous les points d'acceptation de la carte (Les terminaux).
3. Il garantit la confidentialité et l'intégrité des échanges.

## Exercice 4 **Correction par Quentin <3**
  - Le Back Office
  - La machine de PIN Mailing
  - SAA
  - SAE
  - L'interface bancaire du réseau e-RSB
  - Transhiffrement du PIN
  - Vérification du PIN
  - Génération du PIN
  - Calcul de l'ARPC
  - Vérification de l'IDN
  - Dérivation des clés maître Emetteur EMV
  - Calcul de l'IDN
  - Générer des clés
  - Effectuer des calculs cryptographiques
  - Contrôler et faire respecter l'usage des clés
  - Trois
  - Clé KTK
