#include "QSommet.hh"
#include <QDebug>

QSommet::QSommet(Sommet S){
  this->id = S.getID();
  this->posx = S.getPosX();
  this->posy = S.getPosY();
  this->rayon = TAILLE_RAYON;
  this->coul = QColor(0,0,0); // On le met en noir
  this->select = 0;
  setData(0, "Sommet");
  setFlag(QGraphicsItem::ItemIsMovable, 1);
  setFlag(QGraphicsItem::QGraphicsItem::ItemIsSelectable, 1);
}

QSommet::QSommet(QSommet const &S){
  this->id = S.id;
  this->posx = S.posx;
  this->posy = S.posy;
  this->rayon = S.rayon;
  this->coul = S.coul; // On le met en noir
  this->select = S.select;
  setData(0, "Sommet");
  setFlag(QGraphicsItem::ItemIsMovable, 1);
  setFlag(QGraphicsItem::QGraphicsItem::ItemIsSelectable, 1);
}

QSommet::~QSommet(){}

int QSommet::getID() const{return this->id;}
int QSommet::getPosX() const{return this->posx;}
int QSommet::getPosY() const{return this->posy;}
int QSommet::getRayon() const{return this->rayon;}
QColor QSommet::getCoul() const{return this->coul;}
bool QSommet::getSelect() const{return this->select;}

void QSommet::setID(int id){this->id = id;}
void QSommet::setPosX(int x){this->posx = x;}
void QSommet::setPosY(int y){this->posy = y;}
void QSommet::setRayon(int r){this->rayon = r;}
void QSommet::setCoul(QColor color){this->coul = color;}
void QSommet::setSelect(bool select){this->select = select;}

QRectF QSommet::boundingRect() const{
  qreal penWidth = 1;
  return QRectF(-TAILLE_RAYON - penWidth / 2, -TAILLE_RAYON - penWidth / 2, TAILLE_RAYON*2 + penWidth, TAILLE_RAYON*2 + penWidth);
}

void QSommet::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

  this->setPos(mapToScene(event->pos()));
}

void QSommet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  if(select == 0){
    QRectF rect = boundingRect();
    QPen pen(coul, 3);
    QBrush myBrush(coul,Qt::SolidPattern);
    painter->setBrush(myBrush);
    painter->drawEllipse(rect);
  }
  else{
    QRectF rect = boundingRect();
    // QPen pen(Qt::red, 3 );
    // painter->setPen(pen);
    QBrush myBrush(Qt::red,Qt::SolidPattern);
    painter->setBrush(myBrush);
    painter->drawEllipse(rect);
  }
}
