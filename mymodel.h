#pragma once
#define MYMODEL_H


#include <QAbstractTableModel>
#include <QString>
#include "cafe.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;


    void AddCafe(Cafe* cafe);
    void DeleteCafe(int row);
private:
    QList<Cafe*> cafes;
};
