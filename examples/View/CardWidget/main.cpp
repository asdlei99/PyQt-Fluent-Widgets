#include <QApplication>
#include "Demo1.h"
#include "Demo2.h"
#include "Demo3.h"

int main(int argc, char* argv[])
{
    // enable dpi scale
#if (QT_VERSION > QT_VERSION_CHECK(5, 14, 0))
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

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