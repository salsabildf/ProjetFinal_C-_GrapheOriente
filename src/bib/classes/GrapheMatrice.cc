#include "GrapheMatrice.hh"
#include <QDebug>

Graphe::Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path){
  this->etiquette = nom;
  this->liste_Sommets = listeS;
  this->liste_Arcs = listeA;
  this->path = path;
  int Aid;
  int id_Sdepart;

  for(int k = 0; k < this->liste_Arcs.size();++k){
    vector <int> arc_sor;
    id_Sdepart = this->liste_Arcs[k].getIDDepart();
    Aid = this->liste_Arcs[k].getID();
    for(int i = 0; i<this->liste_Sommets.size(); ++i){
      if (liste_Sommets[i].getID() == id_Sdepart){
        arc_sor = liste_Sommets[i].getVecArc();
        arc_sor.push_back(Aid);
        liste_Sommets[i].setVecArc(arc_sor);
      }
    }
  }
}

Graphe::Graphe(string nom){ // Création Graphe vide
  this->etiquette = nom;
  this->path = "\0";
}

Graphe::Graphe(Matrice& M){ // Création d'un Graphe via une matrice d'adjacence
  if(M.getType()!=0){
    std::cout << "/*Mauvais type de Matrice */" << '\n';
    this->etiquette ="ERROR_TYPEMATRICE";
  }
  else{
    this->etiquette = "Graphe Adjacence";
    int id = 0; //nombre d'arcs
    for(int i=0; i<M.gettV(); i++){
        this->liste_Sommets.push_back(Sommet(i)); // Création du Sommet avec son numéro
    }
    for(int i=0; i<M.gettV(); i++){   // ID Sommet depart
      for(int j=0; j<M.gettV(); j++){ // ID Sommet arrivée
        if(M.getTab()[i][j]){         // Si il existe un arc
          this->liste_Arcs.push_back(Arc(id, i, j)); // Création d'un Arc entre i et j avec son id
          vector <int> arc_sor;
		  arc_sor = liste_Sommets[i].getVecArc();
		  arc_sor.push_back(id);
		  this->liste_Sommets[i].setVecArc(arc_sor);


        id++; // On incrémente le nombre d'arc
        }
      }
    }
  }
  this->path = "\0";
}

Graphe::Graphe(const Graphe& G){  // Constructeur de copie
   this->etiquette = G.etiquette;
   this->liste_Sommets = G.liste_Sommets;
   this->liste_Arcs = G.liste_Arcs;
   this->path = G.path;
}

Graphe::Graphe(vector<vector<int>> liste_voisin){
   int id = 0;
   this->etiquette = "Graphe liste_voisins";
   for(int i=0; i < liste_voisin.size(); i++){
       this->liste_Sommets.push_back(Sommet(i)); // Création du Sommet avec son numéro
       for(int j=0; j<liste_voisin[i].size(); j++){
         if(liste_voisin[i][j]>=0){
         this->liste_Arcs.push_back(Arc(id, i, liste_voisin[i][j])); // Création d'un Arc entre i et j avec son id
           id++;
         }
       }
   }

   this->path = "\0";
 }

 Graphe::~Graphe(){

}

// Getters

string Graphe::getEtiq()const{return etiquette;}
vector<Arc> Graphe::getListe_Arcs()const{return liste_Arcs;}
vector<Sommet> Graphe::getListe_Sommets()const{return liste_Sommets;}
string Graphe::getPath()const{return path;}

// Setters
void Graphe::setEtiq(string etiq){this->etiquette = etiq;}
void Graphe::setListe_Arc(vector<Arc> LA){this->liste_Arcs = LA;}
void Graphe::setListe_Sommet(vector<Sommet> LS){this->liste_Sommets = LS;}
void Graphe::setPath(string p){this->path = p;}

// Méthodes
Matrice Graphe::conversion_vers_Matrice_adj(){
   return Matrice(*this, 0);
}

Matrice Graphe::conversion_vers_Matrice_inc(){
   return Matrice(*this, 1);
}

vector<vector<int>>  Graphe::conversion_vers_listeDeVoisins(){
   std::vector<std::vector<int>> v(liste_Sommets.size());
   for(int i = 0; i<liste_Arcs.size(); i++){
     v[liste_Arcs[i].getIDDepart()].push_back(liste_Arcs[i].getIDArrive());
   }
   return v;
}

int Graphe::ajout_Sommet(int id, int posx, int posy){
   this->liste_Sommets.push_back(Sommet(posx,posy,to_string(id),id));
   return id;
}

