#include "MenuInterface.h"
#include "../Common/Translator.h"
#include <QActionGroup>
#include <QFileDialog>
#include <QFluentWidgets/Components/Widgets/CommandBar.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QKeySequence>
#include <QStandardPaths>

using namespace qfluentwidgets;

MenuInterface::MenuInterface(QWidget* parent)
    : GalleryInterface(translator.menus, "<QFluentWidgets/Components/Widgets>", parent)
{
    setObjectName("menuInterface");

    createTimeAction_ = new Action(new FluentIcon(FluentIcon::Calendar), tr("Create Date"));
    shootTimeAction_ = new Action(new FluentIcon(FluentIcon::Camera), tr("Shooting Date"));
    modifiedTimeAction_ = new Action(new FluentIcon(FluentIcon::Edit), tr("Modified time"));
    nameAction_ = new Action(new FluentIcon(FluentIcon::Font), tr("Name"));
    actionGroup1_ = new QActionGroup(this);
    actionGroup1_->addAction(createTimeAction_);
    actionGroup1_->addAction(shootTimeAction_);
    actionGroup1_->addAction(modifiedTimeAction_);
    actionGroup1_->addAction(nameAction_);
    for (auto& act : actionGroup1_->actions()) {
        act->setCheckable(true);
    }

    ascendAction_ = new Action(new FluentIcon(FluentIcon::Up), tr("Ascending"));
    descendAction_ = new Action(new FluentIcon(FluentIcon::Down), tr("Descending"));
    actionGroup2_ = new QActionGroup(this);
    actionGroup2_->addAction(ascendAction_);
    actionGroup2_->addAction(descendAction_);
    for (auto& act : actionGroup2_->actions()) {
        act->setCheckable(true);
    }

    shootTimeAction_->setChecked(true);
    ascendAction_->setChecked(true);

    button1_ = new PushButton(tr("Show menu"), this);
    connect(button1_, &PushButton::clicked,
            [this]() { createMenu(button1_->mapToGlobal(QPoint(button1_->width() + 5, -100))); });

    addExampleCard(tr("Rounded corners menu"), button1_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/menu/menu/demo.py");

    button3_ = new PushButton(tr("Show menu"), this);
    connect(button3_, &PushButton::clicked,
            [this]() { createCustomWidgetMenu(button3_->mapToGlobal(QPoint(button3_->width() + 5, -100))); });

    addExampleCard(tr("Rounded corners menu with custom widget"), button3_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/menu/widget_menu/demo.py");

    button2_ = new PushButton(tr("Show menu"), this);
    connect(button2_, &PushButton::clicked,
            [this]() { createCheckableMenu(button2_->mapToGlobal(QPoint(button2_->width() + 5, -100))); });

    addExampleCard(tr("Checkable menu"), button2_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/menu/menu/demo.py");

    addExampleCard(tr("Command bar"), createCommandBar(),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/menu/menu/demo.py", 1);

    QWidget* widget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(10);

    label_ = new QLabel(tr("Click the image to open a command bar flyout 👇️🥵"), widget);
    imageLabel_ = new ImageLabel(":/gallery/images/chidanta5.jpg", widget);
    imageLabel_->scaledToWidth(350);
    imageLabel_->setBorderRadius(8, 8, 8, 8);
    connect(imageLabel_, &ImageLabel::clicked, this, &MenuInterface::createCommandBarFlyout);

    layout->addWidget(label_);
    layout->addWidget(imageLabel_);

    addExampleCard(tr("Command bar flyout"), widget,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/menu/menu/demo.py", 1);
}

void MenuInterface::createMenu(const QPoint& pos)
{
    RoundMenu* menu = new RoundMenu(this);

    menu->addAction(new Action(new FluentIcon(FluentIcon::Copy), tr("Copy")));
    menu->addAction(new Action(new FluentIcon(FluentIcon::Cut), tr("Cut")));

    RoundMenu* submenu = new RoundMenu(tr("Add to"), this);
    submenu->setIcon(new FluentIcon(FluentIcon::Add));
    submenu->addActions(QList<QAction*>{new Action(new FluentIcon(FluentIcon::Video), tr("Video")),
                                        new Action(new FluentIcon(FluentIcon::Music), tr("Music"))});
    menu->addMenu(submenu);

    menu->addActions({new Action(new FluentIcon(FluentIcon::Paste), tr("Paste")),
                      new Action(new FluentIcon(FluentIcon::Cancel), tr("Undo"))});

    menu->addSeparator();
    menu->addAction(new QAction(tr("Select all"), this));

    menu->insertAction(menu->actions().last(), new Action(new FluentIcon(FluentIcon::Setting), tr("Settings")));
    menu->insertActions(menu->actions().last(),
                        QList<QAction*>{new Action(new FluentIcon(FluentIcon::Help), tr("Help")),
                                        new Action(new FluentIcon(FluentIcon::Feedback), tr("Feedback"))});

    menu->exec(pos);
}

void MenuInterface::createCustomWidgetMenu(const QPoint& pos)
{
    RoundMenu* menu = new RoundMenu(this);

    // add custom widget
    auto card = new ProfileCard(":/gallery/images/shoko.png", tr("Shoko"), "shokokawaii@outlook.com", menu);
    menu->addWidget(card, false);

    menu->addSeparator();
    menu->addActions({new Action(new FluentIcon(FluentIcon::People), tr("Manage account profile")),
                      new Action(new FluentIcon(FluentIcon::ShoppingCart), tr("Payment method")),
                      new Action(new FluentIcon(FluentIcon::Code), tr("Redemption code and gift card"))});
    menu->addSeparator();
    menu->addAction(new Action(new FluentIcon(FluentIcon::Setting), tr("Settings")));
    menu->exec(pos);
}

RoundMenu* MenuInterface::createCheckableMenu(const QPoint& pos)
{
    CheckableMenu* menu = new CheckableMenu(this, MenuIndicatorType::RADIO);

    menu->addActions({createTimeAction_, shootTimeAction_, modifiedTimeAction_, nameAction_});
    menu->addSeparator();
    menu->addActions({ascendAction_, descendAction_});

    if (!pos.isNull()) {
        menu->exec(pos);
    }

    return menu;
}

CommandBar* MenuInterface::createCommandBar()
{
    CommandBar* bar = new CommandBar(this);
    bar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    bar->addActions(QList<QAction*>{new Action(new FluentIcon(FluentIcon::Add), tr("Add")),
                                    new Action(new FluentIcon(FluentIcon::Rotate), tr("Rotate")),
                                    new Action(new FluentIcon(FluentIcon::ZoomIn), tr("Zoom in")),
                                    new Action(new FluentIcon(FluentIcon::ZoomOut), tr("Zoom out"))});
    bar->addSeparator();

    auto editAct = new Action(new FluentIcon(FluentIcon::Edit), tr("Edit"));
    editAct->setCheckable(true);
    bar->addActions(QList<QAction*>{editAct, new Action(new FluentIcon(FluentIcon::Info), tr("Info")),
                                    new Action(new FluentIcon(FluentIcon::Delete), tr("Delete")),
                                    new Action(new FluentIcon(FluentIcon::Share), tr("Share"))});

    // add custom widget
    auto button = new TransparentDropDownPushButton(new FluentIcon(FluentIcon::Scroll), tr("Sort"), bar);

    button->setMenu(createCheckableMenu(QPoint()));
    button->setFixedHeight(34);
    ::setFont(button, 12);
    bar->addWidget(button);

    auto settingAct = new Action(new FluentIcon(FluentIcon::Setting), tr("Settings"));
    settingAct->setShortcut(QKeySequence("Ctrl+I"));
    bar->addHiddenAction(settingAct);
    return bar;
}

void MenuInterface::createCommandBarFlyout()
{
    CommandBarView* view = new CommandBarView(this);

    auto saveAct = new Action(new FluentIcon(FluentIcon::Save), tr("Save"));
    connect(saveAct, &QAction::triggered, this, &MenuInterface::saveImage);

    view->addAction(new Action(new FluentIcon(FluentIcon::Share), tr("Share")));
    view->addAction(saveAct);
    view->addAction(new Action(new FluentIcon(FluentIcon::Heart), tr("Add to favorate")));
    view->addAction(new Action(new FluentIcon(FluentIcon::Delete), tr("Delete")));

    auto printAct = new Action(new FluentIcon(FluentIcon::Print), tr("Print"));
    printAct->setShortcut(QKeySequence("Ctrl+P"));
    view->addHiddenAction(printAct);

    auto settingAct = new Action(new FluentIcon(FluentIcon::Setting), tr("Settings"));
    settingAct->setShortcut(QKeySequence("Ctrl+S"));
    view->addHiddenAction(settingAct);

    view->resizeToSuitableWidth();

    int x = imageLabel_->width();
    QPoint pos = imageLabel_->mapToGlobal(QPoint(x, 0));
    Flyout::make(view, pos, this, FlyoutAnimationType::FadeIn);
}

void MenuInterface::saveImage()
{
    QString path = QFileDialog::getSaveFileName(
        this, tr("Save image"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("PNG (*.png)"));

    if (path.isEmpty()) {
        return;
    }

    imageLabel_->image().save(path);
}

ProfileCard::ProfileCard(const QString& avatarPath, const QString& name, const QString& email, QWidget* parent)
    : QWidget(parent)
{
    avatar_ = new AvatarWidget(avatarPath, this);
    nameLabel_ = new BodyLabel(name, this);
    emailLabel_ = new CaptionLabel(email, this);
    logoutButton_ = new HyperlinkPushButton(tr("注销"), QUrl("https://github.com/zhiyiYo/QMaterialWidgets"), this);

    QColor color = isDarkTheme() ? QColor(206, 206, 206) : QColor(96, 96, 96);
    emailLabel_->setStyleSheet("QLabel{color: " + color.name() + "}");

    color = isDarkTheme() ? QColor(255, 255, 255) : QColor(0, 0, 0);
    nameLabel_->setStyleSheet("QLabel{color: " + color.name() + "}");
    ::setFont(logoutButton_, 13);

    setFixedSize(307, 82);
    avatar_->setRadius(24);
    avatar_->move(2, 6);
    nameLabel_->move(64, 13);
    emailLabel_->move(64, 32);
    logoutButton_->move(52, 48);
}