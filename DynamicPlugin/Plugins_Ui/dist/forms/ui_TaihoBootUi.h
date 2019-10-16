/********************************************************************************
** Form generated from reading UI file 'TaihoBootUi.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAIHOBOOTUI_H
#define UI_TAIHOBOOTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaihoBootUi
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *TaihoBootUi)
    {
        if (TaihoBootUi->objectName().isEmpty())
            TaihoBootUi->setObjectName(QStringLiteral("TaihoBootUi"));
        TaihoBootUi->resize(785, 520);
        TaihoBootUi->setMinimumSize(QSize(200, 100));
        gridLayout = new QGridLayout(TaihoBootUi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(224, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TaihoBootUi);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(300, 50));
        label->setMaximumSize(QSize(300, 50));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(TaihoBootUi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(300, 150));
        pushButton->setMaximumSize(QSize(300, 150));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(TaihoBootUi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(300, 150));
        pushButton_2->setMaximumSize(QSize(300, 150));

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(TaihoBootUi);

        QMetaObject::connectSlotsByName(TaihoBootUi);
    } // setupUi

    void retranslateUi(QWidget *TaihoBootUi)
    {
        TaihoBootUi->setWindowTitle(QApplication::translate("TaihoBootUi", "Form", 0));
        label->setText(QApplication::translate("TaihoBootUi", "TaihoBootUi Plugins(Plugins_Ui)", 0));
        pushButton->setText(QApplication::translate("TaihoBootUi", "Send Msg to Plugins_Core", 0));
        pushButton_2->setText(QApplication::translate("TaihoBootUi", "Send Msg to Plugins_Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class TaihoBootUi: public Ui_TaihoBootUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAIHOBOOTUI_H
