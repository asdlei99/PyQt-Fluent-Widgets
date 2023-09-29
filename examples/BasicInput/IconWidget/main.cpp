#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/StyleSheet.h>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);

        // use fluent icon
        auto icon1 = new IconWidget(new FluentIcon(FluentIcon::GitHub), this);
        icon1->setFixedSize(20, 20);

        // use QIcon
        auto icon2 = new IconWidget(FluentIcon(FluentIcon::Basketball).icon(), this);
        icon2->setFixedSize(20, 20);

        // use custom svg attribute
        auto icon3 = new IconWidget(new FluentIcon(FluentIcon::CommandPrompt), this);
        icon3->setSvgAttributes({{"fill", "red"}}, {{"fill", "cyan"}});
        icon3->setFixedSize(20, 20);

        hBoxLayout->addWidget(icon1);
        hBoxLayout->addWidget(icon2);
        hBoxLayout->addWidget(icon3);

        resize(200, 200);
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

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"
