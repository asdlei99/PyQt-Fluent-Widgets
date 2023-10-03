#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Window/FluentWindow.h>
#include <QTimer>
#include <QVBoxLayout>
#include <framelessconfig_p.h>

using namespace qfluentwidgets;
FRAMELESSHELPER_USE_NAMESPACE

class SubInterface : public QFrame
{
    Q_OBJECT

public:
    explicit SubInterface(const QString& text, QWidget* parent = nullptr) : QFrame(parent)
    {
        auto label = new SubtitleLabel(text, this);
        auto layout = new QHBoxLayout(this);

        ::setFont(label, 24);
        label->setAlignment(Qt::AlignCenter);
        layout->addWidget(label, 1, Qt::AlignCenter);

        setObjectName(text);
    }
};

class Demo : public MSFluentWindow
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr)
        : MSFluentWindow(parent),
          homeInterface(new SubInterface("Home Interface", this)),
          appInterface(new SubInterface("Application Interface", this)),
          videoInterface(new SubInterface("Video Interface", this)),
          libraryInterface(new SubInterface("Library Interface", this))
    {
        initNavigation();

        initWindow();
    }


private:
    void initWindow()
    {
        resize(900, 700);
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
        setWindowTitle("PyQt-Fluent-Widgets");

        // set qss
        auto path = QString("Resource/qss/%1/Navigation1.qss").arg(isDarkTheme() ? "dark" : "light");
        setStyleSheet(getStyleSheetFromFile(path));
    }

    void initNavigation()
    {
        addSubInterface(homeInterface, new FluentIcon(FluentIcon::Home), "主页", NavigationItemPosition::Top,
                        new FluentIcon(FluentIcon::HomeFill));
        addSubInterface(appInterface, new FluentIcon(FluentIcon::Application), "应用");
        addSubInterface(videoInterface, new FluentIcon(FluentIcon::Video), "视频");

        auto pos = NavigationItemPosition::Bottom;
        addSubInterface(libraryInterface, new FluentIcon(FluentIcon::BookShelf), "库", pos, new FluentIcon(FluentIcon::LibraryFill));

        auto item = navigationInterface_->addItem("Help", new FluentIcon(FluentIcon::Help), "帮助", false, nullptr, pos);
        connect(item, &NavigationBarPushButton::clicked, this, &Demo::showMessageBox);

        navigationInterface_->setCurrentItem(homeInterface->objectName());
    }

private slots:
    void showMessageBox(bool triggered)
    {
        auto w = new MessageBox("支持作者",
                                "个人开发不易，如果这个项目帮助到了您，可以考虑请作者喝一瓶快乐水🥤。您的支"
                                "持就是作者开发和维护项目的动力🚀",
                                this);
        w->setYesButtonText("来啦老弟");
        w->setCancelButtonText("下次一定");

        if (w->exec()) {
            QDesktopServices::openUrl(QUrl("https://afdian.net/a/zhiyiYo"));
        }
    }

private:
    SubInterface* homeInterface;
    SubInterface* appInterface;
    SubInterface* videoInterface;
    SubInterface* libraryInterface;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    FramelessConfig::instance()->set(Global::Option::EnableBlurBehindWindow);
    FramelessConfig::instance()->set(Global::Option::DisableLazyInitializationForMicaMaterial);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"