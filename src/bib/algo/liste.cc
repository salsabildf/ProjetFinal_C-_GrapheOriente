#include "liste.hh"
#include <cstdio>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <QDebug>

pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){
  vector<int> dist;
  vector<int> file;
  vector<int> pred;
  vector<vector<int>> liste_res;
  pair <vector<vector<int>>,vector<int>> res;

  if(M.getType()!=0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
    for(int i=0;i<M.gettV();i++){
        dist.push_back(INFINI);
        pred.push_back({-1});
     }
     dist[S.getID()] = 0;

    int cmpA = 0,cmpW = 0;
    for(int i=0;i<M.gettV();i++){     // Nb Arcs
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j])
        cmpA++;//renvoie le nombre d'arcs
      }
    }
    file.push_back(S.getID());
    while(file[0]!=-1 && cmpW<cmpA){ // Bellman (poids des chemins)
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[file[0]][j]!=0){
          if(dist[j] > (dist[file[0]] + M.getTab()[file[0]][j])){
            dist[j] = dist[file[0]] + M.getTab()[file[0]][j];
            file.push_back(j);
            pred[j] = file[0];
          }
        }
      }
      if(file.size()==1){
        file[0]=-1;
      }
      else {
        file.erase(file.begin());
      }
      cmpW++;
    }

    // Cycles négatifs
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          if(dist[j] > (dist[i] + M.getTab()[i][j])){
            dist[j] = dist[i] + M.getTab()[i][j];
          }
        }
      }
    }
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          if(dist[j] > (dist[i] + M.getTab()[i][j])){
            qDebug()<< "dist[j]" <<dist[j] << " j " << j << "dist[i]" <<dist[i] << " i " << i << "tab i j" << M.getTab()[i][j];
            std::cout << "NEGATIVE CYCLE" << '\n';
            qDebug()<< "negative circle ";
            return res;
          }
        }
      }
    }
    // Liste prédécesseurs
    for(int i=0;i<pred.size();i++){
      if(pred[i] == -1){
        liste_res.push_back({S.getID()});
      }
      else if(pred[i]==S.getID()){
        liste_res.push_back({S.getID(),i});


      }
      else{
        int j = i;
        vector<int> tmp;
        vector<int> tmp2;
        while(j!=S.getID()){
          tmp.push_back(j);
          j = pred[j];
        }
        tmp.push_back(S.getID());
        tmp2.resize(tmp.size());
        for(int a=0;a<tmp.size();a++){  // Remet à l'endroit
          tmp2[a] = tmp[tmp.size()-a-1];
        }
        liste_res.push_back(tmp2);
      }
    }

    res.first = liste_res;
    res.second = dist;
    return res;
  }
}

//################# FLOYD Warshall  ######################
pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){
  //parcourt de la matrice d'adjacence
  if(M.getType()!=0){
    Matrice MP(M.gettV(),M.gettV(),2),MT(M.gettV(),M.gettV(),3);
    pair<Matrice,Matrice> res{MP,MT};
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res; //retour de pair<Matrice,Matrice> vide
  }
  else{
    //initialisation de MatriceParent
    Matrice MP(M.gettV(),M.gettV(),3);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          MP.modifTab(i,j,j);
        }
        else
        MP.modifTab(i,j,-1);// il n'y a pas de parent direct

      }
    }

    //init de Matrice de poids
    Matrice MT(M.gettV(),M.gettV(),2);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(i==j){
          MT.modifTab(i,j,0);
        }
        else if(M.getTab()[i][j]!=0){
          MT.modifTab(i,j,M.getTab()[i][j]);
        }
        else{
          MT.modifTab(i,j,INFINI);// il n'y a pas de chemin

        }

      }
    }
    for (int k = 0; k < M.gettV();k++) {
      for (int i = 0; i < M.gettV(); i++) {
        for (int j = 0; j < M.gettV(); j++) {

            if(MT.getTab()[i][j]> (MT.getTab()[i][k]+MT.getTab()[k][j])){
              MT.modifTab(i,j,MT.getTab()[i][k]+MT.getTab()[k][j]);
              MP.modifTab(i,j,MP.getTab()[i][k]);
            }
        }
      }
    }
    //création de la pair<Matrice,Matrice> res
    pair<Matrice,Matrice> res{MT,MP};
    return res;

  }
}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){
  if(Parent.getType()!=3){
    std::cout << "ERROR WRONG TYPE" << '\n';
    vector<int> res{-1};
    return res;
  }
  else{
    vector<int> res{deb};
    while(Parent.getTab()[deb][fin]!=fin){
      if(Parent.getTab()[deb][fin]!=-1){
        deb = Parent.getTab()[deb][fin];
        res.push_back(deb);

      }
      else{
        std::cout << "PAS DE CHEMIN" << '\n';
        vector<int> res{-2};
        return res;
      }
    }
    res.push_back(fin);
    return res;
  }
}

int calcul_degres_entrant(Matrice M, int id){

     /* déclare variable int vide  */
        int nb_entrant = 0;

    /* ittération sur le nombre de sommet de la matrice en paramètre */
        for (int i=0; i < M.gettV() ; i++){
            if (M.getTab()[i][id]) nb_entrant++;
         }
    return nb_entrant;
}

int calcul_degres_sortant(Sommet S){

      /* déclare variable int vide  */
        int nb_sortant = 0;

    /* ittération sur la taille du vecteur de sommet S, contenant les arcs sortants */
        for (int i=0;  i < S.getVecArc().size();  i++){
             nb_sortant ++;
         }
    return nb_sortant;
}

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S){
    pair<int,int> result( calcul_degres_entrant(M, S.getID()) , calcul_degres_sortant(S) );

     return result;
}

vector<int> coloration_Graphe(Graphe G){
    vector<int> res(G.getListe_Sommets().size());//vecteur qui contiendra l'ensemble des couleurs
    vector<Sommet> listeS= G.getListe_Sommets();
    vector<pair<int, Sommet>> L;//vecteur qui contient les Sommets non colorés ainsi que le nb de voisins
    Matrice M(G, 0);
    map<string, VectVal> map;
    pair<int, vector<int>> voisin;
    int s;
    VectVal v;
    v.type = 0;

    //On ajoute le premier sommet
    pair<int, int> tmp = calcul_degres_entrant_sortant(M, G.getListe_Sommets()[0]);
    pair<int, Sommet> t(tmp.first+tmp.second, G.getListe_Sommets()[0]);
    L.push_back(t);

    //on classe les sommets par ordre décroissant de degré
    for(int i=1; i<G.getListe_Sommets().size(); i++){
        tmp = calcul_degres_entrant_sortant(M, G.getListe_Sommets()[i]);
        t.first = tmp.first+tmp.second;
        t.second = G.getListe_Sommets()[i];
        for(int j=0; j<L.size(); j++){
            if(t.first > L[j].first){
                L.insert(L.begin()+j, t);
                break;
            }
            if(j == L.size()-1){
                L.push_back(t);
                break;
            }
        }
    }

    // AJOUTER DANS LE GRAPHE LA COULEUR

    res[L[0].second.getID()] = 1;
    L.erase(L.begin());
    map = G.getListe_Sommets()[0].getCU();
    map.insert(pair<string, VectVal>("couleur", v));
    G.getListe_Sommets()[0].setCU(map);

    while (!L.empty()) {

        //choix du sommet a colorer
        s=0;
        voisin = couleur_adjacente(L[s].second.getID(), res, M);

        for(int i=1; i<L.size(); i++){
            if(voisin.first < couleur_adjacente(L[i].second.getID(), res, M).first){
                s=i;
                voisin = couleur_adjacente(L[i].second.getID(), res, M);
            }
            else{
                if(voisin.first == couleur_adjacente(L[i].second.getID(), res, M).first){
                    if(L[s].first < L[i].first){
                        s=i;
                        voisin = couleur_adjacente(L[i].second.getID(), res, M);
                    }
                }
            }
        }
        //coloration du sommet
        v.valeur_entiere = 1;
        while (res[L[s].second.getID()] == 0) {
            if(voisin.first == 0){
                res[L[s].second.getID()] = v.valeur_entiere;
                map = G.getListe_Sommets()[s].getCU();
                map.insert(pair<string, VectVal>("couleur", v));
                G.getListe_Sommets()[s].setCU(map);
            }
            else{
                for(int i=0; i<voisin.second.size(); i++){
                    if(v.valeur_entiere<voisin.second[i]){
                        res[L[s].second.getID()] = v.valeur_entiere;
                        map = G.getListe_Sommets()[s].getCU();
                        map.insert(pair<string, VectVal>("couleur", v));
                        G.getListe_Sommets()[s].setCU(map);
                        break;
                    }else{
                        if(i == voisin.second.size()-1){
                            v.valeur_entiere += 1;
                            res[L[s].second.getID()] = v.valeur_entiere;
                            map = G.getListe_Sommets()[s].getCU();
                            map.insert(pair<string, VectVal>("couleur", v));
                            G.getListe_Sommets()[s].setCU(map);
                        }
                    }
                    v.valeur_entiere++;

                }

            }

        }
        //suppression du sommet de la liste des sommets non colorés
        L.erase(L.begin()+s);
    }

    return res;
}

