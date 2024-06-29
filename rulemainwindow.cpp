#include "rulemainwindow.h"
#include "ui_rulemainwindow.h"

ruleMainWindow::ruleMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ruleMainWindow)
{
    ui->setupUi(this);
}

ruleMainWindow::~ruleMainWindow()
{
    delete ui;
}

void ruleMainWindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}
