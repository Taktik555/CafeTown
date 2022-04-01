#include "cafe.h"

Cafe::Cafe(QString ID, QString Name, QString Address, QString TypeKitchen, QString TimeWork, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    address = Address;
    typeKitchen = TypeKitchen;
    timeWork = TimeWork;
}

void Cafe::SetID(QString ID)
{
    id = ID;
}
void Cafe::SetName(QString Name)
{
    name = Name;
}
void Cafe::SetAddress(QString Address)
{
    address = Address;
}
void Cafe::SetTypeKitchen(QString TypeKitchen)
{
    typeKitchen = TypeKitchen;
}
void Cafe::SetTimeWork(QString TimeWork)
{
    timeWork = TimeWork;
}
QString Cafe::ID()
{
    return id;
}
QString Cafe::Name()
{
    return name;
}
QString Cafe::Address()
{
    return address;
}
QString Cafe::TypeKitchen()
{
    return typeKitchen;
}
QString Cafe::TimeWork()
{
    return timeWork;
}
 Cafe::~Cafe()
{
}
