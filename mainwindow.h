#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<gukemainwindow.h>
#include<shangjiamainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int flag=0;  //表示是否输入过一次密码

    shangjiaMainWindow * page2 = NULL;
    gukeMainWindow * page3 = NULL;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
