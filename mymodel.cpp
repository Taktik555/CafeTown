#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Cafe* std1 = new Cafe("1","CafeShop","Ивановская ул, д.1","Русская","10:00-22:00",this);
    Cafe* std2 = new Cafe("2","У дяди Вани","Лежневская ул, д.1","Американская","08:00-03:00",this);
    Cafe* std3 = new Cafe("3","Пепперони","Рабфаковская ул. д.1","Итальянская","10:00-18:00",this);
    AddCafe(std1);
    AddCafe(std2);
    AddCafe(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return cafes.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Cafe* std = cafes.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Address();}
        else if (index.column() == 3){Value = std->TypeKitchen();}
        else if (index.column() == 4){Value = std->TimeWork();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Адрес");
            case 3:
                return QString("Тип кухни");
            case 4:
                return QString("Время работы");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Cafe* std = cafes.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetAddress(value.toString());}
        else if (index.column() == 3){std->SetTypeKitchen(value.toString());}
        else if (index.column() == 4){std->SetTimeWork(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddCafe(Cafe* cafe)
{
    beginInsertRows(QModelIndex(),cafes.size(),cafes.size());
    cafes.append(cafe);
    endInsertRows();
    //emit layoutChanged();
}

void MyModel::DeleteCafe(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    cafes.removeAt(row);
    endRemoveRows();
    //emit layoutChanged();
}

