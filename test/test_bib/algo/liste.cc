#include <map>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/algo/liste.hh"
#include <utility>

#ifndef listeTest
#define listeTest

TEST_CASE("Calcul Bellman","[Algorithmes]"){
vector<vector<int>> tab, R_A;

pair<vector<vector<int>>, vector<int>> res_F, res_A;
Sommet S0(0);

// Création de la matrice M0
vector<int> a{0,0,0};
vector<int> b{1,0,0};
vector<int> c{1,0,0};
tab.push_back(a);
tab.push_back(b);
tab.push_back(c);

Matrice M0(3);
M0.setTab(tab);
// ---------------------
res_F = calcul_Bellman(M0, S0);

vector<int> v_a{0,INFINI,INFINI}, v1{0}, v2{0}, v3{0};
vector<vector<int>> g{v1,v2,v3};
res_A.first = g;
res_A.second = v_a;
REQUIRE(res_F == res_A);
}

TEST_CASE("Calcul Floyd-Warshall","[Algorithmes]"){
  Matrice po(3, 3, 2), pa(3, 3, 3);
  vector<vector<int>> po_m{{0,INFINI,INFINI},{1,0,INFINI},{1,INFINI,0}},
                      pa_m{{-1,-1,-1},{0,-1,-1},{0,-1,-1}};

  po.setTab(po_m);
  pa.setTab(pa_m);
  pair<Matrice, Matrice> p_a(po, pa);


  // Création de la matrice M0
  vector<vector<int>> tab;
  vector<int> a{0,0,0};
  vector<int> b{1,0,0};
  vector<int> c{1,0,0};
  tab.push_back(a);
  tab.push_back(b);
  tab.push_back(c);


  Matrice M0(3);
  M0.setTab(tab);
  // ---------------------

  pair<Matrice, Matrice> p_f (calcul_Floyd_Warshall(M0));

  REQUIRE(p_f == p_a);
}

TEST_CASE("liste floyd","[Algorithmes]"){
  // Création de la matrice parent
  Matrice pa(6, 6, 3);
  vector<vector<int>> pa_m{{0,1,2,1,1,2},
                           {0,0,2,3,3,2},
                           {0,0,0,3,3,5},
                           {0,0,0,0,4,0},
                           {0,0,0,0,0,0},
                           {0,0,0,0,0,0}};
  pa.setTab(pa_m);
  //------------
  // Création du vecteur attendu
  vector<int> v_a{0,1,3,4}, v_f;
  //------------
  v_f = liste_floyd(pa, 0, 4);
  REQUIRE(v_f == v_a);

  // Création d'une matrice PAS parent (pour tester le cas d'erreur)
  Matrice pas_pa(6,5,4);
  //------------
  // Création du vecteur d'erreur attendu
  vector<int> ERRv_a{-1};
  //------------
  v_f = liste_floyd(pas_pa, 0, 4);
  REQUIRE(v_f == ERRv_a);
}

TEST_CASE("calcul degres entrant","[Algorithmes]"){
 // Création de la matrice
 Matrice MA1(3);
 MA1.setTab({{0,1,0},
             {0,0,1},
             {1,0,0}});
//---------
  int i_f, i_a = 1;
  i_f = calcul_degres_entrant(MA1, 1);
  REQUIRE(i_f == i_a);

  // Test de l'erreur sur une matrice non adj
  Matrice ME(6,5,4);
  REQUIRE(calcul_degres_entrant(ME, 1) == -1);

}

TEST_CASE("calcul degres sortant","[Algorithmes]"){
  Sommet S(0);
  S.setVecArc({1,2});
  REQUIRE(calcul_degres_sortant(S) == S.getVecArc().size());
}

TEST_CASE("calcul degres entrant sortant","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
 //---------
 // Création du sommet
 Sommet S(0);
 S.setVecArc({0});
 pair<int, int> p_a(1,1);
 REQUIRE(calcul_degres_entrant_sortant(MA1, S) == p_a);
}

