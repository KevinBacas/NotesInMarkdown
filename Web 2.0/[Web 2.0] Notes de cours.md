# [Web 2.0] Notes de cours

## Les cookies
Les cookies permettent de stocker des informations chez le client. Les cookies sont renvoyés automatiquement par l'utilisateur lors des connexions futures.

### Comment les utiliser
On peut les utiliser dans différents cas :
* Identifier une personne
* Implémenter la notion de panier (*Vue en TP*)
* Personnaliser des applications
* Calculer des profils d'utilisateurs (*Google ads*)
* Calculter des statistiques sur des pages (*Google analytics*)

### En PHP
```php
<?php
  // On place un cookie nommé "seen" avec la valeur "yes"
  // Il sera détruit au bout d'une heure
  setcookie("seen", "yes", time()+3600);
?>
<html>
<head>
  <title>Hello</title>
</head>
<body>
  <h1>
  <?php
    // On test la présence du cookie
    if(isset($_COOKIE["seen"])) {
      echo "Je vous ai déja vu quelque part";
    } else {
      echo "Hello Etranger";
    }
  ?>
  </h1>
</body>
</html>
```

### En Javascript
```javascript
var seen=true;
if((document.cookie.length==0)||(document.cookie.indexOf("seen=")==-1)) {
  document.write("Hello Etranger!");
  seen=false;
}
date=new Date();
date.setTime(date.getTime() + 60*60*1000);
// On place un cookie nommé "seen" avec la valeur "yes"
// Il sera détruit au bout d'une heure
document.cookie="seen=yes; expires="+date.toGMTString()+"; path=/";
if(seen) {
  document.write("Je vous ai déjà vu quelque part..");
}
```

#### Quelques fonctions utiles
**Lecture, écriture de Cookies en Javascript**
```javascript
function createCookie(name,value,days,hours) {
  if (days||hours) {
    var date = new Date();
    date.setTime(date.getTime() + (days*24*60*60*1000) + (hours*60*60*1000));
    var expires = "; expires="+date.toGMTString();
  } else {
    var expires = "";
  }
  document.cookie = name+"="+value+expires+"; path=/";
}

function readCookie(name) {
  var nameEQ = name + "=";
  var ca = document.cookie.split(';');
  for(var i=0;i < ca.length;i++) {
    var c = ca[i];
    while (c.charAt(0) == ' '){
      c = c.substring(1, c.length);
    }
    if (c.indexOf(nameEQ) == 0){
      return c.substring(nameEQ.length, c.length);
    }
  }
  return null;
}

function eraseCookie(name) {
  createCookie(name, "", -1);
}
```

## Les sessions en PHP
### Démarrage d'une session
```php
<?php
  session_start();
?>
```

### Fin de sessions
```php
<?php
  // Initialize the session.
  // If you are using session_name("something"), don't forget it now!
  session_start();

  // Unset all of the session variables.
  $_SESSION = array();

  // If it's desired to kill the session, also delete the session cooki
  // Note: This will destroy the session, and not just the session data
  if (isset($_COOKIE[session_name()])) {
   setcookie(session_name(), '', time()-42000, '/');
 }

  // Finally, destroy the session.
  session_destroy();
?>
```

## AJAX
AJAX (*Asynchronous Javascript and Xml*) est une méthode permettant d'*interroger un serveur http à partir d'un navigateur et du language Javascript*. Son avantage est de permettre une plus grande flexibilité de l'interface par rapport au web classique.

### Exemple
```javascript
function sendRequest(url)
{
  var requeteHttp=getRequestHttp();
  if(requeteHttp==null) {
    alert("Impossible d'utiliser AJAX sur ce navigateur");
  } else {
    // Envoie d'une requèete synchrone sur l'URL passée en paramètre
    requeteHttp.open('GET', url, false);
    requeteHttp.send(null);
    if(requeteHttp.readyState == 4) {
      // Requete achevé. Résultat transmis
      if(requeteHttp.status == 200) {
        // Fin correcte de la requete
        // Affichage du message
        alert(requeteHttp.responseText);
      } else {
        alert("Error :"+requeteHttp.status+",La requete ne s'est pas correctement executée");
      }
    }
  }
  return true;
}
```

### Appel Asynchrone
```javascript
function sendRequest(url)
{
  var requeteHttp=getRequestHttp();
  if(requeteHttp==null {
    alert("Impossible d'utiliser Ajax sur ce navigateur");
  } else {
    requeteHttp.open('GET',url,true);
    requeteHttp.onreadystatechange=function (){ process_request(requeteHttp); };
    requeteHttp.send(null);
  }
  return true;
}
```

### Passage par méthode POST
```javascript
function postRequestWithParam(url, param)
{
  var requeteHttp=getRequestHttp();
  if(requeteHttp == null) {
   alert("Impossible d'utiliser Ajax sur ce navigateur");
  } else {
    requeteHttp.open('POST', url, true);
    requeteHttp.onreadystatechange=function (){ process_request(requeteHttp); };
    requeteHttp.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
    requeteHttp.send(param);
  }
  return true;
}
```

## DOM
Permet de manipuler ou explorer l'arbre d'un document XML.

### Exemple
```javascript
function recevoirListeProduits(req)
{
  if (req.readyState == 4)
  {
    if(req.status == 200)
    {
      var tab = req.responseXML.getElementsByTagName("produit");
      var select = document.getElementById("listePdt");

      // Suppression de tous les fils existants
      while(select.childNodes[0])
      {
        select.removeChild(select.childNodes[0]);
      }

      // On créer les nouvelles entrées
      var first_element = true;
      for (var i = tab.length - 1; i >= 0; i--) {
        var option = document.createElement("option");
        option.setAttribute("value",  tab[i].getElementsByTagName("ref")[0].textContent);
        var option_label = document.createTextNode(tab[i].getElementsByTagName("des")[0].textContent);

        if(first_element)
        {
          option.setAttribute("selected", true);
          envoyerRequeteProduit(tab[i].getElementsByTagName("ref")[0].textContent);
          first_element = false;
        }

        option.appendChild(option_label);
        select.appendChild(option);
      }
    }
  }
}
```

**TODO : liste des fonctions principales DOM**
