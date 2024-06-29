#include "creatusermainwindow.h"
#include "ui_creatusermainwindow.h"
#include<user.h>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
creatuserMainWindow::creatuserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creatuserMainWindow)
{
    ui->setupUi(this);
    this->page = new choose2MainWindow(this);
}

creatuserMainWindow::~creatuserMainWindow()
{
    delete ui;
}


void creatuserMainWindow::on_pushButton_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

void creatuserMainWindow::on_pushButton_3_clicked()
{
    //this->hide();
    //this->page->show();
    QMessageBox::information(this,"","已付款",QMessageBox::Ok);
}

void creatuserMainWindow::on_pushButton_2_clicked()
{
    QString name;
    bool sex;  //1男，0女
    int level;  //级别
    int money;  //余额
    int costTime=0;   //消费次数
    QString password;  //支付密码
    QString phone_number;  //支付密码

    sex = ui->radioButton->isChecked();

    money = ui->lineEdit_4->text().toInt();

    password = ui->lineEdit_3->text();

    phone_number = ui->lineEdit_2->text();

    name = ui->lineEdit->text();

    if(money<200)
    {
        level = 3;
    }
    else if(money<500)
    {
        level = 2;
    }
    else
        level = 3;

    if(password.length()!=6)
    {
        QMessageBox::information(this,"","请设置六位密码",QMessageBox::Ok);
        return ;
    }

    user u(name,sex,level,money,costTime,password,phone_number);
    u.save_data();

    QFile file3("password.text");
    file3.open(QIODevice::WriteOnly);
    QTextStream out(&file3);
    QString line = password;
    out << line << endl;
    file3.close();

    QFile file("yue.text");
    file.open(QIODevice::WriteOnly);
    QTextStream in(&file);
    QString line2 = ui->lineEdit_4->text();
    in << line2 << endl;
    file.close();

    QMessageBox::information(this,"","注册成功！",QMessageBox::Ok);
    this->hide();
    this->parentWidget()->show();


}

void creatuserMainWindow::on_radioButton_clicked()
{

}
