#ifndef GRAPHE_HH
#define GRAPHE_HH


#include "Arc.hh"
#include "Sommet.hh"

#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

class Matrice;

class Graphe{
private:
  string etiquette;
  vector<Arc> liste_Arcs;
  vector<Sommet> liste_Sommets;
  string path;

public:
  Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path);
  Graphe(string nom);
  Graphe(Matrice& M);
  Graphe(Graphe& G);
  Graphe(vector<vector<int>> liste_voisin);
  ~Graphe();

  string getEtiq();
  vector<Arc> getListe_Arcs();
  vector<Sommet> getListe_Sommets();
  string getPath();

  void setEtiq(string etiq);
  void setListe_Arc(vector<Arc> LA);
  void setListe_Sommet(vector<Sommet> LS);
  void setPath(string p);

  Matrice conversion_vers_Matrice_adj();
  Matrice conversion_vers_Matrice_inc();
  vector<vector<int>>  conversion_vers_listeDeVoisins();
  int ajout_Sommet(int id, int posx, int posy);
  int supprimer_Sommet(int id);
  int ajout_Arc(int id_Sdepart, int id_Sarrive);
  int supprimer_Arc(int id);
  vector<Sommet> getVecteurSommet(vector<int> id);

  bool operator==(Graphe const& G1);
  bool operator!=(Graphe const& G1);
  //Graphe operator=(Graphe const& G1);
  void operator=(Graphe const& G1);

};

#endif
