#include "choose2mainwindow.h"
#include "ui_choose2mainwindow.h"
#include<QInputDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
choose2MainWindow::choose2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose2MainWindow)
{
    ui->setupUi(this);
    this->page = new payMainWindow(this);
}

choose2MainWindow::~choose2MainWindow()
{
    delete ui;
}

void choose2MainWindow::on_pushButton_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

void choose2MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    this->page->show();
}

void choose2MainWindow::on_pushButton_3_clicked()
{
     this->hide();
     this->page->show();

}
