#pragma once

#include "BasicInputInterface.h"
#include "DateTimeInterface.h"
#include "DialogInterface.h"
#include "HomeInterface.h"
#include "IconInterface.h"
#include "LayoutInterface.h"
#include "MenuInterface.h"
#include "NavigationViewInterface.h"
#include "ScrollInterface.h"
#include "StatusInfoInterface.h"
#include "TextInterface.h"
#include "ViewInterface.h"
#include "SettingInterface.h"
#include <QFluentWidgets/Window/FluentWindow.h>
#include <QFluentWidgets/Window/SplashScreen.h>

class MainWindow : public FluentWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);

private slots:
    void onSupport();
    void switchToSample(const QString& routeKey, int index);

private:
    void initWindow();
    void initNavigation();
    void connectSignalToSlot();

    HomeInterface* homeInterface_;
    IconInterface* iconInterface_;
    BasicInputInterface* basicInputInterface_;
    DateTimeInterface* dateTimeInterface_;
    DialogInterface* dialogInterface_;
    LayoutInterface* layoutInterface_;
    MenuInterface* menuInterface_;
    NavigationViewInterface* navigationViewInterface_;
    ScrollInterface* scrollInterface_;
    StatusInfoInterface* statusInterface_;
    TextInterface* textInterface_;
    ViewInterface* viewInterface_;
    SettingInterface* settingInterface_;
    SplashScreen* splashScreen_;
};