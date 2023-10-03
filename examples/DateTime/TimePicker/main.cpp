#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DateTime/DatePicker.h>
#include <QFluentWidgets/Components/DateTime/TimePicker.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class SecondsFormatter : public PickerColumnFormatter
{
    Q_OBJECT
public:
    SecondsFormatter(QObject* parent = nullptr) : PickerColumnFormatter(parent) {}

    QString encode(const QVariant& value) { return value.toString() + "秒"; }

    QString decode(const QVariant& value) { return value.toString().left(value.toString().count() - 1); }
};

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);

        auto datePicker1 = new DatePicker(this);
        auto datePicker2 = new ZhDatePicker(this);

        auto timePicker1 = new AMTimePicker(this);
        auto timePicker2 = new TimePicker(this);
        auto timePicker3 = new TimePicker(this, true);

        // customize column format
        timePicker3->setColumnFormatter(2, new SecondsFormatter(this));

        connect(datePicker1, &DatePicker::dateChanged, [=](const QDate& date) { qDebug() << date; });
        connect(datePicker2, &DatePicker::dateChanged, [=](const QDate& date) { qDebug() << date; });
        connect(timePicker1, &AMTimePicker::timeChanged, [=](const QTime& time) { qDebug() << time; });
        connect(timePicker2, &TimePicker::timeChanged, [=](const QTime& time) { qDebug() << time; });
        connect(timePicker3, &TimePicker::timeChanged, [=](const QTime& time) { qDebug() << time; });

        // set current date/time
        // datePicker1->setDate(QDate::currentDate())
        // timePicker1->setTime(QTime(13, 15))
        // timePicker2->setTime(QTime(13, 15))

        resize(500, 500);
        vBoxLayout->addWidget(datePicker1, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(datePicker2, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(timePicker1, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(timePicker2, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(timePicker3, 0, Qt::AlignHCenter);
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