# [Java & J2E] Correction de l'annale 2014
## Question 4 :

```java
public class PassagerDAO extends AbstractionDataBaseDAO {

    public PassagerDAO(DataSource ds)
    {
        super(ds);
    }

    public Passager loadPassager(String idPassager) throws SQLException
    {
        Connection conn = null;
        try
        {
            conn = DataSource.getConnection();
            Statement statement = conn.createStatement();
            Passager p = null;
            BilletFactory bf;

            // On recherche les informations relatives au passager
            String query = "SELECT * FROM PASSAGERS WHERE ID=" + idPassager;
            ResultSet rs = statement.executeQuery(query);
            if(rs.next())
            {
                // On construit l'objet passager
                p = new Passager(rs.getString("ID"), rs.getString("NOM"), rs.getString("PRENOM"));
            }
            else
            {
                // Fermeture du Statement avant de quitter la fonction
                statement.close();
                throw new SQLException("Le passager n'existe pas !");
            }

            // On cherche la liste des billets du passager
            query = "SELECT * FROM BILLETS WHERE ID_PASSAGER=" +  idPassager;
            rs = statement.executeQuery(query);
            while(rs.next())
            {
                // On ajoute chaque billet au passager
                Billet b = bf.creerBillet(rs.getString("NO_VOL"), rs.getInt("NO_PLACE"));
                p.addBillet(b);
            }

            statement.close();
            // On retourne l'objet Passager
            return p;
        }
        catch(Exception e)
        {
            // #OnNeSaitPasAQuoiCaSert #QQ
            e.printStackTrace();
        }
        finally
        {
            closeConnection(conn);
        }
    }
}
```

## Question 5 :
La fonction loadPassager renvoie potentiellement une exception de type SQLException. Il faut alors donc la traiter soit en la mettant dans un bloc try/catch ou en ajoutant "throws SQLException" à la déclaration de le fonction appelante.

## Question 6 :
### Ligne 33

```java
String id = request.getParameter("id");
```

> On pourrait faire les tests fondamentaux consistants à savoir si l'attribut est présent et non vide.

### Ligne 36

```java
request.setAttribute("passager", p);
getServletContext().getRequestDispatcher("Billets.jsp").forward(request, response);
```

> On le sauvegarde ici car on ne veut pas le faire dans la base de données. De plus cet objet a une durée de vie très limitée. Le passage par contexte suffit donc amplement.

### Ligne 40

```java
request.setAttribute("Erreur", "Erreur, le passager n'existe pas");
getServletContext().getRequestDispatcher("accueil.jsp").forward(request, response);
```

## Question 7 :
### a)
Il faut transmettre à la fois l'identifiant du vol, la date de départ et le passager car deux vols peuvent avoir le même id.

### b)
Pour pouvoir y accéder et les manipuler plus simplement dans le code. **(Je n'ai pas compris la question alors je suis possiblement à côté de la plaque..)**

## Question 8 :

```html
<%@ taglib uri="cjstl" prefix="c" %>
<jsp:useBean id="passager" scope="request" >
<h1>Billets de ${Passager.nom} ${Passager.prenom}</h1>
<ul>
    <c:forEach var="Passager" items="${billet}">
        <li> ${billet.vol.nom}
        <li> Départ : ${billet.vol.aeroportDepart.pays} - le ${billet.vol.dateDepart}
        </li>
        <li> Arrivée : ${billet.vol.aeroportArrive.pays}
        </li>
        <!-- #Random code //-->
        <li> Durée de vol : ${billet.vol.dateArrivee - billet.vol.dateDepart}
        </li>
        <li>
            N° place :
            <c:choose>
                        <c:when test="${billet.noPlace<=0}">
                            pas encore attribué
                        </c:when>
                        <c:otherwise>
                            ${billet.noPlace}
                        </c:otherwise>
            </c:choose>
        </li>
        <button type="submit" value="Modifier" onclick="choixPlace()">Modifier</button>
    </c:forEach>
</ul>
```
