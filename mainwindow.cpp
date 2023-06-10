
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text();
    Validator valid("(?!.*(\\.\\.))(?!.*@.*@)((^[-_0-9A-Za-z]{1}[%!\\+-_0-9A-Za-z\\.]{0,62}[-_0-9A-Za-z]{1})|(^[-_0-9A-Za-z]{1}))[@]{1}(([0-9A-Za-z]{1}[-0-9A-Za-z]*(\\.)?){1,2}[-A-Za-z0-9]{2,}$)");
    if (valid.isValid(str)){
        ui->label_2->setStyleSheet("color:#0000ff");
        ui->label_2->setText("Адреса E-mail коректна");

    }
    else{
        ui->label_2->setStyleSheet("color:#F70000");
        ui->label_2->setText("Адреса E-mail некоректна");
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_pushButton_clicked();
}

