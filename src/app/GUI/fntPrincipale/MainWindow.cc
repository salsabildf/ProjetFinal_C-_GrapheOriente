#include "MainWindow.hh"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow), grapheCourant("courant"){
  ui->setupUi(this);
  ui->console->clear();

  QTimer::singleShot(1000,this,SLOT(printCaraSelection()));

  QObject::connect(ui->actionNouveau_graphe,&QAction::triggered,this, &MainWindow::nv_graphe_vide);
  QObject::connect(ui->actionNouveau_graphe_al_atoire,&QAction::triggered,this, &MainWindow::nv_graphe_aleatoire);
  QObject::connect(ui->actionEnrengistrer,&QAction::triggered,this, &MainWindow::Enregistrer);
  QObject::connect(ui->actionEnrengistrer_sous,&QAction::triggered,this, &MainWindow::Enregistrer_sous);
  QObject::connect(ui->actionDupliquer_graphe,&QAction::triggered,this, &MainWindow::Dupliquer_graphe) ;
  QObject::connect(ui->actionSupprimer_graphe,&QAction::triggered,this, &MainWindow::Supprimer_graphe) ;
  QObject::connect(ui->actionCharger,&QAction::triggered,this, &MainWindow::Charger) ;
  QObject::connect(ui->actionFord_Bellman,&QAction::triggered,this, &MainWindow::Ford_Bellman) ;
  QObject::connect(ui->actionFloyd_Warshall,&QAction::triggered,this, &MainWindow::Floyd_Warshall) ;
  QObject::connect(ui->actionDegr_sortant,&QAction::triggered,this, &MainWindow::Degr_sortant) ;
  QObject::connect(ui->actionDegr_entrant,&QAction::triggered,this, &MainWindow::Degr_entrant) ;
  QObject::connect(ui->actionDegr_s_entrant_et_sortant,&QAction::triggered,this, &MainWindow::Degrs_entrant_et_sortant) ;
  QObject::connect(ui->actionColoration_de_graphe,&QAction::triggered,this, &MainWindow::Coloration_de_graphe) ;
  QObject::connect(ui->actionD_termination_de_stables,&QAction::triggered,this, &MainWindow::Determinaison_de_stables) ;
  QObject::connect(ui->actionD_termination_de_cliques,&QAction::triggered,this, &MainWindow::Determinaison_de_cliques) ;
  QObject::connect(ui->actionVoisins_de_sommets,&QAction::triggered,this, &MainWindow::Voisins_de_sommets);
  QObject::connect(ui->actionGEstion_de_flots,&QAction::triggered,this, &MainWindow::Gestion_de_flots) ;
  QObject::connect(ui->actionCr_er_un_graphe_d_ordonnancement,&QAction::triggered,this, &MainWindow::Creer_un_graphe_dordonnancement) ;
  QObject::connect(ui->actionArborescence,&QAction::triggered,this, &MainWindow::Arborescence) ;
  QObject::connect(ui->actionAnti_Arborescence,&QAction::triggered,this, &MainWindow::AntiArborescence) ;
  QObject::connect(ui->actionRecherche_de_la_connexit,&QAction::triggered,this, &MainWindow::Recherche_de_la_connexite) ;
  QObject::connect(ui->actionTrouver_chaine_eul_rienne,&QAction::triggered,this, &MainWindow::Trouver_chaine_eulerienne);
  QObject::connect(ui->actionTrouver_chaine_hamiltonienne,&QAction::triggered,this, &MainWindow::Trouver_chaine_hamiltonienne);
  QObject::connect(ui->actionR_solution_du_probl_me_du_postier_chinois,&QAction::triggered,this, &MainWindow::Postier_chinois);
  QObject::connect(ui->actionR_solution_du_probl_me_de_voyageur_de_commerce,&QAction::triggered,this, &MainWindow::Voyageur_de_commerce);
  QObject::connect(ui->actionDocumentation,&QAction::triggered,this, &MainWindow::Documentation);
  QObject::connect(ui->actionGithub,&QAction::triggered,this, &MainWindow::Github);
  QObject::connect(ui->actionExtraire_sous_graphe,&QAction::triggered,this, &MainWindow::extraireSousGraphe) ;
  QObject::connect(ui->actionArranger_sommets,SIGNAL(triggered()),this, SLOT (arrangerSommets()));
  QObject::connect(ui->actionFermer_graphe,&QAction::triggered,this, &MainWindow::fermer_graphe);
  QObject::connect(ui->radioButton, &QRadioButton::toggled,this, &MainWindow::DBEaddSommet);
  QObject::connect(ui->radioButton_2, &QRadioButton::toggled,this, &MainWindow::DBEdeleteSommet);
  QObject::connect(ui->radioButton_3, &QRadioButton::toggled,this, &MainWindow::DBEselection);
  QObject::connect(ui->radioButton_4, &QRadioButton::toggled,this, &MainWindow::DBEaddArc);
  QObject::connect(ui->radioButton_5, &QRadioButton::toggled,this, &MainWindow::DBEdeleteArc);
}

