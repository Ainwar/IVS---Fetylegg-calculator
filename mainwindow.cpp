#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(320,512);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_help_clicked()
{
    help = new HelpDialog(this);
    help->show();
}

void MainWindow::on_pushButton_0_clicked()
{
    ui->textBrowser->insertPlainText("0");
}

void MainWindow::on_pushButton_0_pressed()
{
    ui->pushButton_0->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}


void MainWindow::on_pushButton_0_released()
{
    ui->pushButton_0->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->textBrowser->insertPlainText("1");
}

void MainWindow::on_pushButton_1_pressed()
{
    ui->pushButton_1->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}


void MainWindow::on_pushButton_1_released()
{
    ui->pushButton_1->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}



