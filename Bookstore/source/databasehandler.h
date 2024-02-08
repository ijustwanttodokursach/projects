#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QFile>
#include<QDate>
namespace DbHandler{
#define INSERT_FAIL 23505
#define PATRONS_FAIL 20111
    QSqlDatabase db;
    void setupDb(){
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("pgdb.uni-dubna.ru");
        db.setDatabaseName("students_3254_10");
        db.setPassword("1234Temp");
        db.setUserName("students_3254_10");
        if(db.open()){qDebug()<<"Ok";
        qDebug()<<db.lastError();}
    }
    void createDB(){
        QFile sql("./scripts/libscript.sql");
        sql.open(QFile::ReadOnly | QFile::Text);
        QString query;
        qDebug()<<QFile::exists("./scripts/libscript.sql");
        QTextStream stream1(&sql);
        query = stream1.readAll();
        sql.close();
        db.exec(query);
        qDebug()<<db.lastError();
    };
    struct patron{
        unsigned int id;
        QString name;
        QString phone;
    };
    QVector<patron> fillP(){
        QVector<patron> v;
        QSqlQuery q = db.exec("Select card_num, surname, phone_n from library.patrons");
        while (q.next()){
            patron p{q.value(0).toUInt(), q.value(1).toString(), q.value(2).toString()};
            v.append(p);
        }
        return v;
    };
    struct book{
        unsigned int id;
        QString name;
        QString author;
        QString location;
    };
    QVector<book> fillB(){
        QVector<book> v;
        QSqlQuery q = db.exec("Select * from library.getcopies()");
        qDebug()<<db.lastError();
        while (q.next()){
            book b{q.value(0).toUInt(), q.value(1).toString(), q.value(2).toString(),
                  q.value(3).toString()};
            v.append(b);
        }
        return v;
    };
    struct debt{
        QString title;
        QString author;
    };
    QVector<debt> fillD(unsigned int index){
        QVector<debt> v;
        QSqlQuery q = db.exec("select * from library.debt("+QString::number(index)+")");
        while(q.next()){
            debt d{q.value(0).toString(), q.value(1).toString()};
            v.append(d);
        }
        return v;
    };
    struct issue{
        unsigned int book_id;
        unsigned int card_num;
        QDate borrowD;
        QDate deadline;
        QString surname;
        QString title;
        QString authors;
        QString publisher;
    };
    QVector<issue> fillI(){
        QVector<issue> v;
        QSqlQuery q = db.exec("select * from library.getissues()");
        while(q.next()){
            issue i{q.value(0).toUInt(), q.value(1).toUInt(), q.value(2).toDate(), q.value(3).toDate(), q.value(4).toString(),
                   q.value(5).toString(), q.value(6).toString(), q.value(7).toString()};
            v.append(i);
        }
        return v;
    }
    unsigned int insertIssue(unsigned int &book_id, unsigned int &card_num){
        db.exec("insert into library.issues(book_id, borrow_date, card_num) values ("
                +QString::number(book_id)+",CURRENT_DATE,"+QString::number(card_num)+")");
        return db.lastError().nativeErrorCode().toUInt();
    }
    void deleteIssue(unsigned int &book_id, unsigned int &card_num){
        db.exec("delete from library.issues WHERE book_id = "+QString::number(book_id)
                +"AND card_num = "+QString::number(card_num));
        qDebug()<<db.lastError();
    }
    unsigned int insert_Patron(QString s1, QString s2, QString s3){
        db.exec("Call library.patrons_ins('"+
                                   s1+"' , '"+
                                   s2+"' , '"+
                                   s3+"');");
        return db.lastError().nativeErrorCode().toUInt();
    }
    struct chartStruct{
        QString name;
        unsigned int count;
    };
    QVector<chartStruct> fillBar(){
        QVector<chartStruct> v;
        QSqlQuery q = db.exec("select * from library.archive_book_count()");
        while(q.next()){
            v.push_back({q.value(0).toString(), q.value(1).toUInt()});
        }
        return v;
    }
    QVector<chartStruct> fillDonut(){
        QVector<chartStruct> v;
        QSqlQuery q = db.exec("select * from library.publisher_count()");
        while(q.next()){
            v.push_back({q.value(0).toString(), q.value(1).toUInt()});
        }
        return v;
    }
};
#endif
