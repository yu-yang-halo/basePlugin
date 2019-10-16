/********************************************************************************
** Form generated from reading UI file 'TaihoPluginAI.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAIHOPLUGINAI_H
#define UI_TAIHOPLUGINAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaihoPluginAI
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *TaihoPluginAI)
    {
        if (TaihoPluginAI->objectName().isEmpty())
            TaihoPluginAI->setObjectName(QStringLiteral("TaihoPluginAI"));
        TaihoPluginAI->resize(636, 445);
        gridLayout = new QGridLayout(TaihoPluginAI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(TaihoPluginAI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(200, 80));
        pushButton->setMaximumSize(QSize(200, 80));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(TaihoPluginAI);

        QMetaObject::connectSlotsByName(TaihoPluginAI);
    } // setupUi

    void retranslateUi(QWidget *TaihoPluginAI)
    {
        TaihoPluginAI->setWindowTitle(QApplication::translate("TaihoPluginAI", "Form", 0));
        pushButton->setText(QApplication::translate("TaihoPluginAI", "AI Plugins(BUG)", 0));
    } // retranslateUi

};

namespace Ui {
    class TaihoPluginAI: public Ui_TaihoPluginAI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAIHOPLUGINAI_H
