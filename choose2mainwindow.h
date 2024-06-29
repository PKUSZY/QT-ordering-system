#ifndef CHOOSE2MAINWINDOW_H
#define CHOOSE2MAINWINDOW_H

#include <QMainWindow>
#include<payMainWindow.h>
namespace Ui {
class choose2MainWindow;
}

class choose2MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose2MainWindow(QWidget *parent = nullptr);
    ~choose2MainWindow();

    payMainWindow * page = NULL;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::choose2MainWindow *ui;
};

#endif // CHOOSE2MAINWINDOW_H
