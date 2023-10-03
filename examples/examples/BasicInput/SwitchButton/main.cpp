#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/StyleSheet.h>
#include <QFluentWidgets/Components/Widgets/SwitchButton.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto switchButton = new SwitchButton(this);
        hBoxLayout->addWidget(switchButton, 0, Qt::AlignCenter);
        resize(200, 200);
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
