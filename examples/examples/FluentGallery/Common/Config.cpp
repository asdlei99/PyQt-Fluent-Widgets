#include "Config.h"
#include <QColor>

using namespace qfluentwidgets;

using namespace qfluentwidgets;

Config::Config(QObject* parent)
    : QConfig(parent),
      musicFolders(new FolderListConfigItem("Folders", "LocalMusic", {}, false, this)),
      downloadFolder(new ConfigItem("Folders", "Download", "D:/Shoko/Documents/Download", false, this)),
      micaEnabled(new ConfigItem("MainWindow", "MicaEnabled", false, false, this)),
      dpiScale(new OptionsConfigItem("MainWindow",
                                     "DpiScale",
                                     QVariantList({"1", "1.25", "1.5", "1.75", "2", "Auto"}),
                                     "Auto",
                                     true,
                                     this)),
      language(
          new OptionsConfigItem("MainWindow",
                                "Language",
                                {QLocale(QLocale::Chinese, QLocale::China),
                                 QLocale(QLocale::Chinese, QLocale::HongKong), QLocale(QLocale::English), QLocale()},
                                QLocale(),
                                true,
                                this)),
      checkUpdateAtStartUp(new ConfigItem("Update", "CheckUpdateAtStartUp", true, false, this))
{
}

const QString Config::AUTHOR = "zhiyiYo";
const QString Config::VERSION = "0.1.0";
const QString Config::HELP_URL = "https://qfluentwidgets.com/zh/";
const QString Config::REPO_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets";
const QString Config::EXAMPLE_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/tree/master/examples";
const QString Config::FEEDBACK_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/issues";
const QString Config::RELEASE_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/releases/latest";
const QString Config::SUPPORT_URL = "https://afdian.net/a/zhiyiYo";