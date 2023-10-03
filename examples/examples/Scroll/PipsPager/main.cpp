#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/PipsPager.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        VerticalPipsPager* vPager = new VerticalPipsPager(this);
        HorizontalPipsPager* hPager = new HorizontalPipsPager(this);

        // set the number of page
        vPager->setPageNumber(15);
        hPager->setPageNumber(15);

        // set the number of displayed pips
        hPager->setVisibleNumber(8);
        hPager->setNextButtonDisplayMode(PipsPager::Always);
        hPager->setPreviousButtonDisplayMode(PipsPager::Always);

        // set the display mode of scroll button
        vPager->setNextButtonDisplayMode(PipsPager::Always);
        vPager->setPreviousButtonDisplayMode(PipsPager::Always);

        connect(vPager, &VerticalPipsPager::currentIndexChanged, this,
                [=](int index) { qDebug() << "vertical index changed:" << index; });
        connect(hPager, &HorizontalPipsPager::currentIndexChanged, this,
                [=](int index) { qDebug() << "horizontal index changed:" << index; });

        setLayout(new QHBoxLayout());
        layout()->addWidget(hPager);
        layout()->addWidget(vPager);

        resize(500, 500);
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