pair<int, vector<int>> couleur_adjacente(int id, vector<int> v, Matrice M){
    vector<int> res;
    int r = 0;
    for (int i=0; i<M.gettV(); i++) {
        if(i!=id){
            if(M.getTab()[id][i]==1 && v[i]!=0){
                if(res.empty()){
                    res.push_back(v[i]);
                    r++;
                }
                else{
                    for(int j=0; j<res.size(); j++){
                        if(res[j]>v[i]){
                            res.insert(res.begin()+j, v[i]);
                            r++;
                            break;
                        }
                        if(res[j]==v[i]){
                            r++;
                            break;
                        }
                        if(j==res.size()-1){
                            res.push_back(v[i]);
                            r++;
                            break;
                        }
                }
                }
            }
            else{
                if(v[i]!=0 && M.getTab()[i][id]==1 ){
                    if(res.empty()){
                        res.push_back(v[i]);
                        r++;
                    }
                    else{
                        for(int j=0; j<res.size(); j++){
                            if(res[j]>v[i]){
                                res.insert(res.begin()+j, v[i]);
                                r++;
                                break;
                            }
                            if(res[j]==v[i]){
                                r++;
                                break;
                            }
                            if(j==res.size()-1){
                                res.push_back(v[i]);
                                r++;
                                break;
                            }
                        }
                    }
                }
            }
        }

    }
    return pair<int, vector<int>>(r, res);
}

vector<vector<int>> stables_Graphe(Matrice M){
    Graphe G(M);
    vector<int> colo = coloration_Graphe(G);

    vector<vector<int>> res;
    for(int i=0; i<colo.size(); i++){
        if(colo[i]<=res.size()){
            res[colo[i]-1].push_back(i);
        }
        else{
            vector<int>tmp;
            tmp.push_back(i);
            res.push_back(tmp);
        }
    }
    return res;
}

vector<vector<int>> cliques_Graphe(Matrice M){
    //inversion de la matrice (au sens d'un graphe non orienté)
    for(int i=0; i<M.gettV(); i++){
        for(int j=i+1; j<M.gettV(); j++){
            if(M.getTab()[i][j] == 0 && M.getTab()[j][i] == 0){
                M.modifTab(i, j, 1);
            }
            else{
                M.modifTab(i, j, 0);
                M.modifTab(j, i, 0);
            }
        }
    }
    return stables_Graphe(M);
}

vector<int> voisin_sommet(Matrice M, int ID){
     /* déclare variable vector vide  */
    vector<int> voisins;

     /* ittération sur le nombre de sommet de la matrice M  */
        for (int i=0; i < M.gettV() ; i++){
            if ( M.getTab()[ID][i] )  {
                voisins.insert(voisins.end(),i);
            }
        }
    return voisins;
}

int gestion_flots(Graphe G, int ID_source, int ID_puit){//fonction applicant l'algorithme d'Edmond Karp
  //############ Les variables #############

  vector<vector<int>> MG= Matrice(G,0).getTab();// Matrice d'adjacence du graphe
  vector<vector<int>> GR = MG;                  // Graphe residuel init à 0 (= MG pour init la taille)
  vector<vector<int>> Succ;                     // liste des successeurs init via MG
  vector<int> ListeParent ;                     // liste des parents d'un parcours bfs
  vector<int> CheminCourant;                    // chemin courant du bfs
  int FlotMax = 0;                              // variable contenant le flot maximum
  int flag=0;


  //######## Boucles d'initialisations ##########
  Succ.resize(MG.size()); //on init Succ au nombre de sommets du Graphe
  CheminCourant.resize(MG.size());    //init de Chemin courant en taille
  ListeParent.resize(MG.size());    //init de Liste parent en taille
  //cout << Succ.size() << " " << CheminCourant.size() << " " << ListeParent.size() << endl;
  for(int i=0;i<MG.size();i++){ // init des successeurs
    for(int j=0;j<MG.size();j++){
      if(MG[i][j]>0){   // Si il y a un arc de i a j
        Succ[i].push_back(j); // on ajoute j aux successeurs de i
        Succ[j].push_back(i);
      }
      GR[i][j]=0; // init du graphe résiduel à 0
    }
  }

  while(true){
    //########### Breadth first search (bfs) ##########
    int flot =0;  //calcul  d'un flot entre source et puits

    for(int i=0;i<ListeParent.size();i++){
      ListeParent[i] = -1;            // init de la valeur de chaque parent
    }
    for(int i=0;i<CheminCourant.size();i++){
      CheminCourant[i] = 0;            // init de la valeur du chemin courant
    }

    vector<int> file;
    queue<int> q;
    q.push(ID_source);
    ListeParent[ID_source] = -1;
    CheminCourant[ID_source] = INFINI;
    while(!q.empty()){
      flag = 0;
      int SA = q.front();
      q.pop();
      for(int i=0;i<Succ[SA].size();i++){
        int NEXT = Succ[SA][i];
        if(ListeParent[NEXT] == -1){
          if((MG[SA][NEXT] - GR[SA][NEXT]) > 0){
            ListeParent[NEXT] = SA;
            //calcul du min
            int min = CheminCourant[SA];
            if(min >(MG[SA][NEXT] - GR[SA][NEXT]))
            min = MG[SA][NEXT] - GR[SA][NEXT];
            //fin min
            CheminCourant[NEXT] = min ;
            if(NEXT == ID_puit){
              flag = 1; // flag permetant de sortir
              flot = CheminCourant[ID_puit];
              break; //on sort du for
            }
            q.push(NEXT);
          }
        }
      }//fin du for
      if(flag)break;//sor du while
    }
    //####### Gestion post bfs #########
    if(!flag){//Gestion de la sortie du bfs
      break; //sort du while
    }
    FlotMax += flot;  //ajout du flot au flot total
    int SA = ID_puit; //on part de la fin
    while(SA != ID_source){ // tant qu'on est pas à la source
      int PREV = ListeParent[SA]; // On prend l'ID du precedent du Sommet Actuel
      GR[PREV][SA] += flot; // on ajoute la flot au graphe residuel
      GR[SA][PREV] -= flot;
      SA = PREV;  // Sommet Actuel devient son precedent

    }
  }
  return FlotMax;

}



vector<pert_row> calcul_posterite(vector<pert_row> p){
  vector<pert_row> tmp = p;
  int ex;
  for(int i = 0; i<tmp.size(); i++){
    ex = tmp[i].taches_anterieures.size();
    for(int j = 0; j<tmp[i].taches_anterieures.size(); j++){
      for(int k = 0; k<tmp.size(); k++){
        if(tmp[i].taches_anterieures[j] == tmp[k].tache){
          tmp[k].taches_posterieures.push_back(tmp[i].tache);
          ex --;
        }
      }
    }
    if(ex != 0){
      cout<<"/* ERROR NON-EXISTENT TASK */"<<endl;
      return p;
    }
  }

  for(int i = 0; i<tmp.size(); i++){
    if(tmp[i].taches_anterieures.size() == 0){
      vector<int> v={tmp[i].tache};
      vector<int> suiv = tmp[i].taches_posterieures;
      while(!suiv.empty()){
        for(int j = 0; j<v.size(); j++){
            if(suiv[0] == v[j]){
                cout<<"/* ERROR SELF-PERPETUATING TASK *//*"<<endl;
                return p;
            }
        }
        for(int j = 0; j<tmp.size(); j++){

          if (tmp[j].tache == suiv[0]){
            for(int k = 0; k<tmp[j].taches_posterieures.size(); k++){
              int cmp = 0;
              for(int l=0; l<suiv.size(); l++){
                if(suiv[l] == tmp[j].taches_posterieures[k]){
                  cmp++;
                }
              }
              if(cmp==0){
                suiv.push_back(tmp[j].taches_posterieures[k]);
              }

            }
          }
        }

        v.push_back(suiv[0]);
        suiv.erase(suiv.begin());
      }

    }
  }

  return tmp;
}



