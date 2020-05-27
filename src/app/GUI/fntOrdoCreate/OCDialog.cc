#include "OCDialog.hh"
#include <QDebug>
ordoCreate::ordoCreate(QWidget *parent):QDialog(parent), ui(new Ui::Dialog), res(vector<pert_row>{}){
  this->ui->setupUi(this);
  QObject::connect(ui->ajoutTacheButton, &QPushButton::clicked,this, &ordoCreate::ajoutTache);
  QObject::connect(ui->supprimeTacheButton, &QPushButton::clicked,this, &ordoCreate::supprimerTache);

}
ordoCreate::~ordoCreate(){}

vector<pert_row> ordoCreate::getRes(){
  return res;
}

void ordoCreate::ajoutTache(){
  qDebug()<<ui->DureelineEdit->text();
  pert_row nouvelle;
  vector<int> tmp;
  nouvelle.tache = ui->IDlineEdit->text().toInt();
  nouvelle.nom_tache = ui->nomDeLaTachelineEdit->text().toStdString();
  nouvelle.duree = ui->DureelineEdit->text().toInt();

  QString tacheA = ui->TacheAnterieurlineEdit->text();
  qDebug()<<"tacheA "<<tacheA;
  if(tacheA != ""){
    QStringList list1 = tacheA.split(",");
    for(int i=0;i<list1.size();++i){
      tmp.push_back(list1[i].toInt());
    }
  }

  nouvelle.taches_anterieures = tmp;
  res.push_back(nouvelle);

  ui->IDlineEdit->clear();
  ui->nomDeLaTachelineEdit->clear();
  ui->DureelineEdit->clear();
  ui->TacheAnterieurlineEdit->clear();

ui->tableWidget->setRowCount(0);
for(int c=0;c<res.size();++c){
  ui->tableWidget->insertRow (ui->tableWidget->rowCount());
  for(int i=0;i<4;++i){
    QString string;

    if(i == 0){//id
      string = QString::number(res[c].tache);
    }
    else if(i==1){//nom
      string = QString::fromStdString(res[c].nom_tache);
    }
    else if(i==2){//durée
      string = QString::number(res[c].duree);

    }
    else if(i==3){//tâche antérieur
      for(int a=0;a<res[c].taches_anterieures.size();++a){
        string = string + QString::number(res[c].taches_anterieures[a]) + " ";
        qDebug()<<"TA OCD :"<<res[c].taches_anterieures[a];
      }

    }
    ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                  i,
                                  new QTableWidgetItem(string));
  }
}

}
void ordoCreate::supprimerTache(){
  int current = ui->tableWidget->currentRow();
  int id = ui->tableWidget->item(current, 0)->text().toInt();
  vector<pert_row> nouvellevec;
  for(int i=0;i<res.size();++i){
    if(res[i].tache != id){
      nouvellevec.push_back(res[i]);
    }
  }
  this->res=nouvellevec;
  ui->tableWidget->removeRow(ui->tableWidget->currentRow());

}
