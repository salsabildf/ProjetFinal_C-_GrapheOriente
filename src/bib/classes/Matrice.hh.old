#ifndef MATRICE_HH
#define MATRICE_HH

#include <vector>
#include "struct.hh"
#include "iostream"

class Graphe;

class Matrice {

private:
  int taille_V;		// nombre de sommets
  int taille_E;		// nombre d'arcs (dans le cas d'une matrice d'incidence)
  int type;			// type de la matrice (0->adjacence,1->incidence)
  vector<vector <int>> tab;			// matrice

public:
  Matrice(Graphe G, int type);
  Matrice(int tailleV);
  Matrice(int tailleV, int tailleE, int t);
  Matrice(Matrice &M);
  ~Matrice();
  int gettV();
  int gettE();
  int getType();
  vector<vector <int>> getTab();

  void setV(int v);
  void setE(int e);
  void setType(int type);
  void setTab(vector<vector <int>> tab);

  Matrice conversion_incidence();
  Matrice inversion_Matrice();
  Graphe conversionGraphe();
  int Sommet_non_isole();
  int modifTab(int x, int y, int n);
  void supprLigne(int x);
  void supprCol(int y);

  bool operator==(Matrice & M1);
  bool operator!=(Matrice & M1);
  Matrice operator=(Matrice & M1);

};





#endif
