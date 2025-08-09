#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectinterface.h"
#include <cstring>
#include <QString>
#include <iostream>
#include <Qdebug>
#include <winsock2.h>

std::string email = "";
std::string password = "";


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

bool isValid(){



    return false;
}

void MainWindow::on_loginBut_clicked()
{
    email = ui->inputEmail->text().toStdString();
    password = ui->inputPass->text().toStdString();  //moves email and password to be sent to database (not in Qstring)

}


