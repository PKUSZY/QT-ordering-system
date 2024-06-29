#include "managemainwindow.h"
#include "ui_managemainwindow.h"
#include<QSql>

manageMainWindow::manageMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageMainWindow)
{
    ui->setupUi(this);
}

manageMainWindow::~manageMainWindow()
{
    delete ui;
}

void manageMainWindow::on_returnbt_clicked()
{
    this->parentWidget()->show();
    this->hide();
}