Graphe pert(vector<pert_row> p){
    std::vector<pert_row> pe = p;
    vector<Sommet> ListeS;
    vector<Arc> ListeA;
    VectVal val;
    map<string, VectVal> mapS;
    map<string, VectVal> mapA;
    map<string, VectVal> mapT;
    VectVal fin;

    fin.type = 0;
    fin.valeur_entiere = 0;

    val.type = 0;
    val.valeur_entiere = 0;

    //création d'un sommet départ
    mapA.insert(pair<string, VectVal>("duree", val));
    mapS.insert(pair<string, VectVal> ("date au plus tot", val));
    ListeS.push_back(Sommet(100, 100, "Départ", 0, mapS));

    //création du sommet fin
    ListeS.push_back(Sommet(100, 100, "Fin", 1));

    //création des sommets n'ayant aucunes contraîntes d'antériorités et les arcs correspondants
    for(int i=0; i<p.size(); i++){
        if(p[i].taches_anterieures.empty()){
            val.valeur_entiere = p[i].duree;
            mapS["date au plus tot"] = val;
            ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
            mapA["duree"]=val;
            ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), 0, ListeS.back().getID(), mapA));
            if(p[i].taches_posterieures.empty()){
                if(val.valeur_entiere>fin.valeur_entiere){
                    fin.valeur_entiere = val.valeur_entiere;
                }
                //ajouter arc
                val.valeur_entiere = 0;
                mapA["duree"]=val;
                ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
            }
            p.erase(p.begin()+i);
            i=i-1;
        }
    }

    while (!p.empty()) {
        //on vérifie pour une unique contraînte
        for(int i=0; i<p.size(); i++){
            if(p[i].taches_anterieures.size() == 1){
                int tmp = 0;
                int id;
                for(Sommet s : ListeS){
                    if("fin " + to_string(p[i].taches_anterieures[0]) == s.getEtiq()){
                        tmp++;
                        id = s.getID();
                    }
                }
                if(tmp == 1){
                    val.valeur_entiere = p[i].duree + ListeS[id].getCU()["date au plus tot"].valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"]=val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), id, ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere = p[i].duree + ListeS[id].getCU()["date au plus tot"].valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }

            }
        }


        //test pour plusieurs contraîntes d'antériorités
        for(int i=0; i<p.size(); i++){
            //on vérifie que les taches antérieures sont déjà traitées
            int tmp = 0;
            for(Sommet s : ListeS){
                for(int j=0; j<p[i].taches_anterieures.size(); j++)
                if("fin " + to_string(p[i].taches_anterieures[j]) == s.getEtiq()){
                    tmp++;
                }
            }
            if(tmp == p[i].taches_anterieures.size()){
                //recherche de l'antécédent avec la date au plus tôt la plus élevée
                int x = 0; // id de la tâche
                int id = 0; // id du sommet dans la liste
                for(int k=0; k<ListeS.size(); k++){
                    for(int j=0; j<p[i].taches_anterieures.size(); j++)
                        if("fin " + to_string(p[i].taches_anterieures[j]) == ListeS[k].getEtiq()){
                            if (ListeS[id].getCU()["date au plus tot"].valeur_entiere
                                <= ListeS[k].getCU()["date au plus tot"].valeur_entiere){
                                    id = k;
                                    x = j;
                                }
                        }
                }
                //si l'antécédent avec la date au plus tôt la plus élevée a au plus un sommet postérieur
                if(pe[x].taches_posterieures.size() <= 1){
                    val.valeur_entiere = p[i].duree + ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"]=val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), ListeS[id].getID(), ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere = val.valeur_entiere = p[i].duree + ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    //ajouter les arcs fictifs entre tous les sommets antérieurs et le sommet xi
                    val.valeur_entiere = 0;
                    mapA["duree"]=val;
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        for(int k = 0; k<ListeS.size(); k++){
                            if("fin " + to_string(p[i].taches_anterieures[j]) == ListeS[k].getEtiq() && ListeS[k].getID()!= id){
                                ListeA.push_back(Arc("fictif", ListeA.size(), ListeS[k].getID(), id, mapA));
                             }
                        }
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }
                 //si il a plusieurs sommets postérieurs
                else{
                    //créer un sommet fin de toutes les tâches antérieurs
                    val.valeur_entiere = ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    string etiq = " fin ";
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        etiq += ", " + to_string(p[i].taches_anterieures[j]);
                    }
                    ListeS.push_back(Sommet(100, 100, etiq, ListeS.size(), mapS));
                    val.valeur_entiere = 0;
                    mapA["duree"]=val;
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        for(Sommet s : ListeS){
                            if("fin " + to_string(p[i].taches_anterieures[j]) == s.getEtiq()){
                                ListeA.push_back(Arc("fictif", ListeA.size(), s.getID(), ListeS.back().getID(), mapA));
                             }
                        }
                    }
                    val.valeur_entiere = p[i].duree + ListeS.back().getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"] = val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), ListeS[ListeS.size()-2].getID(),ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere =  p[i].duree + ListeS.back().getCU().at("date au plus tot").valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }
            }
        }

    }



    mapS["date au plus tot"] = fin;
    mapS.insert(pair<string, VectVal> ("date au plus tard", fin));
    ListeS[1].setCU(mapS);





    //calcul de toutes les dates au plus tard

    vector<Arc> li = ListeA; //liste de tous les Arcs non traités
    vector<int> f(ListeS.size()); //liste des sommets traités
    f[1] = 1;


    while(!li.empty()){
      for (int i = ListeS.size()-1; i>= 0; i--){
        int r = 0;
        map<string, VectVal> m = ListeS[i].getCU();

        for(int j = li.size()-1; j>=0; j--){
          if(li[j].getIDDepart() == ListeS[i].getID()){
            if(f[li[j].getIDArrive()] == 1){
              int tmp = ListeS[li[j].getIDArrive()].getCU()["date au plus tard"].valeur_entiere - li[j].getCU()["duree"].valeur_entiere;
              if(ListeS[i].getCU().count("date au plus tard") == 1){
                fin.valeur_entiere = ListeS[i].getCU()["date au plus tard"].valeur_entiere;
                if(tmp < fin.valeur_entiere){
                  fin.valeur_entiere = tmp;
                  m["date au plus tard"] = fin;
                }
              }
              else{
                fin.valeur_entiere = INFINI;
                if(tmp < fin.valeur_entiere){
                  fin.valeur_entiere = tmp;
                  m.insert(pair<string, VectVal> ("date au plus tard", fin));
                }

              }

              ListeS[i].setCU(m);
              li.erase(li.begin() + j);

            }
            else{r++;}

          }
        }
        if(r == 0){
          f[i] = 1;
        }
      }
    }

    for (int i = ListeS.size()-1; i>= 0; i--){
      if(ListeS[i].getCU()["date au plus tot"].valeur_entiere == ListeS[i].getCU()["date au plus tard"].valeur_entiere){
        fin.valeur_entiere = 1;
      }
      else{fin.valeur_entiere = 0;}
      mapT = ListeS[i].getCU();
      mapT.insert(pair<string, VectVal> ("critique", fin));
      ListeS[i].setCU(mapT);
    }

    //création du Graphe
    return Graphe("PERT", ListeS, ListeA, "\0");

}

