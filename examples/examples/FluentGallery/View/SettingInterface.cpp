#include "SettingInterface.h"
#include "../Common/SignalBus.h"
#include "../Common/StyleSheet.h"
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/Icon.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>

using namespace qfluentwidgets;

SettingInterface::SettingInterface(QWidget* parent) : ScrollArea(parent)
{
    qconfig.use(&cfg);

    scrollWidget_ = new QWidget();
    expandLayout_ = new ExpandLayout(scrollWidget_);
    settingLabel_ = new QLabel(tr("Settings"), this);

    // music folders
    musicInThisPCGroup_ = new SettingCardGroup(tr("Music on this PC"), scrollWidget_);
    musicFolderCard_ =
        new FolderListSettingCard(cfg.musicFolders, tr("Local music library"), "", "./", musicInThisPCGroup_);
    downloadFolderCard_ =
        new PushSettingCard(new FluentIcon(FluentIcon::Download), tr("Choose folder"), tr("Download directory"),
                            cfg.get(cfg.downloadFolder).toString(), musicInThisPCGroup_);

    // personalization
    personalGroup_ = new SettingCardGroup(tr("Personalization"), scrollWidget_);

    micaCard_ = new SwitchSettingCard(cfg.micaEnabled, new FluentIcon(FluentIcon::Transparent), tr("Mica effect"),
                                      tr("Apply semi transparent to windows and surfaces"), personalGroup_);

    themeCard_ = new OptionsSettingCard(cfg.themeModeItem, {tr("Light"), tr("Dark"), tr("Use system setting")},
                                        new FluentIcon(FluentIcon::Brush), tr("Application theme"),
                                        tr("Change the appearance of your application"), personalGroup_);
    themeColorCard_ =
        new CustomColorSettingCard(cfg.themeColorItem, new FluentIcon(FluentIcon::Palette), tr("Theme color"),
                                   tr("Change the theme color of you application"), personalGroup_);

    zoomCard_ = new OptionsSettingCard(cfg.dpiScale, {"100%", "125%", "150%", "175%", "200%", tr("Use system setting")},
                                       new FluentIcon(FluentIcon::Zoom), tr("Interface zoom"),
                                       tr("Change the size of widgets and fonts"), personalGroup_);

    languageCard_ = new ComboBoxSettingCard(cfg.language, {"简体中文", "繁體中文", "English", tr("Use system setting")},
                                            new FluentIcon(FluentIcon::Language), tr("Language"),
                                            tr("Set your preferred language for UI"), personalGroup_),

    // update software
        updateSoftwareGroup_ = new SettingCardGroup(tr("Software update"), scrollWidget_);
    updateOnStartUpCard_ =
        new SwitchSettingCard(cfg.checkUpdateAtStartUp, new FluentIcon(FluentIcon::Update),
                              tr("Check for updates when the application starts"),
                              tr("The new version will be more stable and have more features"), updateSoftwareGroup_);

    // application
    aboutGroup_ = new SettingCardGroup(tr("About"), scrollWidget_);
    helpCard_ = new HyperlinkSettingCard(new FluentIcon(FluentIcon::Help), tr("Open help page"), QUrl(Config::HELP_URL),
                                         tr("Help"),
                                         tr("Discover new features and learn useful tips about QFluentWidgets"));
    feedbackCard_ =
        new PrimaryPushSettingCard(new FluentIcon(FluentIcon::Feedback), tr("Provide feedback"), tr("Provide feedback"),
                                   tr("Help us improve QFluentWidgets by providing feedback"), aboutGroup_);

    QString copyright =
        QString("© Copyright %1, %2. Version %3").arg(Config::YEAR).arg(Config::AUTHOR).arg(Config::VERSION);
    aboutCard_ = new PrimaryPushSettingCard(new FluentIcon(FluentIcon::Info), tr("Check update"), tr("About"),
                                            copyright, aboutGroup_);

    initWidgets();
}

void SettingInterface::initWidgets()
{
    resize(1000, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(0, 80, 0, 20);
    setWidget(scrollWidget_);
    setWidgetResizable(true);
    setObjectName("settingInterface");

    scrollWidget_->setObjectName("scrollWidget");
    settingLabel_->setObjectName("settingLabel");
    StyleSheet::applyTo(StyleSheet::SettingInterface, this);

    initLayout();
    connectSignalToSlots();
}

void SettingInterface::initLayout()
{
    settingLabel_->move(36, 30);

    // add cards to group
    musicInThisPCGroup_->addSettingCard(musicFolderCard_);
    musicInThisPCGroup_->addSettingCard(downloadFolderCard_);

    personalGroup_->addSettingCard(micaCard_);
    personalGroup_->addSettingCard(themeCard_);
    personalGroup_->addSettingCard(themeColorCard_);
    personalGroup_->addSettingCard(zoomCard_);
    personalGroup_->addSettingCard(languageCard_);

    updateSoftwareGroup_->addSettingCard(updateOnStartUpCard_);

    aboutGroup_->addSettingCard(helpCard_);
    aboutGroup_->addSettingCard(feedbackCard_);
    aboutGroup_->addSettingCard(aboutCard_);

    // add setting card group to layout
    expandLayout_->setSpacing(28);
    expandLayout_->setContentsMargins(36, 10, 36, 0);
    expandLayout_->addWidget(musicInThisPCGroup_);
    expandLayout_->addWidget(personalGroup_);
    expandLayout_->addWidget(updateSoftwareGroup_);
    expandLayout_->addWidget(aboutGroup_);
}

void SettingInterface::connectSignalToSlots()
{
    connect(&cfg, &QConfig::appRestartSig, this, &SettingInterface::showRestartInfo);

    connect(themeCard_, &OptionsSettingCard::optionChanged, this,
            [](const QVariant& value) { setTheme((Theme)value.value<int>()); });
    connect(themeColorCard_, &CustomColorSettingCard::colorChanged, this,
            [](const QColor& color) { setThemeColor(color); });
    connect(micaCard_, &SwitchSettingCard::checkedChanged, &signalBus, &SignalBus::micaEnabledChanged);

    connect(feedbackCard_, &PrimaryPushSettingCard::clicked, this,
            [] { QDesktopServices::openUrl(QUrl(Config::FEEDBACK_URL)); });
}

void SettingInterface::showRestartInfo()
{
    InfoBar::success(tr("Updated successfully"), tr("Configuration takes effect after restart"), Qt::Horizontal, this,
                     InfoBarPosition::TopRight, 1500);
}
