/********************************************************************************
** Form generated from reading UI file 'ktalk.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KTALK_H
#define UI_KTALK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kTalk
{
public:

    void setupUi(QWidget *kTalk)
    {
        if (kTalk->objectName().isEmpty())
            kTalk->setObjectName(QStringLiteral("kTalk"));
        kTalk->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("\350\217\257\345\272\267\345\260\221\345\245\263\346\226\207\345\255\227W6"));
        kTalk->setFont(font);

        retranslateUi(kTalk);

        QMetaObject::connectSlotsByName(kTalk);
    } // setupUi

    void retranslateUi(QWidget *kTalk)
    {
        kTalk->setWindowTitle(QApplication::translate("kTalk", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class kTalk: public Ui_kTalk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KTALK_H