MainWindow::~MainWindow(){
  delete this->ui->tabWidget;
  delete this->ui->radioButton;
  delete this->ui->radioButton_2;
  delete this->ui->radioButton_3;
  delete this->ui->radioButton_4;
  delete this->ui->radioButton_5;
  delete this->ui->menubar;
  delete this->ui->console;
  delete this->ui->caraSelection;

  delete this->ui;
}
int MainWindow::printConsole(string nomMethode, string valRetFunc){
  QString res = "["+QString(ui->tabWidget->tabText(ui->tabWidget->currentIndex()))+"] ["+QString::fromStdString(nomMethode)+"] : "+QString::fromStdString(valRetFunc);
  ui->console->append(res);
return 1;
}

int MainWindow::printCaraSelection(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  ui->caraSelection->clear();

  if(!listeSommet.empty()){
    qDebug()<<listeSommet;
    vector<Sommet> vs = g.getVecteurSommet(listeSommet);
    for(int i=0; i<vs.size();++i){
      qDebug()<<vs[i].getID();
      ui->caraSelection->append("<b>Sommet "+QString::number(vs[i].getID())+" :</b>");
      ui->caraSelection->append("Etiquette : "+QString::fromStdString(vs[i].getEtiq()));
      ui->caraSelection->append("x :"+QString::number(vs[i].getPosX()));
      ui->caraSelection->append("y :"+QString::number(vs[i].getPosY()));
      ui->caraSelection->append("Liste ID arcs sortant:");
      vector<int> listeIDarc = vs[i].getVecArc();
      // qDebug()<<"LIDSA "<<listeIDarc;
      for(int j=0;j<listeIDarc.size();++j){
        ui->caraSelection->append(QString::number(listeIDarc[j]));
      }
      ui->caraSelection->append("<br>");

    }
  }

  QTimer::singleShot(1000,this,SLOT(printCaraSelection()));
}

int MainWindow::ajouterOnglet(QString nomOnglet, Graphe G){}
int MainWindow::supprimerOnglet(QString nomOnglet){}

void MainWindow::nv_graphe_vide(){
  QString text = QInputDialog::getText(this, tr("Nouveau graphe"),
                                       tr("Nom du graphe :"), QLineEdit::Normal);
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));

  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString nom = "Graphe ";
  QString str;
  if(text != ""){
    Graphe g = zoneDessin->getGraphe_dessine();
    g.setEtiq(text.toStdString());
    zoneDessin->setGraphe_dessine(g);
    nom = text;
    str = nom;

  }
  else{
    str = nom+" "+QString::number(ui->tabWidget->count()+1);
  }


  ui->tabWidget->addTab(tab,str);
}

void MainWindow::nv_graphe_aleatoire(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Graphe "+QString::number(ui->tabWidget->count()+1);

  bool ok;
  int nb_som = QInputDialog::getInt(this, tr("Graphe aléatoire"),
                               tr("Combien de sommets souhaitez-vous ?:"), 0, 0, 100, 1, &ok);

  if (ok){
    int max_arc = nb_som*(nb_som-1);
    Graphe G("randomG");
    for(int i = 0;i<nb_som;++i){
      QRandomGenerator qrg(i*time(NULL));
      int xs = qrg.bounded(1000);
      int ys = qrg.bounded(1000);
      G.ajout_Sommet(i, xs, ys);
    }
    for(int i = 0; i<max_arc;++i){
      QRandomGenerator qrg(i*2600);
      if (qrg.bounded(nb_som)==1){
        int ida = qrg.bounded(nb_som);
        int idb = qrg.bounded(nb_som);
        if(ida != idb){
          G.ajout_Arc(ida,idb);
        }
      }
    }
    zoneDessin->setGraphe_dessine(G);
    ui->tabWidget->addTab(tab,str);
  }

}

