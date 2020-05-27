#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/QZoneDeDessin.hh"
#include "../../../../src/app/GUI/fntPrincipale/QZoneDeDessin.cc"
#include "../../../../src/app/GUI/fntPrincipale/QArc.hh"
#include "../../../../src/app/GUI/fntPrincipale/QArc.cc"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.cc"
#include "../../../../src/bib/classes/GrapheMatrice.cc"
#include "../../../../src/bib/classes/Sommet.cc"
#include "../../../../src/bib/classes/Arc.cc"

class TestQZoneDeDessin: public QObject
{
    Q_OBJECT
private slots:
  void initTestCase()
  {
      qDebug("Called before everything else.");
  }

  void TestConstructQZoneDeDessin(){
    // Pas grand chose à tester jpense
  }

  void TestSettersGetters(){
    QZoneDeDessin qzdd;
    Graphe G("Graphe");
    QGraphicsScene * sc_;

    qzdd.setSelected_list({0,1});
    qzdd.setGraphe_dessine(G);
    qzdd.setScene(sc_);

    vector<int> v {0,1};

    QCOMPARE(qzdd.getSelected_list(), v);
    QCOMPARE(qzdd.getGraphe_dessine(), G);
    QCOMPARE(qzdd.getScene(), sc_);
    QCOMPARE(qzdd.scene(), sc_);
    QCOMPARE(qzdd.scene(), qzdd.getScene());

  }

  void TestplacementSommets(){
    QZoneDeDessin qzdd;
    Sommet S0(0,0,"S0",0), S1(1,1,"S1",1);
    QSommet QS0(S0), QS1(S1);
    qzdd.placementSommets();
    QVERIFY(QS0.getPosX() != QS1.getPosX());
    QVERIFY(QS0.getPosY() != QS1.getPosY());

  }
  void Testdistance(){
    QZoneDeDessin qzdd;
    Sommet S0(0,0,"S0",0), S1(1,1,"S1",1);
    QSommet QS0(S0), QS1(S1);
    pair<int,int> a (1,1);
    pair<int,int> b;
    b = qzdd.distance(QS0, QS1);
    QCOMPARE(b, a);
  }

