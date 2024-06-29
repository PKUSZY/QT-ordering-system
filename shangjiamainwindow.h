#ifndef SHANGJIAMAINWINDOW_H
#define SHANGJIAMAINWINDOW_H

#include <QMainWindow>
#include<managemainwindow.h>
#include<rulemainwindow.h>
#include<creatusermainwindow.h>

namespace Ui {
class shangjiaMainWindow;
}

class shangjiaMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit shangjiaMainWindow(QWidget *parent = nullptr);
    ~shangjiaMainWindow();

    creatuserMainWindow * page = NULL;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_savebt_clicked();

    void on_trueRB_clicked();

    void on_falseRB_clicked();

private:
    Ui::shangjiaMainWindow *ui;
};

#endif // SHANGJIAMAINWINDOW_H
