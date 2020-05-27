# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Projet-S6-full

QT = core gui widgets

HEADERS = \
   $$PWD/app/fichier/gestion_fichier.hh \
   $$PWD/app/GUI/fntModifObjet/MODialog.hh \
   $$PWD/app/GUI/fntModifObjet/UI_modifObjet.hh \
   $$PWD/app/GUI/fntOrdoCreate/OCDialog.hh \
   $$PWD/app/GUI/fntOrdoCreate/UI_ordoCreate.hh \
   $$PWD/app/GUI/fntPrincipale/MainWindow.hh \
   $$PWD/app/GUI/fntPrincipale/QArc.hh \
   $$PWD/app/GUI/fntPrincipale/QSommet.hh \
   $$PWD/app/GUI/fntPrincipale/QZoneDeDessin.hh \
   $$PWD/app/GUI/fntPrincipale/UI_MainWindow.hh \
   $$PWD/bib/algo/liste.hh \
   $$PWD/bib/classes/Arc.hh \
   $$PWD/bib/classes/classes.hh \
   $$PWD/bib/classes/GrapheMatrice.hh \
   $$PWD/bib/classes/Sommet.hh \
   $$PWD/bib/classes/struct.hh \
   $$PWD/bib/bib.hh \
   app/GUI/fntPrincipale/mainwindow_copy.hh

SOURCES = \
   $$PWD/app/fichier/gestion_fichier.cc \
   $$PWD/app/GUI/fntModifObjet/MODialog.cc \
   $$PWD/app/GUI/fntOrdoCreate/OCDialog.cc \
   $$PWD/app/GUI/fntPrincipale/MainWindow.cc \
   $$PWD/app/GUI/fntPrincipale/QArc.cc \
   $$PWD/app/GUI/fntPrincipale/QSommet.cc \
   $$PWD/app/GUI/fntPrincipale/QZoneDeDessin.cc \
   $$PWD/app/main.cc \
   $$PWD/bib/algo/liste.cc \
   $$PWD/bib/classes/Arc.cc \
   $$PWD/bib/classes/GrapheMatrice.cc \
   $$PWD/bib/classes/Sommet.cc

INCLUDEPATH =

#DEFINES = 

FORMS += \
    app/GUI/fntPrincipale/mainwindow.ui \
    app/GUI/fntPrincipale/mainwindow_copy.ui

