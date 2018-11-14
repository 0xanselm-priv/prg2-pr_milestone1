#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../krypto/CBild.h"
#include "../krypto/NBild.h"
#include "../krypto/interface.h"

#include "../GoL/cellularautomaton.h"

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBox_activated(const QString &arg1);

    void matrix1_display(vector < vector<int> >matrix, int height, int length);

    void matrix2_display(vector < vector<int> > matrix, int height, int length, string origin);

    void matrix3_display(vector < vector<int> > matrix, int height, int length);

    void on_save_button_clicked();

    void on_change_pixel_button_clicked(); 

    void on_load_first_btn_clicked();

    void on_rand_mat_button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    string global_filepath;

    string global_filepath2;

    string global_gol;

    void update_mat(vector < vector<int> >& matrix);

    void print_int(int i);

    void print(QString i);

    void print_str(string i);

    void print_bool(bool j);

    vector < vector<int> >& gen_rand_mat();

    vector < vector<int> >& load_second_matrix();

    int core_func_encrypt();

    int core_func_decrypt();

    int core_func_overlay();

    void save_rand_mat();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // MAINWINDOW_H
