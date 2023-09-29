#pragma once
#include "QFluentWidgets/Common/Config.h"
#include <QLocale>

class Config: public qfluentwidgets::QConfig
{
    Q_OBJECT

public:
    explicit Config(QObject* parent = nullptr);

    // folders
    qfluentwidgets::FolderListConfigItem* musicFolders;
    qfluentwidgets::ConfigItem* downloadFolder;

    // online music
    qfluentwidgets::OptionsConfigItem* onlineSongQuality;
    qfluentwidgets::RangeConfigItem* onlinePageSize;
    qfluentwidgets::ConfigItem* lyricColor;

    // main window
    qfluentwidgets::ConfigItem* enableAcrylic;
    qfluentwidgets::OptionsConfigItem* dpiScale;
    qfluentwidgets::OptionsConfigItem* language;

    // check update
    qfluentwidgets::ConfigItem* checkUpdateAtStartUp;

    static const int YEAR = 2023;
    static const QString AUTHOR;
    static const QString VERSION;
    static const QString HELP_URL;
    static const QString FEEDBACK_URL;
    static const QString RELEASE_URL;
};

Q_DECLARE_METATYPE(QLocale)