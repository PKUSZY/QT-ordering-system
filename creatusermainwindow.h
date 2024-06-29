#ifndef CREATUSERMAINWINDOW_H
#define CREATUSERMAINWINDOW_H

#include <QMainWindow>
#include<choose2mainwindow.h>

namespace Ui {
class creatuserMainWindow;
}

class creatuserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creatuserMainWindow(QWidget *parent = nullptr);
    ~creatuserMainWindow();

    choose2MainWindow * page = NULL;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::creatuserMainWindow *ui;
};

#endif // CREATUSERMAINWINDOW_H
