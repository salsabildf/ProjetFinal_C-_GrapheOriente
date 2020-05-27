#ifndef MATRICE_HH
#define MATRICE_HH

#include <vector>
#include "struct.hh"
#include "iostream"

class Graphe;

/**
 * \brief Classe Matrice
 * Cette classe permet de repr&eacute;senter un Graphe orienté sous forme de Matrice.
 * */
class Matrice {

private:
  int taille_V;		/// Nombre de sommets du graphe

  /**
   * Nombre d'arcs du graphe dans le cas d'une matrice d'incidence
   * Nombre de sommets dans le cas d'une matrice d'adjacence
   * */
  int taille_E;

  /**
   * Type de la Matrice
   * 0 : Matrice d'adjacence
   * 1 : Matrice d'incidence
   * */
  int type;
  vector<vector <int>> tab;			/// Matrice

public:

  /**
   * \brief Constructeur de Matrice
   * Cr&eacute;e une Matrice issue d'un graphe existant
   * @param G Graphe existant
   * @param type Type de matrice &agrave; cr&eacute;er : adjacence, incidence, poids, parent ou quelconque
   * */
  Matrice(Graphe G, int type);

  /**
   * \brief Constructeur de Matrice
   * Cr&eacute;e une Matrice d'adjacence vide. La Matrice ne représente pas un Graphe
   * @param tailleV Nombre de sommets de la Matrice
   * */
  Matrice(int tailleV);

  /**
   * \brief Constructeur de Matrice
   * Cr&eacute;e une Matrice vide de type Autre (diff&eacute;rent d'une Matrice d'adjacence) et de taille V*E
   * @param tailleV Nombre de sommets de la Matrice
   * @param tailleE Nombre d'arcs de la Matrice
   * @param type de Matrice
   * */
  Matrice(int tailleV, int tailleE, int t);

  /**
   * \brief Constructeur de Matrice
   * Constructeur de copie de la classe Matrice
   * @param &M Matrice dont on fait la copie
   * */
  Matrice(const Matrice &M);

  ~Matrice();							/// Destructeur d'un objet Matrice
  int gettV()const;						/// Getter du nombre de sommets
  int gettE()const; 					/// Getter du nombre d'arcs
  int getType()const; 					/// Getter du type de Matrice
  vector<vector <int>> getTab()const; 	/// Getter de la Matrice


  void setV(int v);							/// Setter du nombre de sommets
  void setE(int e); 						/// Setter du nombre d'arcs
  void setType(int type);					/// Setter du type de Matrice
  void setTab(vector<vector <int>> tab);	/// Setter

  /**
   * \brief Convertit une Matrice d'adjacence en Matrice d'incidence
   * @return Matrice d'incidence
   * @return Matrice de taille 1 sur 1 avec pour valeur -1 en cas d'erreur
   * */
  Matrice conversion_incidence();

  /**
   * \brief Inversion de la Matrice
   * Cette fonction permet d'utiliser la Matrice dans le module Op&eacute;ration sur les graphes
   * @return Matrice intervertit
   * */
  Matrice inversion_Matrice() const;

  /**
   * \brief Convertit la Matrice en Graphe
   * Cette m&eacute;thode renvoie le graphe correspondant &agrave; la Matrice
   * Ne fonctionne que sur des Matrice d'incidence ou d'adjacence
   * @return Graphe correspondant
   * @return -1 en cas d'erreur
   * */
  Graphe conversionGraphe();

  /**
   * \brief Recherche de Sommet isol&eacute; dans le Graphe
   * Cette m&eacute;thode recherche si un sommet n'est reli&eacute; &agrave; aucune autre
   * @return 0 Si il existe un sommet isol&eacute;
   * @return 1 si il n'y a pas de sommet isol&eacute;
   * */
  int Sommet_non_isole();

