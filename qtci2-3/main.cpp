#include <QCoreApplication>
#include <QSet>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Bryan" << "Heather" << "Chris" << "Tammy";
    people.insert("Rango");

    foreach (QString person, people) {
        qInfo() << person;
    }

    qInfo() << "Bryan in collection:" << people.contains("Bryan");

    return a.exec();
}
