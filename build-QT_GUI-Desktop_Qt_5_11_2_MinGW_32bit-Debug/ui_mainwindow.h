/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton_got;
    QWidget *tab_2;
    QPushButton *save_button;
    QGroupBox *mat1_groupBox;
    QLabel *label_2;
    QLabel *matrix_height;
    QLabel *matrix_length;
    QGroupBox *mat2_groupBox;
    QLabel *filepath2_label;
    QLabel *matrix2_height;
    QLabel *matrix2_length;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QSpinBox *x_spinBox;
    QPushButton *change_pixel_button;
    QLabel *label_6;
    QSpinBox *y_spinBox;
    QLabel *label_5;
    QComboBox *color_comboBox;
    QGroupBox *result_groupBox;
    QLabel *matrix_label;
    QFrame *frame;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QPushButton *pushButton_crypto;
    QPushButton *rand_mat_button;
    QWidget *tab;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(676, 557);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        verticalLayout = new QVBoxLayout(tab_1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        spinBox = new QSpinBox(tab_1);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        verticalLayout->addWidget(spinBox);

        pushButton_got = new QPushButton(tab_1);
        pushButton_got->setObjectName(QStringLiteral("pushButton_got"));

        verticalLayout->addWidget(pushButton_got);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        save_button = new QPushButton(tab_2);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(560, 420, 80, 21));
        mat1_groupBox = new QGroupBox(tab_2);
        mat1_groupBox->setObjectName(QStringLiteral("mat1_groupBox"));
        mat1_groupBox->setGeometry(QRect(10, 0, 120, 80));
        label_2 = new QLabel(mat1_groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 45, 16));
        matrix_height = new QLabel(mat1_groupBox);
        matrix_height->setObjectName(QStringLiteral("matrix_height"));
        matrix_height->setGeometry(QRect(10, 40, 101, 16));
        matrix_length = new QLabel(mat1_groupBox);
        matrix_length->setObjectName(QStringLiteral("matrix_length"));
        matrix_length->setGeometry(QRect(10, 60, 101, 16));
        mat2_groupBox = new QGroupBox(tab_2);
        mat2_groupBox->setObjectName(QStringLiteral("mat2_groupBox"));
        mat2_groupBox->setGeometry(QRect(10, 100, 120, 80));
        filepath2_label = new QLabel(mat2_groupBox);
        filepath2_label->setObjectName(QStringLiteral("filepath2_label"));
        filepath2_label->setGeometry(QRect(10, 20, 45, 16));
        matrix2_height = new QLabel(mat2_groupBox);
        matrix2_height->setObjectName(QStringLiteral("matrix2_height"));
        matrix2_height->setGeometry(QRect(10, 40, 101, 16));
        matrix2_length = new QLabel(mat2_groupBox);
        matrix2_length->setObjectName(QStringLiteral("matrix2_length"));
        matrix2_length->setGeometry(QRect(10, 60, 101, 16));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(460, 0, 141, 151));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 47, 13));
        x_spinBox = new QSpinBox(groupBox_3);
        x_spinBox->setObjectName(QStringLiteral("x_spinBox"));
        x_spinBox->setGeometry(QRect(60, 30, 71, 22));
        change_pixel_button = new QPushButton(groupBox_3);
        change_pixel_button->setObjectName(QStringLiteral("change_pixel_button"));
        change_pixel_button->setGeometry(QRect(50, 120, 80, 21));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 90, 31, 16));
        y_spinBox = new QSpinBox(groupBox_3);
        y_spinBox->setObjectName(QStringLiteral("y_spinBox"));
        y_spinBox->setGeometry(QRect(60, 60, 71, 22));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 47, 16));
        color_comboBox = new QComboBox(groupBox_3);
        color_comboBox->addItem(QString());
        color_comboBox->addItem(QString());
        color_comboBox->setObjectName(QStringLiteral("color_comboBox"));
        color_comboBox->setGeometry(QRect(60, 90, 72, 22));
        result_groupBox = new QGroupBox(tab_2);
        result_groupBox->setObjectName(QStringLiteral("result_groupBox"));
        result_groupBox->setGeometry(QRect(10, 200, 120, 80));
        matrix_label = new QLabel(result_groupBox);
        matrix_label->setObjectName(QStringLiteral("matrix_label"));
        matrix_label->setEnabled(true);
        matrix_label->setGeometry(QRect(10, 30, 101, 41));
        matrix_label->setMinimumSize(QSize(0, 13));
        frame = new QFrame(tab_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 420, 641, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(120, 0, 91, 51));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(10, 20, 72, 22));
        pushButton_crypto = new QPushButton(frame);
        pushButton_crypto->setObjectName(QStringLiteral("pushButton_crypto"));
        pushButton_crypto->setGeometry(QRect(20, 10, 80, 21));
        rand_mat_button = new QPushButton(frame);
        rand_mat_button->setObjectName(QStringLiteral("rand_mat_button"));
        rand_mat_button->setGeometry(QRect(270, 10, 131, 21));
        tabWidget->addTab(tab_2, QString());
        frame->raise();
        save_button->raise();
        mat1_groupBox->raise();
        mat2_groupBox->raise();
        groupBox_3->raise();
        result_groupBox->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "File Path:", nullptr));
        pushButton_got->setText(QApplication::translate("MainWindow", "Load", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Game of Life", nullptr));
        save_button->setText(QApplication::translate("MainWindow", "Save", nullptr));
        mat1_groupBox->setTitle(QApplication::translate("MainWindow", "Matrix 1:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "File Path:", nullptr));
        matrix_height->setText(QApplication::translate("MainWindow", "Matrix Height:", nullptr));
        matrix_length->setText(QApplication::translate("MainWindow", "Matrix Length:", nullptr));
        mat2_groupBox->setTitle(QApplication::translate("MainWindow", "Matrix 2:", nullptr));
        filepath2_label->setText(QApplication::translate("MainWindow", "File Path:", nullptr));
        matrix2_height->setText(QApplication::translate("MainWindow", "Matrix Height:", nullptr));
        matrix2_length->setText(QApplication::translate("MainWindow", "Matrix Length:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Change Pixel:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "X Coord:", nullptr));
        change_pixel_button->setText(QApplication::translate("MainWindow", "Change Pixel", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Color:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Y Coord:", nullptr));
        color_comboBox->setItemText(0, QApplication::translate("MainWindow", "Black", nullptr));
        color_comboBox->setItemText(1, QApplication::translate("MainWindow", "White", nullptr));

        result_groupBox->setTitle(QApplication::translate("MainWindow", "Result:", nullptr));
        matrix_label->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Mode:", nullptr));
        pushButton_crypto->setText(QApplication::translate("MainWindow", "Load", nullptr));
        rand_mat_button->setText(QApplication::translate("MainWindow", "Generate Random Matrix", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Krypto", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
