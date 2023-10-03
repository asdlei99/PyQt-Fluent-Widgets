#include "Config.h"
#include <QColor>

using namespace qfluentwidgets;

Config::Config(QObject* parent)
    : QConfig(parent),
      musicFolders(new FolderListConfigItem("Folders", "LocalMusic", {}, false, this)),
      downloadFolder(new ConfigItem("Folders", "Download", "D:/Shoko/Documents/Download", false, this)),
      onlineSongQuality(new OptionsConfigItem("Online",
                                              "SongQuality",
                                              QVariantList({"Standard", "High", "Super"}),
                                              "Standard",
                                              false,
                                              this)),
      onlinePageSize(new RangeConfigItem("Online", "PageSize", 10, 50, 30, false, this)),
      lyricColor(new ConfigItem("Online", "LyricColor", themeColor(), false, this)),
      enableAcrylic(new ConfigItem("MainWindow", "EnableAcrylic", false, false, this)),
      dpiScale(new OptionsConfigItem("MainWindow",
                                     "DpiScale",
                                     QVariantList({"1", "1.25", "1.5", "1.75", "2", "Auto"}),
                                     "1",
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
const QString Config::HELP_URL = "https://pyqt-fluent-widgets.readthedocs.io";
const QString Config::FEEDBACK_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/issues";
const QString Config::RELEASE_URL = "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/releases/latest";