TEST_CASE("coloration","[Algorithmes]"){
  // Création du graphe
Graphe G("G");
G.ajout_Sommet(0,0,0);
G.ajout_Sommet(1,0,0);
G.ajout_Sommet(2,0,0);
G.ajout_Sommet(3,0,0);

G.ajout_Arc(0,1);
G.ajout_Arc(1,2);
G.ajout_Arc(2,3);
G.ajout_Arc(3,0);
// -------------------
vector<int> v_a{1,2,1,2};

REQUIRE(coloration_Graphe(G) == v_a);

//deuxième cas de test avec un graphe sans arcs
Graphe G0("G0");
G0.ajout_Sommet(0,0,0);
G0.ajout_Sommet(1,0,0);
G0.ajout_Sommet(2,0,0);

vector<int> v{1,1,1};

REQUIRE((coloration_Graphe(G0) == v));
}

TEST_CASE("couleur adjacence","[Algorithmes]"){
    int id = 3;
    Matrice M(4);
    vector<int> v(4);
    vector<int> tmp(2);

    M.modifTab(0, 1, 1);
    M.modifTab(1, 3, 1);
    M.modifTab(2, 1, 1);
    M.modifTab(3, 2, 1);

    v[1]=1;
    v[2]=2;

    tmp[0]=1;
    tmp[1]=2;

    pair<int, vector<int>> res = couleur_adjacente(id, v, M);

    REQUIRE(res.first==2);
    REQUIRE(res.second == tmp);


}

TEST_CASE("stables","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
 //---------
 vector<vector<int>> v_a{{0},{1},{2}};
 REQUIRE(stables_Graphe(MA1) == v_a);

  Matrice MA2(3);
  MA2.setTab({{0,0,0},
              {0,0,0},
              {0,0,0}});
 //---------
 vector<vector<int>> v{{0,1,2}};
 REQUIRE(stables_Graphe(MA2) == v);
}

TEST_CASE("cliques","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1_(3);
  MA1_.setTab({{0,1,0,},
               {0,0,1,},
               {1,0,0,}});
 //---------
 vector<vector<int>> v_a{{0,1,2}};
 REQUIRE(cliques_Graphe(MA1_) == v_a);


}

TEST_CASE("voisin sommet","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
    //---------
    vector<int> res_a{1};
  REQUIRE(voisin_sommet(MA1, 0) == res_a);
}

