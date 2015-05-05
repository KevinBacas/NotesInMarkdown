# [NFC Research] Abstract
## In general
NFC stands for **Near Field Communication**. That technologie enables devices to establish **radio communication** by bringing them to a proximity of typically 10 cm. NFC is a set of short-range wireless technologies, typically requiring a distance of 10 cm or less.

NFC operates at 13.56 MHz on **ISO/IEC 18000-3** air interface and at rates ranging **from 106 kbit/s to 424 kbit/s**. NFC always involves an initiator and a target. The initiator actively generates an RF field that can power a passive target.

### ISO / IEC
NFC is standardized in **ECMA-340** and **ISO/IEC 18092**. These standards specify _the modulation schemes, coding, transfer speeds and frame format of the RF interface of NFC devices, as well as initialization schemes and conditions required for data collision-control during initialization for both passive and active NFC modes_. Furthermore, they also define the transport protocol, including protocol activation and data-exchange methods. The air interface for NFC is standardized in:
- **ISO/IEC 18092 / ECMA-340**
  - Near Field Communication Interface and Protocol-1 ([NFCIP-1](http://www.ecma-international.org/publications/standards/Ecma-340.htm))

- **ISO/IEC 21481 / ECMA-352**
  - Near Field Communication Interface and Protocol-2 ([NFCIP-2](http://www.ecma-international.org/publications/standards/Ecma-352.htm))

NFC incorporates a variety of existing standards including **ISO/IEC 14443** both **Type A** and **Type B** and **FeliCa**. NFC-enabled phones work at a basic level with existing readers. In "**card emulation mode**" an NFC device should transmit, at a minimum, a unique ID number to an existing reader. In addition, the NFC Forum has defined a common data format called **NFC Data Exchange Format (NDEF)**, which can _store and transport various kinds of items, ranging from any MIME-typed object to ultra-short RTD-documents, such as URLs_. The **NFC Forum** added the **Simple NDEF Exchange Protocol (SNEP)** to the spec that allows sending and receiving messages between two NFC-enabled devices.

### Identity and access tokens
_The NFC Forum_ promotes the potential for _NFC-enabled devices_ to act as electronic identity documents and keycards. As NFC has a short range and supports encryption, it may be more suitable than earlier, less private RFID systems. [More over there..](http://www.ecma-international.org/publications/standards/Ecma-340.htm)

## Mifare
**MIFARE** is the **NXP Semiconductors-owned** trademark of a _series of chips widely used in contactless smart cards and _proximity cards_. According to the producers, **10 billion smart card chips** and **150 million reader modules** have been sold. For the variants of MIFARE devices specivications, [check here](http://en.wikipedia.org/wiki/MIFARE#Variants).

## Sources
- [Wikipedia NFC](http://en.wikipedia.org/wiki/Near_field_communication)
- [Wikipedia MIFARE](http://en.wikipedia.org/wiki/MIFARE)
- [NXP::MIFARE - Identification and security](http://www.nxp.com/products/identification_and_security/smart_card_ics/mifare_smart_card_ics/mifare_desfire/)
