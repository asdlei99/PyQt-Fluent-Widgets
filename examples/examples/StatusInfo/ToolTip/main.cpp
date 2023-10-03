#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/ToolTip.h>
#include <QHBoxLayout>
#include <QWidget>
#include <QDesktopServices>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        PushButton* button1 = new PushButton("キラキラ", this);
        PushButton* button2 = new PushButton("食べた愛", this);
        PushButton* button3 = new PushButton("シアワセ", this);

        button1->setToolTip("aiko - キラキラ ✨");
        button2->setToolTip("aiko - 食べた愛 🥰");
        button3->setToolTip("aiko - シアワセ 😊");
        button1->setToolTipDuration(1000);

        button1->installEventFilter(new ToolTipFilter(button1, 0, ToolTip::Top));
        button2->installEventFilter(new ToolTipFilter(button2, 0, ToolTip::Bottom));
        button3->installEventFilter(new ToolTipFilter(button3, 300, ToolTip::Right));

        connect(button1, &PushButton::clicked, this, [=]() {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=S0bXDRY1DGM&list=RDMM&index=1"));
        });
        connect(button2, &PushButton::clicked, this, [=]() {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=CZLs8GuCq2U&list=RDMM&index=4"));
        });
        connect(button3, &PushButton::clicked, this, [=]() {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=fp-yJUB7sS8&list=RDMM&index=3"));
        });

        hBoxLayout->setContentsMargins(24, 24, 24, 24);
        hBoxLayout->setSpacing(16);
        hBoxLayout->addWidget(button1);
        hBoxLayout->addWidget(button2);
        hBoxLayout->addWidget(button3);

        resize(480, 240);
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