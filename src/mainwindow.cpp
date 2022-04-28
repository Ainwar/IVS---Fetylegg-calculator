#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QButtonGroup>
#include <QEventLoop>
#include "mathLib.h"

/**
 * @brief MainWindow::MainWindow constructor
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(320,512);
    this->setWindowTitle("Calculator Fetylegg");
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard | Qt::TextSelectableByMouse);
    ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    ui->textBrowser->setAlignment(Qt::AlignRight);
    //std::string ans;
    //ui->pushButton_help->setIcon("");
    connect(ui->numbers, &QButtonGroup::buttonClicked, this, &MainWindow::numbers_clicked);
    connect(ui->numbers, &QButtonGroup::buttonPressed, this, &MainWindow::numbers_pressed);
    connect(ui->numbers, &QButtonGroup::buttonReleased, this, &MainWindow::numbers_released);
    connect(ui->light_grey_buttons, &QButtonGroup::buttonPressed, this, &MainWindow::light_grey_pressed);
    connect(ui->light_grey_buttons, &QButtonGroup::buttonReleased, this, &MainWindow::light_grey_released);
    connect(ui->operations, &QButtonGroup::buttonClicked, this, &MainWindow::operations_clicked);
    connect(ui->operations, &QButtonGroup::buttonPressed, this, &MainWindow::operations_pressed);
    connect(ui->operations, &QButtonGroup::buttonReleased, this, &MainWindow::operations_released);
    connect(ui->operations_x, &QButtonGroup::buttonPressed, this, &MainWindow::operations_x_pressed);
    connect(ui->operations_x, &QButtonGroup::buttonReleased, this, &MainWindow::operations_x_released);
    shortcut = new QShortcut(QKeySequence("Return"), ui->pushButton_eq);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_pushButton_eq_clicked);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);
    ui->label_10->setVisible(false);

    /*connect(ui->pushButton_fac, &QPushButton::clicked, this, &MainWindow::on_pushButton_fac_clicked);
    connect(ui->pushButton_sqn, &QPushButton::clicked, this, &MainWindow::on_pushButton_sqn_clicked);
    connect(ui->pushButton_sq, &QPushButton::clicked, this, &MainWindow::on_pushButton_sq_clicked);
    connect(ui->pushButton_dec, &QPushButton::clicked, this, &MainWindow::on_pushButton_dec_clicked);*/
}

/**
 * @brief MainWindow::~MainWindow destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButton_help_clicked shows/hides labels with keybinding when "?" button is clicked
 */
void MainWindow::on_pushButton_help_clicked()
{
    if(help == true)
        help = false;
    else
        help = true;
    if(help == true)
    {
        ui->pushButton_help->setStyleSheet("QPushButton{ background-color: rgb(156, 94, 87) } QPushButton{ color: white }");
        //show labels
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_8->setVisible(true);
        ui->label_9->setVisible(true);
        ui->label_10->setVisible(true);
    }
    else
    {
        ui->pushButton_help->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
        //cover labels
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
    }
}

/**
 * @brief MainWindow::on_pushButton_eq_clicked
 * takes written equation, prints it in upper textbrowser, calculates equation via mathlib,
 * stores answer in ans(printed by ans button) and writes it into lower textedit,
 * then gets into loop where answer is deleted when any button is pressed
 */
void MainWindow::on_pushButton_eq_clicked()
{
    flag = 0;
    QString expr;
    expr = ui->textEdit->toPlainText();
    std::string tmp = expr.toStdString();
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(expr);
    ui->textBrowser->insertPlainText(" =");
    ui->textBrowser->setAlignment(Qt::AlignRight);
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
    //send tmp to expression_decode function, return result and print it in textedit
    MathFtion math;
    std::string answer = math.inputFtion(tmp);
    expr = QString::fromStdString(answer);
    ans = answer;
    ui->textEdit->insertPlainText(expr);//ans instead result
    QEventLoop loop;
    connect(ui->numbers, &QButtonGroup::buttonClicked, &loop, &QEventLoop::quit);
    connect(ui->light_grey_buttons, &QButtonGroup::buttonClicked, &loop, &QEventLoop::quit);
    connect(ui->operations, &QButtonGroup::buttonClicked, &loop, &QEventLoop::quit);
    connect(ui->operations_x, &QButtonGroup::buttonClicked, &loop, &QEventLoop::quit);
    disconnect(ui->pushButton_eq, &QPushButton::clicked, this, 0);
    disconnect(shortcut, &QShortcut::activated, this, &MainWindow::on_pushButton_eq_clicked);
    loop.exec();
    QString tmp2 = ui->textEdit->toPlainText();
    connect(ui->pushButton_eq, &QPushButton::clicked, this, &MainWindow::on_pushButton_eq_clicked);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_pushButton_eq_clicked);
    if(flag == 0)
    {
        tmp2.remove(0, expr.length());
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(tmp2);
        ui->textEdit->setAlignment(Qt::AlignRight);
        ui->textEdit->moveCursor(QTextCursor::End);
    }
    flag = 0;
}

