#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/MainWindow.hh"

#ifndef TESTMAINW
#define TESTMAINW

class TestMainWindow: public QObject
{
    Q_OBJECT
private slots:
    void testMainWindow(){
    }
    void testDestructeur(){} // lol
    void testprintConsole(){}
    void testajouterOnglet(){}
    void testsupprimerOnglet(){}
    void testChangeOnglet(){}
    void testnv_graphe_vide(){}
    void testnv_graphe_aleatoire(){}
    void testenregistrer_sous(){}
    void testdupliquer_graphe(){}
    void testsupprimer_graphe(){}
    void testford_Bellman(){}
    void testfloyd_Warshall(){}
    void testdegr_sortant(){}
    void testdegr_entrant(){}
    void testdegr_entrant_et_sortant(){}
    void testcoloration_de_graphe(){}
    void testdetermination_de_stables(){}
    void testdetermination_de_cliques(){}
    void testvoisins_de_sommets(){}
    void testgestion_de_flots(){}
    void testcreer_un_graphe_d_ordonnancement(){}
    void testarborescence(){}
    void testantiArborescence(){}
    void testrecherche_de_la_connexite(){}
    void testtrouver_chaine_eulerienne(){}
    void testtrouver_chaine_hamiltonienne(){}
    void testpostier_chinois(){}
    void testvoyageur_de_commerce(){}
    void testextraireSousGraphe(){}
    void testarrangerSommets(){}
    void testDBEselection(){}
    void testDBEaddSommet(){}
    void testDBEaddArc(){}
    void testDBEdeleteSommet(){}
    void testDBEdeleteArc(){}
};
#ifndef QTT_MAIN
#define QTT_MAIN
QTEST_MAIN(TestMainWindow);
#endif
#include "MainWindow.moc"

#endif
