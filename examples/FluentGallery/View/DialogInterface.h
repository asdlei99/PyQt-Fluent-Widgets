#pragma once

#include "GalleryInterface.h"
#include <QFluentWidgets/Components/DialogBox/MessageBoxBase.h>

class SubtitleLabel;
class LineEdit;

class DialogInterface : public GalleryInterface
{
    Q_OBJECT

public:
    explicit DialogInterface(QWidget* parent = nullptr);

private slots:
    void showMessageDialog();
    void showCustomDialog();
    void showColorDialog();
    void showSimpleFlyout();
    void showComplexFlyout();
    void showBottomTeachingTip();
    void showLeftBottomTeachingTip();

private:
    PushButton* simpleFlyoutButton_;
    PushButton* complexFlyoutButton_;
    PushButton* teachingButton_;
    PushButton* teachingRightButton_;
};

class CustomMessageBox: public MessageBoxBase {
    Q_OBJECT

public:
    explicit CustomMessageBox(QWidget* parent = nullptr);

private slots:
    void validateUrl(const QString& text);

private:
    SubtitleLabel* titleLabel_;
    LineEdit* urlLineEdit_;
};