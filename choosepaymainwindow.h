#ifndef CHOOSEPAYMAINWINDOW_H
#define CHOOSEPAYMAINWINDOW_H

#include <QMainWindow>
#include<paymainwindow.h>
namespace Ui {
class choosepayMainWindow;
}

class choosepayMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit choosepayMainWindow(QWidget *parent = nullptr);
    ~choosepayMainWindow();

    payMainWindow * page = NULL;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::choosepayMainWindow *ui;
};

#endif // CHOOSEPAYMAINWINDOW_H
