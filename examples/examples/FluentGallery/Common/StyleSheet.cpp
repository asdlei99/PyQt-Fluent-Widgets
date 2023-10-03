#include "StyleSheet.h"
#include <QMetaEnum>

using namespace qfluentwidgets;

QString StyleSheet::path(Theme t)
{
    QString tn;
    if (t == Theme::Auto) {
        tn = isDarkTheme() ? "dark" : "light";
    } else {
        tn = themeName(t).toLower();
    }

    QMetaEnum e = QMetaEnum::fromType<Name>();
    auto name = e.valueToKey(static_cast<int>(name_));
    return QString(":/gallery/qss/%1/%2.qss").arg(tn).arg(name);
}

StyleSheet* StyleSheet::applyTo(Name name, QWidget* widget, Theme theme)
{
    auto s = new StyleSheet(name, widget);
    s->apply(widget, theme);
    return s;
}