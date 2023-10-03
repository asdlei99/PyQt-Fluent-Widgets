#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDebug>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/StyleSheet.h>
#include <QFluentWidgets/Components/DialogBox/ColorDialog.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hlayout = new QHBoxLayout(this);
        auto btn = new PrimaryPushButton("color");
        hlayout->addWidget(btn);

        connect(btn, &PrimaryPushButton::clicked, this, [=]() {
            auto dialog = new ColorDialog(QColor("#5012aaa2"), "Background Color", this, true);
            dialog->exec();
        });

        resize(800, 1000);
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