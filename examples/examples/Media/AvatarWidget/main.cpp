#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QHBoxLayout>
#include <QWidget>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        resize(400, 300);
        auto hBoxLayout = new QHBoxLayout(this);

        QPixmap avatar("Resource/images/shoko.png");

        QList<int> sizes = {96, 48, 32, 24};
        for (auto s : sizes) {
            auto w = new AvatarWidget(avatar);
            w->setRadius(s / 2);
            hBoxLayout->addWidget(w);
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