/********************************************************************************
** Form generated from reading UI file 'pet.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PET_H
#define UI_PET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PetClass)
    {
        if (PetClass->objectName().isEmpty())
            PetClass->setObjectName(QStringLiteral("PetClass"));
        PetClass->resize(600, 400);
        menuBar = new QMenuBar(PetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PetClass->setStatusBar(statusBar);

        retranslateUi(PetClass);

        QMetaObject::connectSlotsByName(PetClass);
    } // setupUi

    void retranslateUi(QMainWindow *PetClass)
    {
        PetClass->setWindowTitle(QApplication::translate("PetClass", "Pet", 0));
    } // retranslateUi

};

namespace Ui {
    class PetClass: public Ui_PetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PET_H
