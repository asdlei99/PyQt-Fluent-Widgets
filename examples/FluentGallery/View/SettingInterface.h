#pragma once

#include "../Common/Config.h"
#include "QFluentWidgets/Components/Settings/CustomColorSettingCard.h"
#include "QFluentWidgets/Components/Settings/FolderListSettingCard.h"
#include "QFluentWidgets/Components/Settings/OptionsSettingCard.h"
#include "QFluentWidgets/Components/Settings/SettingCard.h"
#include "QFluentWidgets/Components/Settings/SettingCardGroup.h"
#include "QFluentWidgets/Components/Widgets/Label.h"
#include "QFluentWidgets/Components/Widgets/ScrollArea.h"

class SettingInterface : public ScrollArea
{
    Q_OBJECT

public:
    explicit SettingInterface(QWidget* parent = nullptr);

private slots:
    void showRestartInfo();

private:
    void initWidgets();
    void initLayout();
    void connectSignalToSlots();

    QWidget* scrollWidget_;
    ExpandLayout* expandLayout_;
    QLabel* settingLabel_;

    // music folders
    SettingCardGroup* musicInThisPCGroup_;
    FolderListSettingCard* musicFolderCard_;
    PushSettingCard* downloadFolderCard_;

    // personalization
    SettingCardGroup* personalGroup_;
    SwitchSettingCard* micaCard_;
    OptionsSettingCard* themeCard_;
    CustomColorSettingCard* themeColorCard_;
    OptionsSettingCard* zoomCard_;
    ComboBoxSettingCard* languageCard_;

    // update
    SettingCardGroup* updateSoftwareGroup_;
    SwitchSettingCard* updateOnStartUpCard_;

    // application
    SettingCardGroup* aboutGroup_;
    HyperlinkSettingCard* helpCard_;
    PrimaryPushSettingCard* feedbackCard_;
    PrimaryPushSettingCard* aboutCard_;
};