#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Window/FluentWindow.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

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

class Demo : public FluentWindow
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr)
        : FluentWindow(parent),
          searchInterface(new SubInterface("Search Interface", this)),
          musicInterface(new SubInterface("Music Interface", this)),
          videoInterface(new SubInterface("Video Interface", this)),
          albumInterface(new SubInterface("Albums", this)),
          albumInterface1(new SubInterface("Album 1", this)),
          albumInterface1_1(new SubInterface("Album 1.1", this)),
          albumInterface2(new SubInterface("Album 2", this)),
          folderInterface(new SubInterface("Folder Interface", this)),
          settingInterface(new SubInterface("Setting Interface", this))
    {
        // initialize navigation
        initNavigation();

        initWindow();
    }

private:
    void initWindow()
    {
        resize(900, 700);
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
        setWindowTitle("PyQt-Fluent-Widgets");
    }

    void initNavigation()
    {
        addSubInterface(searchInterface, new FluentIcon(FluentIcon::Search), "Search");
        addSubInterface(musicInterface, new FluentIcon(FluentIcon::Music), "Music library");
        addSubInterface(videoInterface, new FluentIcon(FluentIcon::Video), "Video library");

        navigationInterface_->addSeparator();

        // add navigation items to scroll area
        auto pos = NavigationItemPosition::Scroll;
        addSubInterface(albumInterface, new FluentIcon(FluentIcon::Album), "Albums", pos);
        addSubInterface(albumInterface1, new FluentIcon(FluentIcon::Album), "Albums 1", pos, albumInterface);
        addSubInterface(albumInterface1_1, new FluentIcon(FluentIcon::Album), "Albums 1.1", pos, albumInterface1);
        addSubInterface(albumInterface2, new FluentIcon(FluentIcon::Album), "Albums 2", pos, albumInterface);

        addSubInterface(folderInterface, new FluentIcon(FluentIcon::Folder), "Folder library", pos);

        // add custom widget to bottom
        auto avatar = new NavigationAvatarWidget("zhiyiYo", "Resource/images/shoko.png");
        pos = NavigationItemPosition::Bottom;
        navigationInterface_->addWidget("avatar", avatar, pos);
        connect(avatar, &NavigationAvatarWidget::clicked, this, &Demo::showMessageBox);

        addSubInterface(settingInterface, new FluentIcon(FluentIcon::Setting), "Setting", pos);
    }

private slots:
    void showMessageBox()
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
    SubInterface* searchInterface;
    SubInterface* musicInterface;
    SubInterface* videoInterface;
    SubInterface* albumInterface;
    SubInterface* albumInterface1;
    SubInterface* albumInterface1_1;
    SubInterface* albumInterface2;
    SubInterface* folderInterface;
    SubInterface* settingInterface;
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