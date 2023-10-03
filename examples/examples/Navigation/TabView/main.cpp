#include <FramelessWidgetsHelper>
#include <QApplication>
#include <QDesktopServices>
#include <QFileSystemModel>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Widgets/TabView.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Window/FluentWindow.h>
#include <QHBoxLayout>
#include <QWidget>

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

class TabInterface : public QFrame
{
    Q_OBJECT

public:
    explicit TabInterface(const QString& text,
                          const QString& icon,
                          const QString& objectName,
                          QWidget* parent = nullptr)
        : QFrame(parent)
    {
        auto iconWidget = new IconWidget(icon, this);
        auto label = new SubtitleLabel(text, this);
        auto layout = new QVBoxLayout(this);

        iconWidget->setFixedSize(120, 120);

        layout->setAlignment(Qt::AlignCenter);
        layout->setSpacing(30);
        layout->addWidget(iconWidget, 0, Qt::AlignCenter);
        layout->addWidget(label, 0, Qt::AlignCenter);

        ::setFont(label, 24);
        setObjectName(objectName);
    }
};

class CustomTitleBar : public MSFluentTitleBar
{
    Q_OBJECT

public:
    explicit CustomTitleBar(QWidget* parent = nullptr) : MSFluentTitleBar(parent)
    {
        auto toolButtonLayout = new QHBoxLayout();

        QColor color = isDarkTheme() ? "#cecece" : "#606060";
        auto searchButton =
            new TransparentToolButton(FluentIcon(FluentIcon::SearchMirror).icon(Theme::Auto, color), this);
        auto forwardButton =
            new TransparentToolButton(FluentIcon(FluentIcon::RightArrow).icon(Theme::Auto, color), this);
        auto backButton = new TransparentToolButton(FluentIcon(FluentIcon::LeftArrow).icon(Theme::Auto, color), this);

        forwardButton->setDisabled(true);
        toolButtonLayout->setContentsMargins(20, 0, 20, 0);
        toolButtonLayout->setSpacing(15);
        toolButtonLayout->addWidget(searchButton);
        toolButtonLayout->addWidget(backButton);
        toolButtonLayout->addWidget(forwardButton);
        hBoxLayout_->insertLayout(4, toolButtonLayout);

        // add tab bar
        tabBar = new TabBar(this);

        tabBar->setMovable(true);
        tabBar->setTabMaximumWidth(220);
        tabBar->setTabShadowEnabled(false);
        tabBar->setTabSelectedBackgroundColor(QColor(255, 255, 255, 125), QColor(255, 255, 255, 50));
        // tabBar->setScrollable(true);
        // tabBar->setCloseButtonDisplayMode(TabItem::OnHover);

        connect(tabBar, &TabBar::tabCloseRequested, tabBar, &TabBar::removeTab);
        connect(tabBar, &TabBar::currentChanged, tabBar, [=](int i) { qDebug() << tabBar->tabText(i); });

        hBoxLayout_->insertWidget(5, tabBar, 1);
        hBoxLayout_->setStretch(6, 0);

        // add avatar
        auto avatar = new AvatarWidget("Resource/images/shoko.png", this);
        avatar->setRadius(13);
        hBoxLayout_->insertWidget(7, avatar, 0, Qt::AlignRight);
        hBoxLayout_->insertSpacing(8, 20);

        // make tab bar clickable in frameless window
        FramelessWidgetsHelper::get(parentWidget())->setHitTestVisible(tabBar);
    }

    TabBar* tabBar;
};

class Demo : public MSFluentWindow
{
    Q_OBJECT

public:
    Demo(QWidget* parent = nullptr) : MSFluentWindow(parent)
    {
        // use custom title bar
        auto titleBar = new CustomTitleBar(this);
        setTitleBar(titleBar);
        tabBar = titleBar->tabBar;

        // create sub interface
        homeInterface = new QStackedWidget(this);
        homeInterface->setObjectName("homeInterface");

        appInterface = new SubInterface("Application Interface", this);
        videoInterface = new SubInterface("Video Interface", this);
        libraryInterface = new SubInterface("Library Interface", this);

        initNavigation();
        initWindow();
    };

private:
    void initNavigation()
    {
        addSubInterface(homeInterface, new FluentIcon(FluentIcon::Home), "主页", NavigationItemPosition::Top,
                        new FluentIcon(FluentIcon::HomeFill));
        addSubInterface(appInterface, new FluentIcon(FluentIcon::Application), "应用");
        addSubInterface(videoInterface, new FluentIcon(FluentIcon::Application), "视频");

        addSubInterface(libraryInterface, new FluentIcon(FluentIcon::BookShelf), "库", NavigationItemPosition::Bottom,
                        new FluentIcon(FluentIcon::LibraryFill));
        navigationInterface_->addItem("Help", new FluentIcon(FluentIcon::Help), "帮助", false, nullptr,
                                      NavigationItemPosition::Bottom);

        addTab("Heart", "As long as you love me", "Resource/images/emoji/Hot face.png");

        connect(tabBar, &TabBar::currentChanged, this, &Demo::onTabChanged);
        connect(tabBar, &TabBar::tabAddRequested, this, &Demo::onTabAddRequested);
    }

    void initWindow()
    {
        resize(900, 700);
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
        setWindowTitle("QFluentWidgets");
    }

    void addTab(const QString& routeKey, const QString& text, const QString& icon)
    {
        tabBar->addTab(routeKey, text, QIcon(icon));
        homeInterface->addWidget(new TabInterface(text, icon, routeKey, this));
    }

    void onTabChanged(int index)
    {
        auto objectName = tabBar->currentTab()->routeKey();
        homeInterface->setCurrentWidget(findChild<TabInterface*>(objectName));
        stackedWidget_->setCurrentWidget(homeInterface);
    }

    void onTabAddRequested()
    {
        auto text = QString("硝子酱一级棒卡哇伊×%1").arg(tabBar->count());
        addTab(QString::number(count++), text, "Resource/images/emoji/Smiling face with hearts.png");
    }

    int count{0};
    TabBar* tabBar;
    QStackedWidget* homeInterface;
    SubInterface* appInterface;
    SubInterface* videoInterface;
    SubInterface* libraryInterface;
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