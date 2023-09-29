#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Components/Layout/FlowLayout.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto layout = new FlowLayout(this, true);

        // customize animation
        layout->setAnimation(250, QEasingCurve::OutQuad);

        layout->setContentsMargins(30, 30, 30, 30);
        layout->setVerticalSpacing(20);
        layout->setHorizontalSpacing(10);

        layout->addWidget(new PushButton("aiko"));
        layout->addWidget(new PushButton("刘静爱"));
        layout->addWidget(new PushButton("柳井爱子"));
        layout->addWidget(new PushButton("aiko 赛高"));
        layout->addWidget(new PushButton("aiko 太爱啦😘"));
        layout->addWidget(new PushButton("aiko"));
        layout->addWidget(new PushButton("刘静爱"));
        layout->addWidget(new PushButton("柳井爱子"));
        layout->addWidget(new PushButton("aiko 赛高"));
        layout->addWidget(new PushButton("aiko 太爱啦😘"));

        resize(250, 300);
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
