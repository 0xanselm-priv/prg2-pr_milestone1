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

vector < vector<int> > first_mat;
vector < vector<int> > result_mat;
vector < vector<int> > second_mat;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_spinBox->setMaximum(0);
    ui->y_spinBox->setMaximum(0);
    ui->comboBox->addItem("Encrypt");
    ui->comboBox->addItem("Decrypt");
    ui->comboBox->addItem("Overlay");
    ui->matrix_label->setScaledContents(true);
    ui->change_pixel_button->setEnabled(false);
    ui->mat1_groupBox->adjustSize();
    ui->rand_mat_button->setEnabled(false);
    ui->comboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}

vector < vector<int> >& MainWindow::load_second_matrix() {
    //Done
    Interface interface;
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);

    ui->filepath2_label->setText("File Path: " + file_name);
    ui->filepath2_label->adjustSize();

    global_filepath2 = file_name.toUtf8().constData();

    if (interface.load_matrix(global_filepath2).first) {

        second_mat = interface.load_matrix(global_filepath2).second;

        int height = second_mat.size();
        int length = second_mat[0].size();

        print_int(height);

        ui->matrix2_length->setText("Matrix Length: " + QString::number(length));
        ui->matrix2_length->adjustSize();
        ui->matrix2_height->setText("Matrix Height: " + QString::number(height));
        ui->matrix2_length->adjustSize();

        ui->mat2_groupBox->adjustSize();

        this->matrix1_display(second_mat, height, length);
        ui->mat2_display_groupBox->adjustSize();

        //no pixel setting option

    } else {
        QMessageBox::warning(this,"Wrong Input","No valid Matrix");
        ui->matrix_length->setText("Matrix Length: NaN");
        ui->matrix_height->setText("Matrix Height: NaN");
    }
}

int MainWindow::core_func_encrypt() {

    Interface interface;

    int height = 0;
    int length = 0;

    QMessageBox msgBox;
    msgBox.setWindowTitle("User Interaction");
    msgBox.setText("Do you want to load or generate a Matrix.");
    msgBox.addButton(tr("Load"), QMessageBox::YesRole);
    msgBox.addButton(tr("Generate"), QMessageBox::NoRole);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int temp = msgBox.exec();
    if(temp == 0){
        //loaded matrix
        this->load_second_matrix();
        height = second_mat.size();
        print_int(height);
        length = second_mat[0].size();
        this->matrix2_display(second_mat, height, length, "loaded");
    } else if  (temp == 1){
        //random matrix
        height = first_mat.size();
        length = first_mat[0].size();
        second_mat = interface.create_rand_key(height, length);
        this->matrix2_display(second_mat, second_mat.size(), second_mat[0].size(), "random");
    } else {
        QMessageBox::warning(this,"Error","No sufficient Action");
        return 0;
    }


    if (interface.encrypt(global_filepath, second_mat, "", true).first) { //<- Error here
        result_mat = interface.encrypt(global_filepath, second_mat, "", true).second;
        this->matrix3_display(result_mat, height, length);
    } else {
        QMessageBox::warning(this,"Error","Matrix Error");
    }
    return 0;
}

