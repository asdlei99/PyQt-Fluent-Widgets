#include "Common/Config.h"
#include "View/MainWindow.h"
#include <QApplication>
#include <QFluentWidgets/Common/Translator.h>
#include <QFluentWidgets/Common/FluentApp.h>
#include <framelessconfig_p.h>

using namespace qfluentwidgets;
FRAMELESSHELPER_USE_NAMESPACE

int main(int argc, char* argv[])
{
    // enable dpi scale
    if (cfg.get(cfg.dpiScale).toString() != "Auto") {
        qputenv("QT_ENABLE_HIGHDPI_SCALING", "0");
        qputenv("QT_SCALE_FACTOR", cfg.get(cfg.dpiScale).toString().toLocal8Bit());
    }

    QApplication app(argc, argv);

    // install translator
    auto locale = cfg.get(cfg.language).value<QLocale>();
    ftranslator.load(locale);

    QTranslator galleryTranslator;
    galleryTranslator.load(locale, "gallery", ".", ":/gallery/i18n");

    app.installTranslator(&galleryTranslator);

    MainWindow w;
    w.show();

    return app.exec();
}
