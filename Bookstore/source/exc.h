#ifndef EXC_H
#define EXC_H
#include<QException>
class myException: public QException{
public:
    QString txt;
    myException(QString error):txt(error){};
};
#endif // EXC_H
