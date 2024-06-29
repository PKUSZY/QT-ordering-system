#ifndef RULEMAINWINDOW_H
#define RULEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ruleMainWindow;
}

class ruleMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ruleMainWindow(QWidget *parent = nullptr);
    ~ruleMainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ruleMainWindow *ui;
};

#endif // RULEMAINWINDOW_H
