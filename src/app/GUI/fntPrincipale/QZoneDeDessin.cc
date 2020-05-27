#include "QZoneDeDessin.hh"

QZoneDeDessin::QZoneDeDessin(QWidget *parent_) : QGraphicsView(parent_), graphe_dessine("EMPTY_GRAPH"){
vector<int> a{};
this->selected_list = a;
this->sc = new QGraphicsScene;
QGraphicsView::setScene(sc);

}

QZoneDeDessin::~QZoneDeDessin(){
  delete this->sc;
}

vector<int> QZoneDeDessin::getSelected_list() const{return this->selected_list;}
Graphe QZoneDeDessin::getGraphe_dessine() const{return this->graphe_dessine;}
QGraphicsScene* QZoneDeDessin::getScene() const{return this->sc;}

void QZoneDeDessin::setSelected_list(vector<int> sl){this->selected_list = sl;}
void QZoneDeDessin::setGraphe_dessine(Graphe g){
  this->graphe_dessine = g;
  afficher_Graphe(g);
}

void QZoneDeDessin::setScene(QGraphicsScene * scene){
  this->sc = scene;
  QGraphicsView::setScene(scene);
}
void QZoneDeDessin::placementSommets(){
  Graphe G = Graphe(this->getGraphe_dessine());
  vector<Sommet> liste_Sommets = this->getGraphe_dessine().getListe_Sommets();
  int stable = 0;
  float newx,newy;
  vector<QSommet*> QS;
  vector<vector<int>> SommetCo; // id des sommet connecté au sommet i
  Matrice MG = Matrice(this->graphe_dessine, 0);
  // recuperation des QSommet
  QList<QGraphicsItem*> listS = this->items();

  for(int i=0; i< listS.size(); ++i){
     QS.push_back(qgraphicsitem_cast<QSommet*>(listS[i]));
  }
  for(int i=0; i< listS.size(); ++i){
    if(QS[i]->data(0) != "Sommet"){
      QS.erase(QS.begin()+i);
      i--;
    }
  }
  vector<int> vide;
  for(int inc = 0; inc < QS.size(); inc++){
    SommetCo.push_back(vide);
  }

  // on ajoute les sommet connecter au sommet i dans SommetCo

    for( int k = 0; k < this->getGraphe_dessine().getListe_Arcs().size(); k++){
      int arr = this->getGraphe_dessine().getListe_Arcs()[k].getIDArrive();
      int dep = this->getGraphe_dessine().getListe_Arcs()[k].getIDDepart();
      SommetCo[dep].push_back(arr);
      SommetCo[arr].push_back(dep);
      }

  int i,j;
  // debut de la fonction
  while(stable == 0){
     // on met stable a 0 si un sommet est superposés apres leurs déplacement
     stable = 1;
    for(i = 0; i < QS.size(); i++){ // on parcours tout les sommet
      float ft = 0.0; // ensemble des force a appliquer au vecteur de direction
      // on parcours les sommets autre que i
      for(j = 0; j < QS.size(); j++){
        pair<int, int> degi = calcul_degres_entrant_sortant(MG,liste_Sommets[QS[i]->getID()]);
        pair<int, int> degj = calcul_degres_entrant_sortant(MG,liste_Sommets[QS[j]->getID()]);
        if(i != j){

          // on verifie si le sommet j est connecter ou non au sommet i
            if(SommetCo[i].size() != 0){
              if((std::find(SommetCo[i].begin(),SommetCo[i].end(), j ) != SommetCo[i].end()) || j == SommetCo[i].at(SommetCo[i].size()-1)){
                // si j est connecter alors la force d'attraction est calculé;
                if(distanceForce(*QS[i], *QS[j]) > 0){ // si ils ne sont pas superposés ils s'attire et ce repousse
                   ft = log(distanceForce(*QS[i], *QS[j])*100 - 10.0*(degi.first + degi.second + 1.0)*(degj.first + degj.second + 1.0)/distanceForce(*QS[i], *QS[j]));
                }
                else if(distanceForce(*QS[i], *QS[j]) < 0){ // si ils sont superposés ils se repoussent
                   ft = 0-10.0*(degi.first + degi.second + 1.0 )*(degj.first + degj.second + 1.0 );
                }

                else ft = 0; // si ils sont placé cote a cote on ne les deplace pas
              newx = QS[i]->getPosX() + fmod(ft*(QS[j]->getPosX() - QS[i]->getPosX()), ((QS[j]->getPosX() - QS[i]->getPosX()) - (QS[i]->getRayon()*2)));
              newy = QS[i]->getPosY() + fmod(ft*(QS[j]->getPosY() - QS[i]->getPosY()), ((QS[j]->getPosY() - QS[i]->getPosY()) - (QS[i]->getRayon()*2)));
              }
            }

          // si i et j ne son pas connecter il n'y a pas d'attraction
            if(distanceForce(*QS[i], *QS[j]) > 0){ //force de repulsion faible si ils ne sont pas superposés
               ft = 0-1.0*((degi.first + degi.second + 1.0)*(degj.first + degj.second + 1.0))/distanceForce(*QS[i], *QS[j]) ;

            }
            else if(distanceForce(*QS[i], *QS[j]) < 0){ //force de repulsion forte si ils sont superposés
               ft = 0-10.0*((degi.first + degi.second + 1.0)*(degj.first + degj.second + 1.0));


            }
            else ft = 0; // cote a cote et ne bouge pas
            newx = (QS[i]->getPosX() + fmod(ft*(QS[j]->getPosX() - QS[i]->getPosX()),100));
            newy = (QS[i]->getPosY() + fmod(ft*(QS[j]->getPosY() - QS[i]->getPosY()),100));

        }
        // si ils sont l'un sur l'autre le vecteur de direction est aléatoire
        if ((QS[i]->getPosX() == QS[j]->getPosX()) && (QS[i]->getPosY() == QS[j]->getPosY())){
          newx = QS[i]->getPosX() + ft*pow(-1,rand()%2);
          newy = QS[i]->getPosY() + ft*pow(-1,rand()%2);


        }
        // on applique les nouvelles coordonnés du point a la liste_Sommets et au la liste de QSommet

          QS[i]->setPosX(newx);
          QS[i]->setPosY(newy);

      }

    }
    // on regarde si des point ce superpose encore
    for(i = 0; i < QS.size(); i++){
      liste_Sommets[QS[i]->getID()].setPosX(QS[i]->getPosX());
      liste_Sommets[QS[i]->getID()].setPosY(QS[i]->getPosY());
      for(j = 0; j < QS.size(); j++){
        if(i != j){
          // si les point i et j se superpose le graphe n'est pas stable et on recommence l'algorithme
          if(sqrt(pow(QS[i]->getPosX()-QS[j]->getPosX(),2) + pow(QS[i]->getPosY()-QS[j]->getPosY(),2)) < (QS[i]->getRayon()*2)){
            stable = 0;
          }
        }
      }
    }
  }
  // on applique la liste de sommet au graphe et on le redessine dans la scene.
  G.setListe_Sommet(liste_Sommets);
  this->sc->clear();
  this->setGraphe_dessine(G);
}




