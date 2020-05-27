#ifndef SOMMET_HH
#define SOMMET_HH

#include <string>
#include "struct.hh"
#include <vector>
#include <utility>
using namespace std;

/**
 * Classe Sommet
 * Cette classe repr&eacute;sente un Sommet dans un graphe orient&eacute;
 * */
class Sommet {

    private:
    int x; 					/// Coordonnées sur l'axe des abscisses
    int y; 					/// Coordonnées sur l'axe des ordonn&eacute;es

    /**
     * \brief Identifiant du Sommet
     * Les valeurs vont de  &agrave; V-1, V repr&eacute;sentant le nombre de sommets du Graphe
     * */
    int ID;
    string etiquette; 		/// Nom du Sommet
    vector <int> vecArc;	/// ID des Arcs sortant du Sommet
    map <string, VectVal> SCharge_utile;	/// Informations sur le Sommet utilis&eacute;es dans le module Op&eacute;ration sur les Graphes

    public:

    /**
     * \brief Constructeur de Sommet
     * @param posx Position du Sommet
     * @param posy Position du Sommet
     * @param etiq Etiquette du Sommet
     * @param id ID du Sommet
     * @param map Map du Sommet
     * */
    Sommet(int posx, int posy, string etiq, int id, map <string, VectVal> v);

    /**
     * \brief Constructeur de Sommet
     * @param posx Position du Sommet
     * @param posy Position du Sommet
     * @param etiq Etiquette du Sommet
     * @param id ID du Sommet
     * */
    Sommet(int posx, int posy, string etiq, int id);

    /**
     * \brief Constructeur de Sommet
     * @param etiq Etiquette du Sommet
     * @param id ID du Sommet
     * */
    Sommet(string etiq, int id);

    /**
     * \brief Constructeur de Sommet
     * L'etiquette du Sommet prends ici la valeur ID du Sommet
     * @param id ID du sommet
     * */
    Sommet(int id);

    /**
     * \brief Constructeur de Sommet
     * Constructeur par copie du Sommet
     * @param &S Objet &agrave; copier
     * */
    Sommet(Sommet const &S);

    /**
     * \brief Destructeur de l'objet Sommet
     * */
    ~Sommet();

    int getPosX();  				/// Getter de la position du Sommet sur l'axe des abscisses
    int getPosY();					/// Getter de la position du Sommet sur l'axe des ordonn&eacute;es
    int getID();					/// Getter de l'identifiant du Sommet
    string getEtiq();				/// Getter de l'etiquette du Sommet
    vector<int> getVecArc();		/// Getter des Arcs sortant du Sommet
    map <string, VectVal> getCU();	/// Getter de la map du Sommet

    void setPosX(int x);			/// Setter de la position du Sommet sur l'axe des abscisses
    void setPosY(int y);			/// Setter de la position du Sommet sur l'axe des ordonn&eacute;es
    void setID(int id);				/// Setter de l'identifiant du Sommet
    void setEtiq(string etiq);		/// Setter de l'etiquette du Sommet
    void setVecArc(vector<int> v);	/// Setter des Arcs sortant du Sommet
    void setCU(map <string, VectVal> S_CU);	/// Setter de la map du Sommet

	 /**
	   * \brief Surchage de l'op&eacute;rateur d'&eacute;galit&eacute;
	   * Cette m&eacute;thode permet de v&eacute;rifier si deux obets Sommet sont identiques
	   * @return 1 Si les deux Sommets sont identiques
	   * @return 0 Si une diff&eacute;rence est pr&eacute;sente
	   * */
    bool operator==(Sommet const& S1)const;

    /**
	   * \brief Surcharge de l'op&eacute;rateur d'in&eacute;galit&eacute;
	   * Cette m&eacute;thode permet de v&eacute;rifier si deux objets Sommet sont diff&eacute;rents
	   * @return 1 Si les deux Sommets sont diff&eacute;rentes
	   * @return 0 Si les deux Sommets sont identiques
	   * */
    bool operator!=(Sommet const& S1);

    /**
	 * \brief Surchage de l'op&eacute;rateur d'affectation
   	 * */
    Sommet operator=(Sommet const& S1);
};

#endif
