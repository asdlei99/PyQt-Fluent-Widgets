#pragma once

#include <QFluentWidgets/Common/FluentApp.h>
#include <QWidget>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget* parent = nullptr) : QWidget(parent)
    {
        connect(&qconfig, &qfluentwidgets::QConfig::themeChanged, this, &Widget::updateBackground);
        updateBackground();
    }

private slots:
    void updateBackground()
    {
        if (qfluentwidgets::isDarkTheme()) {
            setStyleSheet("Widget{background:rgb(32,32,32)}");
        } else {
            setStyleSheet("Widget{background:white}");
        }
    }
};