int QZoneDeDessin::distanceForce(QSommet a, QSommet b){ // calcul la distance en prenant en compte le rayon d'un sommet
  int res;
  res = sqrt(pow(b.getPosX() - a.getPosX() ,2)+pow(b.getPosY() - a.getPosY() ,2)) - a.getRayon() -b.getRayon();
  return res;

}

pair<int,int> QZoneDeDessin::distance(QSommet a, QSommet b){
  pair<int,int> res;
  res.first = fabs(a.getPosX() - b.getPosX());
  res.second = fabs(a.getPosY() - b.getPosY());
  return res;

}

void QZoneDeDessin::addSelect_Sommet(int ID){
  vector<int> tmp;
  int flag = 0;
  tmp = this->selected_list;
  for(int i = 0;i<tmp.size();++i){
    if(tmp[i] == ID){
      flag = 1;
    }
  }
  if (!flag){
    tmp.push_back(ID);
    this->selected_list = tmp;
  }
}

void QZoneDeDessin::deleteSelect_Sommet(int ID){
  vector<int> tmp, res;
  tmp = this->selected_list;
  for(int i = 0; i<tmp.size();++i){
    if(tmp[i] != ID){
      res.push_back(tmp[i]);
    }
  }
  this->selected_list = res;
}

void QZoneDeDessin::razSelected_list(){
  this->selected_list = {};
}