int Graphe::supprimer_Sommet(int id){
  if(id>this->liste_Sommets.size()|| id<0){
    std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
    return -1;
  }
  //suppression du Sommet
  this->liste_Sommets.erase(this->liste_Sommets.begin()+id); // Efface l'élément à la position donnée.
  //Gestion des ids des sommets suivants
  for(int i=id;i<this->liste_Sommets.size();i++){
    this->liste_Sommets[i].setID(i);
  }
  //suppression de chaque arc contenant le Sommet id
  for(int i=0;i<this->liste_Arcs.size();i++){
    if((this->liste_Arcs[i].getIDDepart()==id) || (this->liste_Arcs[i].getIDArrive()==id)){
      this->liste_Arcs.erase(this->liste_Arcs.begin()+i);
      i--;

    }
  }

  for(int i=0;i<this->liste_Arcs.size();i++){
    //correction des id Arcs
    this->liste_Arcs[i].setID(i);
    //correction des ids depart et arrive dans chaque arc arc
    if(this->liste_Arcs[i].getIDDepart()>id){
      this->liste_Arcs[i].setIDDepart(this->liste_Arcs[i].getIDDepart()-1);
    }
    if(this->liste_Arcs[i].getIDArrive()>id){
      this->liste_Arcs[i].setIDArrive(this->liste_Arcs[i].getIDArrive()-1);
    }
  }

  //On efface le vecArc de tous les sommets
  for(int i=0;i<this->liste_Sommets.size();++i){
    liste_Sommets[i].setVecArc({});
  }

 int idD;
  // On remet les bons ID
  for(int i=0;i<this->liste_Arcs.size();++i){
    idD = liste_Arcs[i].getIDDepart();
    for(int j=0;j<this->liste_Sommets.size();++j){
      if(this->liste_Sommets[j].getID() == idD){
        vector<int> vac;
        vac = this->liste_Sommets[j].getVecArc();
        vac.push_back(liste_Arcs[i].getID());
        this->liste_Sommets[j].setVecArc(vac);
      }
    }
  }
  return id;
}

int Graphe::ajout_Arc(int id_Sdepart, int id_Sarrive){
  for(int i=0;i<this->liste_Arcs.size();++i){
    if(liste_Arcs[i].getIDDepart() == id_Sdepart && liste_Arcs[i].getIDArrive() == id_Sarrive){
      return -1;
    }
  }
   int id = this->liste_Arcs.size();

   this->liste_Arcs.push_back(Arc(id,id_Sdepart,id_Sarrive));

   vector <int> arc_sor;
   for(int i = 0; i<this->liste_Sommets.size(); ++i){
     if (liste_Sommets[i].getID() == id_Sdepart){
       arc_sor = liste_Sommets[i].getVecArc();
       arc_sor.push_back(id);
       liste_Sommets[i].setVecArc(arc_sor);
     }
   }
   return id;
}

int Graphe::supprimer_Arc(int id){
  if(id>this->liste_Arcs.size()|| id<0){
    std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
    return -1;
  }
  this->liste_Arcs.erase(this->liste_Arcs.begin()+id); // Efface l'élément à la position donnée.

  for(int i=id;i<this->liste_Arcs.size();i++){
    this->liste_Arcs[i].setID(i);
  }
  return id;
}

vector<Sommet> Graphe::getVecteurSommet(vector<int> id){
   std::vector<Sommet> res;
   if(!id.empty()){
       for (int i=0; i<id.size(); i++) {
         for(int j=0;j<liste_Sommets.size();++j){
           if(id[i] == liste_Sommets[j].getID()){
             res.push_back(liste_Sommets[id[i]]);

           }
         }
       }
   }
   return res;
}

// Opérateurs
bool Graphe::operator==(Graphe const & G1) const{
  return ((this->etiquette == G1.etiquette) && (this->liste_Arcs == G1.liste_Arcs) && (this->liste_Sommets == G1.liste_Sommets) && (this->path == G1.path));
}

bool Graphe::operator!=(Graphe const& G1){
  return !(*this==G1);
}

Graphe Graphe::operator=(Graphe const& G1){
   this->etiquette = G1.etiquette;
   this->liste_Arcs = G1.liste_Arcs;
   this->liste_Sommets = G1.liste_Sommets;
   this->path = G1.path;
   return *this;
}


enum typeM{
  ADJACENCE = 0,
  INCIDENCE = 1,
  POIDS = 2,
  PARENT = 3,
  QUELCONQUE = 4
};

 Matrice::Matrice(Graphe G, int type){// Constructeur d'une matrice issue d'un Graphe
   if(type == ADJACENCE){  // Matrice Adjacence
     this->type = type;
     int cmptV=G.getListe_Sommets().size();

     this->taille_V = cmptV;
     this->taille_E = this->taille_V;

     this->tab.resize(cmptV);  // On redimensionne la Matrice
     for(int i=0;i<cmptV;i++){
       this->tab[i].resize(cmptV);
     }
     for(Arc x : G.getListe_Arcs()){//on met le poids dans la Matrice
	   if(x.getCU().empty() == false){
       if(x.getCU().count("poids") > 0){
         this->tab[x.getIDDepart()][x.getIDArrive()]= x.getCU().at("poids").valeur_entiere;
       }
       else{
        this->tab[x.getIDDepart()][x.getIDArrive()] = 1;
        }
     }
       else{
        this->tab[x.getIDDepart()][x.getIDArrive()] = 1;
        }
     }

   }
   else if(type == INCIDENCE){ // Matrice incidence
     this->type = type;
     int cmptV=G.getListe_Sommets().size(),
         cmptE=G.getListe_Arcs().size();


     this->taille_V = cmptV;
     this->taille_E = cmptE;

     this->tab.resize(cmptV);  //on redimensionne la Matrice
     for(int i=0;i<cmptV;i++){
       this->tab[i].resize(cmptE);
     }
    for(Arc x : G.getListe_Arcs()){
       this->tab[x.getIDDepart()][x.getID()]=-1;
       this->tab[x.getIDArrive()][x.getID()]=1;
    }
   }
   else{ //erreur création d'une Matrice vide
     std::cout << "/* Mauvais type de Matrice */" << '\n';
     this->taille_V = 0;
     this->taille_E = 0;
     this->type = type;
   }
 }

