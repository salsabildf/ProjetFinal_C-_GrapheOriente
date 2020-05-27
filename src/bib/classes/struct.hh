#ifndef STRUCTS_HH
#define STRUCTS_HH

#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


/**
 * \brief Structure VectVal
 * Cette structure permet de stocker des donn&eacutes;es sur sur les Sommets et Arcs
 * */
struct VectVal {
	/**
	 * \brief Type de valeur
	 * 0 Si entier
	 * 1 si réel
	 * */
  bool type;
  int valeur_entiere;	/// Valeur de type entiere
  float valeur_reel;	/// Valeur de type r&eacute;elle


  /**
   * \brief Surcharge de l'op&eacute;rateur d'affectation
   * */
  VectVal operator=(VectVal v2){
   type = v2.type;
   valeur_entiere = v2.valeur_entiere;
   valeur_reel = v2.valeur_reel;
   return *this;
 }
};

/**
 * \brief Surchage de l'op&eacute;rateur d'&eacute;galit&eacute;
 * @return true si les deux structures VectVal sont &eacute;gales
 * @return false si les deux structures VectVal sont diff&eacute;rentes
 * */
inline bool operator== (VectVal v1, VectVal v2){
  if (v1.type == v2.type){
    if (v1.valeur_entiere == v2.valeur_entiere || v1.valeur_reel == v2.valeur_reel){
        return true;
    }
  }
  return false;
}



/**
 * \brief Structure ROW
 * Cette structure est utilis&eacute;e lors de l'impl&eacute;mentation de l'algorithme de PERT afin de g&eacute;rer les taches
 * */
typedef struct ROW{
  int tache;				/// Identifiant de la tache
  string nom_tache;			/// Etiquette de la tache
  int duree;				/// Durée de la tache
  vector <int> taches_anterieures;	/// Identifiants des taches antérieures
  vector <int> taches_posterieures; /// Identifiants des taches postérieures
} pert_row;

inline bool operator== (pert_row v1, pert_row v2){
  if (v1.tache == v2.tache && v1.nom_tache == v2.nom_tache && v1.taches_anterieures == v2.taches_anterieures
      && v1.taches_posterieures == v2.taches_posterieures){
        return true;
  }
  return false;
}

#endif
