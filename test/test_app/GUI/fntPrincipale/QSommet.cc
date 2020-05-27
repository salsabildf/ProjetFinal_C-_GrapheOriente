#include <QtTest/QtTest>
#include <QtWidgets>
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.cc"

class TestQSommet: public QObject
{
    Q_OBJECT
private slots:
  void testConstructQSomment(){
    // On fait la map INUTILE du sommet
    VectVal vv;
    vv.type = 0;
    vv.valeur_entiere = 12;

    map <string, VectVal> cu;
    cu.insert (pair <string, VectVal> ("plus_tot", vv));
    cu.insert (pair <string, VectVal> ("plus_tard", vv));

    // On construit le Sommet
    Sommet S0(23, 32, "sommet0", 0, cu);

    // On construit le QSommet
    QSommet QS0(S0);
    QSommet QS0_(QS0);

    QVERIFY(QS0.getID() == S0.getID());
    QVERIFY(QS0.getPosX() == S0.getPosX());
    QVERIFY(QS0.getPosY() == S0.getPosY());
    QVERIFY(QS0.getRayon() == TAILLE_RAYON);
    QVERIFY(QS0.getSelect() == 0);

    QVERIFY(QS0_.getID() == S0.getID());
    QVERIFY(QS0_.getPosX() == S0.getPosX());
    QVERIFY(QS0_.getPosY() == S0.getPosY());
    QVERIFY(QS0_.getRayon() == TAILLE_RAYON);
    QVERIFY(QS0_.getSelect() == 0);
  }


  void TestGettersSetters(){
    // On fait la map INUTILE du sommet
    VectVal vv;
    vv.type = 0;
    vv.valeur_entiere = 12;

    map <string, VectVal> cu;
    cu.insert (pair <string, VectVal> ("plus_tot", vv));
    cu.insert (pair <string, VectVal> ("plus_tard", vv));

    // On construit le Sommet
    Sommet S0(23, 32, "sommet0", 0, cu);

    // On construit le QSommet
    QSommet QS0(S0);

    QS0.setID(2);
    QS0.setPosX(45);
    QS0.setPosY(45);
    QS0.setRayon(11);
    QS0.setCoul(QColor(1,1,1));
    QS0.setSelect(1);

    QVERIFY(QS0.getID() == 2);
    QVERIFY(QS0.getPosX() == 45);
    QVERIFY(QS0.getPosY() == 45);
    QVERIFY(QS0.getRayon() == 11);
    QVERIFY(QS0.getCoul() == QColor(1,1,1));
    QVERIFY(QS0.getSelect() == 1);

  }

  // void TestmouseDoubleClickEvent(){
  //   // On fait la map INUTILE du sommet
  //   VectVal vv;
  //   vv.type = 0;
  //   vv.valeur_entiere = 12;
  //
  //   map <string, VectVal> cu;
  //   cu.insert (pair <string, VectVal> ("plus_tot", vv));
  //   cu.insert (pair <string, VectVal> ("plus_tard", vv));
  //
  //   // On construit le Sommet
  //   Sommet S0(23, 32, "sommet0", 0, cu);
  //
  //   // On construit le QSommet
  //   QSommet QS0(S0);
  //   //QTest::mouseDClick(&QS0);
  //
  //   // On doit créer modifObjet avant LOL
  // }

  // void TestboundingRect();
  // void Testpaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#ifndef QTT_MAIN
#define QTT_MAIN
QTEST_MAIN(TestQSommet);
#endif
#include "QSommet.moc"
