#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/classes/Sommet.hh"
#include <map>
#include <vector>

TEST_CASE ("Test des setters", "[Sommet]"){
  map<string, VectVal> m;
  VectVal v0;
  v0.type = false;
  v0.valeur_entiere = 1;
  m.insert(pair<string, VectVal> ("poid", v0));
  vector<int> va;
  va.push_back(1);
  va.push_back(4);

  Sommet S0 (1,2,"sommet0",0,m);

    SECTION ("Set x"){
      S0.setPosX(54);
      REQUIRE (S0.getPosX() == 54);
    }
    SECTION ("Set y"){
      S0.setPosY (45);
      REQUIRE (S0.getPosY() == 45);
    }
    SECTION ("Set ID"){
      S0.setID (12);
      REQUIRE (S0.getID () == 12);
    }
    SECTION ("Set etiquette"){
      S0.setEtiq("sommet0'");
      REQUIRE (S0.getEtiq() == "sommet0'");
    }
    SECTION ("Set VecArc"){
      S0.setVecArc(va);
      REQUIRE(S0.getVecArc() == va);
    }
    SECTION ("Set SCharge_utile"){
      map<string, VectVal> m0;
      VectVal v1;
      v0.type = true;
      v0.valeur_reel = 10.1;
      m0.insert(pair<string, VectVal> ("poid", v1));

      S0.setCU (m0);
      REQUIRE (S0.getCU() == m0);
    }
}

TEST_CASE ("Test des getters", "[Sommet]"){

  map<string, VectVal> m;
  VectVal v0;
  v0.type = false;
  v0.valeur_entiere = 12;

  m.insert(pair<string, VectVal> ("plus_tot", v0));
  vector<int> va;
  va.push_back(1);
  va.push_back(4);

  Sommet S0 (23,32,"sommet0",0,m);
  S0.setVecArc(va);

    SECTION ("Get x"){
      REQUIRE (S0.getPosX() == 23);
    }
    SECTION ("Get y"){
      REQUIRE (S0.getPosY() == 32);
    }
    SECTION ("Get ID"){
      REQUIRE (S0.getID() == 0);
    }
    SECTION ("Get VecArc"){
      REQUIRE (S0.getVecArc() == va);
    }

    SECTION ("Get etiquette"){
      REQUIRE (S0.getEtiq () == "sommet0");
    }
    SECTION ("Get charge utile"){
      REQUIRE (S0.getCU () == m);
    }
}

TEST_CASE("Test des constructeur de la classe", "[Sommet]" ){

    SECTION ("Test du constructeur avec tous les arguments"){
      map<string, VectVal> cu;
      VectVal v0;
      v0.type = false;
      v0.valeur_entiere = 12;

      cu.insert(pair<string, VectVal> ("plus_tot", v0));

      Sommet S0(23,32,"sommet0",0,cu);

      REQUIRE (S0.getPosX() == 23);
      REQUIRE (S0.getPosY() == 32);
      REQUIRE (S0.getID() == 0);
      REQUIRE (S0.getEtiq () == "sommet0");
      REQUIRE (S0.getCU () == cu);
    }

    SECTION ("Test du constructeur sans map"){
      Sommet S2 (2,3,"sommet2",2);

      REQUIRE (S2.getPosX() == 2);
      REQUIRE (S2.getPosY() == 3);
      REQUIRE (S2.getID() == 2);
      REQUIRE (S2.getEtiq () == "sommet2");
    }

    SECTION ("Test du constructeur avec une etiquette et un ID"){
      Sommet S3 ("sommet3", 3);

      REQUIRE (S3.getID () == 3);
      REQUIRE (S3.getEtiq () == "sommet3");
    }

    SECTION ("Test du constructeur avec un id "){
      Sommet S4 (4);

      REQUIRE (S4.getID() == 4);

        SECTION ("Test du constructeur par copie"){
          Sommet S5 (S4);

          REQUIRE (S5.getID() == 4);
        }
    }

}

TEST_CASE ("Test du destructeur de la classe", "[Sommet]"){

}

TEST_CASE ("Test de l'opérateur =", "[Sommet]"){
  Sommet S2 (2,3,"sommet2", 2);
  Sommet S5 (4);
  vector<int> va;
  va.push_back(1);
  va.push_back(4);
  S2.setVecArc(va);

  S5 = S2;

  REQUIRE (S5.getPosX() == 2);
  REQUIRE (S5.getPosY () == 3);
  REQUIRE (S5.getEtiq() == "sommet2");
  REQUIRE (S5.getID() == 2);
  REQUIRE (S5.getVecArc() == va);
}

/*
Raison pour laquelle il y a deux parenthèse dans le REQUIRE
https://stackoverflow.com/questions/59770581/cant-use-overloaded-comparison-operator-with-catch-test
*/
TEST_CASE ("Test de l'opérateur ==", "[Sommet]"){
  map<string, VectVal> m;
  VectVal v0;
  v0.type = false;
  v0.valeur_entiere = 1;
  m.insert(pair<string, VectVal> ("poid", v0));
  vector<int> va;
  va.push_back(1);
  va.push_back(4);

  vector<int> va0;
  va.push_back(12);
  va.push_back(1);

  map<string, VectVal> m1;
  VectVal v1;
  v1.type = false;
  v1.valeur_entiere = 100;
  m1.insert(pair<string, VectVal> ("poid", v1));

  Sommet S0 (23,32,"sommet0",0,m);
  Sommet S0_0 (23,32,"sommet0",0,m);
  S0.setVecArc(va);
  S0_0.setVecArc(va);

  Sommet S1 (2,3,"sommet1",1,m1);
  S1.setVecArc(va0);
  // Faire les map

  REQUIRE ((S0 != S1));
  REQUIRE ((S0_0 == S0));

}
