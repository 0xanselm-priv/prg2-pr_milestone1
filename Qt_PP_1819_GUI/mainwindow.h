#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "krypto/CBild.h"
#include "krypto/NBild.h"
#include "krypto/interface.h"
#include "GoL/cellularautomaton.h"

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
    void on_pushButton_got_clicked();

    void on_pushButton_crypto_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void matrix_display(vector < vector<int> >matrix, int height, int length);

    void on_save_button_clicked();

    void on_rand_mat_button_clicked();

    void on_change_pixel_button_clicked();

private:
    Ui::MainWindow *ui;

    string global_filepath;

    void update_mat(vector < vector<int> >& matrix);

    void print_int(int i);

    void print(QString i);

    void print_str(string i);

    void print_bool(bool j);

    void gol_painter(CellularAutomaton* automaton);

}
    ;

#endif // MAINWINDOW_H
