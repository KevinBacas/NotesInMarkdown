# [Architecture des systèmes de communication] Correction de l'annale 2014

# Partie 1
## Question 1
### a)
L'attaque TCP reset consiste à interrompre les connexions TCP/IP entre tiers.

### b)
Evaluation du temps nécessaire pour une attaque "TCP reset"
- **hypothèses :**
  - Adresses et ports source et destination connus
  - Fenêtre "TCP window" à la valeur 1000
  - Longueur des segments TCP de 64 octets
  - Débit de la ligne de l'attaquant est de 10 Mbits/s
  - Un seul numéro de séquence aléatoire est vérifié
- On calcule le nombre d'essais par seconde :
  - F = 10 000 000 / (64x8) = 10 000 000 / 512 = **19 531**
- On calcule le nombre d'essais théoriques :
  - T = card(num_sequence)/"TCP window" = (2^32)/1000 = **4 294 967**
  - d'où t = T/F = **219.9 secondes** = **3.67 minutes**

## Question 2
### a)
Le principe de l'*IP spoofing* est d'envoyer des paquets IP en *utilisant une adresse IP source différente de la machine qui les émet*. Cela se traduit par *un déni de service* pour la machine et le réseau auxquels appartient l'adresse utilisée par l'attaquant.

### b)
Il existe différentes méthodes pour prévenir d'un tel type d'attaque. On peut faire un *filtrage par le routeur*. *Le routeur* va *filtrer les paquets* et *empêcher* le passage aux paquets dont l'*adresse IP source* n'appartient pas à l'*ensemble des machines qu'il couvre*.

### c)
Le principal inconvénient de cette méthode -outre le fait de *consommer beaucoup de ressources*- est que la machine qui applique le filtrage *protège localement tous les ordinateurs*, *qu'ils le désirent ou non*.

# Partie 2
## Question 1
CT (Commutateur de Transit)

## Question 2
300 à 3400 Hz

## Question 3
Oui dans le SS7

## Question 4
Chaque fonctionnalité est propre à chaque OS, il faut donc changer l'OS afin d'ajouter des services

## Question 5
BSC

## Question 6
MSC

## Question 7
BTS

## Question 8
MSIISDN

## Question 9
Vrai puisqu'il utilise le *8PSK* alors que le GPRS utilise le GMSK

## Question 10
L'UTRAN est la partie « *accès radio* » (RAN) des réseaux UMTS, communément appelés 3G (pour « 3e génération de téléphonie mobile »). Il peut transporter plusieurs types de trafics en temps réel en mode Circuit (voix) ou en mode Paquet (utilisant les protocoles IP). L'UTRAN permet la connectivité entre les UE (l’équipement de l'utilisateur : téléphone mobile ou smartphone) et le réseau central de l’opérateur. Un UTRAN peut utiliser plusieurs bandes de fréquence radio différentes. L'UTRAN comporte principalement des stations de base, qui sont appelées Node B, réparties sur l’ensemble du territoire et des contrôleurs de réseau radio (RNC).

## Question 11
- *REGISTER* : Enregistrement de son adresse IP et de son nom dans le Registrar
- *BYE* : Terminer une Session
- *OPTION* : Interoger un User Agent sur ses capacités

## Question 12
**DUNNO**

## Question 13
- *SVLTE* : Simultaneous Voice and LTE
- *CSFB* : Circuit Switched FallBack
- *Voix* : Sur internet par des OTT (Over The Top)
- *VoLTE* : Voice over LTE

## Question 14
Une topologie de réseau est *une définition de l'architecture* (physique ou logique) *d'un réseau*, définissant les *connexions entre ces postes et unehiérarchie éventuelle entre eux*.
On peut citer 2 grandes familles de topologie réseau :
- Les réseaux point à point (maillé, ...)
- Les réseaux de diffusion (bus, ...)

## Question 15
La principale caractéristique apportée par le réseau LTE/4G est de pouvoir, pour un utilisateur, *utiliser simultanément plusieurs antennes* afin d'*améliorer le débit*.
