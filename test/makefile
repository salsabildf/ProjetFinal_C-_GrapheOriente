all_test : test_bib test_app clean

test_bib: test_bib_classes test_bib_algo clean

test_app: test_app_fichier test_app_GUI clean

clean:
	rm -f *.o

# TEST BIB =====================================================================
test_bib: test_bib_classes test_bib_algo
## TEST ALGO ===================================================================
test_bib_algo:
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o
test_bib_algo_calcul_Bellman: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "Calcul Bellman"

test_bib_algo_calcul_Floyd_Warshall: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "Calcul Floyd-Warshall"

test_bib_algo_liste_floyd: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "liste floyd"

test_bib_algo_calcul_degres_entrant: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "calcul degres entrant"

test_bib_algo_calcul_degres_sortant: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "calcul degres sortant"

test_bib_algo_calcul_degres_entrant_sortant: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "calcul degres entrant sortant"

test_bib_algo_coloration_Graphe: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "coloration"

test_bib_algo_couleur_adjacente: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "couleur adjacence"

test_bib_algo_stables_Graphe: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "stables"

test_bib_algo_cliques_Graphe: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "cliques"

test_bib_algo_voisin_sommet: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "voisin sommet"

test_bib_algo_gestion_flots: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "gestion de flots"

test_bib_algo_calcul_posterite: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "calcul posterite"

test_bib_algo_pert: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "pert"

test_bib_algo_arborescence: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "arbo"

test_bib_algo_anti_arborescence: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "anti-arbo"

test_bib_algo_connexite: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "connexite"

test_bib_algo_chaine_eulerienne: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "chaine eulerienne"

test_bib_algo_chaine_hamiltonienne: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "chaine hamiltonienne"

test_bib_algo_postier_chinois: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "postier chinois"

test_bib_algo_voyageur_de_commerce: clean
	# Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/bib/algo/liste.cc -c
	# Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o liste.o test_bib/algo/liste.cc -o OUTliste.o
	./OUTliste.o "voyageur de commerce"

## TEST CLASSES ================================================================
test_bib_classes: test_bib_classes_Arc test_bib_classes_Graphe test_bib_classes_Matrice test_bib_classes_Sommet clean

test_bib_classes_Arc: clean
	#Partie code
	g++ ../src/bib/classes/Arc.cc -c
	#Partie test
	g++ Arc.o test_bib/classes/Arc.cc -o OUTarc.o
	./OUTarc.o
test_bib_classes_Graphe: clean
	#Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	#Partie test
	g++ Arc.o Sommet.o GrapheMatrice.o test_bib/classes/Graphe.cc -o OUTgraphe.o
	./OUTgraphe.o
test_bib_classes_Matrice: clean
	#Partie code
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	#Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o test_bib/classes/Matrice.cc -o OUTmatrice.o
	./OUTmatrice.o
test_bib_classes_Sommet: clean
	#Partie code
	g++ ../src/bib/classes/Sommet.cc -c
	#Partie test
	g++ Sommet.o test_bib/classes/Sommet.cc -o OUTSommet.o
	./OUTSommet.o

##==============================================================================
#===============================================================================

# TEST APP =====================================================================
test_app_fichier: clean
	#Partie code
	g++ ../src/bib/classes/GrapheMatrice.cc -c
	g++ ../src/bib/classes/Arc.cc -c
	g++ ../src/bib/classes/Sommet.cc -c
	g++ ../src/app/fichier/gestion_fichier.cc -c
	#Partie test
	g++ GrapheMatrice.o Arc.o Sommet.o gestion_fichier.o test_app/fichier/gestion_fichier.cc -o OUTFichier.o
	./OUTFichier.o

test_app_GUI: clean

test_app_GUI_fntPrincipale_mainwindow: clean
	cd test_app/GUI/fntPrincipale; \
	qmake -makefile -o Makefile MainWindow.pro; \
	make; \
	./MainWindow; \
	rm MainWindow; \
	rm *.moc; \
	rm moc_predefs.h; \
	rm .qmake.stash; \

test_app_GUI_fntPrincipale_QArc: clean
	cd test_app/GUI/fntPrincipale; \
	qmake -makefile -o Makefile QArc.pro; \
	make; \
	./QArc; \
	rm QArc; \
	rm *.moc; \
	rm moc_predefs.h; \
	rm .qmake.stash; \

test_app_GUI_fntPrincipale_QSommet: clean
	cd test_app/GUI/fntPrincipale; \
	qmake -makefile -o Makefile QSommet.pro; \
	make; \
	./QSommet; \
	rm QSommet; \
	rm *.moc; \
	rm moc_predefs.h; \
	rm .qmake.stash; \

test_app_GUI_fntPrincipale_QZoneDeDessin: clean
	cd test_app/GUI/fntPrincipale; \
	qmake -makefile -o Makefile QZoneDeDessin.pro; \
	make; \
	./QZoneDeDessin; \
	rm QZoneDeDessin; \
	rm *.moc; \
	rm moc_predefs.h; \
	rm .qmake.stash; \
#===============================================================================
