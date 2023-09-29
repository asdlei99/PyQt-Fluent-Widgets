#pragma once
#include <QFluentWidgets/Common/Config.h>
#include <QLocale>

#define cfg (Config::instance())

class Config : public qfluentwidgets::QConfig
{
    Q_OBJECT

public:
    explicit Config(QObject* parent = nullptr);

    // folders
    qfluentwidgets::FolderListConfigItem* musicFolders;
    qfluentwidgets::ConfigItem* downloadFolder;

    // main window
    qfluentwidgets::ConfigItem* micaEnabled;
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
    static const QString REPO_URL;
    static const QString EXAMPLE_URL;
    static const QString SUPPORT_URL;

    static Config& instance()
    {
        static Config ins;
        return ins;
    }
};

Q_DECLARE_METATYPE(QLocale)