void QZoneDeDessin::afficher_Sommet(Sommet s){
  QSommet *QS = new QSommet(s);
  QS->setVisible(1); // -
  for(int v=0;v<this->selected_list.size();++v){
    if(QS->getID() == this->selected_list[v]){
      QS->setSelect(1);
    }
  }
  this->sc->addItem(QS);
  QS->setPos(QS->getPosX(),QS->getPosY());
}

void QZoneDeDessin::afficher_arc(Arc a){
  int IDa, IDb, dblFlag = 0;
  IDa = a.getIDDepart();
  IDb = a.getIDArrive();
  QPoint posA, posB;
  QPointF posRef;
  QArc *QA = new QArc(a);

  QList<QGraphicsItem*> listS = items();
  for(int i=0; i< listS.size(); ++i){
    QSommet* QS = qgraphicsitem_cast<QSommet*>(listS[i]);
    if(QS->data(0) == "Sommet"){
      if(QS->getID() == IDa){ //On cherche le sommet de départ
        ++dblFlag;
        posA.setX(QS->getPosX());
        posA.setY(QS->getPosY());
        posRef.setX(QS->x());
        posRef.setY(QS->y());
      }
      else if (QS->getID() == IDb){ // On cherche le sommet d'arrivée
        ++dblFlag;
        posB.setX(QS->getPosX());
        posB.setY(QS->getPosY());
      }
    }
  }
  if (dblFlag < 2){
    qDebug() <<"--> SOMMETS NON TROUVES ID QARC :" <<QA->getID();
    qDebug() << "dbFlag : " <<dblFlag;
    qDebug() << "QA :" <<QA;
  }
  else{
    this->sc->addItem(QA);
    QA->setPos(posRef);
    QA->setPosXA(posA.x());
    QA->setPosYA(posA.y());
    QA->setPosXB(posB.x());
    QA->setPosYB(posB.y());
    QA->setVisible(1);
    qDebug()<<QA->sceneBoundingRect();
  }

}

