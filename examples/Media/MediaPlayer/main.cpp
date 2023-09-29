#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Multimedia/MediaPlayBar.h>
#include <QFluentWidgets/Multimedia/VideoWidget.h>
#include <QVBoxLayout>
#include <QDir>

using namespace qfluentwidgets;

class Demo1 : public Widget
{
    Q_OBJECT
public:
    Demo1(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);
        resize(500, 300);

        auto simpleMediaPlayBar = new SimpleMediaPlayBar(this);
        auto standardMediaPlayBar = new StandardMediaPlayBar(this);

        vBoxLayout->addWidget(simpleMediaPlayBar);
        vBoxLayout->addWidget(standardMediaPlayBar);

        // online music
        simpleMediaPlayBar->player()->setSource(
            QUrl("https://files.cnblogs.com/files/blogs/677826/beat.zip"));

        // local music
        standardMediaPlayBar->player()->setSource(QUrl::fromLocalFile(QDir("Resource/media/aiko - シアワセ.mp3").absolutePath()));
    }
};

class Demo2 : public Widget
{
    Q_OBJECT
public:
    Demo2(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);
        auto videoWidget = new VideoWidget(this);

        // videoWidget->setVideo(
        //     QUrl("https://mvwebfs.tx.kugou.com/202309051557/028d27cbe9d79ae1ffafd9748df93090/v2/"
        //          "e7844104727ea50f658319f2723b6243/KGTX/CLTX002/e7844104727ea50f658319f2723b6243.mp4"));
        // videoWidget->play();

        vBoxLayout->setContentsMargins(0, 0, 0, 0);
        vBoxLayout->addWidget(videoWidget);
        resize(500, 300);
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