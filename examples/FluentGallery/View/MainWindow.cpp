#include "MainWindow.h"
#include "../Common/Icon.h"
#include "../Common/SignalBus.h"
#include "../Common/Translator.h"
#include <QApplication>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QFluentWidgets/Common/Icon.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QScreen>

using namespace qfluentwidgets;

MainWindow::MainWindow() : FluentWindow()
{
    initWindow();

    homeInterface_ = new HomeInterface(this);
    iconInterface_ = new IconInterface(this);
    basicInputInterface_ = new BasicInputInterface(this);
    dateTimeInterface_ = new DateTimeInterface(this);
    dialogInterface_ = new DialogInterface(this);
    layoutInterface_ = new LayoutInterface(this);
    menuInterface_ = new MenuInterface(this);
    navigationViewInterface_ = new NavigationViewInterface(this);
    scrollInterface_ = new ScrollInterface(this);
    statusInterface_ = new StatusInfoInterface(this);
    textInterface_ = new TextInterface(this);
    viewInterface_ = new ViewInterface(this);
    settingInterface_ = new SettingInterface(this);

    connectSignalToSlot();

    initNavigation();
    splashScreen_->finish();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    FluentWindow::resizeEvent(event);
    splashScreen_->resize(size());
}

void MainWindow::initWindow()
{
    resize(950, 780);
    setMinimumWidth(760);
    setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
    setWindowTitle("QFluentWidgets");

    // TODO: Mica

    splashScreen_ = new SplashScreen(windowIcon(), this);
    splashScreen_->setIconSize(QSize(106, 106));
    splashScreen_->raise();

    auto rect = QApplication::screens().at(0)->availableGeometry();
    move(rect.width() / 2 - width() / 2, rect.height() / 2 - height() / 2);
    show();
    QApplication::processEvents();
}

void MainWindow::initNavigation()
{
    addSubInterface(homeInterface_, new FluentIcon(FluentIcon::Home), tr("Home"));
    addSubInterface(iconInterface_, new FluentIcon(FluentIcon::EmojiTabSymbols), translator.icons);
    navigationInterface_->addSeparator();

    auto pos = NavigationItemPosition::Scroll;
    addSubInterface(basicInputInterface_, new FluentIcon(FluentIcon::CheckBox), translator.basicInput, pos);
    addSubInterface(dateTimeInterface_, new FluentIcon(FluentIcon::DateTime), translator.dateTime, pos);
    addSubInterface(dialogInterface_, new FluentIcon(FluentIcon::Message), translator.dialogs, pos);
    addSubInterface(layoutInterface_, new FluentIcon(FluentIcon::Layout), translator.layout, pos);
    addSubInterface(menuInterface_, new GalleryIcon(GalleryIcon::Menu), translator.menus, pos);
    addSubInterface(navigationViewInterface_, new FluentIcon(FluentIcon::Menu), translator.navigation, pos);
    addSubInterface(scrollInterface_, new FluentIcon(FluentIcon::Scroll), translator.scroll, pos);
    addSubInterface(statusInterface_, new FluentIcon(FluentIcon::Chat), translator.statusInfo, pos);
    addSubInterface(textInterface_, new GalleryIcon(GalleryIcon::Text), translator.text, pos);
    addSubInterface(viewInterface_, new GalleryIcon(GalleryIcon::Grid), translator.view, pos);

    // add custom widget to bottom
    auto avatar = new NavigationAvatarWidget("zhiyiYo", ":/gallery/images/shoko.png");
    pos = NavigationItemPosition::Bottom;
    navigationInterface_->addWidget("avatar", avatar, pos);
    connect(avatar, &NavigationAvatarWidget::clicked, this, &MainWindow::onSupport);

    addSubInterface(settingInterface_, new FluentIcon(FluentIcon::Setting), tr("Settings"), pos);
}

void MainWindow::connectSignalToSlot()
{
    connect(&signalBus, &SignalBus::micaEnabledChanged, this, &MainWindow::setMicaEnabled);
    connect(&signalBus, &SignalBus::switchToSampleCard, this, &MainWindow::switchToSample);
    connect(&signalBus, &SignalBus::supported, this, &MainWindow::onSupport);
}

void MainWindow::onSupport()
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

void MainWindow::switchToSample(const QString& routeKey, int index)
{
    auto w = findChild<GalleryInterface*>(routeKey);
    if (w) {
        stackedWidget_->setCurrentWidget(w, false);
        w->scrollToCard(index);
    }
}
