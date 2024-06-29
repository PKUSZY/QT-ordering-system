#include "gukemainwindow.h"
#include "ui_gukemainwindow.h"
#include<creatusermainwindow.h>

gukeMainWindow::gukeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gukeMainWindow)
{
    ui->setupUi(this);
    this->page = new creatuserMainWindow(this);
    this->page2 = new choosepayMainWindow(this);
    this->page3 = new shoppingMainWindow(this);
    ui->pushButton_3->setStyleSheet("QPushButton { border-image: url(:/touxiang.jpeg); }");

}

gukeMainWindow::~gukeMainWindow()
{
    delete ui;
}

void gukeMainWindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void gukeMainWindow::on_pushButton_3_clicked()
{
    this->page->show();
    this->hide();
}

void gukeMainWindow::setpic(bool ok)
{
    if(ok)
    ui->pushButton_3->setStyleSheet("QPushButton { border-image: url(:/tx_1.jpg); }");
    else
    ui->pushButton_3->setStyleSheet("QPushButton { border-image: url(:/tx_2.jpg); }");
}

void gukeMainWindow::on_pushButton_2_clicked()
{
    this->page2->show();
    this->hide();
    this->on_pushButton_4_clicked();
}

void gukeMainWindow::on_pushButton_4_clicked()
{
    this->page3->dishes[0].count = ui->spinBox_6->value();
    this->page3->dishes[1].count = ui->spinBox_5->value();
    this->page3->dishes[2].count = ui->spinBox_8->value();
    this->page3->dishes[3].count = ui->spinBox_10->value();
    this->page3->dishes[4].count = ui->spinBox_7->value();
    this->page3->dishes[5].count = ui->spinBox_11->value();
    this->page3->dishes[6].count = ui->spinBox_12->value();
    this->page3->dishes[7].count = ui->spinBox_14->value();
    this->page3->dishes[8].count = ui->spinBox_13->value();
    this->page3->dishes[9].count = ui->spinBox_15->value();
    this->page3->dishes[10].count = ui->spinBox_18->value();
    this->page3->dishes[11].count = ui->spinBox_16->value();
    this->page3->dishes[12].count = ui->spinBox_17->value();
    this->page3->dishes[13].count = ui->spinBox_20->value();
    this->page3->dishes[14].count = ui->spinBox_19->value();
    this->page3->dishes[15].count = ui->spinBox_24->value();
    this->page3->dishes[16].count = ui->spinBox_22->value();
    this->page3->dishes[17].count = ui->spinBox_23->value();
    this->page3->dishes[18].count = ui->spinBox_26->value();
    this->page3->dishes[19].count = ui->spinBox_25->value();
    this->page3->dishes[20].count = ui->spinBox_21->value();
    this->page3->dishes[21].count = ui->spinBox_9->value();
    this->hide();
    this->page3->show();
    this->page3->set_label();
}
