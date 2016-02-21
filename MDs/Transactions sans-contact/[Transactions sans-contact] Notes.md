# [Transactions sans-contact] Notes
## Le sans-contact
### Principe de base
* Energie + Horloge => Données
* Couplage inductif ou tétrodiffusion
* 13.56 MHz
* Communication par Data Exchange Protocol

### Caractéristiques des cartes
* Duales : Contact et sans-contact
  * Pas de contrôle PIN en sans-contact
  * Des compteurs limitent l'utilisation en mode sans-contact
* Interface sans-contact conforme à ISO 14443
  * Alimentées par induction du champs RF du lecteur
  * Communication par modulation du champs RF
  * Lecteur actif, carte passive
  * La carte réagit dès qu'elle est dans le champs du terminal

### Mifare
* Implémentation de la norme ISO/IEC 14443 type A
* Utilise Mifaire Application Directory (MAD) et Application IDentifiers (AID)
* SmartMX : Solution hautement sécurisée, plus adaptée au paiement

### Les usages
* RFID
* EPC
  * Remplaçant du code barre
  * UID par produit
* Cartes sans-contact
  * Microprocesseur + antenne Radiofréquence
  * Voltage fournis par le support radio
  * Intérêt
    * Rapidité
    * Insensible à l'oxydation des contacts
* Pay Pass (US)
  * Limitation de la pré-autorisation
    * < $30
    * Demande d'auto de $30
    * Une fois que le cumul est atteint on redemande une auto

### Chiffres en France
* CB sans contact
  * 33 millions de cartes (55.3% du parc)
* Commerçants
  * 323k (24.9% du parc)

## NFC
Initialement développé par Phillips et Sony. Cela à donné Mifare et FeliCa.

### NFC-Forum
* Développe spécifications NFC et les standards
* Promotion du NFC
* Vérifie la conformité des produits NFC

### NFCIP-1
* Initiator : Génère le champ RF et démarre la communication
* Target : Répond à l'utilisateur
* Mode actif : Chaque composant dispose de leur propre champs RF
* Mode passif : Seul l'initiateur génère un champs RF
* Gestion de l'anti-collision

* Vitesse de transmission : 106, 212 et 424 Kbps
* Communications à 13.56 MHz

### Types d'objects NFC
* Etiquettes ou cates NFC destinées à être lues
* Equipements NFC destinés à récupérer de l'information
* Le téléphone mobile est un systèmes hybride avec la spécificité de l'émulation carte

### Les applications
* Possibilité d'écrire les apps en Java GlobalPlatform
  * Même application dans la carte et le téléphone
  * Obligation de dev en plus un IHM dans le téléphone
  * Midlet de dev dans le téléphone
  * Carlet de dev dans le Secure Element

### Open-NFC
* Implémentation Open-Source pour faciliter la création d'apps NFC

### Android : API Google
* Evolution progressive
* Features :
  * Lecture tags
  * Emulation tag
  * P2P
  * Host-based Card Emulation (HCE)
    * On peut définir les AID en groupes
    * Définir les accès au HCE
    * Chanque groupe peut-être associé à une catégorie
    * Scénarios :
      * Pur applicatif avec data dans le cloud
        * Element local safe
        * Gestion du risque
      * Avec un élément sécurisé
        * Des brevets à venir
        * Une application de sécurité générique dans le SE

### SEEK (Secure Element Evaluation Kit)
* Propose une SmartCard API
* Premettre l'accès à tout tupe de SE

