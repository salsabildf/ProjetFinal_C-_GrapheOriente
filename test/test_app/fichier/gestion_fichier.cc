#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/app/fichier/gestion_fichier.hh"
#include "../../../src/bib/classes/struct.hh"

#ifndef test_fichier
#define test_fichier


// Le test de la suppression est effectué avant les autres afin de supprimer les présedents essais.
TEST_CASE ("Test de la suppression", "[]"){
  // Il doit y avoir le fichier G0.json dans le repertoire fichierJSON pour que le test passe
  REQUIRE (suppression("../fichierJSON/G0.json") == 0);
  REQUIRE (suppression("../fichierJSON/G0modif.json") == 0);

}


TEST_CASE ("Test de la sauvegarde", "[]"){

  map<string, VectVal> m0;
  VectVal v1,v2;
  v1.type = true;
  v1.valeur_reel = 10.1;

  v2.type = false;
  v2.valeur_entiere = 144;
  m0.insert(pair<string, VectVal> ("poid1", v1));
  m0.insert(pair<string, VectVal> ("poid2", v2));



  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0,0,"sommet0", 0, m0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));

  listeA.push_back(Arc("Arc1",1,listeS[0].getID(),listeS[1].getID(), m0));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  listeA.push_back(Arc(4,listeS[0].getID(),listeS[2].getID()));

  SECTION ("Test de la sauvegarde normale"){
    Graphe G0 ("graphe0", listeS, listeA, "../fichierJSON/G0.json");
    REQUIRE (sauvegarde(G0,"") == 0);
    REQUIRE (G0.getPath() == "../fichierJSON/G0.json");
  }


  SECTION ("Test de la sauvegarde avancé"){
    Graphe G0 ("graphe0", listeS, listeA, "../fichierJSON/G0.json");
    REQUIRE (sauvegarde(G0,"../fichierJSON/G0modif.json") == 0);
  }


  vector <Sommet> S;
  vector <Arc> A;

  Graphe G3 ("graphetest", S,A,"../fichierJSON/gtest.json");
  sauvegarde (G3,"");


}


TEST_CASE ("Test du chargement", "[]"){

  map<string, VectVal> m0,m1;
  VectVal v1,v2,v3,v4;
  v1.type = true;
  v1.valeur_reel = 10.1;

  v2.type = false;
  v2.valeur_entiere = 144;

  v3.type = true;
  v3.valeur_reel = 17.32;

  v4.type = true;
  v4.valeur_reel = 4566.222;

  m0.insert(pair<string, VectVal> ("poid1", v1));
  m0.insert(pair<string, VectVal> ("poid2", v2));

  m1.insert(pair<string, VectVal> ("poid3", v3));
  m1.insert(pair<string, VectVal> ("poid4", v4));



  vector<Sommet> listeS;
  vector<Arc> listeA;

  listeS.push_back(Sommet(20,15, "sommet0", 0, m0));
  listeS.push_back(Sommet(66,55, "sommet1",1, m1));
  listeS.push_back(Sommet(21, 1, "sommet2",2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  listeA.push_back(Arc(4,listeS[0].getID(),listeS[2].getID()));

  Graphe G0 ("graphe0", listeS, listeA, "../fichierJSON/G1.json");
  sauvegarde (G0,"");

  Graphe G2 ("0");
  G2 = chargement("../fichierJSON/G1.json");

  REQUIRE (G0.getEtiq() == G2.getEtiq());
  REQUIRE (G0.getListe_Arcs() == G2.getListe_Arcs());
  REQUIRE (G0.getPath() == G2.getPath());



}



TEST_CASE ("Test de la verification de fichier", "[]"){

   REQUIRE (verif_file ("../fichierJSON/Gtest.json") == true);
   REQUIRE (verif_file ("../fichierJSON/G1.json") == true);
   REQUIRE (verif_file ("../fichierJSON/G0.json") == true);

}



#endif
