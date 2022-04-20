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

    void light_grey_pressed(QAbstractButton *);
    void light_grey_released(QAbstractButton *);

    void operations_clicked(QAbstractButton *);
    void operations_pressed(QAbstractButton *);
    void operations_released(QAbstractButton *);

    void operations_x_clicked(QAbstractButton *);
    void operations_x_pressed(QAbstractButton *);
    void operations_x_released(QAbstractButton *);

   // void operations

    void on_pushButton_del_clicked();

    void on_pushButton_r_clicked();

    void on_pushButton_ans_clicked();

    void on_pushButton_eq_pressed();

    void on_pushButton_eq_released();

    void on_pushButton_neg_clicked();

    void on_pushButton_dec_clicked();

    void on_pushButton_sq_clicked();

    void on_pushButton_sqn_clicked();

    void on_pushButton_fac_clicked();

private:
    Ui::MainWindow *ui;
    HelpDialog *help;
    std::string ans;
    int flag = 0;
};

#endif // MAINWINDOW_H
