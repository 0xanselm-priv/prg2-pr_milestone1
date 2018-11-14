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
#include <QMouseEvent>
#include <utility>

//class vars
vector < vector<int> > first_mat;
vector < vector<int> > result_mat;
vector < vector<int> > second_mat;
int factor = 20;
vector <vector <int,int>> selected_cells;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Constructor
    ui->setupUi(this);
    ui->x_spinBox->setMaximum(0);
    ui->y_spinBox->setMaximum(0);

    ui->comboBox->addItem("Encrypt");
    ui->comboBox->addItem("Decrypt");
    ui->comboBox->addItem("Overlay");

    ui->matrix_label->setScaledContents(true);
    ui->change_pixel_button->setEnabled(false);
    ui->rand_mat_button->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->save_button->setEnabled(false);
}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}

vector < vector<int> >& MainWindow::load_second_matrix() {
    //Done - Option to load the second matrix into the designated matrix2_label
    Interface interface;
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);

    ui->filepath2_label->setText("File Path: " + file_name);
    ui->filepath2_label->adjustSize();

    global_filepath2 = file_name.toUtf8().constData();
    if (global_filepath2.size() == 0) {
        QMessageBox::warning(this,"Filepath","No valid Filepath");
    } else {
        if (interface.load_matrix(global_filepath2).first) {

            second_mat = interface.load_matrix(global_filepath2).second;

            int height = second_mat.size();
            int length = second_mat[0].size();

            ui->matrix2_length->setText("Matrix Length: " + QString::number(length));
            ui->matrix2_length->adjustSize();
            ui->matrix2_height->setText("Matrix Height: " + QString::number(height));
            ui->matrix2_length->adjustSize();

            ui->mat2_groupBox->adjustSize();

            //this->matrix2_display(second_mat, height, length);
            ui->mat2_display_groupBox->adjustSize();

            //no pixel setting option

        } else {
            QMessageBox::warning(this,"Wrong Input","No valid Matrix");
            ui->matrix2_length->setText("Matrix Length: NaN");
            ui->matrix2_height->setText("Matrix Height: NaN");
        }
    }
}

int MainWindow::core_func_encrypt() {
    //1 of 3 functions. ENCRYPT handles the encryption.
    //Also asks fot the whereabouts of second matrix. load or generate option available
    //Displays second matrix in matrix2_label
    //Loads 1 and 2 matrix into encryptor and displays the result

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
        this->matrix2_display(second_mat, second_mat.size(), second_mat[0].size(), "loaded");
    } else if  (temp == 1){
        //random matrix
        second_mat = interface.create_rand_key(first_mat.size(), first_mat[0].size());
        this->matrix2_display(second_mat, second_mat.size(), second_mat[0].size(), "random");
    } else {
        QMessageBox::warning(this,"Error","No sufficient Action");
        return 0;
    }


    if (interface.encrypt(global_filepath, second_mat, "", true).first) { //<- Error here
        result_mat = interface.encrypt(global_filepath, second_mat, "", true).second;
        this->matrix3_display(result_mat, result_mat.size(), result_mat[0].size());
    } else {
        QMessageBox::warning(this,"Error","Matrix Error");
    }
    return 0;
}

