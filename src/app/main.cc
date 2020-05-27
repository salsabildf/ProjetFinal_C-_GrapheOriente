#include "GUI/fntPrincipale/MainWindow.hh"
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <cstring>
#include <QtCore>
using namespace std;

int main(int argc, char *argv[]){
  QApplication app(argc, argv);

  MainWindow F;
  F.show();
  return app.exec();

}
