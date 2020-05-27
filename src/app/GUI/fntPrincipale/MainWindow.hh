#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QRandomGenerator>
#include <QTimer>
#include <utility>
#include "mainwindow_copy.hh"
#include "../../../bib/bib.hh"
#include "../fntOrdoCreate/OCDialog.hh"
#include "../../fichier/gestion_fichier.hh"
#include <time.h> 
/**
 * \brief Fen&ecirc;tre Principale de l'Interface Graphique
 * */
//QT BEGIN NAMESPACE
namespace Ui {
class MainWindow;
} /// Permet de renommer la Classe MainWindow faite dans UI_MainWindow
//QT END NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT
private :
  Ui::MainWindow *ui;			/// Fen&ecirc;tre de l'interface
  Graphe grapheCourant;			/// Graphe courant affiché &agrave; l'écran
  /**

   * \brief Dernier bouton enclench&eacute; par l'utilisateur

   * 0 : Aucune valeur
   * 1 : Selection
   * 2 : Ajout de Sommet
   * 3 : Ajout d'Arc
   * 4 : Suppression de Sommet
   * 5 : Suppression d'Arc
   *  */
  int dernierBoutonEnclenche;
public :
  MainWindow(QWidget *parent = nullptr );	/// Constructeur de MainWindow
  ~MainWindow();							/// Destructeur de l'objet MainWindow

  /**
   * \brief Affiche le résultat d'une fonction dans la console
   * @param nomMethode Nom de la fonction appelante
   * @param ValRetFunc Résultat renvoyé par la fonction appelante
   * @return 0 en cas de réussite
   * @return -1 en cas d'erreur
   * */
  int printConsole(string nomMethode, string valRetFunc);

  /**
   * Affichage des caractéristique de la sélection
   * Cette méthode est appelée par les fonctions de selection des Sommets
   * @return 0 en cas de réussite
   * @return -1 en cas d'erreur
   * */

  int ajouterOnglet(QString nomOnglet, Graphe G);

  /**
   * \brief Suppression Onglet
   * @param nomOnglet Onglet &agrave; fermer
   * @return L'index de l'onglet fermé en cas de réussite
   * @return -1 en cas d'échec
   * */
  int supprimerOnglet(QString nomOnglet);

public slots :
  int printCaraSelection();

  /**
   * \brief Nouvel Onglet
   * Ouvre un nouvel onglet en respectant le placement
   * L'attribut graphe_courant prends la valeur de G
   * L'attribut DernierBoutonEnclenche prends la valeur de 0
   * @param nomOnglet Nom du nouvel onglet
   * @param G Graphe déssiné dans la Zone de Dessin du nouvel onglet
   * @return L'index de l'onglet en cas de réussite
   * @return -1 en cas d'échec
   * */
  void nv_graphe_vide();		/// Ouvre un nouvel onglet avec un Graphe vide en parametre

  /**
   * \brief Ouvre un nouvel onglet avec un Graphe aléatoire en parametre
   * Ouvre une fen&ecirc;tre QInputDialog permettant de récupérer le nombre de Sommets &agrave; creer
   * Sommet créer liés aléatoirement
   * Ouvre un nouvel Onglet avec le Graphe aléatoire en parametre
   * Appelle la méthode force_Atlas2 pour éloigner les Sommets les uns des autres
   * */

