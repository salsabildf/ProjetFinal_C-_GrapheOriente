#include "gestion_fichier.hh"
#include "../../../libExt/rapidjson/writer.h"
#include "../../../libExt/rapidjson/prettywriter.h"
#include "../../../libExt/rapidjson/istreamwrapper.h"
#include "../../../libExt/rapidjson/schema.h"

#include <fstream>
#include <iterator>
#include <map>
#include <iostream>

using namespace rapidjson;

int sauvegarde(Graphe G, string path){

  // sauvegarde classique
if (path == ""){

     StringBuffer s;
     PrettyWriter <StringBuffer> writer(s);
     writer.StartObject();
     writer.SetMaxDecimalPlaces (3);

     writer.Key("etiquette");
     writer.String(G.getEtiq().c_str());

     writer.Key ("path");
     writer.String(G.getPath().c_str());

     writer.Key ("listeS");
     writer.StartArray ();
     //Boucle pour les Sommets
     for (int i = 0; i < G.getListe_Sommets().size() ; i++ ){

      writer.StartObject ();

       writer.Key ("x");
       writer.Uint (G.getListe_Sommets()[i].getPosX());

       writer.Key ("y");
       writer.Uint (G.getListe_Sommets()[i].getPosY());

       writer.Key ("id");
       writer.Uint (G.getListe_Sommets()[i].getID());

       writer.Key("etiquette");
       writer.String(G.getListe_Sommets()[i].getEtiq().c_str());

       writer.Key ("vecArc");
       writer.StartArray();
       //Boucle pour savoir a quels arcs le sommet et relié
        for (int j = 0; j < G.getListe_Sommets()[i].getVecArc().size() ;j++){
          writer.StartObject();
          writer.Key("Tab");
          writer.Uint (G.getListe_Sommets()[i].getVecArc()[j]);
          writer.EndObject();
        }
       writer.EndArray();



       // Poids sur les sommets avec des valeurs entieres ou reelles
       writer.Key("SChargeUtile");
       writer.StartArray ();
       /*Iterateur sur la liste de sommets pour les poids*/
       map<string, VectVal>::iterator itr = G.getListe_Sommets()[i].getCU().begin();
       map<string, VectVal> m  = G.getListe_Sommets()[i].getCU();


        while (itr != m.end()){

         string mot = itr->first; // Accede au premier champs de la map (string)
         VectVal V = itr->second; // Accede au deuxieme champs de la map (VectVal)
         writer.StartObject();
         writer.Key("mot");
         writer.String(mot.c_str());
         writer.Key("type");
         writer.Uint(V.type);

         if (V.type == 1){
           writer.Key("Valeur_reel");
           writer.Double(V.valeur_reel);
         }
         if (V.type == 0){
           writer.Key("Valeur_entiere");
           writer.Uint(V.valeur_entiere);
         }

         writer.EndObject();
         itr ++;

       }
       writer.EndArray (); // Fin de SChargeUtile

     writer.EndObject(); //Fin de listeS
     }

     writer.EndArray (); // Fin des Sommets





     writer.Key ("listeA");
     writer.StartArray ();
     //Boucle pour les Sommets
     for (int i = 0; i < G.getListe_Arcs().size() ; i++ ){

      writer.StartObject ();

       writer.Key ("id");
       writer.Uint (G.getListe_Arcs()[i].getID());

       writer.Key ("etiquette");
       writer.String (G.getListe_Arcs()[i].getEtiq().c_str());

       writer.Key ("IDdepart");
       writer.Uint (G.getListe_Arcs()[i].getIDDepart());

       writer.Key("IDarrive");
       writer.Uint(G.getListe_Arcs()[i].getIDArrive());



       writer.Key("AChargeUtile");
       writer.StartArray();

       map<string, VectVal> map2 = G.getListe_Arcs()[i].getCU();
       map<string, VectVal>::iterator itr = map2.begin();

       while (itr != map2.end()){

         string mot2 = itr->first;
         VectVal V2 = itr->second;

         writer.StartObject();

         writer.Key("mot");
         writer.String(mot2.c_str());
         writer.Key("type");
         writer.Uint(V2.type);

           if (V2.type == 1){
             writer.Key("Valeur_reel");
             writer.Double(V2.valeur_reel);
           }
           if (V2.type == 0){
             writer.Key("Valeur_entiere");
             writer.Uint(V2.valeur_entiere);
           }

         writer.EndObject();
         itr ++;
       }

       writer.EndArray(); // Fin de AChargeUtile


       writer.EndObject(); // Fin de listeA
     }

       writer.EndArray (); // Fin des Arcs


   writer.EndObject(); // Fin du fichier


     // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
     std::ofstream o(G.getPath().c_str());
     o<<s.GetString ();

      if (!o.good())
        return 1;

    return 0;
  }



  // sauvegarde sous
  if (path != ""){

    StringBuffer s;
    PrettyWriter <StringBuffer> writer(s);
    writer.StartObject();

    writer.Key("etiquette");
    writer.String(G.getEtiq().c_str());

    writer.Key ("path");
    writer.String(path.c_str());

    writer.Key ("listeS");
    writer.StartArray ();
    //Boucle pour les Sommets
    for (int i = 0; i < G.getListe_Sommets().size() ; i++ ){

     writer.StartObject ();

      writer.Key ("x");
      writer.Uint (G.getListe_Sommets()[i].getPosX());

      writer.Key ("y");
      writer.Uint (G.getListe_Sommets()[i].getPosY());

      writer.Key ("id");
      writer.Uint (G.getListe_Sommets()[i].getID());

      writer.Key("etiquette");
      writer.String(G.getListe_Sommets()[i].getEtiq().c_str());

      writer.Key ("vecArc");
      writer.StartArray();
      //Boucle pour savoir a quels arcs le sommet et relié
       for (int j = 0; j < G.getListe_Sommets()[i].getVecArc().size() ;j++){
         writer.StartObject();
         writer.Key("Tab");
         writer.Uint (G.getListe_Sommets()[i].getVecArc()[j]);
         writer.EndObject();
       }
      writer.EndArray();



      // Poids sur les sommets avec des valeurs entieres ou reelles
      writer.Key("SChargeUtile");
      writer.StartArray ();
      /*Iterateur sur la liste de sommets pour les poids*/
      map<string, VectVal>::iterator itr = G.getListe_Sommets()[i].getCU().begin();
      map<string, VectVal> m  = G.getListe_Sommets()[i].getCU();


       while (itr != m.end()){

        string mot = itr->first; // Accede au premier champs de la map (string)
        VectVal V = itr->second; // Accede au deuxieme champs de la map (VectVal)
        writer.StartObject();
        writer.Key("mot");
        writer.String(mot.c_str());
        writer.Key("type");
        writer.Uint(V.type);

        if (V.type == 1){
          writer.Key("Valeur_reel");
          writer.Double(V.valeur_reel);
        }
        if (V.type == 0){
          writer.Key("Valeur_entiere");
          writer.Uint(V.valeur_entiere);
        }

        writer.EndObject();
        itr ++;

      }
      writer.EndArray (); // Fin de SChargeUtile

    writer.EndObject(); //Fin de listeS
    }

    writer.EndArray (); // Fin des Sommets





    writer.Key ("listeA");
    writer.StartArray ();
    //Boucle pour les Sommets
    for (int i = 0; i < G.getListe_Arcs().size() ; i++ ){

     writer.StartObject ();

      writer.Key ("id");
      writer.Uint (G.getListe_Arcs()[i].getID());

      writer.Key ("etiquette");
      writer.String (G.getListe_Arcs()[i].getEtiq().c_str());

      writer.Key ("IDdepart");
      writer.Uint (G.getListe_Arcs()[i].getIDDepart());

      writer.Key("IDarrive");
      writer.Uint(G.getListe_Arcs()[i].getIDArrive());



      writer.Key("AChargeUtile");
      writer.StartArray();

      map<string, VectVal> map2 = G.getListe_Arcs()[i].getCU();
      map<string, VectVal>::iterator itr = map2.begin();

      while (itr != map2.end()){

        string mot2 = itr->first;
        VectVal V2 = itr->second;

        writer.StartObject();
        writer.Key("mot");
        writer.String(mot2.c_str());
        writer.Key("type");
        writer.Uint(V2.type);

          if (V2.type == 1){
            writer.Key("Valeur_reel");
            writer.Double(V2.valeur_reel);
          }
          if (V2.type == 0){
            writer.Key("Valeur_entiere");
            writer.Uint(V2.valeur_entiere);
          }

        writer.EndObject();
        itr ++;
      }
      writer.EndArray(); // Fin de AChargeUtile
      writer.EndObject(); // Fin de listeA
    }
      writer.EndArray (); // Fin des Arcs
  writer.EndObject(); // Fin du fichier


    // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
    std::ofstream o(path.c_str());
    o<<s.GetString ();
     if (!o.good())
       return 1;
   return 0;
 }

  return 0; //

}



