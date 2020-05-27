#include <typeinfo>
#include "QArc.hh"

QArc::QArc (Arc A){
  this->id = A.getID();
  setData(0,"Arc");


  this->posxA = 0;
  this->posyA = 0;
  this->posxB = 0;
  this->posyB = 0;
}

QArc::QArc(QArc const &A){
  this->id = A.id;
  this->posxA = A.posxA;
  this->posyA = A.posyA;
  this->posxB = A.posxB;
  this->posyB = A.posyB;
}

QArc::~QArc(){

}

int QArc::getID() const{return this->id;}
int QArc::getPosXA() const{return this->posxA;}
int QArc::getPosYA() const{return this->posyA;}
int QArc::getPosXB() const{return this->posxB;}
int QArc::getPosYB() const{return this->posyB;}

void QArc::setID(int id){this->id = id;}
void QArc::setPosXA(int x){ prepareGeometryChange() ;this->posxA = x;}
void QArc::setPosYA(int y){ prepareGeometryChange() ;this->posyA = y;}
void QArc::setPosXB(int x){ prepareGeometryChange() ;this->posxB = x;}
void QArc::setPosYB(int y){ prepareGeometryChange() ;this->posyB = y;}

void QArc::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){}

QRectF QArc::boundingRect() const{
  // QLineF l(posxA, posyA, posxB, posyB);
  // QGraphicsLineItem line(l);
  // return line.boundingRect();

  return shape().boundingRect();
  //return mapRectFromScene(QRectF(posxA+cos*radius-(rx/2), posyA+sin*radius-(ry/2), posxB-posxA-2*cos*radius+rx, posyB-posyA-2*sin*radius+ry).normalized());
}

QPainterPath QArc::shape() const{

  qreal sin =(posyB-posyA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal cos =(posxB-posxA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal radius = TAILLE_RAYON+10;

  if (qFabs(posxB-posxA) < 10 ){
    sin = (posyB-posyA)/qFabs(posyB-posyA);
    cos = 0;
  }
  QPointF pA = mapFromScene(posxA+cos*radius,posyA+sin*radius);
  QPointF pB = mapFromScene(posxB-cos*radius,posyB-sin*radius);

  QGraphicsLineItem line (pA.x(),pA.y(),pB.x(),pB.y());
  return line.shape();

}

void QArc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

  QPen greenPen(Qt::green, 3 );


  QPen blackPen(Qt::black, 4 );
  painter->setPen(blackPen);

  prepareGeometryChange();
  QPoint firstp,secondp;
  QPointF pA = mapFromScene(posxA,posyA);
  QPointF pB = mapFromScene(posxB,posyB);
  QBrush redBrush(Qt::red,Qt::SolidPattern);

  firstp.setX(pA.x()); firstp.setY(pA.y());
  secondp.setX(pB.x()); secondp.setY(pB.y());

  double a,b,d,e,f,x1,x2,y1,y2;
  QPointF arrow,pI1,pI2,pC;
  if(posxB-posxA != 0){
    a = double(posyB - posyA)/double(posxB - posxA);
    b = posyA - a*posxA;
    d = 1+a*a;
    e = -2*posxB+2*a*b-2*a*posyB;
    f = posxB*posxB+b*b+-2*b*posyB+posyB*posyB-(TAILLE_RAYON+5)*(TAILLE_RAYON+5);
    x1 = (-e + qSqrt(e*e-4*d*f))/(2*d);
    x2 = (-e - qSqrt(e*e-4*d*f))/(2*d);
    y1 = a*x1+b;
    y2 = a*x2+b;
    pI1 = mapFromScene(x1,y1);
    pI2 = mapFromScene(x2,y2);
    if(QLineF(pI1,pA).length()<QLineF(pI2,pA).length()) arrow = pI1;
    else arrow = pI2;

  }
  else{
    if (posyB-posyA > 0)arrow = mapFromScene(posxB,posyB + 5);
    else arrow = mapFromScene(posxB,posyB - 5);
  }


  QBrush whiteBrush(Qt::white,Qt::SolidPattern);
  QPen darkbluePen(Qt::darkBlue,3);
  //
  painter->drawLine(firstp,secondp);
  painter->setBrush(whiteBrush);
  painter->setBrush(redBrush);
  painter->drawEllipse(arrow,5,5);

}