Graphe arborescence(Graphe G){
    int succ=0,pred=0,Smax=0,Pmax=0;
    int deb=-1;
    Matrice M = G.conversion_vers_Matrice_adj();
    Graphe A("Arborescence");
    Graphe tmp("Arborescence");
    vector<int>in;
    bool connexe = 0;

    // parcours en largeur sur chaque sommets*

    int podider;
    podider = 0;
    vector<int> MarkBFS; // init du marquage du parcours
    vector<vector<int>> Succ;
    Succ.resize(M.getTab().size());
    for(int i=0;i<M.getTab().size();i++){
      MarkBFS.push_back(0);
      for(int j=0;j<M.getTab()[i].size();j++){
        if(M.getTab()[i][j]>0){
          Succ[i].push_back(j);
        }
      }
    }


    for(int i=0; i<M.getTab().size();i++){
      int dep = i;
      queue<int> q ;
      q.push(dep);
      podider = 0;
      while(!q.empty()){
        int SA = q.front();
        MarkBFS[SA] = 1; // on marque le sommet courant
        q.pop();
        for(int j=0;j<Succ[SA].size();j++){
          int NEXT = Succ[SA][j]; // on recupere un successeur
          if(!MarkBFS[NEXT]){//si il est pas marqué
          q.push(NEXT);
          }
        }
      }
      for(int j=0;j<MarkBFS.size();j++){
        // qDebug() << "marquage " << MarkBFS[j] ;
        if(MarkBFS[j])
        podider++;
      }
      if(podider==MarkBFS.size()){
        connexe = 1;
        break;
      }
    }

    //##########################################
    // Vérifie si il existe une arborescence
    for(int i=0;i<M.gettV();i++){
        for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;   // Successeurs
            if(M.getTab()[j][i]) pred++;   // Prédecesseurs
        }
        if(!pred){      // Si pas de prédecesseurs
            deb = i;
            Pmax++;
        }

        succ = 0;
        pred = 0;
        in.push_back(0);
    }
    //// qDebug()<< "connexe " << connexe;
    //// qDebug()<< "Pmax " << Pmax;
    if(Pmax >1 || !Pmax || !connexe){    // Si plusieurs/aucun sommet sans prédecesseurs ou non connexe
        std::cout << "NO ARBORESCENCE 1" << '\n';
        tmp.ajout_Sommet(-1, -1,-1);
        return tmp;
    }

    // ##############
    int min=INFINI;
    for(int i=0;i<M.gettV();i++)  A.ajout_Sommet(i,0,0);   // Ajoute les sommets dans graphe de retour

    int out = 0;
    for(int i=0; i<M.gettV() && !in[i];i++){
        if(i==deb)i++;
        for(int j=0;j<M.gettV();j++){   // Calcul Arc de poids min
            if(M.getTab()[j][i] && M.getTab()[j][i]<min){
                min = M.getTab()[j][i];     // Arc entrant de poids min
                if(j == deb) out++;
            }
        }

        for(int j=0;j<M.gettV() && min!=INFINI;j++){    // Ajout arc de poids min arrivant au sommet i
            int val = M.getTab()[j][i]-min;
            if(!val && !in[i]){
              //cout<<"coucou \n";
                in[i] = 1;
                A.ajout_Arc(j,i);
                break;
            }
        }

        min = INFINI;

        if(i == deb) i = -1;
    }

    if(!out){   // Si pas d'arcs de poids min partant du sommet
        std::cout << "NO ARBORESCENCE 2" << '\n';
        tmp.ajout_Sommet(-1, -1,-1);
        return tmp;
    }
    return A;
}

Graphe anti_arborescence(Graphe G){
  int succ=0,Smax=0;
    int fin=-1;
    Matrice M = G.conversion_vers_Matrice_adj();
    Graphe A("Anti-Arborescence");
    Graphe tmp("Anti-Arborescence");
    vector<int>in;

    bool connexe = 0;

    // parcours en largeur sur chaque sommets*

    int podider;
    podider = 0;
    vector<int> MarkBFS; // init du marquage du parcours
    vector<vector<int>> Succ;
    Succ.resize(M.getTab().size());
    for(int i=0;i<M.getTab().size();i++){
      MarkBFS.push_back(0);
      for(int j=0;j<M.getTab()[i].size();j++){
        if(M.getTab()[j][i]>0){
          Succ[i].push_back(j);
        }
      }
    }


    for(int i=0; i<M.getTab().size();i++){
      int dep = i;
      queue<int> q ;
      q.push(dep);
      podider = 0;
      while(!q.empty()){
        int SA = q.front();
        MarkBFS[SA] = 1; // on marque le sommet courant
        q.pop();
        for(int j=0;j<Succ[SA].size();j++){
          int NEXT = Succ[SA][j]; // on recupere un successeur
          if(!MarkBFS[NEXT]){//si il est pas marqué
          q.push(NEXT);
          }
        }
      }
      for(int j=0;j<MarkBFS.size();j++){
        //// qDebug() << "marquage " << MarkBFS[j] ;
        if(MarkBFS[j])
        podider++;
      }
      if(podider==MarkBFS.size()){
        connexe = 1;
        break;
      }
    }

    // Vérifie si il existe une anti-arborescence
    for(int i=0;i<M.gettV();i++){
        for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;   // Successeurs
        }
        if(!succ){      // Si pas de successeurs
            fin = i;
            Smax++;
        }
        succ = 0;
        in.push_back(0);
    }

    if(Smax >1 || !Smax || !connexe){    // Si plusieurs/aucun sommet sans prédecesseurs ou non connexe
        std::cout << "NO ANTI-ARBORESCENCE" << '\n';
        tmp.ajout_Sommet(-1,-1,-1);
        return tmp;
    }
    // ##############
    int min=INFINI;
    for(int i=0;i<M.gettV();i++)  A.ajout_Sommet(i,0,0);   // Ajoute les sommets dans graphe de retour

    int out = 0;
    for(int i=0; i<M.gettV() && !in[i];i++){
        //if(i==fin)i++;
        for(int j=0;j<M.gettV();j++){   // Calcul Arc de poids min
            if(M.getTab()[i][j] && M.getTab()[i][j]<min){
                min = M.getTab()[i][j];     // Arc entrant de poids min
                if(j == fin) out++;
            }
        }

        for(int j=0;j<M.gettV() && min!=INFINI;j++){    // Ajout arc de poids min arrivant au sommet i
            int val = M.getTab()[i][j]-min;
            if(!val && !in[i]){
                in[i] = 1;
                A.ajout_Arc(i,j);
                break;
            }
        }

        min = INFINI;
        if(i == fin) i = -1;
    }

    if(!out){   // Si pas d'arcs de poids min partant du sommet
        std::cout << "NO ANTI-ARBORESCENCE" << '\n';
        tmp.ajout_Sommet(-1, -1,-1);
        return tmp;
    }
    return A;
}

int connexite(Matrice M){
/* Variable temporaire pour stocker degre entrant et sortants d'un sommet S*/
int degreE, degreS;

    /*On parcours chacun des sommets S*/
    for(int id = 0; id< M.gettV(); id++){

    /*On efface le contenu des varibles*/
    degreE = 0;
    degreS = 0;

       /* nombre de degrès entrants*/
       degreE =  calcul_degres_entrant(M, id);

       /* nombre de degrès sortants */
       for(int i=0; i<M.getTab().size(); i++) {  if (M.getTab()[id][i]) degreS++; }

       /* On test si un des sommets ne nous permet pas d'en resortir ou d'en entrer  */
       if ( degreE == 0 || degreS == 0 ) return 0;

    }
   return 1;

}


