#pragma once

#include <QObject>

#define translator (Translator::instance())

class Translator : public QObject
{
    Q_OBJECT

public:
    explicit Translator(QObject* parent = nullptr) : QObject(parent)
    {
        text = tr("Text");
        view = tr("View");
        menus = tr("Menus & toolbars");
        icons = tr("Icons");
        layout = tr("Layout");
        dialogs = tr("Dialogs & flyouts");
        scroll = tr("Scrolling");
        material = tr("Material");
        dateTime = tr("Date & time");
        navigation = tr("Navigation");
        basicInput = tr("Basic input");
        statusInfo = tr("Status & info");
    }

    QString text;
    QString view;
    QString menus;
    QString icons;
    QString layout;
    QString dialogs;
    QString scroll;
    QString material;
    QString dateTime;
    QString navigation;
    QString basicInput;
    QString statusInfo;

    static Translator& instance()
    {
        static Translator t;
        return t;
    }
};