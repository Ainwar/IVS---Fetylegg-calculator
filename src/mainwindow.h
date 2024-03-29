#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAbstractButton>
#include <QMainWindow>
#include <QShortcut>

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

    void numbers_clicked(QAbstractButton *);
    void numbers_pressed(QAbstractButton *);
    void numbers_released(QAbstractButton *);
    void light_grey_pressed(QAbstractButton *);
    void light_grey_released(QAbstractButton *);
    void operations_clicked(QAbstractButton *);
    void operations_pressed(QAbstractButton *);
    void operations_released(QAbstractButton *);
    void operations_x_pressed(QAbstractButton *);
    void operations_x_released(QAbstractButton *);

    void on_pushButton_help_clicked();
    void on_pushButton_eq_clicked();
    void on_pushButton_c_clicked();
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
    bool help = false;
    std::string ans;
    int flag = 0;
    QShortcut *shortcut;
};

#endif // MAINWINDOW_H
