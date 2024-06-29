#include "shoppingmainwindow.h"
#include "ui_shoppingmainwindow.h"
#include<QDebug>
#include<QLabel>
#include<QScrollArea>
#include<QFile>
shoppingMainWindow::shoppingMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shoppingMainWindow)
{
    ui->setupUi(this);
    this->dishes[0].name="糖醋排骨";this->dishes[0].price=48;
    this->dishes[1].name="水煮肉片";this->dishes[1].price=68;
    this->dishes[2].name="蒜香排骨";this->dishes[2].price=48;
    this->dishes[3].name="麻辣小龙虾";this->dishes[3].price=128;
    this->dishes[4].name="小炒黄牛肉";this->dishes[4].price=38;
    this->dishes[5].name="西红柿炒蛋";this->dishes[5].price=25;
    this->dishes[6].name="清炒小青菜";this->dishes[6].price=18;
    this->dishes[7].name="地三鲜";this->dishes[7].price=25;
    this->dishes[8].name="丝瓜炒蛋";this->dishes[8].price=24;
    this->dishes[9].name="凉拌黄瓜";this->dishes[9].price=10;
    this->dishes[10].name="鸡丝凉面";this->dishes[10].price=38;
    this->dishes[11].name="五常大米饭";this->dishes[11].price=5;
    this->dishes[12].name="玉米窝窝头";this->dishes[12].price=20;
    this->dishes[13].name="玉米排骨汤";this->dishes[13].price=8;
    this->dishes[14].name="虫草鸡汤";this->dishes[14].price=15;
    this->dishes[15].name="草莓蛋糕";this->dishes[15].price=20;
    this->dishes[16].name="提拉米苏";this->dishes[16].price=20;
    this->dishes[17].name="芒果小丸子";this->dishes[17].price=25;
    this->dishes[18].name="珍珠奶茶";this->dishes[18].price=18;
    this->dishes[19].name="港式柠檬茶";this->dishes[19].price=18;
    this->dishes[20].name="芝芝葡萄";this->dishes[20].price=20;
    this->dishes[21].name="土豆牛腩";this->dishes[21].price=48;

    for(int i=0;i<30;++i)
        this->label[i] = new QLabel(ui->scrollAreaWidgetContents);
    for(int i=0;i<30;++i)
        this->num[i] = new QLabel(ui->scrollAreaWidgetContents);
}

shoppingMainWindow::~shoppingMainWindow()
{
    delete ui;
}

void shoppingMainWindow::on_pushButton_clicked()
{
    this->hide();
    this->parentWidget()->show();
    for(int i=0;i<22;++i)
    {
        this->num[i]->hide();
        this->label[i]->hide();
    }
    this->total_cost=0;
}

void shoppingMainWindow::set_label()
{
    int numb=0;  //累计菜总数
    int wid=0;
    int hei=0;
    for(int i=0;i<22;++i)
    {
        if(this->dishes[i].count!=0)
        {
            QString str = "x";
            char m = '0'+this->dishes[i].count;
            str.append(m);
            //qDebug() << str << endl;
            this->num[i]->setText(str);
            this->label[i]->setText(this->dishes[i].name);
            this->num[i]->setGeometry(350,50+numb*50,50,20);
            this->label[i]->setGeometry(50,50+numb*50,200,20);
            this->num[i]->show();
            this->label[i]->show();
            ++numb;
        }

        wid = ui->scrollAreaWidgetContents->width();
        hei = ui->scrollAreaWidgetContents->height();

        if((50+50*numb)>(hei-50))
        {
            ui->scrollAreaWidgetContents->setMinimumSize(wid,hei+50);
        }

        this->total_cost+=(this->dishes[i].price)*(this->dishes[i].count);
    }

    if((50+50*numb)>(hei-50))
    {
        ui->scrollAreaWidgetContents->setMinimumSize(wid,hei+50);
    }

    QString str = QString::number(this->total_cost);
    this->num[22]->setText(str);
    this->label[22]->setText("总消费");
    this->num[22]->setGeometry(350,50+numb*50,50,20);
    this->label[22]->setGeometry(50,50+numb*50,200,20);
    this->num[22]->show();
    this->label[22]->show();

    ++numb;

    if((50+50*numb)>(hei-50))
    {
        ui->scrollAreaWidgetContents->setMinimumSize(wid,hei+50);
    }

    double zhekou=0;   //打折
    bool ok=0;  //满减规则

    QFile file("rules.text");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line;
    line = in.readLine();
    double l1 = line.toDouble();
    line = in.readLine();
    double l2 = line.toDouble();
    line = in.readLine();
    double l3 = line.toDouble();
    line = in.readLine();
    double l0 = line.toDouble();

    int lev=0;   // 会员级别

    if(lev==0)
    {
        zhekou=l0/10;
    }
    else if(lev==1)
    {
        zhekou=l1/10;
    }
    else if(lev==2)
    {
        zhekou=l2/10;
    }
    else if(lev==3)
    {
        zhekou=l3/10;
    }

    total_cost *= zhekou;

    QFile file2("boolrule.text");
    file2.open(QIODevice::ReadOnly);
    QTextStream in2(&file2);
    QString line2;
    line2 = in.readLine();
    ok = line.toInt();

    if(ok==1)
    {
        if(total_cost>=100&&total_cost<200)
            total_cost-=5;
        else if(total_cost>=200&&total_cost<500)
            total_cost-=15;
        else if(total_cost>=500)
            total_cost-=50;
    }

    str = QString::number(this->total_cost);
    this->num[23]->setText(str);
    this->label[23]->setText("打折后消费");
    this->num[23]->setGeometry(350,50+numb*50,50,20);
    this->label[23]->setGeometry(50,50+numb*50,200,20);
    this->num[23]->show();
    this->label[23]->show();

    QFile file3("t_cost.text");
    file3.open(QIODevice::WriteOnly);
    QTextStream out3(&file3);
    QString line3 = QString::number(this->total_cost);
    out3 << line3 << endl;

    //qDebug() << line3 << endl;
    file.close();
    file2.close();
    file3.close();

}
