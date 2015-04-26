# [Java & J2E] Notes de cours

## RMI (Remote Method Invocation)
Les RMI vont permettre de distribuer une application sur plusieurs machines. Une application pourra alors faire appel à des méthodes sur des objets localisés sur des machines distantes. RMI se charge de faire transiter les paramètres et la valeur de retour.

### RMI côté serveur
On va définir une interface déclarant les méthodes distantes exposées
```java
import java.rmi.* ;
public interface Hello extends Remote {
  public String envoieHello () throws RemoteException;
}
```

On va ensuite définir une classe implémentant cette interface
```java
import java.rmi.server.* ;
import java.rmi.* ;
import java.net.* ;

public class serHello extends UnicastRemoteObject implements Hello {
  public serHello () throws RemoteException {
    super();
  }

  public String envoieHello () throws RemoteException {
    return "Hello World";
  }

  public static void main (String args []) {
    System.setSecurityManager(new RMISecurityManager());
    try {
      serHello h = new serHello ();
      Naming.rebind ("bonjour", h);
      System.out.println ("Serveur pret") ;
    } catch (RemoteException e) {
      System.err.println ("RemoteException "+e);
    } catch (MalformedURLException e) {
      System.err.println ("Malformed "+e);
    }
  }
}
```

Le fichier java.policy permet de définir les restrictions d'accès à l'application.
**Un exemple de java.policy :**
```
grant {
 permission java.net.SocketPermission "*:1024-65535", "accept, listen, connect, resolve";
} ;
```

### RMI côté client
Le programme client doit rechercher et rapatrier l'interface distante. Les méthodes distantes pourrons alors être exécutées.

```java
import java.rmi.* ;

public class cliHello {
  public static void main (String args []) {
    System.setSecurityManager(new RMISecurityManager());
    try {
      Hello h = (Hello) Naming.lookup ("rmi://e450c.ecole.ensicaen.fr/bonjour");
      String message = h.envoieHello();
      System.out.println("recu : " + message);
    } catch (Exception e) {
      System.err.println("Exception : " + e);
    }
  }
}
```

## JavaBeans
Cela permet d'appliquer une programmation par composant. Son implémentation se base sur le principe de la boîte noire. On exporte simplement les interfaces requises. Les composants sont interconnectables et autodescriptif.

Il y a 3 types de beans :
* Bean Visuel
  * Boutons, icônes, ..
* Bean non visuel
  * Accès à une base de données, ..
* Bean composite
  * Grapheur, feuille de calcul, ...

*La communication entre beans repose sur le modèle événement/action*

### Exemple de bean
```java
import java.awt.*;
import java.io.*;
import java.beans.*;

public class CounterBean extends Canvas implements Serializable {
  protected boolean stopped;
  protected int value;

  public CounterBean() {
    stopped = true;
    setSize(60,40);
    setBackground(Color.white);
  }

  public int value() {
    return value;
  }

  public void reset() {
    value = 0;
  }

  public void start() {
    stopped = false;
  }

  public void stop() {
    stopped = true;
  }

  public void step() {
    if (stopped == false) {
      value++;
      repaint();
    }
  }

  public void paint(Graphics g) {
    FontMetrics fm;
    Dimension dim;
    int strWidth, strAscent, centerBoxX, centerBoxY;
    String str = Integer.toString(value);
    dim = getSize(); fm = g.getFontMetrics();
    strWidth = fm.stringWidth(str); strAscent = fm.getAscent();
    centerBoxX = dim.width/2 - strWidth/2;
    centerBoxY = dim.height/2 + strAscent/2;
    g.drawString(str, centerBoxX, centerBoxY);
  }
}
```

On place alors les beans dans des archives .jar ou .zip avec un fichier MANIFEST.MF.

**Exemple pour CounterBean**
```
Manifest-Version: 1.0
Name: counterbean/CounterBean.class
Java-Bean: True
```

On execute ensuite la commande d'archivage :
```
jar cvfm Counter.jar CounterBean.mf counterbean/*.class
```
