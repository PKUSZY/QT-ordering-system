#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QDebug>
#include<QFile>
class user    //会员类：充值余额，级别（享受不同折扣，姓名，性别，消费次数
{
private:
    QString name;
    bool sex;  //1男，0女
    int level;  //级别
    int money;  //余额
    int costTime;   //消费次数
    QString password;  //支付密码
    QString phone_number;  //支付密码

public:
    user(QString str,bool s,int l,int m,int t,
         QString p,QString _phone_number):name(str),sex(s),level(l),
        money(m),costTime(t),password(p),
      phone_number(_phone_number)
    {};
    user();
    ~user()
    {};

    QString get_name(){
        return name;
    }
    int get_sex(){
        return sex;
    }
    int get_level(){
        return level;
    }
    int get_money(){
        return money;
    }
    int get_costTime(){
        return costTime;
    }
    QString get_password(){
        return password;
    }
    QString get_phone_number(){
        return phone_number;
    }

    user reset(QString _name,int _sex,int _level,int _money,
               int _costTime,QString _password,QString _phone_number){
        //重新设置该用户的数据
        name = _name;
        sex = _sex;
        level = _level;
        money = _money;
        costTime = _costTime;
        password = _password;
        phone_number = _phone_number;
        return * this;
    };

    bool save_data(){ //将该用户的数据保存到 QT user info.txt
        QFile file("QT_user_info.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream stream(&file);
            file.seek(file.size());

            QString inte  =  "**********";
            stream << inte << "\r\n"
                   << name << "\r\n"
                   << sex << "\r\n"
                   << level << "\r\n"
                   << money << "\r\n"
                   << costTime << "\r\n"
                   << password << "\r\n"
                   << phone_number << "\r\n"
                   << inte;

            file.close();
            return true;
        }

        else{
            qDebug() << "Failed to open file: "
                     << file.errorString(); // 如果打开失败，输出错误信息
            return false;
        }

    }

    QVector<user> get_all_user_info(){ //返回一个含有所有用户数据的vector
        QFile files("QT_user_info.txt");

        ////////////////////////////////////////////////////////////
        QFile js("cout.text");
        js.open(QIODevice::WriteOnly);
        QTextStream out(&js);
        out << "test f4 start" <<Qt::endl;
        ////////////////////////////////////////////////////////////

        files.open(QIODevice::ReadOnly); // 打开文件，只读模式
        out << "open   success" << Qt::endl;
        QTextStream stream(&files);
        files.seek(0);

        QVector<user> user_list;
        QString l;

        QString tmp_name;
        int tmp_sex;
        int tmp_level;
        int tmp_money;
        int tmp_costTime;
        QString tmp_password;
        QString tmp_pn;

        l = stream.readLine();
        l = l.trimmed();
        while(!files.atEnd()){
            tmp_name = stream.readLine();
            l = stream.readLine();
            l = l.trimmed();
            tmp_sex = l.toInt();
            l = stream.readLine();
            l = l.trimmed();
            tmp_level = l.toInt();
            l = stream.readLine();
            l = l.trimmed();
            tmp_money = l.toInt();
            l = stream.readLine();
            l = l.trimmed();
            tmp_costTime = l.toInt();
            tmp_password = stream.readLine();
            tmp_pn = stream.readLine();
            l = stream.readLine();
            l = l.trimmed();

            user_list.append(user( tmp_name, tmp_sex, tmp_level,tmp_money,
                                    tmp_costTime, tmp_password, tmp_pn) );
        }
        out<< user_list.begin()->get_password();
        files.close();
        return user_list;


    }

    int get_total_user_number(){ //返回当前总用户数量
        user tmp;
        QVector<user> user_list;
        user_list = tmp.get_all_user_info();
        return user_list.size();
    }

    bool delete_user(QString _name,  QString _phone_number){
        //输入 姓名 和 电话号，删除对应用户
        user tmp;
        QVector<user> user_list, new_user_list;
        user_list = tmp.get_all_user_info();

        QVector<user>::iterator i;
        for(i = user_list.begin();i < user_list.end();i++ ){
            if(i -> get_phone_number() == _phone_number  &&
                i -> get_name() ==  _name){
                continue;
            }
            new_user_list.append(*i);
        }

        QFile file("QT_user_info.txt");
        if (file.open(QIODevice::WriteOnly)) {
            file.close();

            if(new_user_list.isEmpty())
                return true;

            for(i = new_user_list.begin();i < new_user_list.end();i++ ){
                i -> save_data();
            }

            return true;
        }

        else {
            qDebug() << "Failed to open file: "
                     << file.errorString(); // 如果打开失败，输出错误信息
            return false;
        }

    }



};

#endif // USER_H
