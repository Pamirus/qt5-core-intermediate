#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"
#include "Consumer.h"

void doDeleteLater(test * obj) {
    qInfo() << "Deleting:" << obj;
    obj->deleteLater();
}

QSharedPointer<test> createPointer() {
    test * t = new test();
    t->setObjectName("Test object");
    QSharedPointer<test> p(t, doDeleteLater);
    return p;
}

void doStuff(QSharedPointer<Consumer> ptr) {
    qInfo() << "In function:" << ptr.data()->tester;
    ptr.clear(); // Does not actually delete, just removes the reference
}

QSharedPointer<Consumer> makeConsumer() {
    QSharedPointer<Consumer> c(new Consumer, &QObject::deleteLater);
    QSharedPointer<test> t = createPointer();

    c.data()->tester.swap(t);
    doStuff(c);

    return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSharedPointer<Consumer> consumer = makeConsumer();
    qInfo() << "In main:" << consumer.data()->tester;
    consumer.clear();

    return a.exec();
}