TEST_CASE("gestion de flots","[Algorithmes]"){
  // Création du graphe
Graphe G3("G3");
int idS0, idS1, idS2, idS3, idS4, idS5, idS6, idS7, idS8, idS9, idS10, idS11, idS12, idS13, idS14;
G3.ajout_Sommet(0,0,0);
G3.ajout_Sommet(1,0,0);
G3.ajout_Sommet(2,0,0);
G3.ajout_Sommet(3,0,0);
G3.ajout_Sommet(4,0,0);
G3.ajout_Sommet(5,0,0);
G3.ajout_Sommet(6,0,0);
G3.ajout_Sommet(7,0,0);

idS0 = G3.ajout_Arc(0,1);
idS1 = G3.ajout_Arc(0,2);
idS2 = G3.ajout_Arc(0,6);
idS3 = G3.ajout_Arc(1,2);
idS4 = G3.ajout_Arc(1,3);
idS5 = G3.ajout_Arc(1,4);
idS6 = G3.ajout_Arc(2,3);
idS7 = G3.ajout_Arc(3,4);
idS8 = G3.ajout_Arc(3,5);
idS9 = G3.ajout_Arc(3,6);
idS10 = G3.ajout_Arc(4,2);
idS11 = G3.ajout_Arc(4,5);
idS12 = G3.ajout_Arc(4,7);
idS13 = G3.ajout_Arc(5,7);
idS14 = G3.ajout_Arc(6,7);

VectVal VV0 {true, 30}, VV1 {true, 1},VV2 {true, 2},VV3 {true, 8},
        VV4 {true, 11}, VV5 {true, 13},VV6 {true, 26},VV7 {true, 9},
        VV8 {true, 8}, VV9 {true, 22}, VV10 {true, 2}, VV11 {true, 1},
        VV12 {true, 7}, VV13 {true, 7}, VV14 {true, 27};

map <string, VectVal> cu0, cu1, cu2, cu3, cu4, cu5, cu6, cu7, cu8, cu9, cu10, cu11,
                      cu12, cu13, cu14;

string flotName = "flot";
cu0.insert(make_pair(flotName, VV0));
cu1.insert(make_pair(flotName, VV1));
cu2.insert(make_pair(flotName, VV2));
cu3.insert(make_pair(flotName, VV3));
cu4.insert(make_pair(flotName, VV4));
cu5.insert(make_pair(flotName, VV5));
cu6.insert(make_pair(flotName, VV6));
cu7.insert(make_pair(flotName, VV7));
cu8.insert(make_pair(flotName, VV8));
cu9.insert(make_pair(flotName, VV9));
cu10.insert(make_pair(flotName, VV10));
cu11.insert(make_pair(flotName, VV11));
cu12.insert(make_pair(flotName, VV12));
cu13.insert(make_pair(flotName, VV13));
cu14.insert(make_pair(flotName, VV14));

vector<Arc> vArc;
vArc = G3.getListe_Arcs();

for (int banana = 0; banana < vArc.size();++banana){
    if (vArc[banana].getID() == idS0){
      vArc[banana].setCU(cu0);
    }
    if (vArc[banana].getID() == idS1){
      vArc[banana].setCU(cu1);
    }
    if (vArc[banana].getID() == idS2){
      vArc[banana].setCU(cu2);
    }
    if (vArc[banana].getID() == idS3){
      vArc[banana].setCU(cu3);
    }
    if (vArc[banana].getID() == idS4){
      vArc[banana].setCU(cu4);
    }
    if (vArc[banana].getID() == idS5){
      vArc[banana].setCU(cu5);
    }
    if (vArc[banana].getID() == idS6){
      vArc[banana].setCU(cu6);
    }
    if (vArc[banana].getID() == idS7){
      vArc[banana].setCU(cu7);
    }
    if (vArc[banana].getID() == idS8){
      vArc[banana].setCU(cu8);
    }
    if (vArc[banana].getID() == idS9){
      vArc[banana].setCU(cu9);
    }
    if (vArc[banana].getID() == idS10){
      vArc[banana].setCU(cu10);
    }
    if (vArc[banana].getID() == idS11){
      vArc[banana].setCU(cu11);
    }
    if (vArc[banana].getID() == idS12){
      vArc[banana].setCU(cu12);
    }
    if (vArc[banana].getID() == idS13){
      vArc[banana].setCU(cu13);
    }
    if (vArc[banana].getID() == idS14){
      vArc[banana].setCU(cu14);
    }
  }
  G3.setListe_Arc(vArc);

  REQUIRE(gestion_flots(G3, 0, 7) == 32);

}
TEST_CASE("calcul posterite","[Algorithmes]"){
  vector<pert_row> perts, res, per, pe;
  pert_row tache;

  tache.tache = 1;
  tache.nom_tache = "tache 1";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>(0);
  tache.taches_posterieures = vector<int>(0);
  perts.push_back(tache);
  tache.taches_posterieures = vector<int>{2};
  res.push_back(tache);

  tache.tache = 2;
  tache.nom_tache = "tache 2";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{1};
  tache.taches_posterieures = vector<int>(0);
  perts.push_back(tache);
  tache.taches_posterieures = vector<int>{3, 4};
  res.push_back(tache);

  tache.tache = 3;
  tache.nom_tache = "tache 3";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{2};
  tache.taches_posterieures = vector<int>(0);
  perts.push_back(tache);
  tache.taches_posterieures = vector<int>{4};
  res.push_back(tache);

  tache.tache = 4;
  tache.nom_tache = "tache 4";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{2, 3};
  tache.taches_posterieures = vector<int>(0);
  perts.push_back(tache);
  tache.taches_posterieures = vector<int>(0);
  res.push_back(tache);

  perts = calcul_posterite(perts);
  REQUIRE(res == perts);

  tache.tache = 1;
  tache.nom_tache = "tache 1";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{0};
  per.push_back(tache);
  REQUIRE(per == calcul_posterite(per));

  tache.tache = 1;
  tache.nom_tache = "tache 1";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>(0);
  tache.taches_posterieures = vector<int>(0);
  pe.push_back(tache);

  tache.tache = 2;
  tache.nom_tache = "tache 2";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{1, 4};
  tache.taches_posterieures = vector<int>(0);
  pe.push_back(tache);

  tache.tache = 3;
  tache.nom_tache = "tache 3";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{2};
  tache.taches_posterieures = vector<int>(0);
  pe.push_back(tache);

  tache.tache = 4;
  tache.nom_tache = "tache 4";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{3};
  tache.taches_posterieures = vector<int>(0);
  pe.push_back(tache);

  tache.tache = 5;
  tache.nom_tache = "tache 5";
  tache.duree = 5;
  tache.taches_anterieures = vector<int>{4};
  tache.taches_posterieures = vector<int>(0);
  pe.push_back(tache);

  REQUIRE(pe == calcul_posterite(pe));


}