vector<vector<int>> chaine_eulerienne(Matrice M){
  vector<int> path;
  vector<vector<int>> res;

  if(M.getType() != 0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
    int pred=0,succ=0,Dmax=0,Fmax=0;
    int deb=0,fin=-1;
    vector<int> out;

    // Vérifie connexité
    bool connexe = 0;

    // parcours en largeur sur chaque sommets*
    int podider;
    podider = 0;
    vector<int> MarkBFS; // init du marquage du parcours
    vector<vector<int>> Succ;
    Succ.resize(M.getTab().size());
    for(int i=0;i<M.getTab().size();i++){
      MarkBFS.push_back(0);
      for(int j=0;j<M.getTab()[i].size();j++){
        if(M.getTab()[i][j]>0){
          Succ[i].push_back(j);
        }
      }
    }


    for(int i=0; i<M.getTab().size();i++){
      int dep = i;
      queue<int> q ;
      q.push(dep);
      podider = 0;
      while(!q.empty()){
        int SA = q.front();
        MarkBFS[SA] = 1; // on marque le sommet courant
        q.pop();
        for(int j=0;j<Succ[SA].size();j++){
          int NEXT = Succ[SA][j]; // on recupere un successeur
          if(!MarkBFS[NEXT]){//si il est pas marqué
          q.push(NEXT);
          }
        }
      }
      for(int x=0;x<M.getTab().size();x++){
        // int iso = 0 ;
        // for(int y=0;y<M.getTab()[x].size();y++){
        //   if(M.getTab()[x][y]||M.getTab()[y][x]){
        //     iso++;
        //   }
        //   if(!iso){
        //     MarkBFS[x]=1;
        //   }
        // }

        for(Sommet s : M.conversionGraphe().getListe_Sommets()){
          if((calcul_degres_entrant(M,s.getID())+calcul_degres_sortant(s))==0 ){
            MarkBFS[s.getID()] = 1;
            // qDebug() << "0 degres eheh" ;
          }

        }
      }

      for(int j=0;j<MarkBFS.size();j++){
        // qDebug() << " i "<< i  << "marquage " << MarkBFS[j] ;
        if(MarkBFS[j])
        podider++;
      }
      if(podider==MarkBFS.size()){
        connexe = 1;
        break;
      }
    }

    // ########################################
    int mark[M.gettV()][M.gettV()];

    // Vérifie si il existe un chemin Eulérien
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) succ++;
        if(M.getTab()[j][i]) pred++;
        mark[i][j] = 0;
      }
      out.push_back(succ);    // Stocke le nombre de successeurs

      if(succ-pred>1 || pred-succ>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      else{
        if(pred-succ==1){
          fin = i;          // Sommet d'arrivée
          Fmax++;
        }
        else if(succ-pred==1){
          deb = i;         // Sommet de départ
          Dmax++;
        }
      }

      if(!connexite && !succ && !pred){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      if(Dmax>1 || Fmax>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      succ = 0;
      pred = 0;
    }

    // Nombre d'arcs
    int nbA = 0;
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) nbA++;
      }
    }

    // Sommet de départ
    if(deb==0 && !out[deb]){
        for(int i=0;i<M.gettV();i++){
            if(out[i]>0) deb = i;
        }
    }

    // #########################
    int i = deb;
    while (out[i]){
        for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j] && !mark[i][j]){   // Si arc
                --out[i];
                mark[i][j] = 1;
                path.push_back(i);
                i = j;
                j = 0;
            }

            if(!out[i] && path.size() == nbA){
                path.push_back(i);
                res.push_back(path);
                return res;
            }
        } // Fin for
    } // Fin while
  } // Fin else
  return res;
}

vector<vector<int>> chaine_hamiltonienne(Matrice M){
  vector<int> mark;
  vector<int> path;
  vector<vector<int>> chemin_imp(M.gettV());
  vector<int> impossible;
  vector<vector<int>> res;

  if(M.getType() != 0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
      int pred, succ, Pmax = 0, Smax = 0;
      int deb=-1,fin=-1;

      // Vérifie si il existe un chemin Hamiltonien
      for(int i=0;i<M.gettV();i++){
          for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;      // Nb successeur pour i
            if(M.getTab()[j][i]) pred++;      // Nb predecesseur pour j

          }
          mark.push_back(0);
          if(!succ){
            Smax++;
            fin = i;
          }
          if(!pred){
            Pmax++;
            deb = i;
          }
          succ = 0;
          pred = 0;
      }

      if(Smax > 1 || Pmax > 1){                 // Plusieurs sommets sans successeurs ou prédecesseurs
           // qDebug() << "NO HAMILTTONIAN PATH" << '\n';
            return res;
      }
      // qDebug()<<"deb : " <<deb;
      int i = deb;
      int last = i;

      for(int x=0;x<M.gettV();x++){
        if(deb == -1){
          i = x;
          deb = i;
        }
        while(!mark[i]){
          // qDebug()<<"id testée " << i;
          if(path.size() == M.gettV()-1){
            // qDebug()<< "push "<< fin;

              for(int osef=0;osef<mark.size();osef++){
                  if(!mark[osef]){
                    fin = osef;
                  }
              }
              if(M.getTab()[i][fin]){
                path.push_back(fin);
                res.push_back(path);
                return res;
              }
          }

          for(int j=0;j<M.gettV();j++){

            int imp = 1;
            for (int pr = 0; pr<chemin_imp[i].size(); pr++){
              if(chemin_imp[i][pr]==j)
              imp = 0;
            }

            if(M.getTab()[i][j] && !mark[j] && imp){
              mark[i] = 1;
              int test = 0;
              for(int osef =0; osef<path.size();osef++){
                if(path[osef]==i)
                test =1;
              }
              if(!test){
                path.push_back(i);
                // qDebug()<< "push "<< i;
              }
              // qDebug()<<"path : "<<path;
              i = j;
              j = 0;
            }
          } // Fin for
          int test =0;
          for(int osef =0; osef<path.size();osef++){
            if(path[osef]==i)
            test =1;
          }
          if(!test){
            path.push_back(i);
          }
          if(last == i){
            // qDebug()<<" pop "<<path[path.size()-1];
            path.pop_back();
            mark[i] = 0;
            i = path[path.size()-1];
            mark[i] = 0;
            chemin_imp[i].push_back(last);
            chemin_imp[last].clear();
          }
          else last = i;

        } // Fin while
      } // Fin for
    } // Fin else
  return res;
}

vector<int> postier_chinois(Matrice M){

        vector<int> sommetsImpair;
        vector<int> vecteurResult;
        int nb_sortant, nb_entrant;
        pair<Matrice, Matrice> FloydMa = calcul_Floyd_Warshall(M);
        int deb, fin;
        int EstPair = 1;


        /*On vérifie la connexité*/
        if (connexite(M)){

            /*On boucle sur les sommets, pour vérifier s'ils sont tous pairs */
             for(int i=0; i<M.getTab().size(); i++){
                nb_sortant =0;

                /*nb degré entrant */
                nb_entrant = calcul_degres_entrant(M, i);

                /*nb degré sortant */
                for (int j=0; j < M.gettV() ; j++){
                    if (M.getTab()[i][j]) nb_sortant++;
                }

                /* si l'un des sommets a un degré impair on sort de la boucle */
                if (nb_sortant!= nb_entrant){
                     sommetsImpair.push_back(i);
                     EstPair = 0;
                }
            }
            /* on produit le cycle eulérien pour résoudre le postier chinois*/
            if (EstPair) {
                    /* permet de récupérer le premier vecteur des chaines eulériennes.*/
                    vector<vector<int>> tmp = chaine_eulerienne(M);
                    if(!tmp.empty()) vecteurResult = tmp[0];
                return vecteurResult;
            }
            else{
                int tmp;
                int total_poid_couplage=0;
                int total;
                int noChemin;
                int nb_combinaisons;
                vector<int> vect_tmp;
                vector<int> couplageParfait;
                vector<vector<int>> combinaisons;


                /*factoriel pour récupérer le nombre de combinaisons possibles*/
                for(int fact=1; fact<(sommetsImpair.size()+1); fact++){
                    nb_combinaisons*=fact;
                }

                /* récupérer toutes les combinaisons de couplages possibles */
                 do{
                   for( auto i = sommetsImpair.begin(); i < sommetsImpair.end(); i += 1 ){
                       vect_tmp.push_back(*i);
                    }
                    combinaisons.push_back(vect_tmp);
                    vect_tmp.clear();
                }while( std::next_permutation( sommetsImpair.begin(), sommetsImpair.end() ) );


                /*UNIQUEMENT POUR STOCKER LA PREMIERE COMBINAISON POSSIBLE */
                int min=0;
                for(auto deb=combinaisons.begin(); deb!=combinaisons.end(); deb++){

                    /* effacer le vecteur pour pouvoir le réutiliser*/
                    couplageParfait.clear();
                    total_poid_couplage = 0;
                    noChemin = 0;
                    for(auto fin=deb->begin(); fin!=deb->end(); fin=fin+2){
                        tmp = 0;
                        tmp = FloydMa.first.getTab()[*fin ][*(fin+1)];
                        /* s'il n'y a pas de chemin du sommet *fin au sommet *(fin +1),on sort de la boucle interne pour tester la deb+1 combinaisons */
                        if (tmp == 0) {
                            min = 0;
                            break;
                        }
                        if (!noChemin){
                            total_poid_couplage += tmp;
                            /*sauvegarder les sommets dans le vecteur temporaire au cas où ils seraient des couplages parfaits */
                            couplageParfait.push_back(*fin);
                            couplageParfait.push_back(*(fin+1));
                            /*on a récupérer la premiere valeur*/
                            min = 1;
                        }
                    }
                    if (min) break;
                }

                /* ON RECUPERE LE MINIMUM parmis toutes les combinaisons possibles du vecteur couplageParfait*/
                for(auto deb=combinaisons.begin(); deb!=combinaisons.end(); deb++){

                    /* effacer le vecteur pour pouvoir le réutiliser*/
                    vect_tmp.clear();
                    total = 0;
                    noChemin = 0;
                    for(auto fin=deb->begin(); fin!=deb->end(); fin=fin+2){
                        tmp = 0;
                        tmp = FloydMa.first.getTab()[*fin ][*(fin+1)];
                        /* s'il n'y a pas de chemin entre 2 sommets : break*/
                        if (tmp == 0) {
                            noChemin=1;
                            break;
                        }
                        if (!noChemin){
                             total += tmp;
                            /*sauvegarder les sommets dans le vecteur temporaire au cas où ils seraient des couplages parfaits */
                            vect_tmp.push_back(*fin);
                            vect_tmp.push_back(*(fin+1));
                        }
                    }


                        if ( (!noChemin) & (total < total_poid_couplage) ){
                             total_poid_couplage = total;
                            couplageParfait = vect_tmp;
                        }

                }

                /*Création d'un Matrice bis pour stocker les nouveaux arcs */
                Matrice Mbis(M);
                for(auto deb = couplageParfait.begin(); deb != couplageParfait.end(); deb=deb+2 ){
                    Mbis.modifTab(*deb, *(deb+1), 1);
                 }

                /* permet de récupérer le premier vecteur des chaines eulériennes.*/
                vector<vector<int>> stock = chaine_eulerienne(Mbis);
                if(!stock.empty()) vecteurResult = stock[0];
                else vecteurResult= {};
                return vecteurResult;

            }

        }

        else {
            std::cout << "ERREUR CONNEXITE MATRICE (Postier Chinois)" << '\n';
            /* retourne un vecteur vide */
            return vecteurResult;
            }
}