void nv_graphe_aleatoire();

  /**
   * \brief Enregistrer
   * Appelle la fonction de sauvegarde sur le Graphe courant
   * Remplace le fichier si il est déj&agrave; existant
   * */
  void Enregistrer();

  /**
   * \brief Charger
   * Ouvre le gestionnaire de fichier permettant de choisir quel fichier ouvrir
   * Ouvre un nouvel onglet pour afficher le Graphe courant
   * */
  void Charger();
  /**
   * \brief Enregistrer sous
   * Change le chemin de sauvegarde du Graphe
   * Ouvre une fen&ecirc;tre QInputDialog pour r&eacute;cup&eacute;rer le nom
   * */
  void Enregistrer_sous();

  /**
   * \brief Duppliquer
   * Cr&eacute;er un nouvel onglet avec une copie du Graphe courant

   * Le nouvel onglet aura l'etiquette du Graphe courant et le Graphe en parametre
   * */
  void Dupliquer_graphe();

  /**
   * \brief Supprimer
   * Supprime le Graphe courant par Destructeur de Graphe
   * Ferme l'onglet et supprime le fichier
   * */
  void Supprimer_graphe();

  /**
   * \brief Algorithmes applicables sur les Graphes
   * Appelle les fonctions du module Operation sur les Graphes
   * Pour tout les algorithmes les résultats sont affichés dans la console ou sur la Zone de Dessin
   *
   *
   * Pour tout les algorithmes les r&eacute;sultats sont affich&eacute;s dans la console ou sur la Zone de Dessin
   *
   * */

  void Ford_Bellman();			/// Appel de calc_pcc_Bellman en lui passant en parametre deux Sommets s&eacute;l&eacute;ctionn&eacute;s
  void Floyd_Warshall();		/// Appel de calc_pcc_Floyd_Warshall

  /**
   * \brief Appel de calc_deg_sortant
   * Passe en parametre le ou les Sommets correspondant aux ID selectionnés dans QZoneDeDessin
   * Si la liste contient plusieurs ID, la fonction est appelée successivement sur chacun des Sommets
   * */
  void Degr_sortant();

  /**
   * \brief Appel de calc_deg_entrant
   * Passe en parametre le ou les Sommets correspondant aux ID selectionn&eacute;s dans QZoneDeDessin
   * Si la liste contient plusieurs ID, la fonction est appel&eacute;e successivement sur chacun des Sommets
   * */
  void Degr_entrant();
  void Degrs_entrant_et_sortant();	/// Appel de calc_deg_ent_sor

  /**
   * \brief Appel de color_graphe
   * Resultat affiché sur le Graphe courant par coloration des Sommets
   * */
  void Coloration_de_graphe();

  /**
   * \brief Appel de stables_graphe
   * Resultat affiché sur la console et le Graphe courant par coloration des Sommet formant un stable
   * */
  void Determinaison_de_stables();

  /**
   * \brief Appel de cliques_graphe
   * Resultat affiché sur la console et le Graphe courant par coloration des Sommet formant une clique
   * */
  void Determinaison_de_cliques();
  void Voisins_de_sommets();	/// Appel de voisin_sommet
  void Gestion_de_flots();		/// Appel de Edmond_Karp

  /**
   * \brief Graphe d'ordonnancement
   * Cette fonction ouvre une seconde fen&ecirc;tre permettant d'ajouter les taches
   * Un nouvel onglet est ensuite ouver avec comme Graphe courant le Graphe PERT correspondant
   * */
  void Creer_un_graphe_dordonnancement();

  /**
   * \brief Appel d'arborescence
   * Ouvre un nouvel onglet avec comme Graphe courant, l'arborescence du Graphe en parametre
   * */
  void Arborescence();

  /**
   * \brief Appel d'anti_arborescence
   * Ouvre un nouvel onglet avec comme Graphe courant, l'anti-arborescence du Graphe en parametre
   * */
  void AntiArborescence();
  void Recherche_de_la_connexite();		/// Appel de connexite
  void Trouver_chaine_eulerienne();		/// Appel d'eulerien
  void Trouver_chaine_hamiltonienne();	/// Appel de la fonction hamiltonien
  void Postier_chinois();				/// Appel de postier_chinois
  void Voyageur_de_commerce();			/// Appel de Voyageur_commerce
  void Documentation();			/// Affiche un lien renvoyant sur la documentation complete du projet
  void Github();				/// Affiche un lien renvoyant sur la page Github du projet

  /**
   * \brief Extraire Sous Graphe
   * Recupere le Graphe courant et la liste de Sommets selecionn&eacute;s
   * Ouvre un nouvel onglet avec le Graphe issue de la s&eacute;lection
   * */
  void extraireSousGraphe();
  void arrangerSommets();		/// Appel Force atlas 2 sur la zone de dessin
  void fermer_graphe();			/// Ferme l'onglet courant
  void DBEselection(bool checked);			/// Modifie dernierBoutonEnclenche et le met sur 1
  void DBEaddSommet(bool checked);			/// Modifie dernierBoutonEnclenche et le met sur 2
  void DBEaddArc(bool checked);				/// Modifie dernierBoutonEnclenche et le met sur 3
  void DBEdeleteSommet(bool checked);		/// Modifie dernierBoutonEnclenche et le met sur 4
  void DBEdeleteArc(bool checked);			/// Modifie dernierBoutonEnclenche et le met sur 5

};

#endif
