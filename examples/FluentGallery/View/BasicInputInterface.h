#pragma once

#include "GalleryInterface.h"
#include <QFluentWidgets/Common/Action.h>

class SwitchButton;
class SplitPushButton;
class SplitToolButton;

class BasicInputInterface : public GalleryInterface {
    Q_OBJECT
public:
    explicit BasicInputInterface(QWidget* parent = nullptr);

private slots:
    void onSwitchCheckedChanged(bool isChecked);

private:
    RoundMenu* createStandMenu(SplitPushButton *button);
    qfluentwidgets::Action* createAction(const QString& text, SplitPushButton *button);

    SwitchButton* switchButton_;
};