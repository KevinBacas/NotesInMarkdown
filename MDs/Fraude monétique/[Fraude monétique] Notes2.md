# [Fraude monétique] Notes2
## Analyse et maîtrise du risque monétique

### Les types de risque
- Risque stratégique ou spéculatif
  - Risque pris délibérément pour réaliser l'objectif de l'entreprise, la prise de risque fait partie intégrante de l'activité de l'entreprise

- Risque pur ou opérationnel
  - Risque accidentel et aléatoire qui se crée du fait et à l'occasion de l'activité exercée. Risque pouvant aboutir à des dommages causés à l'entreprise, ou par l'entreprise

### Les types de dommages
- Dommages physiques
  - Dommages aux équipements
  - Dommages aux personnes

- Dommages logiques
  - Atteintes aux processus
  - Pertes d'image de marque
  - Pertes d'information

### Définitions
- Menace : action susceptible de porter atteinte à votre système informatique
- Vulnérabilité : probabilité que le système se dégrade
- Risque : menace plus ou moins prévisible
- Contre mesure : action de prévention de la menace
- Sécurité : probabilité que le système accomplisse sa mission en l'absence de circonstances pouvant occasionner des nuisances
- Disponibilité : Garantie des accès
- Confidentialité : Contrôle des accès
- Identification : Vérification d'identité
- Authentification : Garantie des partis échangeurs
- Chiffrement : Rendu illisible d'un élément
- Signature : Marque unique de création ou de modification
- Intégrité : Protection face à l'altération
- Scellement : Rendu impossible à la modification invisible
- Non répudiation : Garantie de participation des partis

