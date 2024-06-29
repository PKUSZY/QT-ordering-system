#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QInputDialog>
#include <QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->page2 = new shangjiaMainWindow(this);

    this->page3 = new gukeMainWindow(this);

    QFile file("password2.text");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    QString line;
    line = in.readLine();
    if(line == "")
    {
            bool ok;
            QString str = QInputDialog::getText(NULL,tr(""),tr("请设置初始密码"),
                                 QLineEdit::Normal,"", &ok);
            QTextStream out(&file);
            QByteArray ba1;
            ba1.append(str);
            out << ba1 << endl;
            line = ba1;
    }


    connect(ui->sjbt,&QPushButton::clicked,[=](){
        this->hide();
        if(flag==1)
        {
            this->page2->show();
        }
        else
        {
            bool ok;
            QString str = QInputDialog::getText(NULL,tr("登陆"),tr("请输入密码"),
                             QLineEdit::Normal,"", &ok);
            if(ok && str == line)
            {
                this->page2->show();
                flag=1;
            }
            else
            {
                QMessageBox::information(NULL,"","密码错误！",QMessageBox::Ok);
                this->show();
            }
        }
    });

    connect(ui->gkbt,&QPushButton::clicked,[=](){
        this->hide();
        this->page3->show();
    });

     file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

