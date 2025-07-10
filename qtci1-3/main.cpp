#include <QCoreApplication>

#include <QDebug>
#include <QScopedPointer>
#include "test.h"

void myTest(QScopedPointer<test> & myPointer) {
    qInfo() << myPointer.data();
}

void useIt(test * obj) {
    if ( ! obj)
        return;

    qInfo() << "Using" << obj;
}

void doStuff() {
    // test * t = new test();
    QScopedPointer<test> myPointer(new test());

    // useIt( myPointer.data() );
    myTest( myPointer );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // for (int i = 0; i < 100; ++i){
    //     doStuff();
    // }

    doStuff();

    return a.exec();
}
