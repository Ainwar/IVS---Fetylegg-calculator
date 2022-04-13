#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAbstractButton>
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

    void on_pushButton_help_clicked();

    void on_pushButton_eq_clicked();

    void on_pushButton_c_clicked();

    void numbers_clicked(QAbstractButton *);
    void numbers_pressed(QAbstractButton *);
    void numbers_released(QAbstractButton *);

   // void operations

    void on_pushButton_del_clicked();

private:
    Ui::MainWindow *ui;
    HelpDialog *help;
};

#endif // MAINWINDOW_H
