#ifndef PAYMAINWINDOW_H
#define PAYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class payMainWindow;
}

class payMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit payMainWindow(QWidget *parent = nullptr);
    ~payMainWindow();

    int point_num=0;
    QString password="";
    QString pass_ = "";

    void set_point(int num);

    void clear_();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::payMainWindow *ui;

};

#endif // PAYMAINWINDOW_H
