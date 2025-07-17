#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>

template<class T>
void fill(T & container) {
    for (int i = 0; i < 5; ++i) {
        container.append(i);
    }
}

template<class T>
void display(T & container) {
    for (int i = 0; i < container.length(); ++i) {
        if (i > 0) {
            auto current  = reinterpret_cast<std::uintptr_t>( & container.at(i)    );
            auto previous = reinterpret_cast<std::uintptr_t>( & container.at(i - 1));
            auto distance = current - previous;
            qInfo() << i << "at:"       << current
                         << "previous:" << previous
                         << "distance:" << distance;
        }
        else {
            qDebug() << Q_FUNC_INFO << __LINE__;
            qInfo() << i << &container.at(i) << "distance: 0";
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vector = QVector<int>();
    QList<int>   list   = QList<int>();

    fill(vector);
    fill(list);

    qInfo() << "Int takes:" << sizeof(int) << "bytes of ram";
    qInfo() << "QVector uses continuous locations in memory.";
    display(vector);
    qInfo() << "";

    qInfo() << "QList uses what ever it can find in memory.";
    display(list);
    qInfo() << "";

    return a.exec();
}
