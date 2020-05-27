/********************************************************************************
** Form generated from reading UI file 'modifObjet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFOBJET_H
#define UI_MODIFOBJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModifObjet
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditEtiquette;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QFormLayout *formLayout;
    QTableWidget *tableWidget;
    QPushButton *supprimeButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *NomlineEdit;
    QLineEdit *ValeurlineEdit;
    QPushButton *addTacheButton;
    QFrame *line_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(365, 440);
        verticalLayout_3 = new QVBoxLayout(Dialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lineEditEtiquette = new QLineEdit(Dialog);
        lineEditEtiquette->setObjectName(QStringLiteral("lineEditEtiquette"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditEtiquette);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        line = new QFrame(Dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, line);


        verticalLayout->addLayout(formLayout_2);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        tableWidget = new QTableWidget(Dialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tableWidget);

        supprimeButton = new QPushButton(Dialog);
        supprimeButton->setObjectName(QStringLiteral("supprimeButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, supprimeButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        NomlineEdit = new QLineEdit(Dialog);
        NomlineEdit->setObjectName(QStringLiteral("NomlineEdit"));

        horizontalLayout->addWidget(NomlineEdit);

        ValeurlineEdit = new QLineEdit(Dialog);
        ValeurlineEdit->setObjectName(QStringLiteral("ValeurlineEdit"));

        horizontalLayout->addWidget(ValeurlineEdit);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);

        addTacheButton = new QPushButton(Dialog);
        addTacheButton->setObjectName(QStringLiteral("addTacheButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addTacheButton);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(Dialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "**Modification**", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Etiquette", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Charge Utile :", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "Valeur", Q_NULLPTR));
        supprimeButton->setText(QApplication::translate("Dialog", "Supprimer", Q_NULLPTR));
        NomlineEdit->setPlaceholderText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        ValeurlineEdit->setPlaceholderText(QApplication::translate("Dialog", "Valeur", Q_NULLPTR));
        addTacheButton->setText(QApplication::translate("Dialog", "Ajouter t\303\242che", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifObjet: public Ui_ModifObjet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFOBJET_H
