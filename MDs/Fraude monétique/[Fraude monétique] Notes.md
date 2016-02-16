# [Fraude monétique] Notes
## Les types de fraude
- Fraude
  - Fraude porteur
  - Fraude commerçant
  - Fraude systémique

- L'abusif
  - Insolvabilité
  - Solde débiteur
  - Mauvaise foi

- Les impacts financiers
  - Les assurances
  - Les pertes et profits

### Fraude carte
- Fraude carte exceptionnelle (62% en volume)
- Fraude carte organisée (38% en volume)
  - MiTM
  - Skimming
  - Carte ré-embossée
  - Copie de piste
  - Vol de fichiers
  - Vol informations carte

### Evolution
Transactions en 2012 : 561 Mds € pour 450 millions de fraude (0.080 %)

### Définitions
Une transaction frauduleuse est une transaction faite par un tiers qui n'est pas le porteur légitime avec une carte ou un numéro de carte qui est, ou va être, en opposition.

Une transaction peut-être rejetée impayée par la banque émettrice si la carte est en opposition et si le commerçant n'a pas respecté l'une des mesures de sécurité.

## Fraudes TPE
- Observation des codes à l'aide d'une caméra
- Observation des échanges clavier/carte ou carte/TPE
- Transaction inversée
- Gravure du N° en sur-impression
- Maquillage des cartes à puce avec hologramme
- Man-in-The-Middle
- Le porteur n'a aucun moyen de vérifier que le TPE n'est pas fraudable

## Attaques EMV
- Clonage de carte SDA- Yes cards
- Copie piste magnétique
- Manipulation du CVM (Cardholder Verification Method)
- Relay attack

# Litiges
## Résolution cas idéal
1. Détail transaction litigieuse
2. Fournis les clés maître de la transaction et le certificat sinon reboursement client.

## Résolution actuelle
1. Détail transaction litigieuse
2. Notre système est sécurisé, votre code PIN a été utilisé. Vous ne pouvez donc pas être remboursé.

## Problème générique
Chaque partie a quelque chose pour le protéger, sauf le client. Relation hautement asymétrique et conflictuelle.

# Lutte contre la fraude
La fraude met en cause la confiance des utilisateurs et l'équilibre économique du système. Ce doit être un objectif posé dès le départ. Ce n'est pas un enjeu de concurrence entre les banques. C'est une action collective où le rôle de chacun doit être clairement établi.

## Environnement
La loi bancaire définit qui a le droit d'émettre des moyens de paiement. Il y a irrévocabilité du paiement et une valeur probante du code confidentiel. CGU porteur, CGU commerçant.

## Structure inter-bancaire
Mandatée et controlée par les banques pour faire ce qu'une banque ne peut pas faire toute seule. Un partage clair des rôles respectifs. Définir des règles et standards techniques, les équilibres financiers interbancaires. Organiser et coordonner la lutte contre la fraude. Assurer les relations spécialisées (Police, justice). Harmoniser l'information technique. Les assurances.

### Les outils
- Table des PIN
- Fichier complet des oppositions
- Fichier des établissements
- Fichier tecnique des commerçants
- Fichier National des GAB
- Tables de routage pour le e-RSB et le STET
- Copie des transactions frauduleuses
- Préconisations
- Statistiques
- Systèmes experts d'analyse des autorisations.

### Leur maintenance
Approche temps réel pour détecter les comportements potentiellement frauduleux. Prise en compte des alertes. Calcul de score en fonction du risque estimé.