  /**
   * \brief Modifie une case de la Matrice
   * Cette m&eacute;thode permet de modifier une case au positions prises en parametre
   * @param x
   * @param y
   * @param n Valeur attribu&eacute;e &agrave; la nouvelle case
   * @return La case modifi&eacute;e
   * @return -1 en cas d'erreur
   * */
  int modifTab(int x, int y, int n);

  /**
   * \brief Supprime une ligne de la Matrice
   * @param x Ligne &agrave; supprimer
   * @return -1 en cas d'erreur
   * */
  void supprLigne(int x);

  /**
   * \brief Supprime une colonne de la Matrice
   * @param y Colonne &agrave; supprimer
   * @return -1 en cas d'erreur
   * */
  void supprCol(int y);


  /**
   * \brief Surcharge de l'op&eacute;rateur d'&eacute;galit&eacute;
   * Cette m&eacute;thode permet de v&eacute;rifier si deux obets Matrices sont identiques
   * @return 1 Si les deux Matrices sont identiques
   * @return 0 Si une diff&eacute;rence est pr&eacute;sente
   * */
  bool operator==(Matrice const & M1)const;

  /**
   * \brief Surcharge de l'op&eacute;rateur d'in&eacute;galit&eacute;
   * Cette m&eacute;thode permet de v&eacute;rifier si deux objets Matrice sont diff&eacute;rents
   * @return 1 Si les deux Matrices sont diff&eacute;rentes
   * @return 0 Si les deux Matrices sont identiques
   * */
  bool operator!=(Matrice & M1);

  /**
   * \brief Surchage de l'op&eacute;rateur d'affectation
   * Test si l'objet Matrice en argument est &eacute;gal &agrave; l'objet Matrice renvoy&eacute;
   * */
  Matrice operator=(Matrice const & M1);

};


#endif
#ifndef GRAPHE_HH
#define GRAPHE_HH

#include "Arc.hh"
#include "Sommet.hh"

#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

/**
 * \brief Classe Graphe
 * Cette classe rep&eacute;sente un Graphe orient&eacute;
 * */
