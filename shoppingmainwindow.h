#ifndef SHOPPINGMAINWINDOW_H
#define SHOPPINGMAINWINDOW_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class shoppingMainWindow;
}

class shoppingMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit shoppingMainWindow(QWidget *parent = nullptr);
    ~shoppingMainWindow();

    struct dish{
        int price;
        int count=0;
        QString name;
    };
    dish dishes[31];

    void set_label();

    QLabel* label[30];
    QLabel* num[30];

    int total_cost=0;
private slots:
    void on_pushButton_clicked();


private:
    Ui::shoppingMainWindow *ui;
};

#endif // SHOPPINGMAINWINDOW_H
