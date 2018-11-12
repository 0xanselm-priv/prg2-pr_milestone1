#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QPainter>
#include <QTextStream>
#include <QDate>
#include <QDebug>
#include <QInputDialog>
#include <exception>
#include <QMessageBox>

NBild int_canvas;
vector < vector<int> > mat;
vector < vector<int> > rand_mat;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_spinBox->setMaximum(0);
    ui->y_spinBox->setMaximum(0);
    ui->comboBox->addItem("Encrypt");
    ui->comboBox->addItem("Decrypt");
    ui->comboBox->addItem("Overlap");
    ui->matrix_label->setScaledContents(true);
    ui->change_pixel_button->setEnabled(false);
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
    QString cur_str = ui->comboBox->currentText();
    if (cur_str == "Encrypt") {
        //here
    } else if (cur_str == "Decrypt") {

    } else if (cur_str == "Overlay") {

    } else {
      //unexpected
    }
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
    NBild int_canvas;
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    QString s = file_name;
    ui->label_2->setText("File Path: " + file_name);
    ui->label_2->adjustSize();
    global_filepath = file_name.toUtf8().constData();
    print_str(global_filepath);

    vector < vector<int> > matrix = int_canvas.import_file(global_filepath);

    if (matrix.empty()) {
        ui->matrix_length->setText("Matrix Length: NaN");
        ui->matrix_height->setText("Matrix Height: NaN");

        QMessageBox::warning(this,"Input","Wrong Matrix Format");
    } else {
        mat = matrix; // for saving
        const int height = int_canvas.get_height();
        const int length = int_canvas.get_length();

        ui->matrix_length->setText("Matrix Length: " + QString::number(length));
        ui->matrix_height->setText("Matrix Height: " + QString::number(height));

        ui->x_spinBox->setMaximum(length);
        ui->y_spinBox->setMaximum(height);

        this->matrix_display(matrix, height, length);
        ui->change_pixel_button->setEnabled(true);
    }
}

void MainWindow::matrix_display(vector < vector<int> > matrix, int height, int length) {

    QPixmap pixmap(height*4, length*4);
    pixmap.fill(QColor("transparent"));

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 1) {
                painter.drawPoint(j,i);
                //ui->matrix_label->setPixmap(pixmap);
            } else if (matrix[i][j] == 0){
                //pass
            }else {
                QMessageBox::warning(this,"Input","Wrong Input Format");
                break;
            }
        }
    }
    ui->matrix_label->setPixmap(pixmap);
    ui->matrix_label->adjustSize();
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

void MainWindow::on_save_button_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Matrix Save");
    msgBox.setText("Which Matrix to save.");
    msgBox.addButton(tr("Random User generated"), QMessageBox::NoRole);
    msgBox.addButton(tr("Loaded Matrix"), QMessageBox::YesRole);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec() == QMessageBox::YesRole){
        if (mat.empty()) {
            QMessageBox::warning(this,"Save","Matrix to save is empty. Please create Matrix befor saving");
        } else {
            QString filter = "Text File (*.txt)";
            QString save_path = QFileDialog::getSaveFileName(this, "Save file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
            QFile file(save_path);
            int_canvas.export_file(save_path.toUtf8().constData(), mat);
        }
    }else {
        if (rand_mat.empty()) {
            QMessageBox::warning(this,"Save","Random Matrix to save is empty. Please create random Matrix befor saving");
        } else {
            QString filter = "Text File (*.txt)";
            QString save_path = QFileDialog::getSaveFileName(this, "Save file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
            QFile file(save_path);
            int_canvas.export_file(save_path.toUtf8().constData(), rand_mat);
        }
    }
    //    if (mat.empty()) {
    //        QMessageBox::warning(this,"Save","Matrix to save is empty. Please create Matrix befor saving");
    //    } else {
    //        QString filter = "Text File (*.txt)";
    //        QString save_path = QFileDialog::getSaveFileName(this, "Save file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    //        QFile file(save_path);
    //        int_canvas.export_file(save_path.toUtf8().constData(), mat);
    //    }
}

void MainWindow::on_rand_mat_button_clicked()
{
    ui->change_pixel_button->setEnabled(false);

    vector < vector<int> > rand_mat;

    QString text = QInputDialog::getText(this,"Random Matrix","Please Enter Random Matrix Size \n separated by ; eg(13;37) \n (m dimension ; n dimension)");

    QRegExp input_rex("[0-9]*;[0-9]*");
    input_rex.setPatternSyntax(QRegExp::RegExp);
    QRegExpValidator regValidator(input_rex, 0);
    bool rex_bool = input_rex.exactMatch(text);
    if (rex_bool) {
        vector < vector<int> > rand_mat;
        QStringList a = text.split(";");
        string height_str = a[0].toUtf8().constData();
        string length_str = a[1].toUtf8().constData();
        int height = atoi(height_str.c_str());
        int length = atoi(height_str.c_str());
        rand_mat = int_canvas.create_rand_picture(height, length);
        this->update_mat(rand_mat);
        this->matrix_display(rand_mat, height, length);
    } else {
        QMessageBox::warning(this,"Wrong Input","Please repeat the input.");
    }


}

void MainWindow::update_mat(vector < vector<int> >& matrix){
    rand_mat = matrix;
}

void MainWindow::on_change_pixel_button_clicked()
{
    int x_coord = ui->x_spinBox->value();
    int y_coord = ui->y_spinBox->value();
    QString color_qstr = ui->color_comboBox->currentText();
    string color = color_qstr.toUtf8().constData();
    mat = int_canvas.change_pixel(mat, x_coord, y_coord, color);
    int length = mat[0].size();
    int height = mat.size();
    this->matrix_display(mat, height, length);
}