TEST_CASE("pert","[Algorithmes]"){

    vector<pert_row> perts;
    pert_row tache;
    vector<Sommet> ListeS;
    vector<Arc> ListeA;
    map<string, VectVal> mapT;
    map<string, VectVal> mapU;
    VectVal v;
    v.type = 0;
    v.valeur_entiere = 0;

    //ajout sommet départ et fin
    mapT.insert(pair<string, VectVal> ("date au plus tot", v));
    mapT.insert(pair<string, VectVal> ("date au plus tard", v));
    v.valeur_entiere = 1;
    mapT.insert(pair<string, VectVal> ("critique", v));
    ListeS.push_back(Sommet(100, 100, "Départ", 0, mapT));

    v.valeur_entiere = 17;
    mapT["date au plus tot"] = v;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 1;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "Fin", 1, mapT));

    //Sommet 1
    tache.tache = 1;
    tache.nom_tache = "tache 1";
    tache.duree = 5;
    tache.taches_anterieures = vector<int>(0);
    tache.taches_posterieures = vector<int>{5, 6, 7, 8};
    perts.push_back(tache);
    //sommet 2
    tache.tache = 2;
    tache.nom_tache = "tache 2";
    tache.duree = 1;
    tache.taches_anterieures = vector<int>(0);
    tache.taches_posterieures = vector<int>{4};
    perts.push_back(tache);
    //sommet 3
    tache.tache = 3;
    tache.nom_tache = "tache 3";
    tache.duree = 7;
    tache.taches_anterieures = vector<int>(0);
    tache.taches_posterieures = vector<int>{7};
    perts.push_back(tache);
    //sommet 4
    tache.tache = 4;
    tache.nom_tache = "tache 4";
    tache.duree = 3;
    tache.taches_anterieures = vector<int>{2};
    tache.taches_posterieures = vector<int>{6};
    perts.push_back(tache);
    //sommet 5
    tache.tache = 5;
    tache.nom_tache = "tache 5";
    tache.duree = 5;
    tache.taches_anterieures = vector<int>{1};
    tache.taches_posterieures = vector<int>{};
    perts.push_back(tache);
    //sommet 6
    tache.tache = 6;
    tache.nom_tache = "tache 6";
    tache.duree = 3;
    tache.taches_anterieures = vector<int>{1, 4};
    tache.taches_posterieures = vector<int>{10};
    perts.push_back(tache);
    //sommet 7
    tache.tache = 7;
    tache.nom_tache = "tache 7";
    tache.duree = 4;
    tache.taches_anterieures = vector<int>{1, 3};
    tache.taches_posterieures = vector<int>{10};
    perts.push_back(tache);
    //sommet 8
    tache.tache = 8;
    tache.nom_tache = "tache 8";
    tache.duree = 4;
    tache.taches_anterieures = vector<int>{1};
    tache.taches_posterieures = vector<int>{9, 11};
    perts.push_back(tache);
    //sommet 9
    tache.tache = 9;
    tache.nom_tache = "tache 9";
    tache.duree = 3;
    tache.taches_anterieures = vector<int>{8};
    tache.taches_posterieures = vector<int>{10};
    perts.push_back(tache);
    //sommet 10
    tache.tache = 10;
    tache.nom_tache = "tache 10";
    tache.duree = 5;
    tache.taches_anterieures = vector<int>{6, 7, 9};
    tache.taches_posterieures = vector<int>{};
    perts.push_back(tache);
    //sommet 11
    tache.tache = 11;
    tache.nom_tache = "tache 11";
    tache.duree = 3;
    tache.taches_anterieures = vector<int>{8};
    tache.taches_posterieures = vector<int>{12};
    perts.push_back(tache);
    //sommet 12
    tache.tache = 12;
    tache.nom_tache = "tache 12";
    tache.duree = 2;
    tache.taches_anterieures = vector<int>{11};
    tache.taches_posterieures = vector<int>{};
    perts.push_back(tache);

    //ajout des Sommets et Arcs correspondants au graphe
    v.valeur_entiere = 5;
    mapT["date au plus tot"] = v;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 1;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 1", 2, mapT));
    v.valeur_entiere = 5;
    mapU.insert(pair<string, VectVal> ("duree",v));
    ListeA.push_back(Arc("1tache 1", 0, 0, 2, mapU));

    v.valeur_entiere = 1;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 6;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 2", 3, mapT));
    v.valeur_entiere = 1;
    mapU["duree"] = v;
    ListeA.push_back(Arc("2tache 2", 1, 0, 3, mapU));

    v.valeur_entiere = 7;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 8;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 3", 4, mapT));
    v.valeur_entiere = 7;
    mapU["duree"] = v;
    ListeA.push_back(Arc("3tache 3", 2, 0, 4, mapU));

    v.valeur_entiere = 4;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 9;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 4", 5, mapT));
    v.valeur_entiere = 3;
    mapU["duree"] = v;
    ListeA.push_back(Arc("4tache 4", 3, 3, 5, mapU));

    v.valeur_entiere = 10;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 17;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 5", 6, mapT));
    v.valeur_entiere = 5;
    mapU["duree"] = v;
    ListeA.push_back(Arc("5tache 5", 4, 2, 6, mapU));
    v.valeur_entiere = 0;
    mapU["duree"] = v;
    ListeA.push_back(Arc("fictif", 5, 6, 1, mapU));

    v.valeur_entiere = 9;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 9;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 1;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 8", 7, mapT));
    v.valeur_entiere = 4;
    mapU["duree"] = v;
    ListeA.push_back(Arc("8tache 8", 6, 2, 7, mapU));


    v.valeur_entiere = 12;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 12;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 1;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 9", 8, mapT));
    v.valeur_entiere = 3;
    mapU["duree"] = v;
    ListeA.push_back(Arc("9tache 9", 7, 7, 8, mapU));

    v.valeur_entiere = 12;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 15;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 11", 9, mapT));
    v.valeur_entiere = 3;
    mapU["duree"] = v;
    ListeA.push_back(Arc("11tache 11", 8, 7, 9, mapU));

    v.valeur_entiere = 14;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 17;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 12", 10, mapT));
    v.valeur_entiere = 2;
    mapU["duree"] = v;
    ListeA.push_back(Arc("12tache 12", 9, 9, 10, mapU));
    v.valeur_entiere = 0;
    mapU["duree"] = v;
    ListeA.push_back(Arc("fictif", 10, 10, 1, mapU));


    v.valeur_entiere = 5;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 9;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, " fin , 1, 4", 11, mapT));
    v.valeur_entiere = 8;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 12;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 6", 12, mapT));
    v.valeur_entiere = 0;
    mapU["duree"] = v;
    ListeA.push_back(Arc("fictif", 11, 2, 11, mapU));
    ListeA.push_back(Arc("fictif", 12, 5, 11, mapU));
    v.valeur_entiere = 3;
    mapU["duree"] = v;
    ListeA.push_back(Arc("6tache 6", 13, 11, 12, mapU));


    v.valeur_entiere = 11;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 12;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 0;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 7", 13, mapT));
    v.valeur_entiere = 4;
    mapU["duree"] = v;
    ListeA.push_back(Arc("7tache 7", 14, 4, 13, mapU));
    v.valeur_entiere = 0;
    mapU["duree"] = v;
    ListeA.push_back(Arc("fictif", 15, 2, 4, mapU));

    v.valeur_entiere = 17;
    mapT["date au plus tot"] = v;
    v.valeur_entiere = 17;
    mapT["date au plus tard"] = v;
    v.valeur_entiere = 1;
    mapT["critique"] = v;
    ListeS.push_back(Sommet(100, 100, "fin 10", 14, mapT));
    v.valeur_entiere = 5;
    mapU["duree"] = v;
    ListeA.push_back(Arc("10tache 10", 16, 8, 14, mapU));
    v.valeur_entiere = 0;
    mapU["duree"] = v;
    ListeA.push_back(Arc("fictif", 17, 14, 1, mapU));
    ListeA.push_back(Arc("fictif", 18, 12, 8, mapU));
    ListeA.push_back(Arc("fictif", 19, 13, 8, mapU));


    Graphe res = pert(perts);
    Graphe tmp("PERT", ListeS, ListeA, "\0");

    REQUIRE(res == tmp);

}

