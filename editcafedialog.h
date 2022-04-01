#ifndef EDITCAFEDIALOG_H
#define EDITCAFEDIALOG_H

#endif // EDITCAFEDIALOG_H*/
#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "cafe.h"

class EditCafeDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editAddress;
    QLineEdit* editTypeKitchen;
    QLineEdit* editTimeWork;

public:
    EditCafeDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString address() const;
    QString typeKitchen() const;
    QString timeWork() const;

    void SetUpDialog(QString id, QString name, QString address, QString typeKitchen, QString timeWork);
};

#endif // INPUTDIALOG_H

