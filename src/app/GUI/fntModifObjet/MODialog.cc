#include "MODialog.hh"
#include <QDebug>

modifObjet::modifObjet(QWidget *parent):QDialog(parent), ui(new Ui::ModifObjet),res(pair<string, map<string,VectVal>>()){
this->ui->setupUi(this);
QObject::connect(ui->addTacheButton, &QPushButton::clicked,this, &modifObjet::addCU);
QObject::connect(ui->supprimeButton, &QPushButton::clicked,this, &modifObjet::supprimeCU);

res.first = "CU";
}
modifObjet::~modifObjet(){}	/// Destructeur de la fenetre

void modifObjet::setEtq(QString s){
  ui->lineEditEtiquette->setText(s);
}

QString modifObjet::getetq(){
  return ui->lineEditEtiquette->text();
}

map <string, VectVal> modifObjet::getCU(){
  return res.second;
}

void modifObjet::setListCU(map <string, VectVal> SCharge_utile){
  res.second = SCharge_utile;
  for(map <string, VectVal>::iterator it=res.second.begin() ; it!=res.second.end() ; ++it)
  {
    QString string;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    for(int i=0;i<2;++i){
      if(i==0){
        string = QString::fromStdString(it->first); // accede à la clé

      }
      else if(i==1){
        // accede à la valeur
        if(it->second.type){
            //réel
            string = QString::number(it->second.valeur_reel);
        }
        else{
            //entier
            string = QString::number(it->second.valeur_entiere);
        }
      }
      ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
      i,
      new QTableWidgetItem(string));
    }
  }
}
void modifObjet::supprimeCU(){
  int current = ui->tableWidget->currentRow();
  QString name = ui->tableWidget->item(current, 0)->text();
  res.second.erase(name.toStdString());
  ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}	/// Supprime la charge utile en surbrillance

void modifObjet::addCU(){
  VectVal vv;

  if (ui->ValeurlineEdit->text().toInt() - ui->ValeurlineEdit->text().toFloat() != 0){
    //Alors c'est un réel
      vv.type = 1;
      vv.valeur_reel = ui->ValeurlineEdit->text().toFloat();
  }
  else{
    vv.type = 0;
    vv.valeur_entiere = ui->ValeurlineEdit->text().toInt();
    qDebug()<<vv.valeur_entiere;
  }

  res.second.insert(pair<string, VectVal>(ui->NomlineEdit->text().toStdString(), vv));
  ui->tableWidget->setRowCount(0);
  for(map <string, VectVal>::iterator it=res.second.begin() ; it!=res.second.end() ; ++it)
  {
    QString string;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    for(int i=0;i<2;++i){
      if(i==0){
        string = QString::fromStdString(it->first); // accede à la clé

      }
      else if(i==1){
        // accede à la valeur
        if(it->second.type){
            //réel
            string = QString::number(it->second.valeur_reel);
        }
        else{
            //entier
            string = QString::number(it->second.valeur_entiere);
        }
      }
      ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(string));
    }
  }
}		/// Ajoute une charge utile respectant les informations entr&eacute{}es dans les lineEdit
