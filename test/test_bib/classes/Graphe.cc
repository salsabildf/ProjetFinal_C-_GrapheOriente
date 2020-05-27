
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/classes/classes.hh"

// A FINIR
TEST_CASE ("Test des setters", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));

  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION ("Set etiquette"){
    G1.setEtiq("modif");
    REQUIRE(G1.getEtiq() == "modif");
  }

  SECTION("Set path"){
    G1.setPath("/home/Desktop/");
    REQUIRE(G1.getPath() == "/home/Desktop/");
  }

  SECTION("Set liste_Arcs"){
    std::vector<Arc> v;
    v.push_back(Arc(0,0,1));
    v.push_back(Arc(1,1,2));
    v.push_back(Arc(2,0,2));
    G1.setListe_Arc(v);

    REQUIRE(G1.getListe_Arcs().size() == v.size());
    if(G1.getListe_Arcs().size() == v.size()){ // Au cas où
      for(int i=0;i<v.size();i++){
        REQUIRE( v[i] == G1.getListe_Arcs()[i]);
      }
    }
  }

  SECTION("Set liste_Sommets"){
    std::vector<Sommet> v;
    v.push_back(Sommet(0));
    v.push_back(Sommet(1));
    v.push_back(Sommet(2));
    G1.setListe_Sommet(v);

    REQUIRE(G1.getListe_Sommets().size() == v.size());
    if(G1.getListe_Sommets().size() == v.size()){ // Au cas où
      for(int i=0;i<v.size();i++){
        REQUIRE(G1.getListe_Sommets()[i]==v[i]);
      }
    }
  }

}

TEST_CASE ("Test des getters", "[Graphe]"){

/* GRAPHE G1*/
vector<Sommet> listeS;
vector<Arc> listeA;
vector<int> a{1}, b{2}, c{3};
int idS;

listeS.push_back(Sommet(0));
listeS.push_back(Sommet(1));
listeS.push_back(Sommet(2));

listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));


Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION("Get etiquette"){
    REQUIRE(G1.getEtiq() == "Graphe1");
  }

  SECTION("Get liste_Arcs"){

    REQUIRE(G1.getListe_Arcs().size() == listeA.size());
    if(G1.getListe_Arcs().size() == listeA.size()){ // Au cas où
      for(int i=0;i<listeA.size();i++){
        REQUIRE(G1.getListe_Arcs()[i]==listeA[i]);
      }
    }
  }

  SECTION("Get liste_Sommets"){

    REQUIRE(G1.getListe_Sommets().size() == listeS.size());
    if(G1.getListe_Sommets().size() == listeS.size()){ // Au cas où
      for(int i=0;i<listeS.size();i++){
        idS = G1.getListe_Sommets()[i].getID();

        REQUIRE(idS==listeS[i].getID());
        if (idS == 0){
          REQUIRE(G1.getListe_Sommets()[i].getVecArc() == a);
        }
        else if (idS == 1){
          REQUIRE(G1.getListe_Sommets()[i].getVecArc() == b);
        }
        else if (idS == 2){
          REQUIRE(G1.getListe_Sommets()[i].getVecArc() == c);
        }
      }
    }
  }

  SECTION("Get path"){
    REQUIRE(G1.getPath() == "NULL");
  }
}

