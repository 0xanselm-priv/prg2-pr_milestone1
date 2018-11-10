#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QPainter>
#include <QTextStream>
#include <QDate>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Encrypt");
    ui->comboBox->addItem("Decrypt");
    ui->comboBox->addItem("Overlap");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->matrix_label->setScaledContents(true);
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

void MainWindow::print_int(int i) {
    QString j = QString::number(i);
    qDebug(j.toLatin1());
}

void MainWindow::print(QString j) {
    qDebug(j.toLatin1());
}

void MainWindow::print_str(string j) {
    print(QString::fromStdString(j));
}

void MainWindow::print_bool(bool j) {
    if (j == 0) {
        qDebug("False");
    } else {
        qDebug("True");
    }
}


void MainWindow::on_pushButton_crypto_clicked()
{
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "C:/Users/R/Desktop", filter);
    QString s = file_name;
    ui->label_2->setText("File Path: " + file_name);
    ui->label_2->adjustSize();
    global_filepath = file_name.toUtf8().constData();
    print_str(global_filepath);
    ui->pushButton_3->setEnabled(true);

    NBild int_canvas;
    vector < vector<int> > matrix = int_canvas.import_file(global_filepath);

    const int height = int_canvas.get_height();
    const int length = int_canvas.get_length();

    ui->matrix_length->setText("Matrix Length: " + QString::number(length));
    ui->matrix_height->setText("Matrix Height: " + QString::number(height));


    this->matrix_display(matrix, height, length);
}

void MainWindow::matrix_display(vector < vector<int> > matrix, int height, int length) {

    QPixmap pixmap(height*4, length*4);
    pixmap.fill(QColor("transparent"));

    print_int(matrix[0][0]);

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    int counter = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 1) {
                painter.drawPoint(j,i);
                //ui->matrix_label->setPixmap(pixmap);
            }
            counter++;
        }
    }
    ui->matrix_label->setPixmap(pixmap);
    ui->matrix_label->adjustSize();
    ui->pushButton_3->setEnabled(true);
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    print_int(ui->spinBox->value());
}

void MainWindow::on_pushButton_clicked()
{
    // i am just changing things to work out git.
    // :)
    // i am wondering y git wont recognize my file changes
    QFile file("../ProgPrak1819/Qt_PP_1819_GUI/test.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text |QFile::Append)) {
        print("Error. Not possible to write");
    } else {
        QTextStream out(&file);
        QString text = "this is a stupid test.";
        out << text;
        file.flush();
        file.close();
        print("Saved file");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //    NBild test;
    //    qDebug("NBild Object generated");
    //    test.export_file("void");
    //    int height = ui->label->height();
    //    int width = ui->label->width();

    //    int height = int_canvas.get_height();
    //    int width = int_canvas.get_length();

    //    QPixmap pixmap(width, height);
    //    pixmap.fill(QColor("transparent"));

    //    QPainter painter (&pixmap);
    //    painter.setBrush(Qt::red);
    //    int counter = 0;
    //    for (int i = 0; i < height; i++) {
    //        for (int j = 0; j < width; j++) {
    //            if (counter % 2 == 0) {
    //                painter.drawPoint(j,i);
    //                ui->matrix_label->setPixmap(pixmap);
    //            }
    //            counter++;
    //        }
    //    }
    //    //ui->label->setPixmap(pixmap);
    //    ui->pushButton_3->setEnabled(true);

}

void MainWindow::on_pushButton_3_clicked()
{
    // Start Button
    //interface interface_n;
    //interface_n.prog2();
    //int_canvas.get_height();
}
