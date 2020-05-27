#include <string.h>
#include "../../bib/classes/classes.hh"

#include "../../../libExt/rapidjson/document.h"

/**
 * \brief Systeme de Gestion de Fichiers
 * */

/**
 * \brief Sauvegarde
 * Sauvegarde du Graphe courant.
 * La fonctione écrit dans un fichier placé en parametre ou dans le chemin en attribut
 * L'objet sera décrit grace &agrave; la bibliotheque JSON
 * Si path n'est pas égal &agrave NULL : sauvegarde sous ou nouveau document
 * @param G Graphe &agrav; sauvegarder
 * @param path Chemin de la sauvegarde
 * @return 0 Si la sauvegarde est réussis
 * @return -1 Si il y a une erreur lors de la sauvegarde
 * */
int sauvegarde(Graphe G, std::string path="NULL");

/**
 * \brief Chargement
 * Cette fonction parse le fichier JSON qui contient un Graphe sauvegardé lors d'une précédente session puis charge le fichier
 * @param path CHemin du fichier &agrave; charger
 * @return Graphe présent dans le fichier
 * */
Graphe chargement(string path);

/**
 * \brief Verification
 * Cette fonction vérifie que le document JSON correspond &agrave; l'archétype de notre document de sauvegarde.
 * La structure Document est un objet en JSON
 * @param path Document &agrave; vérifier
 * @return true Si l'architercture est correcte
 * @return false Si l'achitecture n'est pas la bonne
 * */
bool verif_file(string path);

/**
 * \brief Suppression
 * Supprime le fichier en parametre
 * @param path Fichier &agrave; supprimer
 * @return 0 si le fichier est bien supprimé
 * @return -1 dans le cas contraire
 * */
int suppression(string path);
