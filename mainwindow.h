#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_0_pressed();

    void on_pushButton_0_released();

    void on_pushButton_1_clicked();

    void on_pushButton_1_pressed();

    void on_pushButton_1_released();

    void on_pushButton_2_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_help_clicked();

    void on_pushButton_eq_clicked();

    void on_pushButton_c_clicked();

private:
    Ui::MainWindow *ui;
    HelpDialog *help;
};

#endif // MAINWINDOW_H
