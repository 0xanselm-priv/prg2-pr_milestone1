#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "krypto/CBild.h"
#include "krypto/NBild.h"
#include "krypto/interface.h"

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

    void print_int(int i);

    void print(QString i);

    void print_str(string i);

    void print_bool(bool j);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    // int a = 0;
    NBild int_canvas;
    string global_filepath;
};

#endif // MAINWINDOW_H
