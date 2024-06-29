#include "shangjiamainwindow.h"
#include "ui_shangjiamainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QInputDialog>
#include<QMovie>
#include<QDebug>
shangjiaMainWindow::shangjiaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shangjiaMainWindow)
{
    ui->setupUi(this);

    //QMovie *movie = new QMovie(":/giphy.gif"); // 使用资源路径或文件路径
    //ui->labelmovie->setMovie(movie);
    //movie->start(); // 开始播放动画

    QFile file("rules.text");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line;
    line = in.readLine();
    double l1 = line.toDouble();
    line = in.readLine();
    double l2 = line.toDouble();
    line = in.readLine();
    double l3 = line.toDouble();
    line = in.readLine();
    double l0 = line.toDouble();
    file.close();

    ui->doubleSpinBox_1->setValue(l1);
    ui->doubleSpinBox_2->setValue(l2);
    ui->doubleSpinBox_3->setValue(l3);
    ui->doubleSpinBox->setValue(l0);

    //ui->tabWidget->setStyleSheet("QTabBar::tab { padding: 10px; }");

    this->page = new creatuserMainWindow(this);

    QFile file2("benefit.text");
    file2.open(QIODevice::ReadOnly);
    QTextStream in2(&file2);
    QString line2 ="总收益：";
       QString line3 = in2.readLine();
       line2+=line3;
       //qDebug() << line3 << endl;
       //qDebug() << line2 << endl;
    ui->label_7->setText(line2);
    file2.close();
}

shangjiaMainWindow::~shangjiaMainWindow()
{
    delete ui;
}

void shangjiaMainWindow::on_pushButton_2_clicked()
{
    this->hide();
    this->page->show();
}

void shangjiaMainWindow::on_savebt_clicked()
{
    double l1 = ui->doubleSpinBox_1->value();
    double l2 = ui->doubleSpinBox_2->value();
    double l3 = ui->doubleSpinBox_3->value();
    double l0 = ui->doubleSpinBox->value();

    if(l0<l3|l3<l2|l2<l1)
        QMessageBox::information(NULL,"","请重新设置！",QMessageBox::Ok);
    else
    {
        QMessageBox::information(NULL,"","设置成功",QMessageBox::Ok);
        QFile file("rules.text");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << l1 << endl;
        out << l2 << endl;
        out << l3 << endl;
        out << l0 << endl;
        file.close();
    }
    this->parentWidget()->show();

}

void shangjiaMainWindow::on_trueRB_clicked()
{
    QFile file("boolrule.text");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << 1 << endl;
}

void shangjiaMainWindow::on_falseRB_clicked()
{
    QFile file("boolrule.text");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << 0 << endl;
}

void shangjiaMainWindow::on_pushButton_clicked()
{
    this->hide();
    this->parentWidget()->show();
}
