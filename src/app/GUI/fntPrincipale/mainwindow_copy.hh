/********************************************************************************
** Form generated from reading UI file 'mainwindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_COPY_H
#define UI_MAINWINDOW_COPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QZoneDeDessin.hh"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnrengistrer;
    QAction *actionCharger;
    QAction *actionEnrengistrer_sous;
    QAction *actionDupliquer_graphe;
    QAction *actionSupprimer_graphe;
    QAction *actionFord_Bellman;
    QAction *actionFloyd_Warshall;
    QAction *actionDegr_sortant;
    QAction *actionDegr_entrant;
    QAction *actionDegr_s_entrant_et_sortant;
    QAction *actionColoration_de_graphe;
    QAction *actionD_termination_de_stables;
    QAction *actionD_termination_de_cliques;
    QAction *actionVoisins_de_sommets;
    QAction *actionGEstion_de_flots;
    QAction *actionCr_er_un_graphe_d_ordonnancement;
    QAction *actionArborescence;
    QAction *actionAnti_Arborescence;
    QAction *actionRecherche_de_la_connexit;
    QAction *actionTrouver_chaine_eul_rienne;
    QAction *actionTrouver_chaine_hamiltonienne;
    QAction *actionR_solution_du_probl_me_du_postier_chinois;
    QAction *actionR_solution_du_probl_me_de_voyageur_de_commerce;
    QAction *actionDocumentation;
    QAction *actionGithub;
    QAction *actionNouveau_graphe;
    QAction *actionNouveau_graphe_al_atoire;
    QAction *actionFermer_graphe;
    QAction *actionArranger_sommets;
    QAction *actionExtraire_sous_graphe;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QZoneDeDessin *zoneDessin;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *pageSommet;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *pageArc;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QTextBrowser *caraSelection;
    QTextBrowser *console;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEidition;
    QMenu *menuAlgorithmes;
    QMenu *menuCalcul_du_plus_court_chemin;
    QMenu *menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet;
    QMenu *menuTrouver_arborescence_anti_arborescence;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(981, 613);
        actionEnrengistrer = new QAction(MainWindow);
        actionEnrengistrer->setObjectName(QStringLiteral("actionEnrengistrer"));
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName(QStringLiteral("actionCharger"));
        actionEnrengistrer_sous = new QAction(MainWindow);
        actionEnrengistrer_sous->setObjectName(QStringLiteral("actionEnrengistrer_sous"));
        actionDupliquer_graphe = new QAction(MainWindow);
        actionDupliquer_graphe->setObjectName(QStringLiteral("actionDupliquer_graphe"));
        actionSupprimer_graphe = new QAction(MainWindow);
        actionSupprimer_graphe->setObjectName(QStringLiteral("actionSupprimer_graphe"));
        actionFord_Bellman = new QAction(MainWindow);
        actionFord_Bellman->setObjectName(QStringLiteral("actionFord_Bellman"));
        actionFloyd_Warshall = new QAction(MainWindow);
        actionFloyd_Warshall->setObjectName(QStringLiteral("actionFloyd_Warshall"));
        actionDegr_sortant = new QAction(MainWindow);
        actionDegr_sortant->setObjectName(QStringLiteral("actionDegr_sortant"));
        actionDegr_entrant = new QAction(MainWindow);
        actionDegr_entrant->setObjectName(QStringLiteral("actionDegr_entrant"));
        actionDegr_s_entrant_et_sortant = new QAction(MainWindow);
        actionDegr_s_entrant_et_sortant->setObjectName(QStringLiteral("actionDegr_s_entrant_et_sortant"));
        actionColoration_de_graphe = new QAction(MainWindow);
        actionColoration_de_graphe->setObjectName(QStringLiteral("actionColoration_de_graphe"));
        actionD_termination_de_stables = new QAction(MainWindow);
        actionD_termination_de_stables->setObjectName(QStringLiteral("actionD_termination_de_stables"));
        actionD_termination_de_cliques = new QAction(MainWindow);
        actionD_termination_de_cliques->setObjectName(QStringLiteral("actionD_termination_de_cliques"));
        actionVoisins_de_sommets = new QAction(MainWindow);
        actionVoisins_de_sommets->setObjectName(QStringLiteral("actionVoisins_de_sommets"));
        actionGEstion_de_flots = new QAction(MainWindow);
        actionGEstion_de_flots->setObjectName(QStringLiteral("actionGEstion_de_flots"));
        actionCr_er_un_graphe_d_ordonnancement = new QAction(MainWindow);
        actionCr_er_un_graphe_d_ordonnancement->setObjectName(QStringLiteral("actionCr_er_un_graphe_d_ordonnancement"));
        actionArborescence = new QAction(MainWindow);
        actionArborescence->setObjectName(QStringLiteral("actionArborescence"));
        actionAnti_Arborescence = new QAction(MainWindow);
        actionAnti_Arborescence->setObjectName(QStringLiteral("actionAnti_Arborescence"));
        actionRecherche_de_la_connexit = new QAction(MainWindow);
        actionRecherche_de_la_connexit->setObjectName(QStringLiteral("actionRecherche_de_la_connexit"));
        actionTrouver_chaine_eul_rienne = new QAction(MainWindow);
        actionTrouver_chaine_eul_rienne->setObjectName(QStringLiteral("actionTrouver_chaine_eul_rienne"));
        actionTrouver_chaine_hamiltonienne = new QAction(MainWindow);
        actionTrouver_chaine_hamiltonienne->setObjectName(QStringLiteral("actionTrouver_chaine_hamiltonienne"));
        actionR_solution_du_probl_me_du_postier_chinois = new QAction(MainWindow);
        actionR_solution_du_probl_me_du_postier_chinois->setObjectName(QStringLiteral("actionR_solution_du_probl_me_du_postier_chinois"));
        actionR_solution_du_probl_me_de_voyageur_de_commerce = new QAction(MainWindow);
        actionR_solution_du_probl_me_de_voyageur_de_commerce->setObjectName(QStringLiteral("actionR_solution_du_probl_me_de_voyageur_de_commerce"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QStringLiteral("actionDocumentation"));
        actionGithub = new QAction(MainWindow);
        actionGithub->setObjectName(QStringLiteral("actionGithub"));
        actionNouveau_graphe = new QAction(MainWindow);
        actionNouveau_graphe->setObjectName(QStringLiteral("actionNouveau_graphe"));
        actionNouveau_graphe_al_atoire = new QAction(MainWindow);
        actionNouveau_graphe_al_atoire->setObjectName(QStringLiteral("actionNouveau_graphe_al_atoire"));
        actionFermer_graphe = new QAction(MainWindow);
        actionFermer_graphe->setObjectName(QStringLiteral("actionFermer_graphe"));
        actionArranger_sommets = new QAction(MainWindow);
        actionArranger_sommets->setObjectName(QStringLiteral("actionArranger_sommets"));
        actionExtraire_sous_graphe = new QAction(MainWindow);
        actionExtraire_sous_graphe->setObjectName(QStringLiteral("actionExtraire_sous_graphe"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        zoneDessin = new QZoneDeDessin(tab);
        zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
        zoneDessin->setMinimumSize(QSize(575, 0));

        horizontalLayout_2->addWidget(zoneDessin);


        horizontalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());

        horizontalLayout_3->addWidget(tabWidget);

        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(356, 0));
        verticalWidget->setMaximumSize(QSize(356, 16777215));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line = new QFrame(verticalWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(verticalWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        toolBox = new QToolBox(verticalWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        pageSommet = new QWidget();
        pageSommet->setObjectName(QStringLiteral("pageSommet"));
        pageSommet->setGeometry(QRect(0, 0, 338, 68));
        layoutWidget = new QWidget(pageSommet);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 90, 77));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 2, 0, 1, 1);

        toolBox->addItem(pageSommet, QStringLiteral("Sommet"));
        pageArc = new QWidget();
        pageArc->setObjectName(QStringLiteral("pageArc"));
        pageArc->setGeometry(QRect(0, 0, 338, 68));
        layoutWidget1 = new QWidget(pageArc);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 101, 50));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(layoutWidget1);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout_2->addWidget(radioButton_4, 0, 0, 1, 1);

        radioButton_5 = new QRadioButton(layoutWidget1);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        gridLayout_2->addWidget(radioButton_5, 1, 0, 1, 1);

        toolBox->addItem(pageArc, QStringLiteral("Arcs"));

        verticalLayout->addWidget(toolBox);

        caraSelection = new QTextBrowser(verticalWidget);
        caraSelection->setObjectName(QStringLiteral("caraSelection"));

        verticalLayout->addWidget(caraSelection);

        console = new QTextBrowser(verticalWidget);
        console->setObjectName(QStringLiteral("console"));

        verticalLayout->addWidget(console);


        horizontalLayout_3->addWidget(verticalWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 981, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEidition = new QMenu(menubar);
        menuEidition->setObjectName(QStringLiteral("menuEidition"));
        menuAlgorithmes = new QMenu(menubar);
        menuAlgorithmes->setObjectName(QStringLiteral("menuAlgorithmes"));
        menuCalcul_du_plus_court_chemin = new QMenu(menuAlgorithmes);
        menuCalcul_du_plus_court_chemin->setObjectName(QStringLiteral("menuCalcul_du_plus_court_chemin"));
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet = new QMenu(menuAlgorithmes);
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->setObjectName(QStringLiteral("menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet"));
        menuTrouver_arborescence_anti_arborescence = new QMenu(menuAlgorithmes);
        menuTrouver_arborescence_anti_arborescence->setObjectName(QStringLiteral("menuTrouver_arborescence_anti_arborescence"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEidition->menuAction());
        menubar->addAction(menuAlgorithmes->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouveau_graphe);
        menuFichier->addAction(actionNouveau_graphe_al_atoire);
        menuFichier->addSeparator();
        menuFichier->addAction(actionCharger);
        menuFichier->addAction(actionEnrengistrer);
        menuFichier->addAction(actionEnrengistrer_sous);
        menuFichier->addSeparator();
        menuEidition->addAction(actionDupliquer_graphe);
        menuEidition->addAction(actionSupprimer_graphe);
        menuEidition->addSeparator();
        menuEidition->addAction(actionArranger_sommets);
        menuEidition->addAction(actionExtraire_sous_graphe);
        menuEidition->addSeparator();
        menuEidition->addAction(actionFermer_graphe);
        menuAlgorithmes->addAction(menuCalcul_du_plus_court_chemin->menuAction());
        menuAlgorithmes->addAction(menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->menuAction());
        menuAlgorithmes->addAction(actionColoration_de_graphe);
        menuAlgorithmes->addAction(actionD_termination_de_stables);
        menuAlgorithmes->addAction(actionD_termination_de_cliques);
        menuAlgorithmes->addAction(actionVoisins_de_sommets);
        menuAlgorithmes->addAction(actionGEstion_de_flots);
        menuAlgorithmes->addAction(actionCr_er_un_graphe_d_ordonnancement);
        menuAlgorithmes->addAction(menuTrouver_arborescence_anti_arborescence->menuAction());
        menuAlgorithmes->addAction(actionRecherche_de_la_connexit);
        menuAlgorithmes->addAction(actionTrouver_chaine_eul_rienne);
        menuAlgorithmes->addAction(actionTrouver_chaine_hamiltonienne);
        menuAlgorithmes->addAction(actionR_solution_du_probl_me_du_postier_chinois);
        menuAlgorithmes->addAction(actionR_solution_du_probl_me_de_voyageur_de_commerce);
        menuCalcul_du_plus_court_chemin->addAction(actionFord_Bellman);
        menuCalcul_du_plus_court_chemin->addAction(actionFloyd_Warshall);
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->addAction(actionDegr_sortant);
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->addAction(actionDegr_entrant);
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->addSeparator();
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->addAction(actionDegr_s_entrant_et_sortant);
        menuTrouver_arborescence_anti_arborescence->addAction(actionArborescence);
        menuTrouver_arborescence_anti_arborescence->addAction(actionAnti_Arborescence);
        menuAide->addAction(actionDocumentation);
        menuAide->addSeparator();
        menuAide->addAction(actionGithub);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionEnrengistrer->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
        actionCharger->setText(QApplication::translate("MainWindow", "Ouvrir...", Q_NULLPTR));
        actionEnrengistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous", Q_NULLPTR));
        actionDupliquer_graphe->setText(QApplication::translate("MainWindow", "Dupliquer graphe", Q_NULLPTR));
        actionSupprimer_graphe->setText(QApplication::translate("MainWindow", "Supprimer graphe", Q_NULLPTR));
        actionFord_Bellman->setText(QApplication::translate("MainWindow", "Ford-Bellman", Q_NULLPTR));
        actionFloyd_Warshall->setText(QApplication::translate("MainWindow", "Floyd-Warshall", Q_NULLPTR));
        actionDegr_sortant->setText(QApplication::translate("MainWindow", "Degr\303\251 sortant", Q_NULLPTR));
        actionDegr_entrant->setText(QApplication::translate("MainWindow", "Degr\303\251 entrant", Q_NULLPTR));
        actionDegr_s_entrant_et_sortant->setText(QApplication::translate("MainWindow", "Degr\303\251s entrant et sortant", Q_NULLPTR));
        actionColoration_de_graphe->setText(QApplication::translate("MainWindow", "Coloration de graphe", Q_NULLPTR));
        actionD_termination_de_stables->setText(QApplication::translate("MainWindow", "D\303\251termination de stables", Q_NULLPTR));
        actionD_termination_de_cliques->setText(QApplication::translate("MainWindow", "D\303\251termination de cliques", Q_NULLPTR));
        actionVoisins_de_sommets->setText(QApplication::translate("MainWindow", "Voisins de sommets", Q_NULLPTR));
        actionGEstion_de_flots->setText(QApplication::translate("MainWindow", "Gestion de flots", Q_NULLPTR));
        actionCr_er_un_graphe_d_ordonnancement->setText(QApplication::translate("MainWindow", "Cr\303\251er un graphe d'ordonnancement", Q_NULLPTR));
        actionArborescence->setText(QApplication::translate("MainWindow", "Arborescence", Q_NULLPTR));
        actionAnti_Arborescence->setText(QApplication::translate("MainWindow", "Anti-Arborescence", Q_NULLPTR));
        actionRecherche_de_la_connexit->setText(QApplication::translate("MainWindow", "Recherche de la connexit\303\251", Q_NULLPTR));
        actionTrouver_chaine_eul_rienne->setText(QApplication::translate("MainWindow", "Trouver chaine eul\303\251rienne", Q_NULLPTR));
        actionTrouver_chaine_hamiltonienne->setText(QApplication::translate("MainWindow", "Trouver chaine hamiltonienne", Q_NULLPTR));
        actionR_solution_du_probl_me_du_postier_chinois->setText(QApplication::translate("MainWindow", "R\303\251solution du probl\303\250me du postier chinois", Q_NULLPTR));
        actionR_solution_du_probl_me_de_voyageur_de_commerce->setText(QApplication::translate("MainWindow", "R\303\251solution du probl\303\250me de voyageur de commerce", Q_NULLPTR));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", Q_NULLPTR));
        actionGithub->setText(QApplication::translate("MainWindow", "Github", Q_NULLPTR));
        actionNouveau_graphe->setText(QApplication::translate("MainWindow", "Nouveau graphe vide", Q_NULLPTR));
        actionNouveau_graphe_al_atoire->setText(QApplication::translate("MainWindow", "Nouveau graphe al\303\251atoire", Q_NULLPTR));
        actionFermer_graphe->setText(QApplication::translate("MainWindow", "Fermer graphe", Q_NULLPTR));
        actionArranger_sommets->setText(QApplication::translate("MainWindow", "Arranger sommets", Q_NULLPTR));
        actionExtraire_sous_graphe->setText(QApplication::translate("MainWindow", "Extraire sous graphe", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Graphe 1", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Outils :", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Selection", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageSommet), QApplication::translate("MainWindow", "Sommet", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "Suppression", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageArc), QApplication::translate("MainWindow", "Arcs", Q_NULLPTR));
        caraSelection->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Caract\303\251risitque de la s\303\251l\303\251ction</span></p></body></html>", Q_NULLPTR));
        console->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Console</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">(affichage des r\303\251sultats des algo qui ne dessinent rien)</span></p></body></html>", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuEidition->setTitle(QApplication::translate("MainWindow", "Edition", Q_NULLPTR));
        menuAlgorithmes->setTitle(QApplication::translate("MainWindow", "Algorithmes", Q_NULLPTR));
        menuCalcul_du_plus_court_chemin->setTitle(QApplication::translate("MainWindow", "Calcul du plus court chemin", Q_NULLPTR));
        menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet->setTitle(QApplication::translate("MainWindow", "Calcul des degr\303\251s entrant ou sortant d'un sommet", Q_NULLPTR));
        menuTrouver_arborescence_anti_arborescence->setTitle(QApplication::translate("MainWindow", "Trouver arborescence/anti-arborescence", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_COPY_H
