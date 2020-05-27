#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/classes/Arc.hh"
#include <utility>

#ifndef arctest
#define arctest

TEST_CASE ("Test des setters", "[Arc]"){

  VectVal v {true, 10};

  std::map<string, VectVal> m;
  m.insert (pair<string, VectVal> ("v1", v));

  Arc A1 ("arc1",1, 2,3, m); //map a faire


  SECTION ("Set ID"){
    A1.setID (37);
    REQUIRE (A1.getID() == 37);
  }
  SECTION ("Set etiquette"){
    A1.setEtiq("modif");
    REQUIRE (A1.getEtiq() == "modif");
  }
  SECTION ("Set IDdepart"){
    A1.setIDDepart (7);
    REQUIRE (A1.getIDDepart() == 7);
  }
  SECTION ("Set IDarrive"){
    A1.setIDArrive (44);
    REQUIRE (A1.getIDArrive() == 44);
  }

  SECTION ("Set ACharge_Utile"){ // A faire
/*
    VectVal v2 {true, 55};
    map <string, VectVal> m2;
    m2.insert (pair <string, VectVal> ("v2",v2));
    A1.setCU (m2);
    VectVal v3 {true, 40};
    map <string, VectVal> m3 = A1.getCU();
    REQUIRE (m3==m2);
*/
  VectVal v2 {true, 55};
  map <string, VectVal> m2;
  m2.insert (pair <string, VectVal> ("v2", v2));
  A1.setCU(m2);
  REQUIRE (A1.getCU () == m2);

  }
}

TEST_CASE ("Test des getters", "[Arc]"){

  VectVal v {true, 10};
  std::map<string, VectVal> m;
  m.insert (pair<string, VectVal> ("v1", v));


  Arc A1 ("arc1",1,2,3,m); //map a faire

  SECTION ("Get ID"){
      REQUIRE (A1.getID() == 1);
  }
  SECTION ("Get etiquette"){
    REQUIRE (A1.getEtiq () == "arc1");
  }
  SECTION ("Get IDdepart"){
    REQUIRE (A1.getIDDepart() == 2);
  }
  SECTION ("Get IDarrive"){
    REQUIRE (A1.getIDArrive() == 3);
  }
  SECTION ("Get ACharge_Utile"){

    VectVal v2 {true, 55};
    map <string, VectVal> m2;
    m2.insert (pair <string, VectVal> ("v2", v2));

    REQUIRE (A1.getCU () == m);
  }

}


TEST_CASE("Test des constructeur de la classe", "[Arc]" ){

  SECTION ("Test du constructeur avec tout les arguments"){

    VectVal v {true, 10};
    std::map<string, VectVal> m;
    m.insert (pair<string, VectVal> ("v1", v));

    Arc A1 ("arc1", 1,2,3,m); // Faire la map

    REQUIRE (A1.getEtiq() == "arc1");
    REQUIRE (A1.getID() == 1);
    REQUIRE (A1.getIDDepart () == 2);
    REQUIRE (A1.getIDArrive() == 3);
    REQUIRE (A1.getCU() == m); // A faire
  }


  SECTION ("Test du constructeur sans la map"){
    Arc A2 ("arc2",2,1,4);

    REQUIRE (A2.getEtiq() == "arc2");
    REQUIRE (A2.getID() == 2);
    REQUIRE (A2.getIDDepart() == 1);
    REQUIRE (A2.getIDArrive() == 4);

      SECTION ("Test du constructeur par copie"){
        Arc A4 (A2);

        REQUIRE (A4.getEtiq() == "arc2");
        REQUIRE (A4.getID() == 2);
        REQUIRE (A4.getIDDepart() == 1);
        REQUIRE (A4.getIDArrive() == 4);
      }
  }

  SECTION ("Test du constructeur avec un ID, un id de sommet de départ et d'arrive"){
    Arc A3 (3,4,1);

    REQUIRE (A3.getID() == 3);
    REQUIRE (A3.getIDDepart() == 4);
    REQUIRE (A3.getIDArrive() == 1);
  }
}


TEST_CASE ("Test du destructeur de la classe", "[Arc]"){
  VectVal v {true, 10};
  std::map<string, VectVal> m;
  m.insert (pair<string, VectVal> ("v1", v));

  //A fair avec ce quil y a en dessous

  // Arc A1 ("arc1",1,2,3,m);
  // delete A1;

//   REQUIRE (A1.getEtiq() == nullptr);
//   REQUIRE (A1.getID() == nullptr);
//   REQUIRE (A1.getIDArrive() == nullptr);
//   REQUIRE (A1.getIDArrive() == nullptr);
//   REQUIRE (A1.getCU() == NULL);


}

TEST_CASE ("Test de l'opérateur =", "[arc]"){

  VectVal v {true, 10};
  std::map<string, VectVal> m;
  m.insert (pair<string, VectVal> ("v1", v));

  Arc A1 ("arc1", 1,2,3,m); // Faire la map
  Arc A2 ("arc2",2,1,4);
  A2 = A1;

  REQUIRE (A2.getEtiq() == "arc1");
  REQUIRE (A2.getID() == 1);
  REQUIRE (A2.getIDDepart() == 2);
  REQUIRE (A2.getIDArrive() == 3);
  REQUIRE (A2.getCU() == m);

}

TEST_CASE ("Test de l'opérateur ==", "[Arc]"){
  Arc A2 ("arc2",2,1,4);
  Arc A4 (A2);

  REQUIRE ((A2 == A4));

}

#endif
