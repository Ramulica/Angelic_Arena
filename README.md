# **Angelic Arena** #
---
## Descriere ##

Acest proiect este un mini-joc RPG realizat în C++ în care un erou se luptă cu un inamic într-o bătălie pe ture. Jucătorul alege un erou (de exemplu, un Cavaler), iar jocul generează un inamic (ex: Blood Troll). Fiecare tură constă în atacuri de bază, abilități active și pasive. La finalul luptei, eroul câștigă un obiect (item), primește bonusuri și poate trece la un nivel superior.
---
## Clase și Moșteniri (Universul Jocului)

**Hero** – Luptători legendari cu abilități unice

  -Knight – Un războinic nobil cu scut și onoare, maestru în apărare și forță brută.
  
  -Assassin – Un ucigaș din umbră, agil și mortal, atacă rapid și dispare.

  -Mage – Un înțelept al magiei, stăpân pe vrăji devastatoare și trucuri arcanice.
  
**Enemy** – Ființe ostile ce bântuie lumea jocului

  -BloodTroll – O bestie sângeroasă ce se hrănește cu suferință și se regenerează prin durere.
  
  -GoblinShaman – Un spiriduș corupt de magie neagră, lansează blesteme și se teleportă.
  
  -SkeletonKnight – Un cavaler blestemat, ridicat din morminte, cu armură ruginită și sabie spartă.
  
**Item** – Obiecte magice cu puteri ce sporesc eroul

  -Weapon – Sabii, topoare sau baghete magice ce cresc puterea de atac.
  
  -BodyArmor – Armuri ce protejează trupul și măresc rezistența.
  
  -Boots – Cizme ușoare sau grele ce sporesc mobilitatea și viața.
  
  -Jeweled – Bijuterii rare care dau bonusuri subtile dar puternice la atac.

Alte clase esențiale:
Game – Gestionează bătălia, turele și progresul eroului.
ItemFactory – Forjă magică ce creează obiecte aleatorii după nivelul eroului. 
  Un item se creaza in felul acesta
    1. se alege tupul de item
    2. se alege random o raritate
    3. se alege random o valoare de damage ,health sau alta atributa, 
    4. valoare este imnultita in functie de raritatea itemului

---
## Excepții

**GameException** – Apare când o acțiune invalidă este făcută în timpul luptei.
**FileLoadException** – Se aruncă atunci când un fișier nu poate fi încărcat corect (ex: iteme).
**InvalidEnemyStatsException** – Este folosită când un inamic are statistici incorecte.
**HeroException** – Pentru orice problemă legată direct de starea sau datele unui erou.


