#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DateTime/CalendarPicker.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);

        auto picker = new CalendarPicker(this);

        // picker->setDate(QDate(2023, 5, 20));
        // picker->setDateFormat("yyyy-M-d");

        connect(picker, &CalendarPicker::dateChanged, [=](const QDate& date) { qDebug() << date; });

        resize(500, 500);
        vBoxLayout->addWidget(picker, 0, Qt::AlignHCenter);
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