### Paiement à distance par carte (30)
- Echange sécurisé avec possibilité de répudiation par le porteur (pas d'identification) (SSL, TLS)
- Paiement par Internet non répudiable (SET puis C-SET, 3D SECURE)

### Certification des cartes bancaires
- Emmetteurs doivent utiliser des puces et des logiciels achetés auprès d'encarteurs.
- Les cartes sont soumises au contrôle d'entités de test
  - Evaluation de critères communs
  - Verification de conformité aux standard ISO 7816 et EMV ainsi que CB, Visa, MasterCard
- Validation des visuels de carte
- Utilisation de centre de personnalisation agréés par les réseauxx carte

### Les critères communs
Synthèse des critères à respecter en matière de sécurité pour les SI. Cela concernprincipalement les sous-systèmes (Firewalls, switchs, cartes à puce). C'est l'ISO 15408.

#### Accord CCRA (Common criteria Recognition)
- 7 pays capables de délivrer des certifications
  - Allemagne
  - Australie
  - Nouvelle-Zélande
  - Canada
  - Etats-Unis
  - France
  - Grande-Bretagne

#### TOE, PP et ST
- Partie 1 : Introduction et modèle général
- Partie 2 : Exigences fonctionnelles de sécurité
- Partie 3 : Exigences d'assurance de sécurité

- TOE (Target of evaluation) : Designation de l'objet à certifier
- PP (Protection Profile) : Ensemble type d'exigences de sécurité pour une cartégorie de produits
- ST (Security Target) : Niveau de sécurité spécifique pour le produit à évaluer

#### Niveaux EAL
- EAL1 : testé fonctionnellement
- EAL2 : testé structurellement
- EAL3 : testé et vérifié méthodiquement
- EAL4 : conçu, testé et vériﬁé méthodiquement
- EAL5 : conçu de façon semi-formelle et testé
- EAL6 : conception vérifiée de façon semi-formelle et testé
- EAL7 : conception vérifiée de façon formelle et testé

#### Conclusion
- Les critères communs permettent de caractériser la résistance d'une puce aux attaques connues et même supposées
- Cette norme ISO 15408 permet aux fondeurs de réaliser des puces résistantes
- Permet aux emetteurs de vérifier que les puces ne sont pas attaquable dans l'état des connaissances
- Cette norme qui est acceptée internationalement, l'est aussi pour les "schéma carte"

### L'agrément
#### EMV
- Première norme en 1995 (2.0)
  - 3.0 en 1996
- Reconnaissance à la conformité délivrée par EMVCo
  - Suite à des résultats de tests effectués par un laboratoire d'analyse accrédité
  - Confirmité à deux niveaux
    - 1 : Couvre les interfaces physiques, electrique et transport
    - 2 : Convre sélection d'applications de paiement, de crédit et de traitement des transactions financières

#### L'agrément au réseau carte
Après EMVCo, le TPE doit être agréé par les réseaux carte qui vérifient le couple matériel/logiciel
Procédure:
1. Demande d'agrément
2. Matériel soumis à un laboratoire habilité pour ces tests
3. Résultats des tests soumis à CB
4. Décision transmise à Visa et MasterCard pour validation
5. Terminal agréé Visa, MasterCard et CB pour la France

#### Remarques
- L'agrément est un élément incontournable de la sécurité et de la confiance
- L'agrément assure que les prérequis ont été respectés
- C'est un élément opposable offrant garantie au commerçant d'être payé
- C'est la garantie que la matériel ne perturbera pas le fonctionnemetn de l'ensemble du réseau carte

### PCI (PCI DSS, PCI PED) (60+)
#### PCI = Payment Card Industry
- Destiné à déterminer, mettre en place et contrôler les dispositifs de sécurité nécessaires au paiement par carte
- L'organisation va être confiée à PCIco, Visa, Mastercard, JCB

- PCI-PTS : Payment Terminal Security
- PCI-DSS : Data Security Standards
- PCI-PA-DSS : Payment Application Data Security Standards
- PCI-P2PE : Point-to-Point Encryption

- PCI-PTS + PCI-DSS + PCI-PA-DSS = PCI Security & compliance
- Terminal + Système accepteur + Système acquéreur

#### PCI-DSS
- PCI-DSS est une réponse globale à la fraude organisée
- Contrainte coûteuse sans apport positif pour le commerçant
- 12 contraintes pour être conforme
- Réduit le risque de faille de sécurité compromettant les données sensibles ainsi que la fraude nuisible résultant de ces failles

#### PCI-PA-DSS
- Originellement PABP par Visa
- A pour but d'aider les fournisseurs de logiciels à développer des applications de paiement sécurisées qui ne mémorisent pa de données interdites

#### PCI-PTS
- Vise à renforcer la robustesse des terminaux, via des normes sur la sécurité de paiement. S'applique mondialement.

#### PCI-P2PE
- Chiffrement bout en bout, qui combine des dispositifs de sécurité, d'applications et de processus permettant de chiffrer les données du point d'interaction (ou d'acceptation de la transaction) jusqu'au tiers fournissant le service et l'environnement de déchiffrement.

### La sécurité des systèmes monétiques
- Les fichiers des transactions, réalisée par le CMI, sont envoyés chaque jour aux différentes Banques
  - Autorisations données
  - Transaction réalisées
- Analyse de ces fichiers par les banques
  - Recherche de fraude
  - Préparation des réponses pour les porteurs ou les commerçants
  - Rechercher les POC
- La banque doit permettre à au moins 2 de ses employés de se former en permanance à la fraude
- En particulier :
  - Plan de gestion de crise
  - Participer à la mise en place et du fonctionnement de réunions pays et sous régionales
  - Effectuer veille stratégique sur l'évolution des fraudes cartes
  - Se préparer à répondre aux demandes de l'audit interne à la banque
  - Pousser le CMI à se doter d'outils adaptés à la lutte contre la fraude

#### Modèle de Reason
- Est util pour analyser la sécurité globale d'un système
- N'est qu'une partie de l'analyse
- N'est souvent utilisable qu'à posteriori de l'incident
- Propriétés :
  - Chaque couche créée est opérée par des aprtenaires différents
  - Ces règles évolues en fonction de différents processus
  - Les tranches de fromages bougent séparément
  - Parfois, les trous s'alignent 

#### Evolution de la Fraude
- *Vente à distance* = 70% de la fraude notamment à cause d'internet.