TEST_CASE("arbo","[Algorithmes]"){
Matrice M0(3);
M0.setTab({{0,1,1},
          {0,0,0},
          {0,0,0}});

Graphe G("Arborescence"), G_ret(M0);
G.ajout_Sommet(0,0,0);
G.ajout_Sommet(1,0,0);
G.ajout_Sommet(2,0,0);

G.ajout_Arc(0,1);
G.ajout_Arc(0,2);

REQUIRE(arborescence(G_ret).getListe_Arcs() == G.getListe_Arcs());
REQUIRE(arborescence(G_ret).getListe_Sommets() == G.getListe_Sommets());
REQUIRE(arborescence(G_ret) == G);

Matrice M1(3); // Matrice sans arbo
M1.setTab({{0,0,0},
          {1,0,0},
          {0,0,0}});
Graphe G_err(M1), Gerr_A("Arborescence");
Gerr_A.ajout_Sommet(-1,-1,-1);
REQUIRE(arborescence(G_err) == Gerr_A);
}

TEST_CASE("anti-arbo","[Algorithmes]"){
  Matrice M0(3);
  M0.setTab({{0,0,0},
             {1,0,0},
             {1,0,0}});

  Graphe G("Anti-Arborescence"), G_ret(M0);
  G.ajout_Sommet(0,0,0);
  G.ajout_Sommet(1,0,0);
  G.ajout_Sommet(2,0,0);

  G.ajout_Arc(1,0);
  G.ajout_Arc(2,0);

  REQUIRE(anti_arborescence(G_ret) == G);

  Matrice M1(3); //Matrice sans anti arbo
  M1.setTab({{0,0,0},
            {1,0,0},
            {0,0,0}});
  Graphe G_err(M1), Gerr_A("Anti-Arborescence");
  Gerr_A.ajout_Sommet(-1,-1,-1);

  //Gerr_A.setPath("ERROR"); A voir...

  REQUIRE(anti_arborescence(G_err) == Gerr_A);
}

