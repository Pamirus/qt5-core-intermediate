#include <QCoreApplication>
#include <QMap>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 49);
    ages.insert("Rango", 15);

    qInfo() << "Bryan is" << ages["Bryan"] << "years old";
    qInfo() << "Keys:"    << ages.keys();

    foreach (QString key, ages.keys()) {
        qInfo() << key << "=" << ages[key];
    }

    return a.exec();
}