void MainWindow::Enregistrer(){
  QString chem = QString::fromStdString(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath());
  if(chem == "\0"){
    Enregistrer_sous();
  }
  else{
    sauvegarde(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine(), chem.toStdString());
    printConsole("Enregistrer", "Graphe sauvegardé "+chem.toStdString());
  }
}
void MainWindow::Charger(){
  QString chem;

  chem = QFileDialog::getOpenFileName(this, tr("Enregsitrer"), tr(".json"));
  Graphe g = chargement(chem.toStdString());
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setGraphe_dessine(g);
  ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), QString::fromStdString(g.getEtiq()));
  printConsole("Charger", "Graphe chargé depuis "+chem.toStdString());


}
void MainWindow::Enregistrer_sous(){
  QString chem;

  chem = QFileDialog::getSaveFileName(this, tr("Enregsitrer"), tr(".json"));
  qDebug()<<chem;
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g.setPath(chem.toStdString());

  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setGraphe_dessine(g);
  sauvegarde(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine(), chem.toStdString());
  printConsole("Enregistrer sous", "Graphe sauvegardé "+chem.toStdString());

}
void MainWindow::Dupliquer_graphe(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Duplicata "+ui->tabWidget->tabText(ui->tabWidget->currentIndex());
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g.setPath("\0");


  zoneDessin->setGraphe_dessine(g);
  ui->tabWidget->addTab(tab,str);
  printConsole("Duplication", "Graphe dupliqué");

}
void MainWindow::Supprimer_graphe(){
  string chem = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath();
  if (ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath() == "\0"){
    printConsole("Supprimer graphe","Le fichier n'existe pas");
  }
  else{
    if (suppression(chem) == 0){
      printConsole("Supprimer graphe", "Fichier supprimé");
    }
    else{
      printConsole("Supprimer graphe", "Problème lors de la suppression du fichier");
    }
  }
  ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::Ford_Bellman(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<Sommet> vs = g.getVecteurSommet(listeSommet);

  if(!listeSommet.empty()){
    qDebug()<<"qdebug "<<listeSommet;
    for(int i=0; i<vs.size();++i){
      pair<vector<vector<int>>, vector<int>> res = calcul_Bellman(g.conversion_vers_Matrice_adj(), vs[i]);


      string str = "Appliqué sur sommet :"+to_string(vs[i].getID())+"<br>";
      vector<int> dP = res.second;
      str = str+"Distance de "+to_string(vs[i].getID())+" à i : <br>";
      for(int j=0;j<dP.size();++j){
        if(dP[j] != 999999999){
          str = str+to_string(dP[j])+", ";
        }
        else{
          str =str + "infini, ";
        }
      }
      vector<vector<int>> pP = res.first;
      for(int k=0; k<pP.size();++k){
        str = str + "<br> Le chemin pour aller de "+to_string(vs[i].getID())+" à "+ to_string(k)+"<br>";
        for(int l=0;l<pP[k].size();++l){
          str = str+to_string(pP[k][l])+", ";
        }
      }
      printConsole("Ford_Bellman", str);
    }
  }
  else{
    printConsole("Ford_Bellman", "Pas de sommets selectionnés");

  }

}
void MainWindow::Floyd_Warshall(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  pair<Matrice, Matrice> res = calcul_Floyd_Warshall(g.conversion_vers_Matrice_adj());
  string str = "Matrice de poids :<br>";
  Matrice pP = res.first;
  for(int i = 0; i < pP.gettV(); i++){
    for(int j = 0; j < pP.gettE(); j++){
      if(pP.getTab()[i][j] != 999999999){
        str = str + to_string(pP.getTab()[i][j]) + " ";
      }
      else{
        str = str + "I" + " ";
      }
    }
    str = str + "<br>" ;
  }
  str = str + "Matrice parent :<br>";
  pP = res.second;
  for(int i = 0; i < pP.gettV(); i++){
    for(int j = 0; j < pP.gettE(); j++){
      if(pP.getTab()[i][j] != 999999999){
        str = str + to_string(pP.getTab()[i][j]) + " ";
      }
      else{
        str = str + "I" + " ";
      }
    }
    str = str + "<br>" ;
  }
  printConsole("Floyd_Warshall", str);

}
void MainWindow::Degr_sortant(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<Sommet> vs = g.getVecteurSommet(listeSommet);
  for(int i=0; i<vs.size();++i){
    int res = calcul_degres_sortant(vs[i]);
    string str = "Le sommet "+to_string(vs[i].getID())+" a un degrès sortant de "+to_string(res);
    printConsole("Degres sortant", str);

  }
}
void MainWindow::Degr_entrant(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();

  for(int i=0; i<listeSommet.size();++i){
    int res = calcul_degres_entrant(g.conversion_vers_Matrice_adj(), listeSommet[i]);
    string str = "Le sommet "+to_string(listeSommet[i])+" a un degrès entrant de "+to_string(res);
    printConsole("Degres entrant", str);

  }
}
void MainWindow::Degrs_entrant_et_sortant(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<Sommet> vs = g.getVecteurSommet(listeSommet);
  for(int i=0; i<vs.size();++i){
    pair<int, int> res = calcul_degres_entrant_sortant(g.conversion_vers_Matrice_adj(),vs[i]);
    string str = "Le sommet "+to_string(vs[i].getID())+" a un degrès entrant de "+to_string(res.first)+" et un degrès sortant de "+to_string(res.second);
    printConsole("Degres entrant et sortant", str);

  }
}
void MainWindow::Coloration_de_graphe(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  vector<int> color = coloration_Graphe(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine());
  QList<QGraphicsItem*> listS = sceneAcolor->items();
  vector<QColor> couleurs;

  int tmpC;
  for(int k=0;k<listS.size();++k){
    couleurs.push_back(QColor(0,0,0));
  }
  for(int i=0;i<listS.size();++i){
    if(listS[i]->data(0) == "Sommet"){
      QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
      tmpC = color[QS_->getID()];
      if(couleurs[tmpC] == QColor(0,0,0)){
        QRandomGenerator qrg(time(NULL)*i);
        couleurs[tmpC] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
        QS_->setCoul(couleurs[tmpC]);
        QS_->update();
      }
      else{
        QS_->setCoul(couleurs[tmpC]);
        QS_->update();
      }
    }
  }
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
  printConsole("Coloration de graphe", "Graphe coloré");

}
void MainWindow::Determinaison_de_stables(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<vector<int>> res = stables_Graphe(g.conversion_vers_Matrice_adj());
  QList<QGraphicsItem*> listS = sceneAcolor->items();

  vector<QColor> couleurs;
  for(int i=0;i<res.size();++i){
    couleurs.push_back(QColor(0,0,0));
  }

  for(int i=0;i<res.size();++i){
    if(couleurs[i] == QColor(0,0,0)){
      QRandomGenerator qrg(34526*i);
      couleurs[i] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
    }
  }
  for(int n=0;n<res.size();++n){
    for(int j=0;j<res[n].size();++j){
      for(int k=0;k<listS.size();++k){
        if(listS[k]->data(0) == "Sommet"){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[k]);
          if(res[n][j] == QS_->getID()){
            QS_->setCoul(couleurs[n]);
            QS_->update();
          }
        }
      }
    }
  }
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
  printConsole("Détermination des stables", "Stables colorés");



}
void MainWindow::Determinaison_de_cliques(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<vector<int>> res = cliques_Graphe(g.conversion_vers_Matrice_adj());
  QList<QGraphicsItem*> listS = sceneAcolor->items();

  vector<QColor> couleurs;
  for(int i=0;i<res.size();++i){
    couleurs.push_back(QColor(0,0,0));
  }

  for(int i=0;i<res.size();++i){
    if(couleurs[i] == QColor(0,0,0)){
      QRandomGenerator qrg(34526*i);
      couleurs[i] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
    }
  }
  for(int n=0;n<res.size();++n){
    for(int j=0;j<res[n].size();++j){
      for(int k=0;k<listS.size();++k){
        if(listS[k]->data(0) == "Sommet"){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[k]);
          if(res[n][j] == QS_->getID()){
            QS_->setCoul(couleurs[n]);
            QS_->update();
          }
        }
      }
    }
  }
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
  printConsole("Détermination des cliques", "Cliques colorés");
}
void MainWindow::Voisins_de_sommets(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<int> voisins;
  for(int i = 0; i<listeSommet.size();++i){
    voisins = voisin_sommet(g.conversion_vers_Matrice_adj(), listeSommet[i]);
    string str = "Le sommet "+to_string(listeSommet[i])+" a comme voisin(s) ";

    for(int j=0;j<voisins.size();++j){
      str = str + to_string(voisins[j]) + " ";
    }
    printConsole("Voinsins de sommet", str);
  }
}
void MainWindow::Gestion_de_flots(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  if(listeSommet.size()==2){
    int source = listeSommet[0];
    int puit = listeSommet[1];
    int res = gestion_flots(g, source, puit);
    printConsole("Gestion de flot", "Le flot maximum pour aller de "+to_string(source) +" à "+to_string(puit) +" est de "+to_string(res));
  }
  else{
    printConsole("Gestion de flot", "Vous avez selectionné trop ou pas assez de sommets");
  }
}
void MainWindow::Creer_un_graphe_dordonnancement(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Ordonnancement";
  int f;

  ordoCreate*mMyNewWindow = new ordoCreate(); // Be sure to destroy your window somewhere
  f = mMyNewWindow->exec();
  if(f){
    vector<pert_row> donnee = mMyNewWindow->getRes();

    donnee = calcul_posterite(donnee);

    Graphe p = pert(donnee);
    qDebug()<<"hey";
    vector<Sommet> ls =  p.getListe_Sommets();
    for(int g=0;g<ls.size();++g){
      QRandomGenerator qrg(g*1200);
      int si = ls.size();
      if(g == 1){
        ls[g].setPosX(100+qrg.bounded((si-1)*100,si*100)*si);
        ls[g].setPosY(100+g*200);
      }
      ls[g].setPosX(100+qrg.bounded((g-1)*100,g*100)*g);
      ls[g].setPosY(100+g*200);
    }
    p.setListe_Sommet(ls);

    zoneDessin->setGraphe_dessine(p);
    ui->tabWidget->addTab(tab,str);

    printConsole("Ordonnancement", "Création du graphe d'ordonnancement");
  }
  else{
    printConsole("Ordonnancement", "Une erreur a été detectée lors de la création du graphe d'ordonnancement");

  }
  delete mMyNewWindow;

}