int MainWindow::core_func_decrypt() {

    Interface interface;

    int height = 0;
    int length = 0;

//    QMessageBox msgBox;
//    msgBox.setWindowTitle("User Interaction");
//    msgBox.setText("Do you want to load or generate a Matrix.");
//    msgBox.addButton(tr("Load"), QMessageBox::YesRole);
//    msgBox.addButton(tr("Generate"), QMessageBox::NoRole);
//    msgBox.setDefaultButton(QMessageBox::Yes);
//    int temp = msgBox.exec();
//    if(temp == 0){
//        //loaded matrix
//        this->load_second_matrix();
//        height = second_mat.size();
//        length = second_mat[0].size();
//        this->matrix2_display(second_mat, height, length, "loaded");
//    } else if  (temp == 1){
//        //random matrix
//        height = first_mat.size();
//        length = first_mat[0].size();
//        second_mat = interface.create_rand_key(height, length);
//        this->matrix2_display(second_mat, height, length, "random");
//    } else {
//        QMessageBox::warning(this,"Error","No sufficient Action");
//        return 0;
//    }


//    QString filter = "Text File (*.txt)";
//    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);

//    ui->filepath2_label->setText("File Path: " + file_name);
//    ui->filepath2_label->adjustSize();

//    global_filepath2 = file_name.toUtf8().constData();

    this->load_second_matrix();
    height = second_mat.size();
    length = second_mat[0].size();
    this->matrix2_display(second_mat, height, length, "loaded");


    if (interface.decrypt(global_filepath, global_filepath2, "", true).first) { //<- Error here
        result_mat = interface.decrypt(global_filepath, global_filepath2, "", true).second;
        this->matrix3_display(result_mat, result_mat.size(), result_mat[0].size());
    } else {
        QMessageBox::warning(this,"Error","Matrix Error");
    }
    return 0;
}

int MainWindow::core_func_overlay() {

    Interface interface;

    int height = 0;
    int length = 0;

    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);

    ui->filepath2_label->setText("File Path: " + file_name);
    ui->filepath2_label->adjustSize();

    global_filepath2 = file_name.toUtf8().constData();

    if (interface.overlay(global_filepath, global_filepath2, "", true).first) { //<- Error here
        result_mat = interface.encrypt(global_filepath, global_filepath2, "", true).second;
        this->matrix3_display(result_mat, height, length);
    } else {
        QMessageBox::warning(this,"Error","Matrix Error");
    }
    return 0;
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    //Done
    QString cur_str = ui->comboBox->currentText();
    Interface inter;

    if (cur_str == "Encrypt") {
        this->core_func_encrypt();
    } else if (cur_str == "Decrypt") {
        this->core_func_decrypt();
    } else if (cur_str == "Overlay") {
        this->core_func_overlay();
    }
}

void MainWindow::print_int(int i)
{
    //Helper for printing int
    QString j = QString::number(i);
    qDebug(j.toLatin1());
}

void MainWindow::print(QString j)
{
    //Helper for printing QString on console
    qDebug(j.toLatin1());
}

void MainWindow::print_str(string j)
{
    //Helper for printing string
    print(QString::fromStdString(j));
}

void MainWindow::print_bool(bool j)
{
    //Helper for printing bool
    if (j == 0) {
        qDebug("False");
    } else {
        qDebug("True");
    }
}



void MainWindow::on_load_first_btn_clicked()
{
    //Done
    Interface interface;
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    QString s = file_name;

    ui->label_2->setText("File Path: " + file_name);
    ui->label_2->adjustSize();

    global_filepath = file_name.toUtf8().constData();

    if (interface.load_matrix(global_filepath).first) {

        vector < vector<int> > matrix = interface.load_matrix(global_filepath).second;
        first_mat = matrix;

        int height = matrix.size();
        int length = matrix[0].size();

        ui->matrix_length->setText("Matrix Length: " + QString::number(length));
        ui->matrix_length->adjustSize();
        ui->matrix_height->setText("Matrix Height: " + QString::number(height));
        ui->matrix_length->adjustSize();

        ui->mat1_groupBox->adjustSize();

        this->matrix1_display(matrix, height, length);
        ui->mat1_display_groupBox->adjustSize();
        ui->x_spinBox->setMaximum(length);
        ui->y_spinBox->setMaximum(height);
        ui->change_pixel_button->setEnabled(true);
        ui->rand_mat_button->setEnabled(true);
        ui->comboBox->setEnabled(true);

    } else {
        QMessageBox::warning(this,"Wrong Input","No valid Matrix");
        ui->matrix_length->setText("Matrix Length: NaN");
        ui->matrix_height->setText("Matrix Height: NaN");
    }
}