Graphe chargement (string path){



  ifstream fichier(path);
  IStreamWrapper fic (fichier);

  rapidjson::Document doc;

  doc.ParseStream<0>(fic);
  if (verif_file (path) == false ){
    Graphe G1 ("erreur");
    return G1;
  }

  string chemin = doc["path"].GetString(); // Recupere le path du graphe
  string etiq = doc ["etiquette"].GetString(); // Recupere le nom du Graphe

  vector <Sommet> LISTESOM;
  int compteurSom = doc["listeS"].Size();
  LISTESOM.resize (compteurSom, Sommet (0));

  vector <Arc> LISTEARC;
  int compteurArc = doc["listeA"].Size();
  LISTEARC.resize(compteurArc,Arc (0,0,0));


  for (int i = 0; i<doc["listeS"].Size(); i++){
    LISTESOM[i].setPosX (doc["listeS"][i]["x"].GetInt());
    LISTESOM[i].setPosY (doc["listeS"][i]["y"].GetInt());
    LISTESOM[i].setID(doc["listeS"][i]["id"].GetInt());
    LISTESOM[i].setEtiq(doc["listeS"][i]["etiquette"].GetString());


   //  vector <int> VecteurArc;
   //  VecteurArc.resize(doc["listeS"][i]["vecArc"].Size() ,0);
   //
   //  for (int j = 0; j <  doc["listeS"][i]["vecArc"].Size(); j++){
   //    VecteurArc[j] = doc["listeS"][i]["vecArc"][j]["Tab"].GetInt();
   //  }
   //
   //
   // LISTESOM[i].setVecArc(VecteurArc);


      map <string, VectVal> m1;

      for (int j = 0; j < doc["listeS"][i]["SChargeUtile"].Size(); j++){

        string nom = doc["listeS"][i]["SChargeUtile"][j]["mot"].GetString();
        VectVal v;

        v.type = doc["listeS"][i]["SChargeUtile"][j]["type"].GetInt();
          if (v.type == 0){
            v.valeur_entiere = doc["listeS"][i]["SChargeUtile"][j]["Valeur_entiere"].GetInt();
            v.valeur_reel = 0;
          }
          if (v.type == 1){
            v.valeur_reel = doc["listeS"][i]["SChargeUtile"][j]["Valeur_reel"].GetDouble();
            v.valeur_entiere = 0;
          }

          m1.insert(pair<string,VectVal> (nom, v));
      }


    LISTESOM[i].setCU(m1);

  }





  for (int i = 0; i < doc["listeA"].Size(); i++){
    LISTEARC[i].setID(doc["listeA"][i]["id"].GetInt());
    LISTEARC[i].setEtiq(doc["listeA"][i]["etiquette"].GetString());
    LISTEARC[i].setIDDepart(doc["listeA"][i]["IDdepart"].GetInt());
    LISTEARC[i].setIDArrive(doc["listeA"][i]["IDarrive"].GetInt());

    map <string, VectVal> m1;

    for (int j = 0; j < doc["listeA"][i]["AChargeUtile"].Size(); j++){

      string nom = doc["listeA"][i]["AChargeUtile"][j]["mot"].GetString();
      VectVal v;

      v.type = doc["listeA"][i]["AChargeUtile"][j]["type"].GetInt();
        if (v.type == 0){
          v.valeur_entiere = doc["listeA"][i]["AChargeUtile"][j]["Valeur_entiere"].GetInt();
          v.valeur_reel = 0;
        }
        if (v.type == 1){
          v.valeur_reel = doc["listeA"][i]["AChargeUtile"][j]["Valeur_reel"].GetDouble();
          v.valeur_entiere = 0;
        }

        m1.insert(pair<string,VectVal> (nom, v));
    }


    LISTEARC[i].setCU(m1);

  }




  Graphe G0 (etiq, LISTESOM, LISTEARC, chemin);


  return G0;

}


bool verif_file (string path){


    ifstream fichier(path);
    IStreamWrapper fic (fichier);

    ifstream schm("../fichierJSON/graphschema.json");
    IStreamWrapper sch(schm);


      rapidjson::Document doc;

      if( doc.ParseStream<0>(fic).HasParseError()){
        cout<<" le docuement est pas un json valide"<<endl;
        return false;
      }


      rapidjson::Document sd;

      sd.ParseStream<0>(sch);
      if (sd.HasParseError()){
        cout << "allo" << endl;
        return false;
      }


    rapidjson::SchemaDocument schema(sd);

    SchemaValidator validator(schema);
    if(!doc.Accept(validator)){
      cout<<"le fichier ne correspond pas au schéma"<<endl;
      return false;
    }

  return true;
}





int suppression (string path){
  return std::remove (path.c_str());
}
