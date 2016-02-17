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

### La sécurité des systèmes monétiques (92+)