int MainWindow::core_func_decrypt() {
    //2 of 3 functions. DECRYPT handles the decryption.
    //Displays second matrix in matrix2_label
    //Loads 1 and 2 matrix into decryptor and displays the result

    Interface interface;

    int height = 0;
    int length = 0;

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
    //3 of 3 functions. Overlay handles the overlay.
    //Displays second matrix in matrix2_label
    //Loads 1 and 2 matrix into overlay and displays the result

    Interface interface;

    int height = 0;
    int length = 0;

    this->load_second_matrix();
    height = second_mat.size();
    length = second_mat[0].size();
    this->matrix2_display(second_mat, height, length, "loaded");

    if (interface.overlay(global_filepath, global_filepath2, "", true).first) { //<- Error here
        result_mat = interface.overlay(global_filepath, global_filepath2, "", true).second;
        this->matrix3_display(result_mat, result_mat.size(), result_mat[0].size());
    } else {
        QMessageBox::warning(this,"Error","Matrix Error");
    }
    return 0;
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    //Done - Selects the mode {encryption, decryption, overlay} and calls designated functions.
    QString cur_str = ui->comboBox->currentText();
    Interface inter;

    if (cur_str == "Encrypt") {
        this->core_func_encrypt();
    } else if (cur_str == "Decrypt") {
        this->core_func_decrypt();
    } else if (cur_str == "Overlay") {
        this->core_func_overlay();
    }
    ui->save_button->setEnabled(true);
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
    //Done - Loads the first Matrix via file open dialog into the matrix_label with a qpainter
    Interface interface;
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    QString s = file_name;

    ui->label_2->setText("File Path: " + file_name);
    ui->label_2->adjustSize();

    global_filepath = file_name.toUtf8().constData();

    if (global_filepath.size() == 0) {
        QMessageBox::warning(this,"Filepath","No valid Filepath");
    } else {


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
}

void MainWindow::matrix1_display(vector < vector<int> > matrix, int height, int length)
{
    //Done - Function for printing matrix1 into matrix_label. Also adjustment of informative labels
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

    ui->matrix_label->setMaximumHeight(90);
    ui->matrix_label->setMaximumWidth(305);

    ui->matrix_label->setScaledContents(true);

}

void MainWindow::matrix2_display(vector < vector<int> > matrix, int height, int length, string origin)
{
    //Done - Function for printing matrix2 into matrix2_label. Also adjustment of informative labels
    QPixmap pixmap2(length+2, height+2);
    pixmap2.fill(QColor("transparent"));

    QPainter painter (&pixmap2);
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

    ui->matrix2_label->setPixmap(pixmap2);
    ui->matrix2_label->adjustSize();

    ui->matrix2_label->setMaximumHeight(90);
    ui->matrix2_label->setMaximumWidth(305);
    ui->matrix2_label->setScaledContents(true);

    ui->mat2_display_groupBox->adjustSize();
}

void MainWindow::matrix3_display(vector<vector<int> > matrix, int height, int length)
{
    //Done - Function for printing matrix3 into matrix3_label, which is the result. Also adjustment of informative labels
    QPixmap pixmap3(length+2, height+2);
    pixmap3.fill(QColor("transparent"));

    QPainter painter (&pixmap3);
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
    ui->matrix3_label->setPixmap(pixmap3);
    ui->matrix3_label->adjustSize();

    ui->matrix3_label->setMaximumHeight(90);
    ui->matrix3_label->setMaximumWidth(305);
    ui->matrix3_label->setScaledContents(true);

    ui->mat3_display_groupBox->adjustSize();
}

void MainWindow::on_save_button_clicked()
{  
    //Done - asking for save options of result matrix
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
    //Done - Saves a randomly generated matrix. Error with the random function

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
    //Done - changes pixel in first matrix to opposite
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
    //Done - Should produce a random matrix with dimension of first loaded matrix
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

void MainWindow::on_pushButton_clicked()
{
    print_int(ui->gol_label->width());
    print_int(ui->gol_label->height());
    //Loads a gol instance
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", "../ProgPrak1819/Qt_PP_1819_GUI", filter);
    ui->filepath_gol_label->setText("Filepath: " + file_name);
    ui->filepath_gol_label->adjustSize();
    string fp = file_name.toUtf8().constData();

    if (fp.size() == 0) {
        QMessageBox::warning(this,"Error","No sufficient Filepath");
    } else {
        global_gol = fp;
        for (int k = 0; k < 2; k++){
            CellularAutomaton automat = CellularAutomaton(file_name.toUtf8().constData());


            QPixmap pixmap((automat.num_rows() * factor)+1, (automat.num_cols() * factor)+1);
            pixmap.fill(QColor("transparent"));

            QPainter painter (&pixmap);
            painter.setBrush(Qt::red);

            int rows = automat.num_rows();
            int cols = automat.num_cols();

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (automat.cell_state(i,j)) {
                        painter.setBrush(Qt::green);
                        painter.drawRect(i*factor,j*factor,factor,factor);
                    } else {
                        painter.setBrush(Qt::red);
                        painter.drawRect(i*factor,j*factor,factor,factor);
                    }
                }

            }
            ui->gol_label->adjustSize();
            ui->gol_label->setPixmap(pixmap);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    //Gets mouse click koordinates
    if (ui->tabWidget->currentIndex() == 0) {

        QString x_str = QString::number(ev->x());
        QString y_str = QString::number(ev->y());
        //qDebug() << x << "," << y;
        int x = x_str.toInt();
        int y = y_str.toInt();

        print("X:" + x_str + " Y:" + y_str);
        int label_pos_x = ui->gol_label->pos().x();
        int label_pos_y = ui->gol_label->pos().y();
        int height = ui->gol_label->width();
        int width = ui->gol_label->height();
        int tab_pos_x = ui->tabWidget->pos().x();
        int tab_pos_y = ui->tabWidget->pos().y();

        int bias_x = 15;
        int bias_y = 19;

        int start_x = label_pos_x + tab_pos_x; int end_x = tab_pos_x + label_pos_x + width;
        int start_y = label_pos_y + tab_pos_y + bias_y; int end_y = tab_pos_y + label_pos_y + height + bias_y;

        vector <int,int> cell;

        if (start_x <= x && x <= end_x && start_y <= y && y <= end_y) {
            print("In");
            int cell_x = 20 - ((end_x - x) / factor);
            int cell_y = 20 - ((end_y - y) / factor);
            print_int(cell_x);
            print_int(cell_y);
            selected_cells.push_back(cell);
        } else {
            print("Out");
        }
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    CellularAutomaton automat(global_gol);

    int rows = automat.num_rows();
    int cols = automat.num_cols();

    for (int e = 0; e < selected_cells.size(); e++) {
        vector<int> vec;
        vec.push_back(selected_cells[e]);
        int x = vec[0];
        int y = vec[1];
        automat.ChangeCellState(x,y);
    }


    QPixmap pixmap((automat.num_rows() * factor)+1, (automat.num_cols() * factor)+1);
    pixmap.fill(QColor("transparent"));

    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (automat.cell_state(i,j)) {
                painter.setBrush(Qt::green);
                painter.drawRect(i*factor,j*factor,factor,factor);
            } else {
                painter.setBrush(Qt::red);
                painter.drawRect(i*factor,j*factor,factor,factor);
            }
        }

    }
    ui->gol_label->adjustSize();
    ui->gol_label->setPixmap(pixmap);
}

