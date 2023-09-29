#include "DialogInterface.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Components/DialogBox/ColorDialog.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Widgets/Flyout.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/LineEdit.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/TeachingTip.h>

DialogInterface::DialogInterface(QWidget* parent)
    : GalleryInterface(translator.dialogs, "<QFluentWidgets/Components/DialogBox>", parent)
{
    setObjectName("dialogInterface");

    // mask message dialog
    auto messageBoxButton = new PushButton(tr("Show dialog"));
    connect(messageBoxButton, &PushButton::clicked, this, &DialogInterface::showMessageDialog);
    addExampleCard(
        tr("A message box with mask"), messageBoxButton,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/message_dialog/demo.py");

    // custom message box
    auto customBoxButton = new PushButton(tr("Show dialog"));
    connect(customBoxButton, &PushButton::clicked, this, &DialogInterface::showCustomDialog);
    addExampleCard(
        tr("A custom message box"), customBoxButton,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/custom_message_box/demo.py");

    // color box
    auto colorBoxButton = new PushButton(tr("Show dialog"));
    connect(colorBoxButton, &PushButton::clicked, this, &DialogInterface::showColorDialog);
    addExampleCard(
        tr("A color dialog"), colorBoxButton,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/color_dialog/demo.py");

    // flyout
    simpleFlyoutButton_ = new PushButton(tr("Show flyout"), this);
    connect(simpleFlyoutButton_, &PushButton::clicked, this, &DialogInterface::showSimpleFlyout);
    addExampleCard(tr("A simple flyout"), simpleFlyoutButton_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/flyout/demo.py");

    complexFlyoutButton_ = new PushButton(tr("Show flyout"), this);
    connect(complexFlyoutButton_, &PushButton::clicked, this, &DialogInterface::showComplexFlyout);
    addExampleCard(tr("A flyout with image and button"), complexFlyoutButton_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/flyout/demo.py");

    teachingButton_ = new PushButton(tr("Show teaching tip"), this);
    connect(teachingButton_, &PushButton::clicked, this, &DialogInterface::showBottomTeachingTip);
    addExampleCard(
        tr("A teaching tip"), teachingButton_,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/teaching_tip/demo.py");

    teachingRightButton_ = new PushButton(tr("Show teaching tip"), this);
    connect(teachingRightButton_, &PushButton::clicked, this, &DialogInterface::showLeftBottomTeachingTip);
    addExampleCard(
        tr("A teaching tip with image and button"), teachingRightButton_,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/dialog_flyout/teaching_tip/demo.py");
}

void DialogInterface::showMessageDialog()
{
    auto title = tr("This is a message dialog with mask");
    auto content = tr("If the content of the message box is veeeeeeeeeeeeeeeeeeeeeeeeeery long, it will automatically "
                      "wrap like this.");
    auto w = new MessageBox(title, content, window());
    if (w->exec()) {
        qDebug() << "Yes button is pressed";
    } else {
        qDebug() << "Cancel button is pressed";
    }
}

void DialogInterface::showCustomDialog()
{
    auto w = new CustomMessageBox(window());
    if (w->exec()) {
        qDebug() << "Yes button is pressed";
    } else {
        qDebug() << "Cancel button is pressed";
    }
}

void DialogInterface::showColorDialog()
{
    auto w = new ColorDialog(Qt::cyan, tr("Choose color"), window());
    connect(w, &ColorDialog::colorChanged, this, [](const QColor& c) { qDebug() << c; });
    w->exec();
}

void DialogInterface::showSimpleFlyout()
{
    auto view = new FlyoutView("Lesson 3", tr("Believe in the spin, just keep believing!"),
                               new InfoBarIcon(InfoBarIcon::Success), "");
    Flyout::make(view, simpleFlyoutButton_, window());
}

void DialogInterface::showComplexFlyout()
{
    auto view = new FlyoutView(
        "Julius·Zeppeli",
        tr("Where the tennis ball will land when it touches the net, no one can predict. \nIf that moment comes, I "
           "hope the 'goddess' exists. \nIn that case, I would accept it no matter which side the ball falls on."),
        nullptr, ":/gallery/images/SBR.jpg");

    // add custom widget
    auto button = new PushButton("Action");
    button->setFixedWidth(120);
    view->addWidget(button, 0, Qt::AlignRight);

    // adjust layout
    view->widgetLayout()->insertSpacing(1, 5);
    view->widgetLayout()->insertSpacing(0, 5);
    view->widgetLayout()->addSpacing(5);

    Flyout::make(view, complexFlyoutButton_, window(), FlyoutAnimationType::SlideRight);
}

void DialogInterface::showBottomTeachingTip()
{
    auto view = new TeachingTipView("Lesson 4", tr("With respect, let's advance towards a new stage of the spin."),
                                    new InfoBarIcon(InfoBarIcon::Success), "", true);
    auto tip = TeachingTip::make(view, teachingButton_, -1, TeachingTipTailPosition::Bottom, window());
    connect(view, &TeachingTipView::closed, tip, &TeachingTip::close);
}

void DialogInterface::showLeftBottomTeachingTip() {
    auto pos = TeachingTipTailPosition::LeftBottom;
    auto view = new TeachingTipView("Lesson 5", tr("The shortest shortcut is to take a detour."), nullptr, "", true, pos);

    auto button = new PushButton("Action");
    button->setFixedWidth(120);
    view->addWidget(button, 0, Qt::AlignRight);

    auto tip = TeachingTip::make(view, teachingRightButton_, 3000, pos, this);
    connect(view, &TeachingTipView::closed, tip, &TeachingTip::close);
}

CustomMessageBox::CustomMessageBox(QWidget* parent)
    : MessageBoxBase(parent), titleLabel_(new SubtitleLabel(tr("Open URL"), this)), urlLineEdit_(new LineEdit(this))
{
    urlLineEdit_->setPlaceholderText(tr("Enter the URL of a file, stream, or playlist"));
    urlLineEdit_->setClearButtonEnabled(true);

    // add widget to view layout
    viewLayout()->addWidget(titleLabel_);
    viewLayout()->addWidget(urlLineEdit_);

    // change the text of button
    setYesButtonText(tr("Open"));
    setCancelButtonText(tr("Cancel"));

    widget_->setMinimumWidth(360);
    yesButton_->setDisabled(true);
    connect(urlLineEdit_, &LineEdit::textChanged, this, &CustomMessageBox::validateUrl);
}

void CustomMessageBox::validateUrl(const QString& text)
{
    yesButton_->setEnabled(QUrl(text).isValid());
}
