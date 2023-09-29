#include "SettingInterface.h"
#include "QFluentWidgets/Common/FluentApp.h"
#include <QDebug>

using namespace qfluentwidgets;

SettingInterface::SettingInterface(QWidget* parent) : ScrollArea(parent)
{
    config_ = new Config(this);
    qconfig.use(config_);

    scrollWidget_ = new QWidget();
    expandLayout_ = new ExpandLayout(scrollWidget_);
    settingLabel_ = new TitleLabel("设置", this);

    // music folders
    musicInThisPCGroup_ = new SettingCardGroup("此 PC 上的音乐", scrollWidget_);
    musicFolderCard_ = new FolderListSettingCard(config_->musicFolders, "本地音乐库", "", "./", musicInThisPCGroup_);
    downloadFolderCard_ = new PushSettingCard(new FluentIcon(FluentIcon::Download), "选择文件夹", "下载目录",
                                              config_->get(config_->downloadFolder).toString(), musicInThisPCGroup_);

    // personalization
    personalGroup_ = new SettingCardGroup("个性化", scrollWidget_);
    enableAcrylicCard_ =
        new SwitchSettingCard(config_->enableAcrylic, new FluentIcon(FluentIcon::Transparent), "启用亚克力特效",
                              "亚克力特效视觉效果更佳，但可能导致界面卡顿", personalGroup_);
    themeCard_ =
        new OptionsSettingCard(config_->themeModeItem, {"浅色", "深色", "跟随主题"}, new FluentIcon(FluentIcon::Brush),
                               "应用主题", "调整你的应用外观", personalGroup_);
    themeColorCard_ = new CustomColorSettingCard(config_->themeColorItem, new FluentIcon(FluentIcon::Palette), "主题色",
                                                 "调整你的应用主题颜色", personalGroup_);
    zoomCard_ =
        new OptionsSettingCard(config_->dpiScale, {"100%", "125%", "150%", "175%", "200%", "跟随系统"},
                               new FluentIcon(FluentIcon::Zoom), "界面缩放", "调整组件和字体的大小", personalGroup_);
    languageCard_ =
        new ComboBoxSettingCard(config_->language, {"简体中文", "繁體中文", "English", "跟随系统"},
                                new FluentIcon(FluentIcon::Language), "语言", "设置界面所使用的语言", personalGroup_),

    // online music
        onlineMusicGroup_ = new SettingCardGroup("在线音乐", scrollWidget_);
    onlinePageSizeCard_ = new RangeSettingCard(config_->onlinePageSize, new FluentIcon(FluentIcon::Search), "在线音质",
                                               "", onlineMusicGroup_);
    onlineLyricColorCard_ = new ColorSettingCard(config_->lyricColor, new FluentIcon(FluentIcon::Palette), "歌词",
                                                 "调整歌词字体的颜色", onlineMusicGroup_);
    onlineMusicQualityCard_ =
        new OptionsSettingCard(config_->onlineSongQuality, {"流畅", "高品", "超品"}, new FluentIcon(FluentIcon::Music),
                               "在线音质", "", onlineMusicGroup_);

    // update software
    updateSoftwareGroup_ = new SettingCardGroup("软件更新", scrollWidget_);
    updateOnStartUpCard_ =
        new SwitchSettingCard(config_->checkUpdateAtStartUp, new FluentIcon(FluentIcon::Update), "应用启动时检查更新",
                              "新版本会更加稳定并拥有更多新特性", updateSoftwareGroup_);

    // application
    aboutGroup_ = new SettingCardGroup("关于", scrollWidget_);
    helpCard_ = new HyperlinkSettingCard(new FluentIcon(FluentIcon::Help), "获取帮助", QUrl(Config::HELP_URL), "帮助",
                                         "发现新特性并了解 QFluentWidgets 的正确使用姿势");
    feedbackCard_ = new PrimaryPushSettingCard(new FluentIcon(FluentIcon::Feedback), "提供反馈", "反馈",
                                               "提供反馈以帮助我们改善 QFluentWidgets", aboutGroup_);

    QString copyright =
        QString("© 版权所有 %1, %2. 版本 %3").arg(Config::YEAR).arg(Config::AUTHOR).arg(Config::VERSION);
    aboutCard_ =
        new PrimaryPushSettingCard(new FluentIcon(FluentIcon::Info), "检查更新", "关于", copyright, aboutGroup_);

    initWidgets();
}

void SettingInterface::initWidgets()
{
    resize(1000, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(0, 120, 0, 20);
    setWidget(scrollWidget_);
    setWidgetResizable(true);

    setStyleSheet("SettingInterface{background: transparent}");
    scrollWidget_->setStyleSheet("QWidget{background: transparent}");

    initLayout();

    connect(&qconfig, &QConfig::themeChanged, this, &SettingInterface::onThemeChanged);
}

void SettingInterface::initLayout()
{
    settingLabel_->move(60, 63);

    // add cards to group
    musicInThisPCGroup_->addSettingCard(musicFolderCard_);
    musicInThisPCGroup_->addSettingCard(downloadFolderCard_);

    personalGroup_->addSettingCard(enableAcrylicCard_);
    personalGroup_->addSettingCard(themeCard_);
    personalGroup_->addSettingCard(themeColorCard_);
    personalGroup_->addSettingCard(zoomCard_);
    personalGroup_->addSettingCard(languageCard_);

    onlineMusicGroup_->addSettingCard(onlinePageSizeCard_);
    onlineMusicGroup_->addSettingCard(onlineLyricColorCard_);
    onlineMusicGroup_->addSettingCard(onlineMusicQualityCard_);

    updateSoftwareGroup_->addSettingCard(updateOnStartUpCard_);

    aboutGroup_->addSettingCard(helpCard_);
    aboutGroup_->addSettingCard(feedbackCard_);
    aboutGroup_->addSettingCard(aboutCard_);

    // add setting card group to layout
    expandLayout_->setSpacing(28);
    expandLayout_->setContentsMargins(60, 10, 60, 0);
    expandLayout_->addWidget(musicInThisPCGroup_);
    expandLayout_->addWidget(personalGroup_);
    expandLayout_->addWidget(onlineMusicGroup_);
    expandLayout_->addWidget(updateSoftwareGroup_);
    expandLayout_->addWidget(aboutGroup_);
}

void SettingInterface::onThemeChanged(Theme theme)
{
    setTheme(theme);
}