// A FINIR
TEST_CASE("Test des constructeur de la classe", "[Graphe]" ){

  /*GRAPHE G0*/
  vector<Sommet> listeS, listeSres;
  vector<Arc> listeA;
  Sommet A(0), B(1), C(2), D(3), E(4), F(5);

  listeS.push_back(A);
  listeS.push_back(B);
  listeS.push_back(C);
  listeS.push_back(D);
  listeS.push_back(E);
  listeS.push_back(F);
  listeA.push_back(Arc(0,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[0].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[1].getID(),listeS[3].getID()));
  listeA.push_back(Arc(4,listeS[2].getID(),listeS[3].getID()));
  listeA.push_back(Arc(5,listeS[2].getID(),listeS[5].getID()));
  listeA.push_back(Arc(6,listeS[3].getID(),listeS[4].getID()));

  A.setVecArc({1,2});
  B.setVecArc({0,3});
  C.setVecArc({4,5});
  D.setVecArc({6});
  E.setVecArc({});
  F.setVecArc({});

  listeSres.push_back(A);
  listeSres.push_back(B);
  listeSres.push_back(C);
  listeSres.push_back(D);
  listeSres.push_back(E);
  listeSres.push_back(F);

  SECTION("Test du constructeur avec tout les arguments"){
      Graphe G0("Graphe0", listeS, listeA, "NULL");
      REQUIRE(G0.getEtiq() == "Graphe0");
      REQUIRE(G0.getListe_Arcs().size() == listeA.size());
      if(G0.getListe_Arcs().size() == listeA.size()){ // Au cas où
        for(int i=0;i<listeA.size();i++){
          REQUIRE(G0.getListe_Arcs()[i]==listeA[i]);
        }
      }
      REQUIRE(G0.getListe_Sommets().size() == listeS.size());
      if(G0.getListe_Sommets().size() == listeS.size()){ // Au cas où
        for(int i=0;i<listeS.size();i++){
          REQUIRE(G0.getListe_Sommets()[i]==listeSres[i]);
        }
      }
      REQUIRE(G0.getPath() == "NULL");

  }

  SECTION("Test du constructeur vide"){
    Graphe G0 ("Graphe G0");
    REQUIRE(G0.getEtiq() == "Graphe G0");
    REQUIRE(G0.getPath() == "\0");
    REQUIRE(G0.getListe_Arcs().size() == 0);
    REQUIRE(G0.getListe_Sommets().size() == 0);
  }

  SECTION("Test du constructeur par Matrice d'Adjacence"){
      Matrice MA1(3); //Matrice Adjacence avec 3 Sommets 0 Arcs

      MA1.modifTab(0,1,1);
      MA1.modifTab(1,2,1);
      MA1.modifTab(2,0,1);

      Graphe G1(MA1);
      REQUIRE(G1.getEtiq() == "Graphe Adjacence");

      REQUIRE(G1.getListe_Sommets().size() == MA1.gettV());
      int cmp=0;
      for(int i=0;i<MA1.getTab().size();i++){
        for(int j=0;j<MA1.getTab()[i].size();j++){
          if(MA1.getTab()[i][j]==1){
            cmp++;
          }
        }
      }
      REQUIRE(G1.getListe_Arcs().size()==cmp);

      for(int i=0;i<G1.getListe_Arcs().size();i++){
        REQUIRE(MA1.getTab()[G1.getListe_Arcs()[i].getIDDepart()][G1.getListe_Arcs()[i].getIDArrive()]);
      }
    //  REQUIRE(G1.getPath() == "\0");
  }


  SECTION("Test du constructeur par copie"){
    Graphe G1("Bonjour");
    Graphe G2(G1);
    REQUIRE(G1.getEtiq()==G2.getEtiq());
    REQUIRE(G1.getListe_Arcs().size()==G2.getListe_Arcs().size());
    REQUIRE(G1.getListe_Sommets().size()==G2.getListe_Sommets().size());
    REQUIRE(G1.getPath()==G2.getPath());
    for(int i =0;i<G1.getListe_Arcs().size();i++){
      REQUIRE(G1.getListe_Arcs()[i]==G1.getListe_Arcs()[i]);

    }
    for(int i =0;i<G1.getListe_Sommets().size();i++){
      REQUIRE(G1.getListe_Sommets()[i]==G2.getListe_Sommets()[i]);
    }

  }

  SECTION("Test du constructeur par Liste de Voisin"){
     vector<vector<int>> LV(3);
     LV[0].push_back({1});
     LV[1].push_back({2});
     LV[2].push_back({0});
     Graphe G1(LV);

     REQUIRE(G1.getEtiq() == "Graphe liste_voisins");
     REQUIRE(G1.getPath() == "\0");

     REQUIRE(G1.getListe_Sommets().size()==3);
     REQUIRE(G1.getListe_Arcs().size()==3);

     REQUIRE(G1.getListe_Sommets()[0]==Sommet(0));
     REQUIRE(G1.getListe_Sommets()[1]==Sommet(1));
     REQUIRE(G1.getListe_Sommets()[2]==Sommet(2));

     REQUIRE(G1.getListe_Arcs()[0]==Arc(0, 0, 1));
     REQUIRE(G1.getListe_Arcs()[1]==Arc(1, 1, 2));
     REQUIRE(G1.getListe_Arcs()[2]==Arc(2, 2, 0));

  }

}


TEST_CASE ("Test du destructeur de la classe", "[Graphe]"){ // A FAIRE
  // à faire
}

TEST_CASE ("Test de l'opérateur =", "[Graphe]"){
     vector<Sommet> listeS;
     vector<Arc> listeA;

     listeS.push_back(Sommet(0));
     listeS.push_back(Sommet(1));
     listeS.push_back(Sommet(2));

     listeA.push_back(Arc(0, 0, 1));
     listeA.push_back(Arc(1, 1, 2));
     listeA.push_back(Arc(2, 2, 0));

     Graphe G0 ("Graphe G0", listeS, listeA, "/home/Desktop/");
     Graphe G1 (G0);

    REQUIRE(G1.getEtiq()==G0.getEtiq());
    REQUIRE(G1.getPath()==G0.getPath());

    REQUIRE(G1.getListe_Sommets().size()==G0.getListe_Sommets().size());
    REQUIRE(G1.getListe_Arcs().size()==G0.getListe_Arcs().size());

    for(int i=0; i<G1.getListe_Sommets().size(); i++){
        REQUIRE(G1.getListe_Sommets()[i]==G0.getListe_Sommets()[i]);
    }
    for(int j=0; j<G1.getListe_Arcs().size(); j++){
            REQUIRE(G1.getListe_Arcs()[j]==G0.getListe_Arcs()[j]);
        }
}