void MainWindow::Arborescence(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Arborescence "+ui->tabWidget->tabText(ui->tabWidget->currentIndex());

  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g = arborescence(g);
  vector<Sommet> ls =  g.getListe_Sommets();
  if(ls[0].getID()==-1){
    printConsole("Arborescence", "Impossible de trouver une arborescence");

  }
  else{
    for(int g=0;g<ls.size();++g){
      QRandomGenerator qrg(g*1200);

      ls[g].setPosX(100+qrg.bounded(-100,100)*g);
      ls[g].setPosY(100+g*200);
    }
    g.setListe_Sommet(ls);
    zoneDessin->setGraphe_dessine(g);
    ui->tabWidget->addTab(tab,str);

    printConsole("Arborescence", "Création de l'arborescence du graphe courant");
  }
}
void MainWindow::AntiArborescence(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Anti_arborescence "+ui->tabWidget->tabText(ui->tabWidget->currentIndex());

  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g = anti_arborescence(g);
  vector<Sommet> ls =  g.getListe_Sommets();
  if(ls[0].getID()==-1){
    printConsole("Anti_arborescence", "Impossible de trouver une anti arborescence");

  }
  else{
    for(int g=0;g<ls.size();++g){
      QRandomGenerator qrg(g*1200);

      ls[g].setPosX(100+qrg.bounded(-100,100)*g);
      ls[g].setPosY(100+g*200);
    }
    g.setListe_Sommet(ls);
    zoneDessin->setGraphe_dessine(g);
    ui->tabWidget->addTab(tab,str);

    printConsole("Anti_arborescence", "Création de l'anti arborescence du graphe courant");
  }
}
void MainWindow::Recherche_de_la_connexite(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  int res = connexite(g.conversion_vers_Matrice_adj());
  if (res) printConsole("Connexite", "Graphe connexe");
  else printConsole("Connexite", "Graphe non-connexe");

}
void MainWindow::Trouver_chaine_eulerienne(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<vector<int>> res = chaine_eulerienne(g.conversion_vers_Matrice_adj());
  QList<QGraphicsItem*> listS = sceneAcolor->items();

  if(!res.empty()){
    vector<QColor> couleurs;
    for(int i=0;i<res.size();++i){
      couleurs.push_back(QColor(0,0,0));
    }

    for(int i=0;i<res.size();++i){
      if(couleurs[i] == QColor(0,0,0)){
        QRandomGenerator qrg(34526*i);
        couleurs[i] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
      }
    }
    for(int n=0;n<res.size();++n){
      for(int j=0;j<res[n].size();++j){
        for(int k=0;k<listS.size();++k){
          if(listS[k]->data(0) == "Sommet"){
            QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[k]);
            if(res[n][j] == QS_->getID()){
              QS_->setCoul(couleurs[n]);
              QS_->update();
            }
          }
        }
      }
    }
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
    printConsole("Chaine eulérienne", "Chaines colorées");

    string str0 = "Les sommets composant la chaines sont dans l'ordre :<br>";
    for(int u=0; u<res[0].size();++u){
      str0 = str0 + to_string(res[0][u])+ " ";
    }
    printConsole("Chaine eulérienne", str0);
  }
  else{
    printConsole("Chaine eulérienne", "Pas de chaines trouvable");
  }

}
void MainWindow::Trouver_chaine_hamiltonienne(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<vector<int>> res = chaine_hamiltonienne(g.conversion_vers_Matrice_adj());
  QList<QGraphicsItem*> listS = sceneAcolor->items();

  if(!res.empty()){
    vector<QColor> couleurs;
    for(int i=0;i<res.size();++i){
      couleurs.push_back(QColor(0,0,0));
    }

    for(int i=0;i<res.size();++i){
      if(couleurs[i] == QColor(0,0,0)){
        QRandomGenerator qrg(34526*i);
        couleurs[i] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
      }
    }
    for(int n=0;n<res.size();++n){
      for(int j=0;j<res[n].size();++j){
        for(int k=0;k<listS.size();++k){
          if(listS[k]->data(0) == "Sommet"){
            QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[k]);
            if(res[n][j] == QS_->getID()){
              QS_->setCoul(couleurs[n]);
              QS_->update();
            }
          }
        }
      }
    }
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
    printConsole("Chaine hamiltonienne", "Chaines colorées");

    string str0 = "Les sommets composant la chaines sont dans l'ordre :<br>";
    for(int u=0; u<res[0].size();++u){
      str0 = str0 + to_string(res[0][u])+ " ";
    }
    printConsole("Chaine hamiltonienne", str0);

  }
  else{
    printConsole("Chaine hamiltonienne", "Pas de chaines trouvable");
  }
}
void MainWindow::Postier_chinois(){
  QGraphicsScene* sceneAcolor = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getScene();
  vector<int> color = postier_chinois(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().conversion_vers_Matrice_adj());
  QList<QGraphicsItem*> listS = sceneAcolor->items();
  vector<QColor> couleurs;
  QRandomGenerator qrg(1200);
  if(!color.empty()){
      int tmpC;
      for(int k=0;k<listS.size();++k){
        couleurs.push_back(QColor(0,0,0));
      }
      for(int i=0;i<listS.size();++i){
        if(listS[i]->data(0) == "Sommet"){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
          tmpC = color[QS_->getID()];
          if(couleurs[tmpC] == QColor(0,0,0)){
            couleurs[tmpC] = QColor(qrg.bounded(1,255),qrg.bounded(1,255),qrg.bounded(1,255));
            QS_->setCoul(couleurs[tmpC]);
            QS_->update();
          }
          else{
            QS_->setCoul(couleurs[tmpC]);
            QS_->update();
          }
        }
      }
      ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setScene(sceneAcolor);
      printConsole("Postier chinois", "Graphe coloré");
  }
  else{
    printConsole("Postier chinois", "Problème non resolvable sur ce graphe.");

  }

}
void MainWindow::Voyageur_de_commerce(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<Sommet> ls = g.getListe_Sommets();
  vector<int> vils, res;
  string str;
  for(int i=0;i<ls.size();++i){
    vils.push_back(ls[i].getID());
  }
  res = voyageur_de_commerce(vils, g.conversion_vers_Matrice_adj());
  if(!res.empty()){

    str = "Chemin du cycle du plus court chemin :<br>";
    for(int i=0;i<res.size();++i){
      str = str + to_string(res[i]) + " ";
    }
    printConsole("Voyageur_de_commerce", str);

  }
  else{
    printConsole("Voyageur_de_commerce", "Exécution du voyageur de commerce échouée");

  }
}

