# README #



## Table des matières ##
* Informations Générales
* Contenu
* Installation
* Exécution
* Auteurs



## Informations Générales ##
Cette archive contient tout les fichiers composants notre projet d'IN608, intitulé Manipulation des Graphes Orientés.
Le projet est codé en C++.
Les bibliothèques suivantes sont utilisées : 
	- Catch2 (Tests)
	- RapidJSON (Gestion des fichiers de sauvegardes)
	- Qt (interface graphique)

Ce projet à pour but de pouvoir utiliser une bibliothèque permettant la manipulation de graphe orientés et l'application d'algorithme sur ceux-ci. Mais aussi de pouvoir utiliser notre application pour créer des graphes de manière visuelle et les manipuler.   


## Contenu ##
- doc : Documentation
- fichierJSON : Tests de gestion de fichiers
- libExt : Importation des bibliothèques extérieures
- report : Cahier des Charges, Cahier des Spécification et Compte Rendu 
- src - app - fichier : Gestion de fichiers
- src - app - GUI : Interface Graphique
- src - bib - classes : Gestion de Graphes
- src - bib - algo : Opérations sur les Graphes
- test : Test des modules

## Installation/Exécution ##
Pré-requis nécessaires : Qt 5 

Exécuter le fichier `Projet-S6/src/Projet-S6-full.pro` avec l'aide de Qt pour  compiler et exécuter l'application.

Si vous souhaitez faire passer les tests aux fonctions de la bibliothèque alors utilisez `test/makefile` avec une commande de type `make test_bib_classes_Sommet` qui reprend le chemin menant aux différents fichiers.

## Auteurs ##
AIRIAU Vincent
DAFRANE Salsabil
DE FREITAS Alexandre
GODINEAU Camille
MALO Amandine
NARDIN Théo
OILLO Sébastien
PEUGNET Guillaume
TEDESCHI Hugo