#pragma once

#include <QFluentWidgets/Common/Icon.h>
#include <QMetaEnum>

class GalleryIcon : public qfluentwidgets::FluentIconBase
{
    Q_OBJECT
public:
    enum Type { Menu = 0, Text, Grid };
    Q_ENUM(Type)

    explicit GalleryIcon(Type iconType, QObject* parent = nullptr) : FluentIconBase(parent), iconType_(iconType) {}

    QString path(qfluentwidgets::Theme theme = qfluentwidgets::Theme::Auto) override
    {
        return QString(":/gallery/images/icons/%1_%2.svg").arg(name()).arg(qfluentwidgets::getIconColor(theme));
    }

    virtual FluentIconBase* clone() override { return new GalleryIcon(iconType_, parent()); }

    virtual QString name()
    {
        QMetaEnum e = QMetaEnum::fromType<Type>();
        return e.valueToKey(static_cast<int>(iconType_));
    }

private:
    Type iconType_ = Type::Menu;
};