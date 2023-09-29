#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QHBoxLayout>
#include <QLabel>

using namespace qfluentwidgets;

class Demo1 : public ScrollArea
{
    Q_OBJECT
public:
    Demo1(QWidget* parent = nullptr) : ScrollArea(parent)
    {
        auto imageLabel = new ImageLabel("Resource/images/chidanta1.jpg", this);
        imageLabel->scaledToWidth(775);

        setWidget(imageLabel);
        resize(775, 730);

        setWindowTitle("Scroll Area");

        if (qfluentwidgets::isDarkTheme()) {
            setStyleSheet("Demo1{background:rgb(32,32,32); border: none}");
        } else {
            setStyleSheet("Demo1{background:white; border: none}");
        }
    }
};

class Demo2 : public SmoothScrollArea
{
    Q_OBJECT
public:
    Demo2(QWidget* parent = nullptr) : SmoothScrollArea(parent)
    {
        auto imageLabel = new ImageLabel("Resource/images/chidanta1.jpg", this);
        imageLabel->scaledToWidth(775);

        setScrollAnimation(Qt::Vertical, 500, QEasingCurve::OutQuint);
        setScrollAnimation(Qt::Horizontal, 500, QEasingCurve::OutQuint);

        setWidget(imageLabel);
        resize(775, 730);
        setWindowTitle("Smooth Scroll Area");

        if (qfluentwidgets::isDarkTheme()) {
            setStyleSheet("Demo2{background:rgb(32,32,32); border: none}");
        } else {
            setStyleSheet("Demo2{background:white; border: none}");
        }
    }
};

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

    return app.exec();
}

#include "main.moc"