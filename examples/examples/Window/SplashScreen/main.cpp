#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Window/SplashScreen.h>
#include <QTimer>
#include <QWidget>

using namespace qfluentwidgets;

class Demo : public QWidget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : QWidget(parent)
    {
        resize(700, 600);
        setWindowTitle("QFluentWidgets");
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));

        // create splash screen
        auto splashScreen = new SplashScreen(windowIcon(), this);
        splashScreen->setIconSize(QSize(102, 102));

        show();

        // create other subinterfaces
        createSubInterface();

        // close splash screen
        splashScreen->finish();
    }

private:
    void createSubInterface()
    {
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"