#ifndef MANAGEMAINWINDOW_H
#define MANAGEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class manageMainWindow;
}

class manageMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit manageMainWindow(QWidget *parent = nullptr);
    ~manageMainWindow();

private slots:
    void on_returnbt_clicked();

private:
    Ui::manageMainWindow *ui;
};

#endif // MANAGEMAINWINDOW_H
