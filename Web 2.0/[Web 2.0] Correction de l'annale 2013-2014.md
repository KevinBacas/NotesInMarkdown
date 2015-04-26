# [Web 2.0] Correction de l'annale 2013-2014

## Question 1

**getProduits.php**
```php
<?php

if(isset($_GET['ca_id']) && !empty($_GET['ca_id']))
{
  $id = $_GET['ca_di'];
  // Connexion à la base de données
  $conn = connexion();
  $query = "SELECT * FROM PRODUIT WHERE ca_id=$id";
  // Execution de la requète
  $res = pg_query($conn, $query);
  // On ferme la connexion à la base de données
  pg_close($conn);

  // Construction du XML
  $xml = "<?xml version='1.0' encoding='ISO-8859-1' ?>";
  $xml .= "<catalogue>";
  while($line = pg_fetch_array($res))
  {
    $xml .= "<produit>";
    $xml .= "<ref>";
    $xml .= $line["pr_id"];
    $xml .= "</ref>";
    $xml .= "<des>";
    $xml .= $line["pr_nom"];
    $xml .= "</des>";
    $xml .= "</produit>";
  }
  $xml .= "</catalogue>";
  // On libère les ressoruces de la requète
  pg_free_result($res);
  // On écrit le XML
  echo $xml;
}
else
{
  die("QQ : Le paramètre n'est pas valide.");
}

?>
```

## Question 2

**getInfo.php**
```php
<?php

if(isset($_GET['pr_id']) && !empty($_GET['pr_id']))
{
  $id = $_GET['pr_id'];
  // Connexion à la base de données
  $conn = connexion();
  $query = "SELECT pr_prix FROM PRODUIT WHERE pr_id=$id";
  // Execution de la requète
  $res = pg_query($conn, $query);
  // On ferme la connexion à la base de données
  pg_close($conn);

  if(pg_num_rows($res) == 1)
  {
    $produit = pg_fetch_array($res);
    echo $produit["pr_prix"];
  }
  else
  {
    die("QQ : Le produit n'existe pas.");
  }
  // On libère les ressoruces de la requète
  pg_free_result($res);
}
else
{
  die("QQ : Le paramètre n'est pas valide.");
}

?>
```

## Question 3

### a)
**envoyerRequeteListeProduits.js**
```javascript
function envoyerListeProduits(idCateg)
{
  var requeteHttp = getRequestHttp();
  if(requeteHttp == null)
  {
    alert("Impossible d'utiliser Ajax sur ce navigateur");
  }
  else
  {
    var url = "./getProduits.php?ca_id=" + idCateg;
    requeteHttp.open('GET', url, true);
    requeteHttp.onreadystatechange = function(){ recevoirListeProduits(requeteHttp); }
    requeteHttp.send(null);
  }
}
```

### b)
**recevoirListeProduits.js**
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
        option.setAttribute("value",  tab[i].getNamedItem("ref").value);
        var option_label = document.createTextNode(tab[i].getNamedItem("des").value);

        if(first_element)
        {
          option.setAttribute("selected", true);
          envoyerRequeteProduit(tab[i].getNamedItem("ref").value);
          first_element = false;
        }

        option.appendChild(option_label);
        select.appendChild(option);
      }
    }
  }
}
```

## Question 4

### a)
**envoyerRequeteProduit.js**
```javascript
function envoyerRequeteProduit(idPdt)
{
  var requeteHttp = getRequestHttp();
  if(requeteHttp == null)
  {
    alert("Impossible d'utiliser Ajax sur ce navigateur");
  }
  else
  {
    var url = "./getInfo.php?pr_id=" + idCateg;
    requeteHttp.open('GET', url, true);
    requeteHttp.onreadystatechange = function(){ recevoirInfoProduit(requeteHttp); }
    requeteHttp.send(null);
  }
}
```

### b)
**recevoirInfoProduit.js**
```javascript
function recevoirListeProduits(req)
{
  if (req.readyState == 4)
  {
    if(req.status == 200)
    {
      var prix = req.responseText;
      var span = document.getElementById("prix");
      span.innerHTML = prix;
    }
  }
}
```