void MainWindow::matrix1_display(vector < vector<int> > matrix, int height, int length)
{
    //Done
    QPixmap pixmap(length+2, height+2);
    pixmap.fill(QColor("transparent"));

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 1) {
                painter.drawPoint(j,i);
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

void MainWindow::matrix2_display(vector < vector<int> > matrix, int height, int length, string origin)
{
    //Done
    QPixmap pixmap(length+2, height+2);
    pixmap.fill(QColor("transparent"));

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 1) {
                painter.drawPoint(j,i);
            } else if (matrix[i][j] == 0){
                //pass
            }else {
                QMessageBox::warning(this,"Input","Wrong Input Format");
                break;
            }
        }
    }

    if (origin == "random") {
        ui->filepath2_label->setText("Filepath: Not saved yet");
        ui->filepath2_label->adjustSize();
    } else if (origin == "load") {
        ui->filepath2_label->setText("Filepath: " + QString::fromStdString(global_filepath2));
        ui->filepath2_label->adjustSize();
    }

    ui->mat2_groupBox->adjustSize();

    ui->matrix2_height->setText("Matrix Height: " + QString::number(height));
    ui->matrix2_height->adjustSize();
    ui->matrix2_length->setText("Matrix Length: " +QString::number(length));
    ui->matrix2_length->adjustSize();

    ui->matrix2_label->setPixmap(pixmap);
    ui->matrix2_label->adjustSize();

    ui->mat2_display_groupBox->adjustSize();
}

void MainWindow::matrix3_display(vector<vector<int> > matrix, int height, int length)
{
    //Done
    QPixmap pixmap(length+2, height+2);
    pixmap.fill(QColor("transparent"));

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 1) {
                painter.drawPoint(j,i);
            } else if (matrix[i][j] == 0){
                //pass
            }else {
                QMessageBox::warning(this,"Input","Wrong Input Format");
            }
        }
    }
    ui->matrix3_label->setPixmap(pixmap);
    ui->matrix3_label->adjustSize();

    ui->mat3_display_groupBox->adjustSize();
}

void MainWindow::on_save_button_clicked()
{  
    //
    QString filter = "Text File (*.txt)";
    QString save_path = QFileDialog::getSaveFileName(this, "Save file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    QFile file(save_path);

    Interface interface;

    if (save_path.size()==0) {
         QMessageBox::warning(this,"Error","Filepath Error.");
    } else {
        interface.save_matrix(save_path.toUtf8().constData(), result_mat);
        QMessageBox::information(this,"Saved","File Saved");
    }
}

void MainWindow::save_rand_mat()
{
    //
    QString filter = "Text File (*.txt)";
    QString save_path = QFileDialog::getSaveFileName(this, "Save file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    QFile file(save_path);

    Interface interface;

    if (save_path.size() == 0) {
         QMessageBox::warning(this,"Error","Filepath Error.");
    } else {
        interface.save_matrix(save_path.toUtf8().constData(), second_mat);
        QMessageBox::information(this,"Saved","File Saved");
    }
}

void MainWindow::on_change_pixel_button_clicked()
{
    //Done
    int x_coord = ui->x_spinBox->value();
    int y_coord = ui->y_spinBox->value();

    int color = ui->color_comboBox->currentIndex();

    Interface interface;
    first_mat = interface.change_pixel(first_mat, x_coord, y_coord, color);


    int length = first_mat[0].size();
    int height = first_mat.size();
    this->matrix1_display(first_mat, height, length);
}

void MainWindow::on_rand_mat_button_clicked()
{
    //Done
    int height = first_mat.size();
    int length = first_mat[0].size();

    Interface interface;
    second_mat = interface.create_rand_key(height, length);

    this->matrix2_display(second_mat, height, length, "random");

    QMessageBox msgBox;
    msgBox.setWindowTitle("User Interaction");
    msgBox.setText("Do you want to save random generated Matrix");
    msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("Nah"), QMessageBox::NoRole);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int temp = msgBox.exec();
    if(temp == 0){
        this->save_rand_mat();
    } else if  (temp == 1){
        QMessageBox::information(this,"Yeet","Alrighty");
    } else {
        QMessageBox::warning(this,"Error","No sufficient Action");
    }
}