  void TestaddSelect_Sommet(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{0,1,2};
    qzdd.setSelected_list({0,1});

    qzdd.addSelect_Sommet(2);

    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void TestdeleteSelect_Sommet(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{0};
    qzdd.setSelected_list({0,1});
    qzdd.deleteSelect_Sommet(1);
    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void TestrazSelected_list(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{};
    qzdd.setSelected_list({0,1});

    qzdd.razSelected_list();
    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void Testafficher_Sommet(){
    QZoneDeDessin qzdd;
    Sommet S(1,1,"Sommet",0);
    QSommet QS_r (S);
    qzdd.afficher_Sommet(S);

    QSommet* QS = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(qzdd.mapFromScene(QPointF (1,1)))); // Cast de QGraphicsItem* vers QSommet*
    qDebug()<< "QS data " << QS->data(0) << "\n\n";

      // QList<QGraphicsItem*> listS = qzdd.items();
      // for(int i=0; i< listS.size(); ++i){
      //   QSommet* QS = qgraphicsitem_cast<QSommet*>(listS[i]);
      //   qDebug()<< "QS data " << QS->data(0);
      //   qDebug()<< "QS pos " << QS->pos();
      // }

    //qDebug()<< QS->pos() << "\n\n";

    QVERIFY(QS->data(0) == "Sommet");
    QCOMPARE(QS->getID(), QS_r.getID());
    QCOMPARE(QS->getPosX(), QS_r.getPosX());
    QCOMPARE(QS->getPosY(), QS_r.getPosY());
    QCOMPARE(QS->getRayon(), QS_r.getRayon());
    QCOMPARE(QS->getCoul(), QS_r.getCoul());
    QCOMPARE(QS->getSelect(), QS_r.getSelect());
  }

  void Testafficher_arc(){
    QZoneDeDessin qzdd;
    Sommet S0(100,100,"Sommet",0);
    Sommet S1(300,300,"Sommet",1);
    qzdd.afficher_Sommet(S0);
    qzdd.afficher_Sommet(S1);

    Arc A("5", 5, 0, 1);
    QArc QA_r(A);
    QA_r.setPosXA(100);
    QA_r.setPosYA(100);
    QA_r.setPosXB(300);
    QA_r.setPosYB(300);
    qzdd.afficher_arc(A);
    QArc* QA = qgraphicsitem_cast<QArc*>(qzdd.itemAt(qzdd.mapFromScene(QPointF (200,200))));
    qDebug()<< "QA data " << QA->data(0) << "\n\n";

    // QList<QGraphicsItem*> listS = qzdd.items();
    // for(int i=0; i< listS.size(); ++i){
    //   QArc* QA = qgraphicsitem_cast<QArc*>(listS[i]);
    //   qDebug()<< "QA data " << QA->data(0);
    //   qDebug()<< "QA posx " << QA->pos();
    // }

    QVERIFY(QA->data(0) == "Arc");
    QCOMPARE(QA->getPosXA(), QA_r.getPosXA());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYA());
    QCOMPARE(QA->getPosXB(), QA_r.getPosXB());
    QCOMPARE(QA->getPosYB(), QA_r.getPosYB());

  }
  void Testafficher_Graphe(){
    QZoneDeDessin qzdd;
    Graphe g("G-test");
    g.ajout_Sommet(0,100, 100);
    g.ajout_Sommet(1,300, 100);
    g.ajout_Arc(0,1);

    Sommet S0(100,100,"Sommet",0);
    Sommet S1(300,100,"Sommet",1);

    QSommet QS_r(S0);
    QSommet QS0_r(S1);

    Arc A(0, 0, 1);
    QArc QA_r(A);
    QA_r.setPosXA(S0.getPosX());
    QA_r.setPosYA(S0.getPosY());
    QA_r.setPosXB(S1.getPosX());
    QA_r.setPosYB(S1.getPosY());

    qzdd.afficher_Graphe(g);
    QArc* QA = qgraphicsitem_cast<QArc*>(qzdd.itemAt(qzdd.mapFromScene(QPointF (200,102))));
    qDebug()<< "Bounding Rect" << QA->boundingRect();
    qDebug()<< "Bounding Rect TOP" << QA->boundingRect().top();
    qDebug()<< "Bounding Rect BOTTOM" << QA->boundingRect().bottom();
    qDebug()<< "bounding Rect DANS SCENE" << QA->sceneBoundingRect();
    qDebug()<< QA->pos();

    QVERIFY(QA->data(0) == "Arc");
    QCOMPARE(QA->getPosXA(), QA_r.getPosXA());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYA());
    QCOMPARE(QA->getPosXB(), QA_r.getPosXB());
    QCOMPARE(QA->getPosYB(), QA_r.getPosYB());

    QSommet* QS = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(qzdd.mapFromScene(QPointF (100,100))));
    qDebug()<< "QS data " << QS->data(0) << "\n\n";

    QVERIFY(QS->data(0) == "Sommet");
    QCOMPARE(QS->getID(), QS_r.getID());
    QCOMPARE(QS->getPosX(), QS_r.getPosX());
    QCOMPARE(QS->getPosY(), QS_r.getPosY());
    QCOMPARE(QS->getRayon(), QS_r.getRayon());
    QCOMPARE(QS->getCoul(), QS_r.getCoul());
    QCOMPARE(QS->getSelect(), QS_r.getSelect());

    QSommet* QS0 = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(qzdd.mapFromScene(QPointF (300,100))));
    qDebug()<< "QS0 data " << QS0->data(0) << "\n\n";

    QVERIFY(QS0->data(0) == "Sommet");
    QCOMPARE(QS0->getID(), QS0_r.getID());
    QCOMPARE(QS0->getPosX(), QS0_r.getPosX());
    QCOMPARE(QS0->getPosY(), QS0_r.getPosY());
    QCOMPARE(QS0->getRayon(), QS0_r.getRayon());
    QCOMPARE(QS0->getCoul(), QS0_r.getCoul());
    QCOMPARE(QS0->getSelect(), QS0_r.getSelect());
  }

  void testMousePressEvent(){

  }

  void testDessiner_sommet(){

  }

  void testDessiner_arc(){

  }
};

#ifndef QTT_MAIN
#define QTT_MAIN

QTEST_MAIN(TestQZoneDeDessin);
#endif

#include "QZoneDeDessin.moc"
