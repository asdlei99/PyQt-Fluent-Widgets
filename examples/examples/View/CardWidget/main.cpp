#include <QApplication>
#include "Demo1.h"
#include "Demo2.h"
#include "Demo3.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo1 w1;
    w1.show();

    Demo2 w2;
    w2.show();

    Demo3 w3;
    w3.show();

    return app.exec();
}

#include "main.moc"