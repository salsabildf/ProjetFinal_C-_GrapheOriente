#ifndef H_QARC
#define H_QARC

#include <QGraphicsItem>
#include <QDebug>
#include <QList>
#include <QGraphicsLineItem>
#include <QtMath>
#include "QSommet.hh"
#include "../../../bib/bib.hh"

class QArc : public QGraphicsItem{

private:
    int id;		/// ID de l'Arc &agrave; partie duquel il et construit
    int posxA;	/// Position x du Sommet duquel sort l'Arc
    int posyA;	/// Position y du Sommet duquel sort l'Arc
    int posxB;	/// Position x du Sommet duquel rentre l'Arc
    int posyB;	/// Position y du Sommet duquel rentre l'Arc

public:

	/**
	 * \brief Constructeur de QArc
	 * @param A Arc &agrave; partir duquel le QArc est construit
	 * */
    QArc (Arc A);

    /**
     * \brief Constructeur par copie de QArc
     * @param A Arc &agrave; copier
     * */
    QArc (QArc const &A);
    ~QArc();	/// Destructeur d'objet QArc

    int getID() const;		/// Getter de ID
    int getPosXA() const;	/// Getter de posxA
    int getPosYA() const;	/// Getter de posyA
    int getPosXB() const;	/// Getter de posxB
    int getPosYB() const;	/// Getter de posyB

    void setID(int id);		/// Setter de ID
    void setPosXA(int x);	/// Setter de posxA
    void setPosYA(int y);	/// Setter de posyA
    void setPosXB(int x);	/// Setter de posxB
    void setPosYB(int y);	/// Setter de posyB

	/**
     * \brief Double Click
     * Cette méthode ouvre une fenètre permettant de modifier l'etiquette ou la charge utile d'un Arc
     * Récupere la paure renvoyée par la fen&ecirc;tre de dialogue
     * */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    /**
     * \brief Délimitation
     * Cette méthode permet de déterminer les liites exterieures de la forme qui permettront d'interagie avec elle
     * */
    QRectF boundingRect() const;
    QPainterPath shape() const;
    /**
     * \brief Dessin d'Arc
     * Cette méthode permet de dessiner l'Arc sur ZoneDeDessin
     * Arc de sa couleur coul ou de la couleur séléctionnée
     * Arc avec son etiquette
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