void QZoneDeDessin::afficher_Graphe(Graphe G){
  this->sc->clear();
  vector<Arc> La = G.getListe_Arcs();
  vector<Sommet> Ls = G.getListe_Sommets();

  for(int i =0; i<Ls.size(); ++i) afficher_Sommet(Ls[i]);

  for(int i =0; i<La.size(); ++i) afficher_arc(La[i]);
}
void QZoneDeDessin::mouseDoubleClickEvent(QMouseEvent *e){
if (itemAt(e->pos())->data(0) == "Sommet"){
  QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
  Sommet som = graphe_dessine.getVecteurSommet(vector<int>{QS->getID()})[0];

  modifObjet* mdo = new modifObjet();
  mdo->setEtq(QString::fromStdString(som.getEtiq()));
  mdo->setListCU(som.getCU());
  if(mdo->exec()){
    som.setCU(mdo->getCU());
    som.setEtiq(mdo->getetq().toStdString());
    vector<Sommet> ls = graphe_dessine.getListe_Sommets();
    for(int i=0;i<ls.size();++i){
      if(ls[i].getID() == som.getID()){
        ls[i] = som;
      }
    }
    graphe_dessine.setListe_Sommet(ls);
  }
}
else if (itemAt(e->pos())->data(0) == "Arc"){
  QArc* QA = qgraphicsitem_cast<QArc*>(itemAt(e->pos()));
  vector<Arc> la = graphe_dessine.getListe_Arcs();
  Arc a(0,0,0);
  for(int i=0;i<la.size();++i){
    if(la[i].getID() == QA->getID()){
      a = la[i];
    }
  }
  modifObjet* mdo = new modifObjet();
  mdo->setEtq(QString::fromStdString(a.getEtiq()));
  mdo->setListCU(a.getCU());
  if(mdo->exec()){
    a.setCU(mdo->getCU());
    a.setEtiq(mdo->getetq().toStdString());

    for(int i=0;i<la.size();++i){
      if(la[i].getID() == a.getID()){
        la[i] = a;
      }
    }
    graphe_dessine.setListe_Arc(la);
  }

}
}
void QZoneDeDessin::mousePressEvent(QMouseEvent * e){
  int dbe = property("DBE").toInt();

  vector<Sommet> ls1 = graphe_dessine.getListe_Sommets();
  QList<QGraphicsItem*> listS0 = items();
  for(int i=0; i< listS0.size(); ++i){
    if(listS0[i]->data(0) == "Sommet"){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(listS0[i]);
      QS->setX(QS->x());
      QS->setY(QS->y());
      QS->setPosX(QS->x());
      QS->setPosY(QS->y());

      QS->update();

      for(int l=0;l<ls1.size();++l){
        if(ls1[l].getID() == QS->getID()){
          ls1[l].setPosX(QS->getPosX());
          ls1[l].setPosY(QS->getPosY());
        }
      }

    }
  }
  graphe_dessine.setListe_Sommet(ls1);
  setGraphe_dessine(graphe_dessine);

  QGraphicsView::mousePressEvent(e);
  if(dbe == 1){
    //select
    if (itemAt(e->pos())->data(0) == "Sommet"){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
      if(QS->getSelect()){
        QS->setSelect(0);
        deleteSelect_Sommet(QS->getID());
      }
      else{
        addSelect_Sommet(QS->getID());
        QS->setSelect(1);
      }
      QS->update();
      qDebug()<<selected_list;
    }
    else{
      QList<QGraphicsItem*> listS = items();
      for(int i = 0;i<selected_list.size();++i){
        for(int i=0; i< listS.size(); ++i){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
          if(QS_->data(0) == "Sommet"){
            if(QS_->getSelect() != 0){
              QS_->setSelect(0);
              QS_->update();
            }
          }
        }
      }
      razSelected_list();
    }
  }
  else if(dbe == 2){
    //add sommet
    if (!(itemAt(e->pos())->data(0) == "Sommet" || itemAt(e->pos())->data(0) == "Arc")){
      dessiner_sommet(e->x(), e->y());
    }

  }
  else if(dbe == 3){
    // add arc

    if (!(itemAt(e->pos())->data(0) == "Sommet" || itemAt(e->pos())->data(0) == "Arc")){
      QList<QGraphicsItem*> listS = items();
      for(int i = 0;i<selected_list.size();++i){
        for(int i=0; i< listS.size(); ++i){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
          if(QS_->data(0) == "Sommet"){
            if(QS_->getSelect() != 0){
              QS_->setSelect(0);
              QS_->update();
            }
          }
        }
      }
      razSelected_list();
    }
    else if (itemAt(e->pos())->data(0) == "Sommet"){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
      QS->setSelect(1);
      QS->update();
      addSelect_Sommet(QS->getID());
      if (selected_list.size()==2){
        QList<QGraphicsItem*> listS = items();
        for(int i = 0;i<selected_list.size();++i){
          for(int i=0; i< listS.size(); ++i){
            QSommet* QSb = qgraphicsitem_cast<QSommet*>(listS[i]);
            if(QSb->data(0) == "Sommet"){
              if(QSb->getID() == selected_list[0]){
                dessiner_arc(QSb->getPosX(), QSb->getPosY(), QS->getPosX(), QS->getPosY());
                razSelected_list();

                QS->setSelect(0);
                QSb->setSelect(0);
                QS->update();
                QSb->update();
              }
            }
          }
        }
      }
    }
  }
  else if(dbe == 4){
    //del sommet
    QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
    vector<int> arc_sor, arc_ent;
    vector<Arc> ListeA = graphe_dessine.getListe_Arcs();
    vector<Sommet> vS = graphe_dessine.getListe_Sommets();

    if (QS->data(0) == "Sommet"){
      this->sc->removeItem(QS); // On retire l'item sommet graphique

      for(int i = 0; i<vS.size();++i){ // On cherche les arcs sortants du sommet
        if(QS->getID() == vS[i].getID()){
          arc_sor = vS[i].getVecArc();
        }
      }
      qDebug()<<"sortant :"<<arc_sor;

      for(int i =0;i<ListeA.size();++i){ //On trouve les IDs des arcs entrants
        if(QS->getID() == ListeA[i].getIDArrive()){
          arc_ent.push_back(ListeA[i].getID());
        }
      }
      qDebug()<<"Entrant :"<<arc_ent;

      QList<QGraphicsItem*> listS = items();
      for(int i=0; i< listS.size(); ++i){
        if (listS[i]->data(0) == "Arc"){
          QArc* QA = qgraphicsitem_cast<QArc*>(listS[i]);
          for(int j= 0; j<arc_sor.size();++j){
            if(QA->getID() == arc_sor[j]){ // On supprime les arcs sortants graphiquement
              this->sc->removeItem(QA);
            }
          }
          for(int k=0;k<arc_ent.size();++k){ // On supprime les arcs entrants graphiquement
            if(QA->getID() == arc_ent[k]){
              this->sc->removeItem(QA);
            }
          }
        }
      }

      for(int j = 0; j<arc_sor.size();++j){ // On supprime les arcs sortants du graphe
        graphe_dessine.supprimer_Arc(arc_sor[j]);
      }

      for(int j = 0; j<arc_ent.size();++j){ // On supprime les arcs sortants du graphe
        graphe_dessine.supprimer_Arc(arc_ent[j]);
      }

      graphe_dessine.supprimer_Sommet(QS->getID()); // On supprime le sommet du graphe
      setGraphe_dessine(graphe_dessine);
    }
  }
  else if(dbe == 5){
    //del arc
    QArc* QA = qgraphicsitem_cast<QArc*>(itemAt(e->pos()));
    if(QA->data(0) == "Arc"){
      this->sc->removeItem(QA);
      graphe_dessine.supprimer_Arc(QA->getID());
    }
  }

sc->update();
}
void QZoneDeDessin::dessiner_sommet(int x, int y){
  Graphe Gtmp = graphe_dessine;
  int Sid;
  Sid = Gtmp.ajout_Sommet(Gtmp.getListe_Sommets().size(), x, y);
  afficher_Sommet(Gtmp.getListe_Sommets()[Sid]);
  graphe_dessine = Gtmp;

}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){
  Graphe Gtmp = graphe_dessine;
  int Aid;
  QSommet* qsA = qgraphicsitem_cast<QSommet*>(itemAt(mapFromScene(QPointF (xA,yA))));
  QSommet* qsB = qgraphicsitem_cast<QSommet*>(itemAt(mapFromScene(QPointF (xB,yB))));
  qDebug()<<qsA->getID();
  qDebug()<<qsB->getID();
  Aid = Gtmp.ajout_Arc(qsA->getID(), qsB->getID());
  afficher_arc(Gtmp.getListe_Arcs()[Aid]);
  graphe_dessine = Gtmp;
}