/**
 * @brief MainWindow::on_pushButton_eq_pressed changing color of "=" button when pressed
 */
void MainWindow::on_pushButton_eq_pressed()
{
    ui->pushButton_eq->setStyleSheet("QPushButton{ background-color: rgb(165, 110, 110) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::on_pushButton_eq_released changing back color of "=" button when released
 */
void MainWindow::on_pushButton_eq_released()
{
    ui->pushButton_eq->setStyleSheet("QPushButton{ background-color: rgb(162, 94, 87) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::numbers_clicked inserting text of button when clicked on button from number buttongroup
 * @param button pointer to button from group numbers
 */
void MainWindow::numbers_clicked(QAbstractButton *button)
{
    ui->textEdit->insertPlainText(button->text());
}

/**
 * @brief MainWindow::numbers_pressed changing color of number buttons when pressed
 * @param button pointer to button from group numbers
 */
void MainWindow::numbers_pressed(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(60,60,60) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::numbers_released changing back color of number buttons when released
 * @param button pointer to button from group numbers
 */
void MainWindow::numbers_released(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(52,52,52) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::light_grey_pressed changing color of light grey buttons when pressed
 * @param button pointer to button from group light_grey_buttons
 */
void MainWindow::light_grey_pressed(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(145,130,125) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::light_grey_released changing back color of light grey button when released
 * @param button pointer to button from group light_grey_buttons
 */
void MainWindow::light_grey_released(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(134,114,111) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::on_pushButton_del_clicked deletes previous char in textedit
 */
void MainWindow::on_pushButton_del_clicked()
{
    ui->textEdit->textCursor().deletePreviousChar();
}

/**
 * @brief MainWindow::on_pushButton_c_clicked clears all text in textedit and textbrowser
 */
void MainWindow::on_pushButton_c_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignRight);
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
}

/**
 * @brief MainWindow::on_pushButton_ans_clicked prints last answer into textedit
 */
void MainWindow::on_pushButton_ans_clicked()
{
    QString tmp = QString::fromStdString(ans);
    ui->textEdit->insertPlainText(tmp);
}

/**
 * @brief MainWindow::on_pushButton_neg_clicked negates whole string in textedit by
 * putting it into brackets and multiplying by -1
 */
void MainWindow::on_pushButton_neg_clicked()
{
    QString tmp = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    //ui->textEdit->insertPlainText(tmp);
    ui->textEdit->insertPlainText("(");
    ui->textEdit->insertPlainText(tmp);
    ui->textEdit->insertPlainText(")*(-1)");
    ui->textEdit->setAlignment(Qt::AlignRight);
    flag = 1;
}

/**
 * @brief MainWindow::on_pushButton_dec_clicked prints decimal point into textedit
 */
void MainWindow::on_pushButton_dec_clicked()
{
    ui->textEdit->insertPlainText(".");
}

/**
 * @brief MainWindow::operations_clicked prints operators "+","-","*","/" into textedit
 * @param button pointer to button from group operations
 */
void MainWindow::operations_clicked(QAbstractButton *button)
{
    if(button->text() != "X")
    ui->textEdit->insertPlainText(button->text());
    else
    ui->textEdit->insertPlainText("*");
}

/**
 * @brief MainWindow::operations_pressed changing color of operations group button when pressed
 * @param button pointer to button from group operations
 */
void MainWindow::operations_pressed(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(120,85,80) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::operations_released changing color of operations group button when released
 * @param button pointer to button from group operations
 */
void MainWindow::operations_released(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(107,75,71) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::operations_x_pressed changing color of operations_x group button when pressed
 * @param button pointer to button from group operations_x
 */
void MainWindow::operations_x_pressed(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(120,85,80) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::operations_x_released changing color of operations_x group button when released
 * @param button pointer to button from group operations_x
 */
void MainWindow::operations_x_released(QAbstractButton *button)
{
    button->setStyleSheet("QPushButton{ background-color: rgb(107,75,71) } QPushButton{ color: white }");
}

/**
 * @brief MainWindow::on_pushButton_sq_clicked inserts "^2" into textedit
 */
void MainWindow::on_pushButton_sq_clicked()
{
    ui->textEdit->insertPlainText("^2");
}

/**
 * @brief MainWindow::on_pushButton_sqn_clicked inserts "^()" into textedit
 */
void MainWindow::on_pushButton_sqn_clicked()
{
    ui->textEdit->insertPlainText("^()");
}

/**
 * @brief MainWindow::on_pushButton_r_clicked inserts "√" into textedit
 */
void MainWindow::on_pushButton_r_clicked()
{
    ui->textEdit->insertPlainText("√");
}

/**
 * @brief MainWindow::on_pushButton_fac_clicked inserts "!" into textedit
 */
void MainWindow::on_pushButton_fac_clicked()
{
    ui->textEdit->insertPlainText("!");
}
