#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/AcrylicBrush.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent), acrylicBrush(this, 50)
    {
        resize(400, 400);

        QPainterPath path;
        path.addEllipse(0, 0, 400, 400);
        acrylicBrush.setClipPath(path);

        acrylicBrush.setImage(
            QPixmap("Resource/images/shoko.png").scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

protected:
    void paintEvent(QPaintEvent* e)
    {
        acrylicBrush.paint();
        Widget::paintEvent(e);
    }

private:
    AcrylicBrush acrylicBrush;
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

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"
