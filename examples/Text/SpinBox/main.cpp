#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/SpinBox.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);

        vBoxLayout->setContentsMargins(100, 50, 100, 50);
        vBoxLayout->addWidget(new SpinBox());
        vBoxLayout->addWidget(new DoubleSpinBox());
        vBoxLayout->addWidget(new TimeEdit());
        vBoxLayout->addWidget(new DateEdit());
        vBoxLayout->addWidget(new DateTimeEdit());
        resize(500, 500);

        if (!isDarkTheme()) {
            setStyleSheet("Demo{background:rgb(242,242,242)}");
        }
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