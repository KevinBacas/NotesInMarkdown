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

/slide 25

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