Matrice::Matrice(int tailleV){ //Construceur d'une matrice d'adjacence vide
  this->taille_V = tailleV;
  this->taille_E = tailleV;
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

Matrice::Matrice(const Matrice &M){ // Constructeur de copie d'une Matrice
  this->taille_V = M.taille_V;
  this->taille_E = M.taille_E;
  this->type = M.type;
  this->tab = M.tab;
}

Matrice::~Matrice(){}

//Getters
int Matrice::gettV()const{return this->taille_V;}
int Matrice::gettE()const{return this->taille_E;}
int Matrice::getType()const{return this->type;}
vector<vector <int>> Matrice::getTab()const{return this->tab;}

//Setters
void Matrice::setV(int v){this->taille_V = v;}
void Matrice::setE(int e){this->taille_E = e;}
void Matrice::setType(int type){this->type = type;}
void Matrice::setTab(vector<vector <int>> tab){this->tab=tab;}

//Méthodes
Matrice Matrice::conversion_incidence(){
//conversion d'une matrice d'adjacence en matrice d'incidence
   if(this->type == ADJACENCE){
    vector<int> indices;
    int c = 0;

    for(int i = 0 ;i<this->taille_E;i++){
      for(int j = 0;j<this->taille_V;j++){
        if(this->tab[i][j] > 0){
			indices.push_back(i);
			indices.push_back(j);
			c += 2;
		}
      }
    }
    Matrice res(this->taille_V,c/2,INCIDENCE);
    for(int k=0;k<res.taille_E;k++){
		res.tab[indices[k*2]][k] = -1;
		res.tab[indices[k*2+1]][k] = 1;
        }
    return res;

  }
  else{
    std::cout << "/* Mauvais type pour la conversion  */" << '\n';
    return *this;
  }
}

Matrice Matrice::inversion_Matrice() const{
  Matrice res(*this);
  res.type = this->type;
  res.taille_E = this->taille_E;
  res.taille_V = this->taille_V;
    for(int i=0;i<this->taille_V;i++){
      for(int j=0;j<this->taille_E;j++){
        if(this->tab[i][j]==0 && i != j)
          res.tab[i][j]= 1 ;
        else  res.tab[i][j]= 0 ;
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

    for (int i=0; i<this->taille_V;i++){
      cmp = 0;
      for(int j=0; j<this->taille_E;j++){
        if(this->tab[i][j]){
          cmp++;
        }
      }
      if(!cmp) return 0; // Sommet isolé
    }

  return 1; // Pas de sommet isolé

}

int Matrice::modifTab(int x, int y, int n){ // Modifie la case [x][y]

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


void Matrice::supprLigne(int x){ // Supprime une ligne
    if((x<0)||(x>this->taille_V)){
		std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
		std::cout << "/* Nothing happend */" << '\n';
    }

    else{
		this->taille_V--;
		this->tab.erase(this->tab.begin()+x);

		if(this->type == ADJACENCE || INCIDENCE)
		this->type = QUELCONQUE;


    }

}

 void Matrice::supprCol(int y){ //supprime une colonne
    if((y<0)||(y>this->taille_E)){
		std::cout << "/* ERROR OUT OF BOUNDS */" << '\n';
		std::cout << "/* Nothing happend */" << '\n';
    }

    else{
		this->taille_E--;
		for(int i = 0; i<taille_V; i++){

			this->tab[i].erase(this->tab[i].begin()+y);
		}

		if(this->type == ADJACENCE || INCIDENCE)
		this->type = QUELCONQUE;


    }

 }

bool Matrice::operator==(Matrice const & M1)const{
  if(
  (this->taille_E == M1.taille_E)
  && (this->taille_V == M1.taille_V)
  && (this->type == M1.type)
  && (this->tab == M1.tab)
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

  Matrice Matrice::operator=(Matrice const & M1){
  this->taille_E = M1.gettE();
  this->taille_V = M1.gettV();
  this->type = M1.getType();
  this->tab = M1.getTab();

  return *this;
  }
