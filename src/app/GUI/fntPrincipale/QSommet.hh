#ifndef H_QSOMMET
#define H_QSOMMET

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <map>
#include <vector>
#include <QPen>
#include <QPainter>
#include "../../../bib/bib.hh"

//Taille du rayon des QSommets en pixel
#define TAILLE_RAYON 10

class QSommet : public QGraphicsItem{

private:
    int id;			/// ID du Sommet à partie duquel il est construit
    int posx;		/// Position x du Sommet sur la graphicView
    int posy;		/// Position y du Sommet sur la graphicViex
    int rayon;		/// Rayon du Sommet en pixel
    QColor coul;	/// Couleur du Sommet
    bool select;	/// Permet de savoir si le Sommet est séléctionné

public:
	/**
	 * \brief Constructeur de QSommet
	 * @param Sommet à partir duquel le QSommet est construit
	 * */
    QSommet(Sommet S);

    /**
     * \brief Constructeur par copie de QSommet
     * @param &S Sommet copié
     * */
    QSommet(QSommet const &S);
    ~QSommet();		/// Destructeur d'objet QSommet

    int getID() const;		/// Getter de l'ID
    int getPosX() const;	/// Getter de posx
    int getPosY() const;	/// Getter de la posy
    int getRayon() const;	/// Getter de rayon
    QColor getCoul() const;	/// Getter de coul
    bool getSelect() const;	/// Getter de select

    void setID(int id);		/// Setter de l'ID
    void setPosX(int x);	/// Setter de posx
    void setPosY(int y);	/// Setter de posy
    void setRayon(int r);	/// Setter de rayon
    void setCoul(QColor color);		/// Setter de coul

    /**
     * \brief Setter de select
     * Modifie l'attribut select du Sommet et sa couleur si séléctionnée
     * */
    void setSelect(bool select);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    /**
     * \brief Délimitation
     * Cette méthode permet de déterminer les liites exterieures de la forme qui permettront d'interagie avec elle
     * */

    QRectF boundingRect() const;

    /**
     * \brief Dessin de Sommet
     * Cette méthode permet de dessiner le Sommet sur ZoneDeDessin
     * Sommet de sa couleur coul ou de la couleur séléctionnée
     * Sommet avec son etiquette
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