vector<int> voyageur_de_commerce(vector<int> sommet, Matrice M)
{
	////////////////////////////////////:
	// On retire de M, tous les sommets qui ne sont pas mis en argument dans le vector sommet.

	// on check pour chacun des elements de la matrice si ils sont present dans le vecteur.
	// Sinon on supprimme la ligne et la colonne corespondante
	// printf("on inclue les sommets: ");
	// for(int unsigned i = 0; i<sommet.size();i++)
	// {
  //
	// 	printf("%d ", sommet[i]);
	// }
	// printf("\n");

	for(int i = 0; i<M.gettV(); i++)
	{
		int check = 0;
		for(int unsigned j = 0; j<sommet.size(); j++)
		{
			if(sommet[j] == i)
			{
				check = 1;
			}
		}
		if(check == 0)
		{
			M.supprCol(i);
			M.supprLigne(i);
		}


	}

	//~ M.affiche_matrice();

	////////////////////////////////////
		// printf("Matrice initiale:\n");
		//M.affiche_matrice();

    // for(int i = 0; i<M.gettV();i++){
    //   for(int j=0; j< M.gettV();j++){
    //     cout << M.getTab()[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // printf("\n");
	////////////////////////////////////
	// ATTENTION A BIEN PRENDRE EN COMPTE SEULEMENT LES SOMMET MSI EN ARGUMENT ET PAS TOUS CEUX DU GRAPHE
	//////////////////////////////////
	int somme_reduc = 0;
	Graphe arbre = Graphe("arbre");
  vector<vector<int>> ListeChemin;
	//////////////////////////////////////////

	// PREMIERE REDUCTION DE LA MATRICE
	//////////////////////////////////////////

	int reduc_colonne = 10000000;
	int reduc_ligne = 10000000;


	vector < vector <int>> tab = M.getTab();
	// diagonale de la matrice à -2
 	for(int i = 0; i<M.gettV(); i++)
	{
		for(int j = 0; j<M.gettV(); j++)
		{
			if(i == j)
			{
				tab[i][j] = -2;
			}
		}
	}




	//~ //Ici, réduction ligne
	for(int i = 0; i<M.gettV(); i++)
	{
		reduc_ligne = 10000000;
		for(int j = 0; j<M.gettV(); j++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_ligne && (tab[i][j] != (-2))&& (tab[i][j] != (-3)))
			{
				reduc_ligne = tab[i][j];
			}

		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
    if( reduc_ligne != 10000000)
		somme_reduc = somme_reduc + reduc_ligne;


		for(int j = 0; j<M.gettV(); j++)
		{
				if(tab[i][j] != -2 && tab[i][j] != -3)
				{
				tab[i][j] = tab[i][j] - reduc_ligne;
				}

		}
	}

	//~ //Ici, réduction colonne
	for(int j = 0; j<M.gettV(); j++)
	{
		reduc_colonne = 10000000;
		for(int i = 0; i<M.gettV(); i++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_colonne && (tab[i][j] != (-2))&& (tab[i][j] != (-3)))
			{
				reduc_colonne = tab[i][j];
			}

		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
    if(reduc_colonne != 10000000)
		somme_reduc = somme_reduc + reduc_colonne;
		for(int i = 0; i<M.gettV(); i++)
		{
				if(tab[i][j] != -2 && tab[i][j] != -3)
				{
				tab[i][j] = tab[i][j] - reduc_colonne;
				}

		}
	}


	////////////////////////////////
	//fin de la première réduction
	//////////////////////////////

	// si l'arbre est vide, on initialise le sommet racine à la valeur de la réduction de la matrice pour
	// pour la première réduction

	if(arbre.getListe_Sommets().size() == 0)
	{

		string etiquette = "racine";
		map <string, VectVal> A;
		string a = "value";

		VectVal regret;
		regret.type = 0;
		regret.valeur_entiere = somme_reduc;
		regret.valeur_reel = 0;

		A[a]=regret;
		// printf("création de la racine de l'arbre, avec pour valeur:%d\n", somme_reduc);
		Sommet racine = Sommet(1, 1, etiquette , 0, A);

		vector<Sommet> liste = arbre.getListe_Sommets();
		liste.push_back(racine);
		arbre.setListe_Sommet(liste);
		// printf("présentation de l'arbre crée\n");

	}
	M.setTab(tab);

	int compteur = 1;
	int taille_matrice = M.gettV();
	while(taille_matrice> 2) // tant que on a pas une matrice de taille 2x2
	{
	// printf("///////////////////////////////////////////////////////////////////////////////////\n");
  // cout << "Affichage Matrice " << '\n';
  // for(int i = 0; i<M.gettV();i++){
  //   for(int j=0; j< M.gettV();j++){
  //     cout << M.getTab()[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // printf("\n");
  //
	// printf("réduction numéro %d", compteur);
	// printf("\n");
  //
	// printf("\n");
	// 	printf("\nCalcul des regrets aux cases avec comme valeur 0\n");
    vector< vector<int> > tableau = M.getTab();
    vector< vector<int>> regrets; // on ajoutera des vecteur avec trois elements, dans ce vecteur regrets

    //pour un vecteur donne, il y aura:
    //1er element -> regret de la case ( ou il y a un zéro)
    //2eme element = coordonnées x
    //3eme element = coordonnées y

    ////////////////////////////////////////////////////////////////////////////////////////////////
    int regret = 0; // on initie un entier regret, qui contiendra la valeur du regret pour une case donnée.
    //ces deux entiers serviront à la recherche de l'entier minimal en x et en y.
    // car regret = minimum en x + minimum en y.
    int regretX = 0;
    int regretY = 0;
    //////////////////////////////////////////////////////////////////////////////////
    // PARTIE 1: ON INSTANCIE REGRET A UNE VALEUR ELEVE
    ////////////////////////////
    // il est important de leur associer une valeur élevé afin d'obtenir la plus petite valeur par la suite.
    // mettre à zéro directement empecherai de trouver la valeur minimale
    for(int i = 0; i < M.gettV(); i++)
    {
		 for(int j = 0; j < M.gettV(); j++)
		 {
			if(tableau[i][j]>regret)
			{
				regret = tableau[i][j];
			}
		 }

    }
    regretX = regret;
    regretY = regret;


    /////////////////////////////////////////////////////////////////////////////////

    // PARTIE 2: ON RECHERCHE LES CASES DE LA MATRICE REDUITE DONT LA VALEUR EST ZERO
    // ET ON CALCULE LES REGRETS ASSOCIES, ON STOCKERA DANS UN VECTEUR TOUTS LES REGRETS

	for(int x = 0; x<M.gettV(); x++)
	{
		for(int y = 0; y<M.gettV(); y++)
		{
			if(tableau[x][y] == 0)
			{

			// Si une case vaut zéro, il faut calculer le regret asscocié, si on ne prendrait pas ce chemin

				for(int i = 0; i<M.gettV(); i++)
				{
					// on fera attention en cherchant la valeur minimale comme regret de pas prendre 0
					// ca c'est va valeur de la case étudiée justement.
					if(regretY > tableau[i][y] && (i != x) && tableau[i][y] != -2 && tableau[i][y] != -3 )
					{
						regretY = tableau[i][y];
					}
				}
				for(int j = 0; j<M.gettV();j++)
				{
					if(regretX> tableau[x][j] && (j != y) && tableau[x][j] != -2 && tableau[j][y] != -3 )
					{
						regretX= tableau[x][j];
					}
				}
				regret = regretX + regretY;
				vector<int> regret_actuel {regret, y, x};
				regrets.push_back(regret_actuel);
			}

			///////////////////////////////////////
			// on remet à zero les valeur de regretX et regretY puis on leur donne la valeur max possible.
			regretX = 0;
			regretY = 0;
			regret = 0;

			 for(int i = 0; i < M.gettV(); i++)
			 {
				for(int j = 0; j < M.gettV(); j++)
				{
					if(tableau[i][j]>regret)
					{
						regret = tableau[i][j];
					}
				}

			 }
			regretX = regret;
			regretY = regret;
			///////////////////////////////////////////////

		}
	}
		for(int unsigned i= 0; i<regrets.size(); i++)
	 // usigned car le nombre d'elements renvoyé par le size() est un entier non signé.

	// on va stocker les coordonnées X et Y du plus grand regret, afin de le recuperer après.
	{

			//printf("case [%d][%d], valeur du vecteur regret: %d\n", regrets[i][1], regrets[i][2], regrets[i][0]);

	}

	//////////////////////////////////////////////////////////////////////////////////////
	//PARTIE 3, ON VA SELECTIONNER LE PLUS GRAND REGRET DANS LE VECTEUR AYANT STOCKE LES REGRETS
	// OU UNE CASE VALAIT 0 D APRES LA MATRICE REDUITE.
	//////////////////////////////////////////////////////////////////////////////////////

	regret = 0;
	for(int unsigned i= 0; i<regrets.size(); i++)
	{
	// usigned car le nombre d'element renvoyé par le la taile
	// du vecteur est un entier non signé.

	// on va stocker les coordonnées X et Y du plus grand regret, afin de le recuperer après.

		if(regrets[i][0]> regret)
		{
			regret = regrets[i][0];
      regretX = regrets[i][2];
			regretY = regrets[i][1];
		}
	}


	vector<int> REGRET_FINAL{regret, regretX, regretY}; // ici, le regret final contient la case avec le plus haut regret ainsi que ses

		//printf("\nvaleur du vecteur regret max: %d, à la case [%d][%d]\n", REGRET_FINAL[0], REGRET_FINAL[1],REGRET_FINAL[2] );

	////////////////////////////////////////////////////////////////////////////////////////
	// PARTIE 4: ON AJOUTE A L ABRE LE CAS DE L AJOUT DU CHEMIN VERS CE SOMMET AVEC LE PLUS GRAND REGRET
	// ET ENSUITE LE CAS OU ON NE PREND PAS CE MEME CHEMIN
	////////////////////////////////////////////////////////////////////////////////////////

	// on cherche à récupérer la valeur du plus grand indice de sommet

	///////////////////////////////////////////


	// taille permet de fixer les id des sommet
	// taille paire -> sommet inclu
	// taille impaire -> sommet exclu


	int unsigned taille = arbre.getListe_Sommets().size();

	string name1_1 = to_string(REGRET_FINAL[1]);
	string name1_2 = to_string(REGRET_FINAL[2]);
	string name = name1_1 + name1_2;

	map <string, VectVal> Avec_chemin;
	map <string, VectVal> Sans_chemin;
	string a = "value";

		VectVal regret_Avec_chemin;
		VectVal regret_Sans_chemin;

		regret_Sans_chemin.type = 0;
		regret_Sans_chemin.valeur_reel = 0;
		if(arbre.getListe_Sommets().size() == 1)
		{
			regret_Sans_chemin.valeur_entiere = somme_reduc + REGRET_FINAL[0]; // valeur du père + regret total de reduction de matrice
			Sans_chemin[a]=regret_Sans_chemin;
		}

		if(arbre.getListe_Sommets().size()  != 1)
		{
			vector<Sommet> listee = arbre.getListe_Sommets();
			map<string,VectVal> a = listee[listee.size()-1].getCU();
			int b = a["value"].valeur_entiere;

			regret_Sans_chemin.valeur_entiere = REGRET_FINAL[0] + b;
			Sans_chemin["value"]=regret_Sans_chemin;
		//	printf("valeur du sommet avec chemin exclu: %d + %d\n",REGRET_FINAL[0], b);
		}

		//~ /////////////////////////////////////
	//~ // ON SUPPRIMME LA LIGNE ET LA COLONNE DE LA CASE CHOISIE

	///////////////////////////////////////:::::
	// ON doit supprimer l'arc inverse pour éviter un aller-retour
	//////////////////////////////

	//~ /////////////////////////////////////
  if(M.getTab()[REGRET_FINAL[2]][REGRET_FINAL[1]]!=-3)
	M.modifTab(REGRET_FINAL[2], REGRET_FINAL[1], -2);

	// printf("on associe à la case [%d][%d] la valeur -2\n", REGRET_FINAL[2], REGRET_FINAL[1]);
  //
  // cout << "Affichage Matrice " << '\n';
  // for(int i = 0; i<M.gettV();i++){
  //   for(int j=0; j< M.gettV();j++){
  //     cout << M.getTab()[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // printf("\n");

	tab = M.getTab();
	for(int i = 0; i<M.gettV(); i++)
	{
		tab[i][REGRET_FINAL[2]] = -3;
		tab[REGRET_FINAL[1]][i] = -3;

	}
	M.setTab(tab);
	// printf("suppression de la colonne %d\n",REGRET_FINAL[1] );
	// printf("suppression de la ligne %d\n",REGRET_FINAL[2] );
		///////////////////////

    // elimination des chemins inutiles
    for(int i = 0;i<ListeChemin.size();i++){

    }

		// REDUCTION DE LA MATRICE
		// printf("nouvelle réduction de la matrice\n");

	tab = M.getTab();
  // cout << "Affichage Matrice " << '\n';
  // for(int i = 0; i<M.gettV();i++){
  //   for(int j=0; j< M.gettV();j++){
  //     cout << M.getTab()[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // printf("\n");
	reduc_colonne = 10000000;
	reduc_ligne = 10000000;
	// printf(" reduction ligne = %d\n", reduc_ligne);
	// printf("reduction colonne = %d\n", reduc_colonne);
	taille_matrice--;

	//~ //Ici, réduction ligne
	for(int i = 0; i<M.gettV(); i++)
	{
		reduc_ligne = 10000000;
		for(int j = 0; j<M.gettV(); j++)
		{

			// on cherche la valeur minimale pour la ligne donnée
			if(tab[i][j]<reduc_ligne && (tab[i][j] != (-2)) && (tab[i][j] != (-3)))
			{
				reduc_ligne = tab[i][j];

			}

		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
    if(reduc_ligne != 10000000)
    somme_reduc = somme_reduc + reduc_ligne;
		for(int j = 0; j<M.gettV(); j++)
		{
				if((tab[i][j] != -2) && (tab[i][j] != -3))
				{
				tab[i][j] = tab[i][j] - reduc_ligne;
				}

		}
		// printf(" reduction ligne = %d\n", reduc_ligne);
	}
	//~ //Ici, réduction colonne
	for(int j = 0; j<M.gettV(); j++)
	{
		reduc_colonne = 10000000;

		for(int i = 0; i<M.gettV(); i++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_colonne && (tab[i][j] != (-2)) && (tab[i][j] != (-3)))
			{
				reduc_colonne= tab[i][j];
			}

		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
    if( reduc_colonne != 10000000)
    somme_reduc = somme_reduc + reduc_colonne;

		for(int i = 0; i<M.gettV(); i++)
		{
				if((tab[i][j] != -2) && (tab[i][j] != -3))
				{
				tab[i][j] = tab[i][j] - reduc_colonne;
				}
		}
		// printf("reduction colonne = %d\n", reduc_colonne);
	}

	M.setTab(tab);

	// printf("nouvelle valeur de somme_reduc:%d\n", somme_reduc);

		///////////////////////

	//	Avec-chemin correspond au sommet avec le chemin inclu
	// sans-chemin correspond au sommet avec le chemin exclu

	regret_Avec_chemin.type = 0;
	regret_Avec_chemin.valeur_entiere = somme_reduc;
	regret_Avec_chemin.valeur_reel = 0;

	Avec_chemin[a]=regret_Avec_chemin;
  //tmp
  ListeChemin.push_back({REGRET_FINAL[1],REGRET_FINAL[2]});

  //
  string string_avec_chemin = to_string(REGRET_FINAL[1]) +"-"+ to_string(REGRET_FINAL[2]) + " ";
	string string_sans_chemin = to_string(REGRET_FINAL[1]) +"-"+ to_string(REGRET_FINAL[2]) + " ";
	Sommet avec_chemin = Sommet(1, 1, string_avec_chemin, taille+1, Avec_chemin);
    Sommet sans_chemin = Sommet(1, 1, string_sans_chemin, taille, Sans_chemin);

	vector<Sommet> liste = arbre.getListe_Sommets();
	liste.push_back(sans_chemin);
	liste.push_back(avec_chemin);

	arbre.setListe_Sommet(liste);


	// le premier sommet a pour id 0, donc si on a 3 sommets dans un graphe, taille = 3 mais sommet1 a pour id 0 et sommet 2 a pour id 1 et sommet 3 a pour id 2
	arbre.ajout_Arc(taille-1, taille);
	arbre.ajout_Arc(taille-1, taille+1);


	//////////////////////////////////////////
	compteur++;
	REGRET_FINAL.clear();
  // cout << "Affichage Matrice " << '\n';
  // for(int i = 0; i<M.gettV();i++){
  //   for(int j=0; j< M.gettV();j++){
  //     cout << M.getTab()[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // printf("\n");

	}


	//////////////////
	// FIN DU CAS AUTRE QUE MATRICE 2*2
	////////////////////////

	// printf("///////////////////////////////////////////////////////////////");
  //   printf("\n\n matrice de taille 2*2: \n\n\n");
	//~ M.affiche_matrice();
	// ICI ON DOIT AVOIR UNE MATRICE DE TAILLE 2x2.

	 tab = M.getTab();
	 vector<Sommet> listeS = arbre.getListe_Sommets();
	if(M.gettV() == 2) // Si on a une matrice de taille 2x2
	{
		for(int i = 0; i<2; i++)
		{
			for(int j = 0; j<2; j++)
			{
				if(tab[i][j] != -2 )
				{

					// il faut regarder si ce chemin n'est pas déjà contenu dans dans les autres sommets sous forme du chemin inverse
					// exemple 1-2 et 2-1. cela revient au meme. Donc il faut vérifier cela.
					for(int z = 0; z<listeS.size(); z++)
					{
						string a =   to_string(j) + to_string(i);
						if(listeS[z].getEtiq() == a)
						{
							 // le chemin inverse est déjà present
							tab[i][j] = -2; // on annule ce chemin
						}
					}
				}
			}
		}
		for(int i = 0; i<2; i++)
		{
			for(int j = 0; j<2; j++)
			{
				if(tab[i][j] != -2  && tab[i][j] != -3)
				{
					// on va ajouter les derniers chemin à l'arbre




					string string_dernier_chemin = to_string(i) +"-" +to_string(j) + " ";
					int taille = listeS.size();
					map<string,VectVal> A;
					Sommet dernier_chemin = Sommet(i, j, string_dernier_chemin, taille, A);

					vector<Sommet> liste = arbre.getListe_Sommets();
					liste.push_back(dernier_chemin);

					arbre.setListe_Sommet(liste);


				}
			}


		}
	}

	/////////////////////////////////////////////////////
	// PARTIE 5: IL FAUT VISITER LES AUTRES CHEMIN EXCLU
	/////////////////////////////////////////////////////
  // EH MERDE

	//~ ////////////////////

	// juste de l'affichage pour la fin ici....
	vector<Sommet> liste = arbre.getListe_Sommets();
	for(int unsigned i = 0; i<liste.size(); i++)
	{
		if(i == 0)
		{
			map<string,VectVal> a = liste[i].getCU();
			int b = a["value"].valeur_entiere;
			// cout<<"racine sommet "<< i << "de valeur "<<b<<" et etiquette "<<liste[i].getEtiq()<<"\n";
		}
		else if(i%2 == 0)
		{
		map<string,VectVal> a = liste[i].getCU();
		int b = a["value"].valeur_entiere;
		// cout<<"chemin inclue "<< i << " de valeur "<<b<<" et etiquette "<<liste[i].getEtiq()<<"\n";
		}
		else if((i+1)%2 == 0)
		{
		map<string,VectVal> a = liste[i].getCU();
		int b = a["value"].valeur_entiere;
		// cout<< "chemin  exclu "<< i << " de valeur "<<b<<" et etiquette "<<liste[i].getEtiq()<<"\n";
		}
	}

	// printf("les sommets de valeur 0 sont ceux issu de la matrice 2*2");




	//~ // A PARTIR DE L ARBRE IL FAUT RENVOYER LE CYCLE
	// on récupère les premeiers chemins trouvés
	 listeS = arbre.getListe_Sommets();
	string listeSommet;
	vector<int> solution;

	/////////////////::

	for(int i = 0; i<listeS.size(); i++)
	{
		if(i != 0 && (i%2) == 0)
		{
		//~ cout<<listeS[i].getEtiq();
		listeSommet = listeSommet + listeS[i].getEtiq();

		}
	}
   char c[listeSommet.size() + 1];
   strcpy(c, listeSommet.c_str());
   // cout <<"\n non triée: "<< c <<'\n';

	// on va trier le vecteur listeSommet.

	// ici je cherche à le trier de manière à avoir par exemple 1-2 2-4 4-3 3-7 7-1 etccc: un truc logique en gros
	// for(int i = 1; i<listeSommet.size(); i = i +2)
	// {
	// 	for(int j = i+1 ; j<listeSommet.size(); j = j+2)
	// 	{
	// 		int a = c[i];
	// 		int b = c[j];
	// 		printf("c[i] affiche %c et valeur de a %d et ", c[i], a);
	// 		printf("c[j] affiche %c et la valeur de b %d", c[j], b);
	// 		printf("\n");
	// 		if(a>b)
	// 		{
  //
	// 			char st1 = c[i-1];
	// 			char st2 = c[i];
  //
	// 			c[i-1] = c[j];
	// 			c[i] =  c[j+1];
	// 			c[j] = st1;
	// 			c[j+1] = st2;
  //
  //
	// 		}
	// 	}
	// }

	 //cout<<"triée: " << c <<'\n';

	//~ cout<<"\n"<<listeSommet;


  //Gestion du res
  int DEP = ListeChemin[0][0];
  solution.push_back(DEP);
  int NEXT = ListeChemin[0][1];
  int cmplc = 0 ;
  while(cmplc < ListeChemin.size() && NEXT != DEP){
    for(int i = 0; i< ListeChemin.size();i++){
      if(ListeChemin[i][0] == NEXT){
        solution.push_back(NEXT);
        NEXT = ListeChemin[i][1];
        break;
      }
    }
    cmplc++;
  }

  solution.push_back(NEXT);
  // for(int i =0;i< solution.size()-1;i++){
  //   std::cout << solution[i] << " -> ";
  // }
  // std::cout << solution[solution.size()-1] << '\n';
	return solution;
}
