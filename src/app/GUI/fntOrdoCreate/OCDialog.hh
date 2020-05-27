#include "UI_ordoCreate.hh"
#include <vector>
#include "../../../bib/bib.hh"
#include <QStringList>
#include <QString>

namespace Ui {
class Dialog;
}


class ordoCreate : public QDialog {
Q_OBJECT
private:
  Ui::Dialog *ui;
  vector<pert_row> res;

public:
    ordoCreate(QWidget *parent = nullptr);
    ~ordoCreate();
    vector<pert_row> getRes();


public slots:

    void ajoutTache();
    void supprimerTache();
};
