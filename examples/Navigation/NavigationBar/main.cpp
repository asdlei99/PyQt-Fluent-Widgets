#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Navigation/NavigationBar.h>
#include <QStackedWidget>
#include <QTimer>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class SubInterface : public QFrame
{
    Q_OBJECT

public:
    explicit SubInterface(const QString& text, QWidget* parent = nullptr) : QFrame(parent)
    {
        auto label = new QLabel(text, this);
        auto layout = new QHBoxLayout(this);

        label->setAlignment(Qt::AlignCenter);
        layout->addWidget(label, 1, Qt::AlignCenter);

        setObjectName(text);
    }
};

class Demo : public QWidget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr)
        : QWidget(parent),
          hBoxLayout(new QHBoxLayout(this)),
          navigationBar(new NavigationBar(this)),
          homeInterface(new SubInterface("Home Interface", this)),
          appInterface(new SubInterface("Application Interface", this)),
          videoInterface(new SubInterface("Video Interface", this)),
          libraryInterface(new SubInterface("Library Interface", this)),
          stackedWidget(new QStackedWidget(this))
    {
        // initialize layout
        initLayout();

        // initialize navigation
        initNavigation();

        initWindow();
    }


private:
    void initLayout()
    {
        hBoxLayout->setSpacing(0);
        hBoxLayout->setContentsMargins(0, 0, 0, 0);
        hBoxLayout->addWidget(navigationBar);
        hBoxLayout->addWidget(stackedWidget);
        hBoxLayout->setStretchFactor(stackedWidget, 1);
    }

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
        addSubInterface(libraryInterface, new FluentIcon(FluentIcon::Setting), "库", pos);

        auto item = navigationBar->addItem("Help", new FluentIcon(FluentIcon::Help), "帮助", false, nullptr, pos);
        connect(item, &NavigationBarPushButton::clicked, this, &Demo::showMessageBox);

        navigationBar->setCurrentItem(homeInterface->objectName());
    }

    void addSubInterface(SubInterface* interface,
                         FluentIconBase* icon,
                         const QString& text,
                         NavigationItemPosition position = NavigationItemPosition::Top,
                         FluentIconBase* selectedIcon = nullptr)
    {
        stackedWidget->addWidget(interface);

        auto item = navigationBar->addItem(interface->objectName(), icon, text, true, selectedIcon, position);
        connect(item, &NavigationBarPushButton::clicked, this, [=](bool t) { this->switchTo(interface); });
    }


private slots:
    void switchTo(SubInterface* interface) { stackedWidget->setCurrentWidget(interface); }

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
    QHBoxLayout* hBoxLayout;
    NavigationBar* navigationBar;
    SubInterface* homeInterface;
    SubInterface* appInterface;
    SubInterface* videoInterface;
    SubInterface* libraryInterface;
    QStackedWidget* stackedWidget;
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

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"