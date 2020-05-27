#include "Sommet.hh"
#include <iostream>

using namespace std;

Sommet::Sommet(int posx, int posy, string etiq, int id, map <string, VectVal> v){
  this->x = posx;
  this->y = posy;
  this->ID = id;
  this->etiquette = etiq;
  this->SCharge_utile = v;

  vector<int> vecArc;
  this->vecArc = vecArc;
}

Sommet::Sommet(int posx, int posy, string etiq, int id){
  this->x = posx;
  this->y = posy;
  this->ID = id;
  this->etiquette = etiq;
  map<string, VectVal> v;
  this->SCharge_utile = v;

  vector<int> vecArc;
  this->vecArc = vecArc;
}

Sommet::Sommet(string etiq, int id){
  this->ID = id;
  this->etiquette = etiq;
  this->x = 0;
  this->y = 0;
  map<string, VectVal> v;
  this->SCharge_utile = v;
  vector<int> vecArc;
  this->vecArc = vecArc;
}

Sommet::Sommet(int id){
  this->ID = id;

  this->etiquette = to_string(id);
  this->x = 0;
  this->y = 0;
  map<string, VectVal> v;
  this->SCharge_utile = v;
  vector<int> vecArc;
  this->vecArc = vecArc;
}

Sommet::Sommet(Sommet const &S){
  this->x = S.x;
  this->y = S.y;
  this->ID = S.ID;
  this->etiquette = S.etiquette;
  this->vecArc = S.vecArc;
  this->SCharge_utile = S.SCharge_utile;
}

Sommet::~Sommet(){
  //delete(this);
}

int Sommet::getPosX(){
  return this->x;
}

int Sommet::getPosY(){
  return this->y;
}

int Sommet::getID(){
  return this->ID;
}

string Sommet::getEtiq(){
  return this->etiquette;
}

vector<int> Sommet::getVecArc(){
  return this->vecArc;
}

map <string, VectVal> Sommet::getCU(){
  return this->SCharge_utile;
}

void Sommet::setPosX(int x){
  this->x = x;
}

void Sommet::setPosY(int y){
  this->y = y;
}

void Sommet::setID(int id){
  this->ID = id;
}

void Sommet::setEtiq(string etiq){
  this->etiquette = etiq;
}

void Sommet::setVecArc(vector<int> v){
  this->vecArc = v;
}

void Sommet::setCU(map <string, VectVal> S_CU){
  this->SCharge_utile = S_CU;
}

bool Sommet::operator==(Sommet const & S1)const{
  return (this->x == S1.x)&&(this->vecArc == S1.vecArc)&&(this->y == S1.y)&&(this->ID == S1.ID)&&(this->etiquette == S1.etiquette)&&(this->SCharge_utile == S1.SCharge_utile);
}
bool Sommet::operator!=(Sommet const & S1){
  return (this->x != S1.x)||(this->vecArc != S1.vecArc)||(this->y != S1.y)||(this->ID != S1.ID)||(this->etiquette != S1.etiquette)||(this->SCharge_utile != S1.SCharge_utile);
}
Sommet Sommet::operator=(Sommet const& S1){
  this->x = S1.x;
  this->y = S1.y;
  this->ID = S1.ID;
  this->etiquette = S1.etiquette;
  this->vecArc = S1.vecArc;
  this->SCharge_utile = S1.SCharge_utile;

  return *this;
  //return S;
}
