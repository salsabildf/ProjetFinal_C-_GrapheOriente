#include "UI_modifObjet.hh"
#include <utility>
#include <string>
#include "../../../bib/bib.hh"

// class Ui_Dialog {
// public:
//
//     QLineEdit *lineEditEtiquette;	/// Permet de modifier l'etiquette qui s'affiche en placeholder
//     QTableWidget *tableWidget;		/// Afficher l'ensemble des charges utiles (stock&eacute;e sous forme de map)
//     QPushButton *supprimeButton;	/// Permet de supprimer la charge utile selectionn&eacute;e par l'utilisateur
//     QLineEdit *NomlineEdit;	/// Permet d'entrer le nom d'une future charge utile
//     QLineEdit *ValeurlineEdit;	/// Permet d'entrer la valeur d'une nouvelle charge utile
//     QPushButton *addTacheButton;	/// Permet d'afficher le tableau des valeurs entr&eacute;es dans les lineEdit
//
//     /**
//      * \brief Valide ou Annule les modifications
//      * Si valide&eacute;, les informations du tableau et de la zone d'edition remplacerons celles deja presentes dans res
//      * */
//     QDialogButtonBox *buttonBox;
//
// };

namespace Ui {
class ModifObjet;
}

class modifObjet : public QDialog {
Q_OBJECT
private:
    Ui::ModifObjet *ui;

    pair<string, map<string,VectVal>> res;
public:
  QString getetq();
  map <string, VectVal> getCU();
  void setListCU(map <string, VectVal> SCharge_utile);
  void setEtq(QString s);
	/**
	 * Constructeur de modifObjet
	 * Constructeur de la fen&ecirc;tre
	 * Affiche dans le tableau les informations de l'objet cliqu&eacute; et son etiquette dans le champ dedi&eacute;
	 * Informations affect&eacute;es dans res
	 * res[0] egal &agrave; l'etiquette
	 * res[1] egal &agrave; la map embarquant la charge utile
	 * */
    modifObjet(QWidget *parent = nullptr);
    ~modifObjet();	/// Destructeur de la fenetre


public slots:
    void supprimeCU();	/// Supprime la charge utile en surbrillance
    void addCU();		/// Ajoute une charge utile respectant les informations entr&eacute;es dans les lineEdit

};
