# [Architecture des système de communication] Cours sur le Réseau 4G LTE (by RT)
Norme : IETF (Internet Engineering Task Force)

## 2G:
- GSM : Global System for Mobile
- GPRS : General Packet Radio Service
- EDGE : Enheanced Data for Global Evolution

## 3G :
- UMTPS : Universal Mobile Telecommunication System
- HSDPA : High Speed Downlink Packet Access
- HSUPA : High Speed Uplink Packet Access
- HSPA+ : High Speed Packet Access+

## 4G :
EPS : Evolved Packet System

_Nouvelles techniques de modulation de fréquence_
- OFDMA
- SC-FDMA

**3 fois plus élevé que HSPA**

_Principales caractéristiques de LTE_
- Connexion IP permanente
- Partie circuit qui disparait

**Plus de communication par voix/SMS :(**

_Quels sont les techniques pour avoir des solutions ?_
- VOLTE (Voice on LTE)
- Circuit Switch Fall Back (CSFB)

LTE : Long Term Evolution

C'est un projet du **3GPP**

_Au niveau de son architecture, LTE ajoute :_
- Accès radio de type eNode B
- E-UTRAN
- Nouveau coeur de réseau ePC(evolved Packet Core)

**LTE != 4G**

## ePC/SAE :
- MME : Mobility Manegement Entity
  - Gère le plan de contrôle (signalisation).

- Serving Gateway :
  - Gère le plan de trafic (gère les antennes selon les déplacements).

- PDN-Gateway :
  - Gère le plan de trafic et la connection vers les réseaux IP (routeur)

## Téléphonie sur IP
Architecture téléphonique : On a ajouté au réseau de téléphonie analogique une Passerelle qui permet de faire le lien entre réseau IP et analogique (RTC)

_RTP : Real Time Protocol_
- Permet de limiter les effets de la perte de paquet en les résolvant

_RTControlP :_ infos du réseau

_MGCP : Media Gateway Communication Protocol_
- Media Gateway Control Protocol (MGCP) est un protocole permettant de contrôler les passerelles multimédia (Media Gateways) qui assurent la conversion de la voix et de la vidéo entre les réseaux IP et le Réseau Téléphonique Commuté (RTC).

_H.323 :_
- H.323 regroupe un ensemble de protocoles de communication de la voix, de l'image et de données sur IP. Basé sur RTC mais en plus simple. (Fin de vie car pas dans l'esprit internet il est complexe)

_SIP: Session Initiation Protocol_
- Source d'inspiration internet
- Utilise l'architecture et les protocoles IP existants
- Standardisé par l'IETF
- SIP permet de créer, modifier et terminer des sessions avec un ou plusieurs participants.
- Les sessions peuvent être vidéos, jeux, médias, etc.. Indépendant de la couche transport, contrôle de la couche application.

_Plusieurs éléments SIP :_
- User Agent (Client-UAC et Serveur-UAS ), le client émet des requetes et le
- serveur traite les requêtes entreinte
- Registrer Server, enregistre les adresses des terminaux
- Proxy Server, route les requêtes SIP
- Redirect Server, retourne à l'appelant la nouvelle adresse de l'appelé
- Back to Back User Agent (B2BUA), UAC et UAS en un.

_Protocole :_
1. Enregistrement, Demande d'appel -> SIP
2. Négociation -> Protocole SDP
- Avantage : Simple à mettre en œuvre, interopérabilité, gestion de la mobilité
- Inconvénients : Deploiement en cours, pas si simple (dizaines RFC)

_SIP-URI :_ Un SIP-URI est un système d'adressage SIP pour appeler une autre personne via SIP. En d'autres termes, un SIP-URI est le numéro de téléphone SIP d'un utilisateur. Le SI- URI ressemble à une adresse email et se présente sous le format suivant :
- SIP URI = sip:x@y:Port x=nom d'utilisateur et y=hôte (domaine ou IP)

_SDP : Session Description Protocol_ Permet de savoir quel type de médias c'est, protocole, format...
- Toutes les informations du message
- Les participants se mettent d'accord sur un même Sdp pour pouvoir communiquer (CODECS ...)
