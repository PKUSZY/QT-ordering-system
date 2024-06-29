#ifndef GUKEMAINWINDOW_H
#define GUKEMAINWINDOW_H

#include <QMainWindow>
#include<creatusermainwindow.h>
#include<choosepaymainwindow.h>
#include<shoppingmainwindow.h>
namespace Ui {
class gukeMainWindow;
}

class gukeMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit gukeMainWindow(QWidget *parent = nullptr);
    ~gukeMainWindow();
    creatuserMainWindow * page = NULL;
    choosepayMainWindow * page2 = NULL;
    shoppingMainWindow * page3 = NULL;

    void setpic(bool ok);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::gukeMainWindow *ui;
};

#endif // GUKEMAINWINDOW_H
