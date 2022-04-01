#include "editcafedialog.h"
#include "cafe.h"
EditCafeDialog::EditCafeDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editAddress = new QLineEdit();
    editTypeKitchen = new QLineEdit();
    editTimeWork = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Адрес"),3,1);
    mainLayout->addWidget(editAddress,3,2);
    mainLayout->addWidget(new QLabel("Тип кухни"),4,1);
    mainLayout->addWidget(editTypeKitchen,4,2);
    mainLayout->addWidget(new QLabel("Время работы"),5,1);
    mainLayout->addWidget(editTimeWork,5,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о кафе города");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditCafeDialog::id() const
{
    return editID->text();
}
QString EditCafeDialog::name() const
{
    return editName->text();
}
QString EditCafeDialog::address() const
{
    return editAddress->text();
}
QString EditCafeDialog::typeKitchen() const
{
    return editTypeKitchen->text();
}
QString EditCafeDialog::timeWork() const
{
    return editTimeWork->text();
}

void EditCafeDialog::SetUpDialog(QString id, QString name, QString address, QString typeKitchen, QString timeWork)
{
    editID->setText(id);
    editName->setText(name);
    editAddress->setText(address);
    editTypeKitchen->setText(typeKitchen);
    editTimeWork->setText(timeWork);
}
