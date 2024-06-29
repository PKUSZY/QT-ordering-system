#include "paymainwindow.h"
#include "ui_paymainwindow.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
payMainWindow::payMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::payMainWindow)
{
    ui->setupUi(this);
    QFile file("t_cost.text");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readLine();
    //qDebug() << line << endl;
    ui->label_4->setText(line);
    file.close();


}

payMainWindow::~payMainWindow()
{
    delete ui;
}

void payMainWindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
    this->clear_();
}

void payMainWindow::set_point(int num)
{
    QFile file3("password.text");
    file3.open(QIODevice::ReadOnly);
    QTextStream in(&file3);
    QString line = in.readLine();
    this->password = line;

    if(num==0)
    {
        ui->pushButton_2->setText("");
        ui->pushButton_3->setText("");
        ui->pushButton_4->setText("");
        ui->pushButton_5->setText("");
        ui->pushButton_6->setText("");
        ui->pushButton_7->setText("");
    }

    if(num==1)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("");
        ui->pushButton_4->setText("");
        ui->pushButton_5->setText("");
        ui->pushButton_6->setText("");
        ui->pushButton_7->setText("");
    }
    else if(num==2)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("*");
        ui->pushButton_4->setText("");
        ui->pushButton_5->setText("");
        ui->pushButton_6->setText("");
        ui->pushButton_7->setText("");
    }
    else if(num==3)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("*");
        ui->pushButton_4->setText("*");
        ui->pushButton_5->setText("");
        ui->pushButton_6->setText("");
        ui->pushButton_7->setText("");
    }
    else if(num==4)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("*");
        ui->pushButton_4->setText("*");
        ui->pushButton_5->setText("*");
        ui->pushButton_6->setText("");
        ui->pushButton_7->setText("");
    }
    else if(num==5)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("*");
        ui->pushButton_4->setText("*");
        ui->pushButton_5->setText("*");
        ui->pushButton_6->setText("*");
        ui->pushButton_7->setText("");
    }
    else if(num==6)
    {
        ui->pushButton_2->setText("*");
        ui->pushButton_3->setText("*");
        ui->pushButton_4->setText("*");
        ui->pushButton_5->setText("*");
        ui->pushButton_6->setText("*");
        ui->pushButton_7->setText("*");

        if(pass_==password)
        {
            ui->setupUi(this);
            QFile file("t_cost.text");
            file.open(QIODevice::ReadOnly);
            QTextStream in(&file);
            QString line = in.readLine();
            ui->label_4->setText(line);
            file.close();

            QMessageBox::information(this,"","支付成功！",QMessageBox::Ok);
            QFile file2("benefit.text");
            file2.open(QIODevice::ReadWrite);
            QTextStream in2(&file2);
            QString line2 = in.readLine();
            //qDebug() << "总收益" << line2 << endl;
            int tot = line.toInt()+line2.toInt();
            //qDebug() << "新的总收益：" << tot << endl;
            QString l = QString::number(tot);
            in2 << l << endl;
            file2.close();
        }
        else
        {
            QMessageBox::information(this,"","密码错误！",QMessageBox::Ok);
        }

        this->parentWidget()->show();
        this->hide();

    }



}

void payMainWindow::on_pushButton_12_clicked()
{
    this->point_num++;
    this->pass_.append("1");
    set_point(this->point_num);
}


void payMainWindow::on_pushButton_11_clicked()
{
    this->point_num++;
    this->pass_.append("2");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_13_clicked()
{
    this->point_num++;
    this->pass_.append("3");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_8_clicked()
{
    this->point_num++;
    this->pass_.append("4");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_9_clicked()
{
    this->point_num++;
    this->pass_.append("5");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_10_clicked()
{
    this->point_num++;
    this->pass_.append("6");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_14_clicked()
{
    this->point_num++;
    this->pass_.append("7");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_15_clicked()
{
    this->point_num++;
    this->pass_.append("8");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_16_clicked()
{
    this->point_num++;
    this->pass_.append("9");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_17_clicked()
{
    this->point_num++;
    this->pass_.append("0");
    set_point(this->point_num);
}

void payMainWindow::on_pushButton_18_clicked()
{
    this->point_num--;
    this->pass_.chop(1);
    set_point(this->point_num);
}

void payMainWindow::clear_()
{
    this->point_num=0;
    this->pass_.clear();
    set_point(this->point_num);
}
