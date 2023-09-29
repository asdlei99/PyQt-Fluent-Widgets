#pragma once

#include "GalleryInterface.h"

namespace qfluentwidgets
{
class Action;
}

class QActionGroup;
class CommandBar;
class CheckableMenu;

class MenuInterface : public GalleryInterface
{
    Q_OBJECT

public:
    explicit MenuInterface(QWidget* parent = nullptr);

private slots:
    void createMenu(const QPoint& pos);
    void createCustomWidgetMenu(const QPoint& pos);
    RoundMenu* createCheckableMenu(const QPoint& pos);
    CommandBar* createCommandBar();
    void createCommandBarFlyout();
    void saveImage();

private:
    qfluentwidgets::Action* createTimeAction_;
    qfluentwidgets::Action* shootTimeAction_;
    qfluentwidgets::Action* modifiedTimeAction_;
    qfluentwidgets::Action* nameAction_;
    QActionGroup* actionGroup1_;
    qfluentwidgets::Action* ascendAction_;
    qfluentwidgets::Action* descendAction_;
    QActionGroup* actionGroup2_;
    PushButton* button1_;
    PushButton* button2_;
    PushButton* button3_;
    QLabel* label_;
    ImageLabel* imageLabel_;
};

class ProfileCard : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileCard(const QString& avatarPath,
                         const QString& name,
                         const QString& email,
                         QWidget* parent = nullptr);

private:
    AvatarWidget* avatar_;
    BodyLabel* nameLabel_;
    CaptionLabel* emailLabel_;
    HyperlinkPushButton* logoutButton_;
};