class Graphe{
private:
  string etiquette;					/// Identifiant du Graphe
  vector<Arc> liste_Arcs;			/// Ensemble des Arcs du Graphe
  vector<Sommet> liste_Sommets;		/// Ensemble des Sommets du Graphe
  string path;						/// Chemin où enregister le graphe

public:
  /**
   * \brief Constructeur de Graphe
   * @param nom Nom du Graphe
   * @param listeS Liste de sommets du Graphe
   * @param listeA Liste d'Arcs du Graphe
   * @param path Chemin du Graphe
   *
   * */
  Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path);

  /**
   * \brief Constructeur de Graphe
   * Constructeur de Graphe vide. Les vecteurs liste_Arcs et liste_Sommets sont vides, et l'attribut path est mis &agrave; NULL
   * @param nom Nom du Graphe
   * */
  Graphe(string nom);

  /**
   * \brief Constructeur de Graphe
   * Constructeur de graphe &agreve; partir d'une Matrice d'adjacence ou d'incidence.
   * @param M Matrice du Graphe
   * */
  Graphe(Matrice& M);

  /**
   * \brief Constructeur de Graphe
   * Constructeur par copie &agrave; partir d'un graphe d&eacute;j&agrave; existant
   * @param G Graphe &grave; copier
   * */
  Graphe(const Graphe& G);

  /**
   * \brief Constructeur de Graphe
   * Construit un Graphe &agrave; partir d'une liste de voisin
   * @param liste_voisin Liste de voisins du Graphe
   * */
  Graphe(vector<vector<int>> liste_voisin);

  /**
   * \brief Destructeur d'objets Graphes
   * */
  ~Graphe();

  string getEtiq() const;					/// Getter de l'identifiant du Graphe
  vector<Arc> getListe_Arcs() const;		/// Getter de la liste d'Arcs
  vector<Sommet> getListe_Sommets() const;	/// Getter de la liste de Sommets
  string getPath() const;					/// Getter du path du Graphe

  void setEtiq(string etiq);				/// Setter de l'identifiant du Graphe
  void setListe_Arc(vector<Arc> LA);		/// Setter de la liste d'Arcs
  void setListe_Sommet(vector<Sommet> LS);	/// Setter de la liste de Sommets
  void setPath(string p);					/// Setter du path du Graphe

  /**
   * \brief Convertit le Graphe en Matrice d'adjacence
   * @return Matrice d'adjacence du Graphe
   * */
  Matrice conversion_vers_Matrice_adj();

  /**
   * \brief Convertit le Graphe en Matrice d'incidence
   * @return Matrice d'incidence du Graphe
   * */
  Matrice conversion_vers_Matrice_inc();

  /**
   * \brief Convertit le Graphe en liste de voisins
   * @return Liste de voisins
   * */
  vector<vector<int>>  conversion_vers_listeDeVoisins();

  /**
   * \brief Ajout d'un Sommet
   * Cette m&eacute;thode permet d'ajouter un Sommmet dans le Graphe
   * @param id Identifiant du Sommet
   * @param posx Position du Sommet
   * @param posy Position du Sommet
   * @return 1 Si l'ajout du Sommet est r&eacute;alis&eacute;
   * @return -1 en cas d'erreur
   * */
  int ajout_Sommet(int id, int posx, int posy);

  /**
   * \brief Supprime un Sommet
   * Cette m&eacute;thode permet de supprimer un Sommet du Graphe
   * @param id Identifiant du Sommet &agrave; supprimer
   * @return 1 Si la suppression est faite
   * @return -1 en cas d'erreur
   * */
  int supprimer_Sommet(int id);

  /**
   * \brief Ajout d'Arc
   * Cette m&eacute;thode permet d'ajouter un Arc dans le Graphe
   * @param id_Sdepart Sommet de d&eacute;part de l'Arc
   * @param id_Sarrive Sommet d'arriv&eacute;e de l'Arc
   * @return 1 Si l'Arc est ajout&eacute;
   * @return -1 en cas d'erreur
   * */
  int ajout_Arc(int id_Sdepart, int id_Sarrive);

  /**
   * \brief Suppression D'Arc
   * Cette m&eacute;thode permet de supprimer une Arc dans le Graphe
   * @param id Identifiant de l'Arc &agrave; supprimer
   * @return 1 Si l'Arc est supprim&eacute;
   * @return -1 en cas d'erreur
   * */
  int supprimer_Arc(int id);

  /**
   * \brief R&eacute;cupere un vecteur de sommets
   * Cette méeacute;thode r&eacute;cupere un vecteur de sommets correspondant au vecteur d'id en parametre
   * @param id Vecteur d'id
   * */
  vector<Sommet> getVecteurSommet(vector<int> id);

  /**
   * \brief Surcharge de l'op&eacute;rateur d'&eacute;galit&eacute;
   * Cette m&eacute;thode permet de v&eacute;fifier si deux objets Graphes sont bien identiques
   * @return 1 Si les deux objets sont identiques
   * @return -1 Si les deux objets ne sont pas identiques
   * */
  bool operator==(Graphe const& G1) const;

  /**
   * \brief Surcharge de l'op&eacute;rateur d'in&eacute;galit&eacute;
   * Cette m&eacute;thode permet de v&eacute;rifier si deux objets Graphes sont diff&eacute;rents
   * @return 1 Si les deux objets sont diff&eacute;rents
   * @return -1 Si les deux objets sont diff&eacute;rents
   * */
  bool operator!=(Graphe const& G1);
  //Graphe operator=(Graphe const& G1);

  /**
   * \brief Surchage de l'op&eacute;rateur d'affectation
   * @return 1
   * @return -1 en cas d'erreur
   * */
  Graphe operator=(Graphe const& G1);

};

#endif
