#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Encrypt");
    ui->comboBox->addItem("Decrypt");
    ui->comboBox->addItem("Overlap");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_got_clicked()
{
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "C:/Users/R/Desktop", filter);
    QString s = file_name;
    ui->label_3->setText("File Path: " + s);
    print(file_name);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    print(ui->comboBox->currentText());
}

void MainWindow::print(int i) {
    QString j = QString::number(i);
    qDebug(j.toLatin1());
}

void MainWindow::print(QString j) {
    qDebug(j.toLatin1());
}


void MainWindow::on_pushButton_crypto_clicked()
{
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "C:/Users/R/Desktop", filter);
    QString s = file_name;
    ui->label_2->setText("File Path: " + s);
    print(file_name);
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    print(ui->spinBox->value());
}

void MainWindow::on_pushButton_clicked()
{
    // i am just changing things to work out git.
    // :)
    // i am wondering y git wont recognize my file changes
    QFile file("C:/Users/R/Documents/ProgPrak1819/txt_file_R.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text |QFile::Append)) {
        print("Error. Not possible to write");
    }
    QTextStream out(&file);
    QString text = "this is a stupid test.";
    out << text;
    file.flush();
    file.close();
    print("Saved file");
}

void MainWindow::on_pushButton_2_clicked()
{
    NBild test;
    qDebug("NBild Object generated");
    test.export_file("void");

    QImage img;
    img.load("test.png");

    QLabel label;
    labe1.setPixmap(QPixmap::fromImage(img));
    label.show();
}
