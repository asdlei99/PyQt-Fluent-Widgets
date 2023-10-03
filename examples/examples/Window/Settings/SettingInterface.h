#pragma once

#include "Config.h"
#include "QFluentWidgets/Components/Settings/FolderListSettingCard.h"
#include "QFluentWidgets/Components/Settings/OptionsSettingCard.h"
#include "QFluentWidgets/Components/Settings/SettingCard.h"
#include "QFluentWidgets/Components/Settings/SettingCardGroup.h"
#include "QFluentWidgets/Components/Settings/CustomColorSettingCard.h"
#include "QFluentWidgets/Components/Widgets/Label.h"
#include "QFluentWidgets/Components/Widgets/ScrollArea.h"

class SettingInterface : public ScrollArea
{
    Q_OBJECT

public:
    explicit SettingInterface(QWidget* parent = nullptr);

private slots:
    void onThemeChanged(qfluentwidgets::Theme theme);

private:
    void initWidgets();
    void initLayout();

    Config* config_;

    QWidget* scrollWidget_;
    ExpandLayout* expandLayout_;
    TitleLabel* settingLabel_;

    // music folders
    SettingCardGroup* musicInThisPCGroup_;
    FolderListSettingCard* musicFolderCard_;
    PushSettingCard* downloadFolderCard_;

    // personalization
    SettingCardGroup* personalGroup_;
    SwitchSettingCard* enableAcrylicCard_;
    OptionsSettingCard* themeCard_;
    CustomColorSettingCard* themeColorCard_;
    OptionsSettingCard* zoomCard_;
    ComboBoxSettingCard* languageCard_;

    // online music
    SettingCardGroup* onlineMusicGroup_;
    RangeSettingCard* onlinePageSizeCard_;
    ColorSettingCard* onlineLyricColorCard_;
    OptionsSettingCard* onlineMusicQualityCard_;

    // update
    SettingCardGroup* updateSoftwareGroup_;
    SwitchSettingCard* updateOnStartUpCard_;

    // application
    SettingCardGroup* aboutGroup_;
    HyperlinkSettingCard* helpCard_;
    PrimaryPushSettingCard* feedbackCard_;
    PrimaryPushSettingCard* aboutCard_;
};