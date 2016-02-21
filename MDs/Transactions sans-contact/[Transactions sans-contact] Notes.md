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