TEST_CASE ("Test de l'opérateur ==", "[Graphe]"){
    Graphe A("graphe");
    A.ajout_Sommet(0,0,0);
    A.ajout_Sommet(1,0,0);

    A.ajout_Arc(0,1);
    Graphe B(A);

    REQUIRE(A == B);

}

// A finir
TEST_CASE ("Test de conversion en matrice d'adjacence et d'incidence", "[Graphe]"){
  // GRAPHE G1
  std::vector<Sommet> listeS;
  std::vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(0,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(1,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(2,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe0", listeS, listeA, "NULL");

  SECTION("Test de conversion en Matrice d'adjacence"){
    //Matrice MA1
    Matrice MA1 (3);
    MA1.modifTab(0, 1, 1);
    MA1.modifTab(1, 2, 1);
    MA1.modifTab(2, 0, 1);

    Matrice M2(3);

    M2 = G1.conversion_vers_Matrice_adj();

    REQUIRE(M2 == MA1);
  }

  SECTION("Test de conversion en Matrice d'incidence"){
    //Matrice MI
    Matrice MI1 (3,3,1);
    MI1.modifTab(0, 0, -1);
    MI1.modifTab(0, 2, 1);
    MI1.modifTab(1, 0, 1);
    MI1.modifTab(1, 1, -1);
    MI1.modifTab(2, 1, 1);
    MI1.modifTab(2, 2, -1);



	Matrice M3(3);

    M3 = G1.conversion_vers_Matrice_inc();

    REQUIRE(M3 == MI1);
  }
}


TEST_CASE ("Test ajout de sommet", "[Graphe]"){
	std::vector<Sommet> listeS;
	std::vector<Arc> listeA;
	listeS.push_back(Sommet(0));
	listeS.push_back(Sommet(1));
	listeA.push_back(Arc(0,listeS[0].getID(),listeS[1].getID()));
	Graphe G1("Graphe1", listeS, listeA, "NULL");

	G1.ajout_Sommet(2,0,0);

	std::vector<Sommet> listeS2;
	std::vector<Arc> listeA2;
	listeS2.push_back(Sommet(0));
	listeS2.push_back(Sommet(1));
	listeS2.push_back(Sommet(2));
	listeA2.push_back(Arc(0,listeS2[0].getID(),listeS2[1].getID()));
	Graphe G2("Graphe1", listeS2, listeA2, "NULL");

	REQUIRE((G1 == G2));

}


TEST_CASE ("Test suppression de sommet", "[Graphe]"){

	std::vector<Sommet> listeS;
	std::vector<Arc> listeA;
	listeS.push_back(Sommet(0));
	listeS.push_back(Sommet(1));
	listeS.push_back(Sommet(2));
	listeA.push_back(Arc(0,listeS[0].getID(),listeS[1].getID()));
	listeA.push_back(Arc(1,listeS[1].getID(),listeS[2].getID()));
	listeA.push_back(Arc(2,listeS[2].getID(),listeS[0].getID()));
	Graphe G1("Graphe2", listeS, listeA, "NULL");

	G1.supprimer_Sommet(2);

	std::vector<Sommet> listeS2;
	std::vector<Arc> listeA2;
	listeS2.push_back(Sommet(0));
	listeS2.push_back(Sommet(1));
	listeA2.push_back(Arc(0,listeS2[0].getID(),listeS2[1].getID()));
	Graphe G2("Graphe2", listeS2, listeA2, "NULL");

	REQUIRE((G1 == G2));
}


TEST_CASE ("Test ajout d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");

}


TEST_CASE ("Test de suppression d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");
}

TEST_CASE ("Test de conversion en liste de voisin", "[Graphe]"){
  /*GRAPHE G0*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeS.push_back(Sommet(3));
  listeS.push_back(Sommet(4));
  listeS.push_back(Sommet(5));

  listeA.push_back(Arc(0,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[0].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[1].getID(),listeS[3].getID()));
  listeA.push_back(Arc(4,listeS[2].getID(),listeS[3].getID()));
  listeA.push_back(Arc(5,listeS[2].getID(),listeS[5].getID()));
  listeA.push_back(Arc(6,listeS[3].getID(),listeS[4].getID()));
  Graphe G0("Graphe0", listeS, listeA, "NULL");
  vector<vector<int>> result = G0.conversion_vers_listeDeVoisins();

  REQUIRE(result.size() == 6);
  REQUIRE(result[0].size() == 2);
  REQUIRE(result[1].size() == 2);
  REQUIRE(result[2].size() == 2);
  REQUIRE(result[3].size() == 1);
  REQUIRE(result[4].size() == 0);
  REQUIRE(result[5].size() == 0);

  REQUIRE(result[0][0] == 1);
  REQUIRE(result[0][1] == 2);
  REQUIRE(result[1][0] == 2);
  REQUIRE(result[1][1] == 3);
  REQUIRE(result[2][0] == 3);
  REQUIRE(result[2][1] == 5);
  REQUIRE(result[3][0] == 4);

}
