#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../krypto_copy/NBild.h"

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

    void print(int i);

    void print(QString i);

    void print(bool j);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
