#ifndef ARC_HH
#define ARC_HH

#include "struct.hh"


/**
 * \brief Classe Arc
 * Cette classe repr&eacute;sente un Arc dans un graphe orient&eacute;
 * Un Arc n'est empruntable que dans un sens et relie deux Sommet
 * */
class Arc {

    private:
			/**
			 * \brief Identifiant de l'Arc
			 * Les identifiants vont de 0 &agrave; E-1
			 * */
			int ID;

			/**
			 * \brief Nom de l'Arc
			 * Valeur par défaut &eacute;gale &agrave; ID de l'Arc
			 * */
			string etiquette;
			int IDdepart;	/// Sommet de d&eacute;part de l'Arc
			int IDarrive;	/// Sommet d'ariv&eacute; de l'Arc

			/**
			 * \brief Relation entre un string et entier ou r&eacute;el
			 * Le string correspond au nom de la charge &agrave; stocker
			 * L'entier correspond &agrave; la valeur de la charge utile
			 * */
			map <string, VectVal> ACharge_Utile;

		public:

			/**
			 * \brief Constructeur d'Arc
			 * @param etiq Nom de l'Arc
			 * @param id ID de l'Arc
			 * @param SDepart Sommet de d&eacute;part de l'Arc
			 * @param SArrive Sommet d'arriv&eacute; de l'Arc
			 * @param map Informations sur l'Arc
			 * */
			Arc(string etiq, int id, int SDepart, int SArrive, map <string, VectVal>);

			/**
			 * \brief Constructeur d'Arc
			 * Ce constructeur cr&eacute;er un Arc sans map, la valeur par défaut sera donc vide
			 * Permet de cr&eacute; des Arcs sans poids ou flot maximal
			 * @param etique Nom de l'Arc
			 * @param id ID de l'Arc
			 * @param SDepart Sommet de d&eacute;part de l'Arc
			 * @param SArrive Sommet d'arriv&eacute; de l'Arc
			 * */
			Arc(string etiq, int id, int SDepart, int SArrive);

			/**
			 * \brief Constructeur d'Arc
			 * La valeur d'&eacute;tiquette est &eacute;gal &agrave l'ID de l'Arc
			 * @param id ID de l'Arc
			 * @param SDepart Sommet de d&eacute;part de l'Arc
			 * @param SArrive Sommet d'arriv&eacute; de l'Arc
			 * */
			Arc(int id, int SDepart, int SArrive);

			/**
			 * \brief Constructeur d'Arc
			 * Constructeur par copie d'Arc
			 * @param &a Arc &agrave; copier
			 * */
			Arc(Arc const&a);

			/**
			 * \brief Destructeur d'objet Arc
			 * */
			~Arc();

			int getID() const;						/// Getter de l'ID de l'Arc
			string getEtiq() const;					/// Getter de l'&eacute;tiquette de l'Arc
			int getIDDepart() const;				/// Getter de l'ID de sommet de d&eacute;part de l'Arc
			int getIDArrive() const;				/// Getter de l'ID du sommet d'arriv&eacute;e de l'Arc
			map <string, VectVal> getCU() const;	/// Getter de la map de l'Arc

			void setID(int id);						/// Setter de l'ID de l'Arc
			void setEtiq(string etiq);				/// Setter de l'&eacute;tiquette de l'Arc
			void setIDDepart(int id);				/// Setter de l'ID de sommet de d&eacute;part de l'Arc
			void setIDArrive(int id);				/// Setter de l'ID du sommet d'arriv&eacute;e de l'Arc
			void setCU(map <string, VectVal> CU);	/// Setter de la map de l'Arc

	  /**
	   * \brief Surchage de l'op&eacute;rateur d'&eacute;galit&eacute;
	   * Cette m&eacute;thode permet de v&eacute;rifier si deux obets Arc sont identiques
	   * @return 1 Si les deux Arcs sont identiques
	   * @return 0 Si une diff&eacute;rence est pr&eacute;sente
	   * */
      bool operator==(Arc const&A) const;

      /**
	   * \brief Surcharge de l'op&eacute;rateur d'in&eacute;galit&eacute;
	   * Cette m&eacute;thode permet de v&eacute;rifier si deux objets Arc sont diff&eacute;rents
	   * @return 1 Si les deux Arcs sont diff&eacute;rentes
	   * @return 0 Si les deux Arcs sont identiques
	   * */
      bool operator!=(Arc const&A);

       /**
		* \brief Surchage de l'op&eacute;rateur d'affectation
		* */
      Arc operator=(Arc const&A1);

};

#endif
