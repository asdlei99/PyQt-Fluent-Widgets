#pragma once

#include "GalleryInterface.h"

class StatusInfoInterface : public GalleryInterface
{
    Q_OBJECT

public:
    explicit StatusInfoInterface(QWidget* parent = nullptr);

private:
    PushButton* button_;
    ImageLabel* label_;

    void createInfoBarSampleCard();

    void createTopRightInfoBar();
    void createTopInfoBar();
    void createTopLeftInfoBar();
    void createBottomRightInfoBar();
    void createBottomInfoBar();
    void createBottomLeftInfoBar();
};