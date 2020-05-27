#include "Matrice.hh"
#include "Graphe.hh"

enum typeM{
  ADJACENCE = 0,
  INCIDENCE = 1,
  POIDS = 2,
  PARENT = 3,
  QUELCONQUE = 4
};

 Matrice::Matrice(Graphe G, int type){// Constructeur d'une matrice issue d'un Graphe
//   if(type == ADJACENCE){  // Matrice Adjacence
//     this->type = type;
//     int cmptV=G.getListe_Sommets().size();
//
//     this->taille_V = cmptV;
//     this->taille_E = -1;
//
//     this->tab.resize(cmptV);  // On redimensionne la Matrice
//     for(int i=0;i<cmptV;i++){
//       this->tab[i].resize(cmptV);
//     }
//     for(Arc x : G.getListe_Arcs()){//on met le poids dans la Matrice
//       this->tab[x.getIDDepart()][x.getIDArrive()]= x.getCU().at("poids").valeur_entiere;
//     }
//
//   }
//   else if(type == INCIDENCE){ // Matrice incidence
//     this->type = type;
//     int cmptV=G.getListe_Sommets().size(),
//         cmptE=G.getListe_Arcs().size();
//
//
//     this->taille_V = cmptV;
//     this->taille_E = cmptE;
//
//     this->tab.resize(cmptV);  //on redimensionne la Matrice
//     for(int i=0;i<cmptV;i++){
//       this->tab[i].resize(cmptE);
//     }
//     for(Arc x : G.getListe_Arcs()){
//       this->tab[x.getIDDepart()][x.getID()]=1;
//       this->tab[x.getIDArrive()][x.getID()]=-1;
//     }
//   }
//   else{ //erreur création d'une Matrice vide
//     std::cout << "/* Mauvais type de Matrice */" << '\n';
//     this->taille_V = 0;
//     this->taille_E = 0;
//     this->type = type;
//   }
 }

Matrice::Matrice(int tailleV){ //Construceur d'une matrice d'adjacence vide
  this->taille_V = tailleV;
  this->taille_E = 0;
  this->type = ADJACENCE;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleV);
  }
}

Matrice::Matrice(int tailleV, int tailleE, int t){ // Constructeur d'une matrice autre vide
  this->taille_V = tailleV;
  this->taille_E = tailleE;
  this->type = t;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleE);
  }
}

Matrice::Matrice(Matrice &M){ // Construceur de copie d'une Matrice
  this->taille_V = M.taille_V;
  this->taille_E = M.taille_E;
  this->type = M.type;
  this->tab = M.tab;
}

Matrice::~Matrice(){}

//Getters
int Matrice::gettV(){return this->taille_V;}
int Matrice::gettE(){return this->taille_E;}
int Matrice::getType(){return this->type;}
vector<vector <int>> Matrice::getTab(){return this->tab;}

//Setters
void Matrice::setV(int v){this->taille_V = v;}
void Matrice::setE(int e){this->taille_E = e;}
void Matrice::setType(int type){this->type = type;}
void Matrice::setTab(vector<vector <int>> tab){this->tab=tab;}

//Méthodes
Matrice Matrice::conversion_incidence(){
//conversion d'une matrice d'adjacence en matrice d'incidence
  if(this->type == ADJACENCE){
    this->type = INCIDENCE;
    int cmp=0;
    for(int i=0;i<this->taille_E;i++){
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j])cmp++;
      }
    }

    Matrice res(this->taille_V,cmp,INCIDENCE);
    //a finir
    cmp=0;
    for(int i=0;i<this->taille_V;i++){
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j]){
          res.tab[i][cmp] = 1; //arc sortant
          res.tab[j][cmp] = -1; //arc entrant
          cmp++;

        }
      }
    }
    return res;

  }
  else{
    std::cout << "/* Mauvaise conversion  */" << '\n';
    return *this;
  }
}

Matrice Matrice::inversion_Matrice(){
  Matrice res(*this);
  res.type = this->type;
  res.taille_E = this->taille_E;
  res.taille_V = this->taille_V;
  if(this->type == ADJACENCE){
    for(int i=0;i<this->taille_V;i++){
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j]==0)
          res.tab[i][j]= 1 ;
        else  res.tab[i][j]= 0 ;

      }
    }

  }
  else{
    for(int i=0;i<this->taille_V;i++){
      for(int j=0;j<this->taille_E;j++){
        if(this->tab[i][j]==0)
          res.tab[i][j]= 1 ;
        else  res.tab[i][j]= 0 ;
      }
    }
  }

  return res;
}

Graphe Matrice::conversionGraphe(){
  Graphe res(*this);
  return res;
}

int Matrice::Sommet_non_isole(){ // Cherche si un Sommet est isolé
  int cmp;
  if(this->type == ADJACENCE){ // Pour une matrice d'Adjacence
    for(int i=0; i<this->taille_V;i++){
      cmp = 0;
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j]){
          cmp++;
        }
        if(this->tab[j][i]){
          cmp++;
        }
      }
      if(!cmp) return 0; // Sommet isolé
    }
  }
  else{
    for (int i=0; i<this->taille_V;i++){
      cmp = 0;
      for(int j=0; j<this->taille_E;j++){
        if(this->tab[i][j]){
          cmp++;
        }
      }
      if(!cmp) return 0; // Sommet isolé
    }
  }
  return 1; // Pas de sommet isolé

}

int Matrice::modifTab(int x, int y, int n){ // Modifie la case [x][y]
  if(this->type==ADJACENCE){
    if((x>=this->taille_V)||(x<0)||(y>=this->taille_V)||(y<0)){
      // Cas d'erreur x ou y hors de la taille des Matrices
      std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
      return -1;
    }
    else{
      this->tab[x][y]=n;
      return 1;
    }

  }
  else{
    if((x>=this->taille_V)||(x<0)||(y>=this->taille_E)||(y<0)){
      // Cas d'erreur x ou y hors de la taille des Matrices
      std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
      return -1;
    }
    else{
      this->tab[x][y]=n;
      return 1;
    }
  }
}

// void Matrice::supprLigne(int x){ // Suprimme une ligne
//   // Matrice res();
//
//   if((x<0)||(x>this->taille_V)){
//     std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
//     std::cout << "/* Nothing happend */" << '\n';
//   }
//   else{
//     if(this->type == ADJACENCE){
//       this->type = QUELCONQUE;
//       this->taille_E=this->taille_V;
//       //this->taille_V--;
//       for(int i=x;i<this->taille_V;i++){}
//
//     }
//     else{
//       this->type = QUELCONQUE;
//
//     }
//
//   }
//
// }
//
// void Matrice::supprCol(int y){ //supprime une colonne
//
// }

bool Matrice::operator==(Matrice & M1){
  if(
  (this->taille_E == M1.gettE())
  && (this->taille_V == M1.gettV())
  && (this->type == M1.getType())
  && (this->tab == M1.getTab())
  )
  return 1;
  else return 0;


}

bool Matrice::operator!=(Matrice & M1){
  if(
     this->taille_E != M1.gettE()
  || this->taille_V != M1.gettV()
  || this->type != M1.getType()
  || this->tab != M1.getTab()
  )
  return 1;
  else return 0;
  }

  Matrice Matrice::operator=(Matrice & M1){
  this->taille_E = M1.gettE();
  this->taille_V = M1.gettV();
  this->type = M1.getType();
  this->tab = M1.getTab();
  return *this;
  }
