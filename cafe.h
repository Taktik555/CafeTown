#ifndef CAFE_H
#define CAFE_H
#include "QString"
#include <QObject>

class Cafe: public QObject
{
    Q_OBJECT

public:
    Cafe(QString ID, QString Name, QString Address, QString TypeKitchen, QString TimeWork, QObject *parent = nullptr );
    virtual ~Cafe();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetAddress(QString Address);
    void SetTypeKitchen(QString TypeKitchen);
    void SetTimeWork(QString TimeWork);

    QString ID();
    QString Name();
    QString Address();
    QString TypeKitchen();
    QString TimeWork();
private:
    QString id;
    QString name;
    QString address;
    QString typeKitchen;
    QString timeWork;
};
#endif // CAFE_H