TEST_CASE("connexite","[Algorithmes]"){
  Matrice M0bis(3); // Matrice connexe
  M0bis.setTab({{0,1,0},
                {1,0,1},
                {1,0,0}});

Matrice M1(3); // Matrice pas connexe
M1.setTab({{0,0,0},
           {1,0,0},
           {0,0,0}});

  REQUIRE(connexite(M0bis) == 1);
  REQUIRE(connexite(M1) == 0);
}

TEST_CASE("chaine eulerienne","[Algorithmes]"){
Matrice MA1(3);
MA1.setTab({{0,1,0},
            {0,0,1},
            {1,0,0}});

vector<vector<int>> v_a{{0,1,2,0}}; //{1,2,0},{2,0,1} A ajouter si on compte TOUS les cas même ceux qui sont juste des réagenemnts du premier
REQUIRE(chaine_eulerienne(MA1) == v_a);
}

TEST_CASE("chaine hamiltonienne","[Algorithmes]"){
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});

  vector<vector<int>> v_a{{0,1,2}}; // {1,2,0,1}, {2,0,1,2}
  REQUIRE(chaine_hamiltonienne(MA1) == v_a);
}

TEST_CASE("postier chinois","[Algorithmes]"){
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});

 vector<int> v_a{0,1,2,0};
 REQUIRE(postier_chinois(MA1) == v_a);
}

TEST_CASE("voyageur de commerce","[Algorithmes]"){
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});

  vector<int> v_a{0,1,2}, v_f{0,1,2};
  REQUIRE(voyageur_de_commerce(v_f, MA1) == v_a);
}



#endif
