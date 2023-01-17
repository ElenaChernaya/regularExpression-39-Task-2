#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->enterNumber->setGeometry(140, 150, 200, 30);
    ui->validation->setGeometry(370, 150, 200, 30);

    connect(ui->enterNumber, &QLineEdit::textEdited, [this](QString str)
    {
         QRegularExpression exp("^(\\+)\\d{11}$");

         //("\\d[0-3]") Что он проверяет????? При 0 - incorrect, при 00 - correct, при 55550 - correct

         if(exp.match(str).hasMatch()) setCorrectInput();
         else setIncorrectInput();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCorrectInput()
{
    if(ui->enterNumber->text() == "") ui->validation->setText("");
    else {
        ui->validation->setText("Correct input");
        ui->validation->setStyleSheet("QLineEdit {color: green}");
    }
}

void MainWindow::setIncorrectInput()
{
    if(ui->enterNumber->text() == "") ui->validation->setText("");
    else {
        ui->validation->setText("Incorrect input");
        ui->validation->setStyleSheet("QLineEdit {color: red}");
    }
}


