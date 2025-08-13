/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *inputPass;
    QPushButton *loginBut;
    QLineEdit *inputEmail;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QTextEdit *emailText;
    QTextEdit *passText;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(955, 631);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(210, 340, 121, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("TI-Nspire")});
        font.setPointSize(20);
        label_2->setFont(font);
        label_2->setLineWidth(1);
        inputPass = new QLineEdit(centralwidget);
        inputPass->setObjectName("inputPass");
        inputPass->setGeometry(QRect(330, 340, 301, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("TI-Nspire")});
        inputPass->setFont(font1);
        inputPass->setEchoMode(QLineEdit::EchoMode::Password);
        loginBut = new QPushButton(centralwidget);
        loginBut->setObjectName("loginBut");
        loginBut->setGeometry(QRect(380, 420, 211, 91));
        inputEmail = new QLineEdit(centralwidget);
        inputEmail->setObjectName("inputEmail");
        inputEmail->setEnabled(true);
        inputEmail->setGeometry(QRect(330, 190, 301, 31));
        inputEmail->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(250, 190, 121, 31));
        label_3->setFont(font);
        label_3->setLineWidth(1);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(370, 30, 211, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("TI-Nspire")});
        font2.setPointSize(36);
        textBrowser->setFont(font2);
        emailText = new QTextEdit(centralwidget);
        emailText->setObjectName("emailText");
        emailText->setEnabled(false);
        emailText->setGeometry(QRect(390, 160, 171, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(227, 0, 0, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush1);
        emailText->setPalette(palette);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("TI-Nspire")});
        font3.setPointSize(15);
        font3.setUnderline(true);
        emailText->setFont(font3);
        emailText->setFrameShape(QFrame::Shape::NoFrame);
        emailText->setFrameShadow(QFrame::Shadow::Plain);
        emailText->setLineWidth(0);
        emailText->setAcceptRichText(true);
        passText = new QTextEdit(centralwidget);
        passText->setObjectName("passText");
        passText->setEnabled(false);
        passText->setGeometry(QRect(390, 310, 221, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush1);
        passText->setPalette(palette1);
        passText->setFont(font3);
        passText->setFrameShape(QFrame::Shape::NoFrame);
        passText->setFrameShadow(QFrame::Shadow::Plain);
        passText->setLineWidth(0);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label_3->raise();
        passText->raise();
        emailText->raise();
        inputPass->raise();
        loginBut->raise();
        inputEmail->raise();
        textBrowser->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        inputPass->setText(QString());
        loginBut->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'TI-Nspire'; font-size:36pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI';\">Star Bank</span></p></body></html>", nullptr));
        emailText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'TI-Nspire'; font-size:15pt; font-weight:400; font-style:normal; text-decoration: underline;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        emailText->setPlaceholderText(QString());
        passText->setMarkdown(QString());
        passText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'TI-Nspire'; font-size:15pt; font-weight:400; font-style:normal; text-decoration: underline;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        passText->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
