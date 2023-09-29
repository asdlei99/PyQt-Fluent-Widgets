#pragma once

#include <QFluentWidgets/Common/StyleSheet.h>

class StyleSheet : public qfluentwidgets::StyleSheetBase
{
    Q_OBJECT

public:
    enum Name {
        LinkCard = 0,
        SampleCard,
        HomeInterface,
        IconInterface,
        ViewInterface,
        SettingInterface,
        GalleryInterface,
        NavigationViewInterface
    };

    Q_ENUM(Name)

    explicit StyleSheet(Name name, QObject* parent = nullptr) : StyleSheetBase(parent), name_(name){};

    virtual QString path(qfluentwidgets::Theme theme = qfluentwidgets::Theme::Auto) override;

    static StyleSheet* applyTo(Name name, QWidget* widget, qfluentwidgets::Theme theme = qfluentwidgets::Theme::Auto);

private:
    Name name_;
};