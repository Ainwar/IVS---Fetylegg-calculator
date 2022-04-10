#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpdialog.h"
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(320,512);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard | Qt::TextSelectableByMouse);
    ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    ui->textBrowser->setAlignment(Qt::AlignRight);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onClicked);
    //QpushButton("&1",this);
    //QShortcut *shortcut = new QShortcut(QKeySequence("1"), parent);
    //QObject::connect(shortcut, SIGNAL(activated()), on_pushButton_1_clicked(), SLOT(yourSlotHere()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
//textedit

void MainWindow::on_pushButton_help_clicked()
{
    help = new HelpDialog(this);
    help->show();
}
//button 0
void MainWindow::on_pushButton_0_clicked()
{
    ui->textEdit->insertPlainText("0");
}
void MainWindow::on_pushButton_0_pressed()
{
    ui->pushButton_0->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}
void MainWindow::on_pushButton_0_released()
{
    ui->pushButton_0->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}
//button 1
void MainWindow::on_pushButton_1_clicked()
{
    //ui->textBrowser->insertPlainText("1");
    ui->textEdit->insertPlainText("1");
}

void MainWindow::on_pushButton_1_pressed()
{
    ui->pushButton_1->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}
void MainWindow::on_pushButton_1_released()
{
    ui->pushButton_1->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}
//button 2
void MainWindow::on_pushButton_2_clicked()
{
    //ui->textBrowser->insertPlainText("2");
    ui->textEdit->insertPlainText("2");
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}
void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}



void MainWindow::on_pushButton_eq_clicked()
{
    QString expr;
    expr = ui->textEdit->toPlainText();
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(expr);
    ui->textBrowser->insertPlainText(" =");
    ui->textBrowser->setAlignment(Qt::AlignRight);
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
    //send expr to expression_decode function, return result and print it in textedit
    ui->textEdit->insertPlainText(ui->pushButton_0->text());
}


void MainWindow::on_pushButton_c_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignRight);
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
}
