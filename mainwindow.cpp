#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectinterface.h"
#include <cstring>
#include <QString>
#include <iostream>
#include <Qdebug>
#include <winsock2.h>

routingInterface user;
std::string email = "";
std::string password = "";
std::string message = "";
const int CLIENT = 1;
const int SERVER = 2;
QString empty = "";

//THIS FUNCTION IS TO TRANSFORM INTO CSTRING BUT NOT CONST BECAUSE OF PARAM ISSUES

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user.clientStartup();
    std::cout << "Client is setup!!" << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isValid(){



    return false;
}

void MainWindow::on_loginBut_clicked(){
    const QColor c(0xffe00000);
    if (ui->inputEmail->text() == empty){
        ui->emailText->setTextColor(c);
        ui->emailText->setText("No Email inputted");
    }
    else{
        ui->emailText->setText("");
    }
    if (ui->inputPass->text() == empty){
        ui->passText->setTextColor(c);
        ui->passText->setText("No password inputted");
    }
    else{
        ui->passText->setText("");
    }
    if(ui->inputEmail->text() == empty || ui->inputPass->text() == empty){
    }
    else{
        email = ui->inputEmail->text().toStdString();
        password = ui->inputPass->text().toStdString();  //moves email and password to be sent to database (not in Qstring)
        std::string data = "0\n" + email + "\n" + password;
        message = user.sendData(data.c_str(), user.getSock());
        std::cout << message << std::endl;
        message.erase(0,2);
        std::cout << message << std::endl;
        if(message.compare("OK") == 0){
            std::cout << "LOGGED IN" << std::endl;
        }
        else{
            std::cout << "NOT LOGGED IN" << std::endl;
        }
    }
}