void MainWindow::Documentation(){
  QMessageBox msgBox;
  msgBox.setText("<a href='../../../../../doc/html/index.html'>Documentation</a>");
  msgBox.exec();
}
void MainWindow::Github(){
  QMessageBox msgBox;
  msgBox.setText("<a href='https://github.com/gnouf1/Projet-S6'>Depôt github</a>");
  msgBox.exec();
}

void MainWindow::extraireSousGraphe(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<int> listeSelect = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list(),
  listeIDArc_nec;
  if(!listeSelect.empty()){
    QString text = QInputDialog::getText(this, tr("Nouveau graphe"),
    tr("Nom du graphe :"), QLineEdit::Normal);
    string etiq = "Graphe extrait";
    if (text != "") etiq = text.toStdString();
    Graphe g_extract(etiq);
    vector<Arc> listeArc = g.getListe_Arcs();
    vector<Sommet> vgs = g.getVecteurSommet(listeSelect);


    for(int i=0;i<listeArc.size();++i){
      int flag_dep = 0, flag_arr = 0;
      for(int j = 0; j<listeSelect.size();++j){ // id départ
        if(listeSelect[j] == listeArc[i].getIDDepart()){
          flag_dep = 1;
        }
      }
      for(int j = 0; j<listeSelect.size();++j){ // id arrive
        if(listeSelect[j] == listeArc[i].getIDArrive()){
          flag_arr = 1;
        }
      }
      if(flag_arr && flag_dep){
        listeIDArc_nec.push_back(listeArc[i].getID());
      }
    }
    qDebug()<<"listeIDArc_nec"<<listeIDArc_nec;
    for(int i = 0; i<vgs.size();++i){ // Ajoute les sommets
      // g_extract.ajout_Sommet(vgs[i].getID(), vgs[i].getPosX(), vgs[i].getPosY());
      g_extract.ajout_Sommet(i, vgs[i].getPosX(), vgs[i].getPosY());
      vector<Sommet> ls0 = g_extract.getListe_Sommets();
      ls0[i].setEtiq(vgs[i].getEtiq());
      g_extract.setListe_Sommet(ls0);
    }

    for(int i=0;i<listeArc.size();++i){
      for(int j=0;j<listeIDArc_nec.size();++j){
        int idDep=-1, idArr=-1;
        if(listeArc[i].getID() == listeIDArc_nec[j]){
          // g_extract.ajout_Arc(listeArc[i].getIDDepart(), listeArc[i].getIDArrive());
          for(int k=0;k<vgs.size();++k){
            if(vgs[k].getID() == listeArc[i].getIDDepart()){
              idDep = k;
            }
          }
          for(int k=0;k<vgs.size();++k){
            if(vgs[k].getID() == listeArc[i].getIDArrive()){
              idArr = k;
            }
          }
        }
        if(idDep != -1 && idArr != -1) g_extract.ajout_Arc(idDep, idArr);
      }
    }

    QWidget *tab = new QWidget();
    tab->setObjectName(QStringLiteral("tab"));
    QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
    QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
    zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
    zoneDessin->setMinimumSize(QSize(575, 0));
    horizontalLayout_2->addWidget(zoneDessin);
    horizontalLayout->addLayout(horizontalLayout_2);

    zoneDessin->setGraphe_dessine(g_extract);
    ui->tabWidget->addTab(tab,QString::fromStdString(etiq));
    printConsole("Extraction", "Graphe extrait");
  }
  else{
    printConsole("Extraction", "L'extraction de graphe a échouée");

  }
}
void MainWindow::arrangerSommets(){
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->placementSommets();
  printConsole("Arranger sommets", "Les sommets ont été éloignés les uns des autres");

}

void MainWindow::fermer_graphe(){
  ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
  printConsole("Fermer graphe", "Onglet fermé");

}
void MainWindow::DBEselection(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 1);
    qDebug()<<"selection";
  }
}
void MainWindow::DBEaddSommet(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 2);
    qDebug()<<"addS";
  }
}
void MainWindow::DBEaddArc(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 3);
    qDebug()<<"addA";
  }
}
void MainWindow::DBEdeleteSommet(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 4);
    qDebug()<<"delS";
  }
}
void MainWindow::DBEdeleteArc(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 5);
    qDebug()<<"delA";

  }
}
