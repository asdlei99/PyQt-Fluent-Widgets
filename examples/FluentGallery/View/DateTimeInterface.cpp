#include "DateTimeInterface.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Components/DateTime/DatePicker.h>
#include <QFluentWidgets/Components/DateTime/TimePicker.h>
#include <QFluentWidgets/Components/DateTime/CalendarPicker.h>

DateTimeInterface::DateTimeInterface(QWidget* parent)
    : GalleryInterface(translator.dateTime, "<QFluentWidgets/Components/DataTime>", parent)
{
    setObjectName("dateTimeInterface");

    addExampleCard(
        tr("A simple CalendarPicker"), new CalendarPicker(this),
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/calendar_picker/demo.py");

    auto w = new CalendarPicker(this);
    w->setDateFormat(Qt::TextDate);
    addExampleCard(
        tr("A CalendarPicker in another format"), w,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/calendar_picker/demo.py");

    addExampleCard(tr("A simple DatePicker"), new DatePicker(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/time_picker/demo.py");

    addExampleCard(tr("A DatePicker in another format"), new ZhDatePicker(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/time_picker/demo.py");

    addExampleCard(tr("A simple TimePicker"), new AMTimePicker(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/time_picker/demo.py");

    addExampleCard(tr("A TimePicker using a 24-hour clock"), new TimePicker(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/time_picker/demo.py");

    addExampleCard(tr("A TimePicker with seconds column"), new TimePicker(this, true),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/date_time/time_picker/demo.py");
}