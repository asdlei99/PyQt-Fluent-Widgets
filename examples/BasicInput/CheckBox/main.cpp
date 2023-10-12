#include "../../Shared/Widget.h"
#include <QApplication>
#include <QVBoxLayout>

// use header alias, you can also include header file like "QFluentWidgets/Common/FluentApp.h"
#include <FApp>
#include <FStyleSheet>
#include <FCheckBox>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);
        auto checkBox = new CheckBox("CheckBox", this);

        checkBox->setTristate(true);

        vBoxLayout->addWidget(checkBox, 0, Qt::AlignCenter);
        resize(300, 150);
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