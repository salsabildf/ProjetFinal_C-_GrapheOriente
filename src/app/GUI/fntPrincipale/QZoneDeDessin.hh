#ifndef H_QZDD
#define H_QZDD

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QMouseEvent>
#include <math.h>
#include <QDebug>
#include <QVariant>
#include "QSommet.hh"
#include "QArc.hh"
#include "../../../bib/algo/liste.hh"
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include <QMainWindow>
#include "../fntModifObjet/MODialog.hh"


class QZoneDeDessin : public QGraphicsView{
    Q_OBJECT

private:
     QGraphicsScene *sc;	/// Fournis une surface permettant de gerer un grand nombre d'objets 2D
     // QGraphicsItem itemParent;
     vector<int> selected_list;	/// Stock les Sommets selectionn&eacute;s

     /**
      * \brief Graphe dessin&eacute;
      * Stock le Graphe dessin&eacute; dans sa forme objet
      * Permet de savoir ce qui est dessin&eacute; sur chaque Zone de Dessin
      *
      * */
     Graphe graphe_dessine;

public :
    explicit QZoneDeDessin(QWidget *parent = 0);	/// Constructeur de la Zone de Dessin
    ~QZoneDeDessin();
    vector<int> getSelected_list()const;	/// Getter de selected_list
    Graphe getGraphe_dessine()const;		/// Getter de graphe_dessine
    QGraphicsScene* getScene()const;		/// Getter de sc

    void setSelected_list(vector<int> sl);	/// Setter de selected_list
    void setGraphe_dessine(Graphe g);		/// Setter de graphe_dessine
    void setScene(QGraphicsScene * scene);	/// Setter de sc

	/**
	 * \brief Force Atlas 2
	 * Algorithme de force appelé par arranger_bouton
	 * Distance les points sur le Graphe courant
	 * */
    void placementSommets();

    int distanceForce(QSommet a, QSommet b);


    /**
     * \brief Distance entre Sommets
     * Renvoie la distance entre pixel entre deux Sommets
     * Premier int : difference en x
     * Deuxieme int : difference en y
     * @param a Premier Sommet
     * @param b Deuxieme Sommet
     * */
    pair<int,int> distance(QSommet a, QSommet b);

    /**
     * \brief Ajoute l'ID d'un sommet à selected_list
     * @param ID Sommet à ajouter
     * */
    void addSelect_Sommet(int ID);

    /**
     * \brief Supprime de la selected_list l'ID du Sommet en parametre
     * @param ID Sommet à enlever de la liste
     * */
    void deleteSelect_Sommet(int ID);
    void razSelected_list();	/// Remet &agrave;  la selected_liste

    /**
     * \brief Affiche Graphe
     * Genere le Graphe C sur la QZoneDeDessin
     * Appel de afficher_sommet et afficher_arc
     * @param G Graphe à afficher
     * */
    void afficher_Graphe(Graphe G);

    /**
     * \brief Dessine Sommet
     * @param s Sommet à afficher
     * */
    void afficher_Sommet(Sommet s);

    /**
     * \brief Dessine Arc
     * @param a Arc à afficher
     * */
    void afficher_arc(Arc a);

public slots :

	/**
	 * \brief Surcharge du Double Click
	 * Surchage de la fonction s'enclenchant lors d'un clique sur QgraphicView
	 * Recupere informations pour dessiner un objet sur cette position
	 *
	 * Si l'un des boutons suivant a &eacute;t&eacute; selecionn&eacute; :
	 * addSommetButton : Dessine Sommet sur la position du curseur
	 * addArcButton : Dessin un Arc en le precedent Sommet et celui qui vient d'&ecirc;tre cliqu&eacute;
	 * selectButton : Si select sur false, ID du sommet cliqu&eacute; ajout&eacute; &agrave; la liste des ID_selected et ce dernier change de couleur
	 * selectButton : Si select sur true, ID du Sommet cliqu&eacute; supprim&eacute; de la selected_liste et reprends sa couleur originale
	 * deleteSommet : Si clic sur un Sommet, Sommet supprim&eacute; du Graphe avec tout ses arcs sortants
	 * deleteArc : Si clic sur un Arc, Arc supprim&eacute; du graphe
	 *
	 * L'affichage est mis &agrave; jour
	 *
	 * @param e Clic r&eacute;alis&eacute;
	 * */
    void mousePressEvent(QMouseEvent * e);
    /**
     * \brief Double Click
     * Cette m&eacute;thode ouvre une fen&ecirc;tre permettant de modifier l'etiquette ou la charge utile d'un Sommet
     * R&eacute;cupere la paure renvoy&eacute;e par la fen&ecirc;tre de dialogue
     * */
    void mouseDoubleClickEvent(QMouseEvent *e);

    /**
     * Dessine Sommet
     * Dessine un Sommet sur la QGraphicView en precisant les positions x et y
     * Ajoute un Sommet &agrave; la liste des Sommets du Graphe couratn
     * @param x Position en x du Sommet
     * @param y Position en y du Sommet
     * */
    void dessiner_sommet(int x, int y);

    /**
     * \brief Dessine Arc
     * Dessine un Arc sur la GGraphicView
     * Ajout un Arc &agrave; la liste des Arcs du Graphe courant
     * @param xa Position en x du Sommet sortant
     * @param ya Position en y du Sommet sortant
     * @param xb Position en x du Sommet entrant
     * @param yb Position en y du Sommet entrant
     * */
    void dessiner_arc(int xA, int yA, int xB, int yB);

};

#endif
