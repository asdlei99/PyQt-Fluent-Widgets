#include "ui_LoginWindow.h"
#include <FramelessHelper/Core/FramelessManager>
#include <FramelessHelper/Widgets/FramelessWidgetsHelper>
#include <FramelessHelper/Widgets/StandardSystemButton>
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Common/Translator.h>
#include <QFluentWidgets/Window/FluentWindow.h>
#include <QTimer>
#include <QVBoxLayout>

using namespace qfluentwidgets;
FRAMELESSHELPER_USE_NAMESPACE
using namespace Global;

class Demo : public QWidget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : QWidget(parent), ui(new Ui::Form), titleBar(new SplitTitleBar(this))
    {
        FramelessWidgetsHelper::get(this)->extendsContentIntoTitleBar();

        setThemeColor("#28afe9");

        ui->setupUi(this);
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
        setWindowTitle("QFluentWidgets");
        resize(1000, 650);

        setStyleSheet("Demo{background: rgb(242,242,242)}");
        titleBar->titleLabel()->setStyleSheet(
            "QLabel{ background: transparent; font: 13px 'Segoe UI'; padding: 0 4px; color: white}");

        // set up title bar
        FramelessWidgetsHelper* helper = FramelessWidgetsHelper::get(this);
        helper->setTitleBarWidget(titleBar);
        helper->setSystemButton(titleBar->minButton(), SystemButtonType::Minimize);
        helper->setSystemButton(titleBar->maxButton(), SystemButtonType::Maximize);
        helper->setSystemButton(titleBar->closeButton(), SystemButtonType::Close);

        titleBar->raise();
    }

protected:
    void resizeEvent(QResizeEvent* e)
    {
        QWidget::resizeEvent(e);
        titleBar->resize(width(), titleBar->height());
    }

private:
    Ui::Form* ui;
    SplitTitleBar* titleBar;
};

int main(int argc, char* argv[])
{
    // enable dpi scale
#if (QT_VERSION > QT_VERSION_CHECK(5, 14, 0))
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);

    // internationalization
    ftranslator.load(QLocale());

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"