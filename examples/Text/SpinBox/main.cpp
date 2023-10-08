#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/SpinBox.h>
#include <QGridLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto gridLayout = new QGridLayout(this);

        gridLayout->setContentsMargins(100, 50, 100, 50);
        gridLayout->setHorizontalSpacing(30);

        gridLayout->addWidget(new SpinBox(), 0, 0);
        gridLayout->addWidget(new CompactSpinBox(), 0, 1, Qt::AlignLeft);

        gridLayout->addWidget(new DoubleSpinBox(), 1, 0);
        gridLayout->addWidget(new CompactDoubleSpinBox(), 1, 1, Qt::AlignLeft);

        gridLayout->addWidget(new TimeEdit(), 2, 0);
        gridLayout->addWidget(new CompactTimeEdit(), 2, 1, Qt::AlignLeft);

        gridLayout->addWidget(new DateEdit(), 3, 0);
        gridLayout->addWidget(new CompactDateEdit(), 3, 1, Qt::AlignLeft);

        gridLayout->addWidget(new DateTimeEdit(), 4, 0);
        gridLayout->addWidget(new CompactDateTimeEdit(), 4, 1, Qt::AlignLeft);
        resize(500, 500);
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
    app.setOrganizationName("Shokokawaii Inc.");

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"