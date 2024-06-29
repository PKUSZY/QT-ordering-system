#include "choosepaymainwindow.h"
#include "ui_choosepaymainwindow.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QFile>
#include<QTextStream>
choosepayMainWindow::choosepayMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choosepayMainWindow)
{
    ui->setupUi(this);
}

choosepayMainWindow::~choosepayMainWindow()
{
    delete ui;
}

void choosepayMainWindow::on_pushButton_clicked()
{
    QFile file3("t_cost.text");
    file3.open(QIODevice::ReadOnly);
    QTextStream in(&file3);
    QString line = in.readLine();
    file3.close();

    int yue=0;  //余额
    QFile file2("yue.text");
    file2.open(QIODevice::ReadOnly);
    QTextStream out(&file2);
    QString line2 = out.readLine();
    yue = line2.toInt();
    file2.close();


    if(yue>=line.toInt())
    {
        this->hide();
        this->page = new payMainWindow(this);
        this->page->show();
    }
    else
    {
        QMessageBox::information(this,"","余额不足！",QMessageBox::Ok);
    }

}

void choosepayMainWindow::on_pushButton_4_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

void choosepayMainWindow::on_pushButton_2_clicked()
{
    this->hide();
    this->page = new payMainWindow(this);
    this->page->show();
}

void choosepayMainWindow::on_pushButton_3_clicked()
{
    this->hide();
    this->page = new payMainWindow(this);
    this->page->show();
}
