#include "StatusInfoInterface.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Components/Widgets/InfoBadge.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
#include <QFluentWidgets/Components/Widgets/ProgressRing.h>
#include <QFluentWidgets/Components/Widgets/ToolTip.h>

StatusInfoInterface::StatusInfoInterface(QWidget* parent)
    : GalleryInterface(translator.dateTime, "<QFluentWidgets/Components/Widgets>", parent)
{
    setObjectName("statusInfoInterface");

    // Tool tip
    button_ = new PushButton(tr("Button with a simple ToolTip"), this);
    button_->installEventFilter(new ToolTipFilter(button_));
    button_->setToolTip(tr("Simple ToolTip"));
    addExampleCard(tr("A button with a simple ToolTip"), button_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/tool_tip/demo.py");

    label_ = new ImageLabel(":/gallery/images/kunkun.png", this);
    label_->scaledToHeight(160);
    label_->installEventFilter(new ToolTipFilter(label_, 500));
    label_->setToolTip(tr("Label with a ToolTip"));
    label_->setToolTipDuration(2000);
    label_->setFixedSize(160, 160);
    addExampleCard(tr("A label with a ToolTip"), label_,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/tool_tip/demo.py");

    // Info badge
    QWidget* badgeWidget = new QWidget(this);
    QHBoxLayout* badgeLayout = new QHBoxLayout(badgeWidget);
    badgeLayout->addWidget(InfoBadge::info("1"));
    badgeLayout->addWidget(InfoBadge::success("10"));
    badgeLayout->addWidget(InfoBadge::attention("100"));
    badgeLayout->addWidget(InfoBadge::warning("1000"));
    badgeLayout->addWidget(InfoBadge::error("10000"));
    badgeLayout->addWidget(InfoBadge::custom("1w+", "#005fb8", "#60cdff"));
    badgeLayout->setSpacing(20);
    badgeLayout->setContentsMargins(0, 10, 0, 10);
    addExampleCard(tr("InfoBadge in different styles"), badgeWidget,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/info_bar/demo.py");

    // Short info bar
    InfoBar* infoBar1 = new InfoBar(new InfoBarIcon(InfoBarIcon::Success), tr("Success"),
                                    tr("The Anthem of man is the Anthem of courage."), Qt::Horizontal, this,
                                    InfoBarPosition::None, -1, true);
    addExampleCard(tr("A closable InfoBar"), infoBar1,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/info_bar/demo.py");

    // Long info bar
    QString content =
        tr("My name is kira yoshikake, 33 years old. Living in the villa area northeast of duwangting, unmarried. I "
           "work in Guiyou chain store. Every day I have to work overtime until 8 p.m. to go home. I don't smoke. The "
           "wine is only for a taste. Sleep at 11 p.m. for 8 hours a day. Before I go to bed, I must drink a cup of "
           "warm milk, then do 20 minutes of soft exercise, get on the bed, and immediately fall asleep. Never leave "
           "fatigue and stress until the next day. Doctors say I'm normal.");
    InfoBar* infoBar2 = new InfoBar(new InfoBarIcon(InfoBarIcon::Warning), tr("Warning"), content, Qt::Vertical, this,
                                    InfoBarPosition::None, -1, true);
    addExampleCard(tr("A closable InfoBar with long message"), infoBar2,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/info_bar/demo.py");

    createInfoBarSampleCard();

    // Indeterminate progress bar
    IndeterminateProgressBar* indeterminateProgressBar = new IndeterminateProgressBar(this);
    indeterminateProgressBar->setFixedWidth(200);
    auto card = addExampleCard(
        tr("An indeterminate progress bar"), indeterminateProgressBar,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/progress_bar/demo.py");
    card->topLayout()->setContentsMargins(12, 24, 12, 24);

    ProgressBar* progressBar = new ProgressBar(this);
    progressBar->setFixedWidth(200);
    progressBar->setValue(50);
    card = addExampleCard(
        tr("A progress bar"), progressBar,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/progress_bar/demo.py");
    card->topLayout()->setContentsMargins(12, 24, 12, 24);

    // Indeterminate progress ring
    IndeterminateProgressRing* indeterminateProgressRing = new IndeterminateProgressRing(this);
    indeterminateProgressRing->setFixedSize(80, 80);
    addExampleCard(
        tr("An indeterminate progress ring"), indeterminateProgressRing,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/progress_bar/demo.py");

    // Progress ring
    ProgressRing* progressRing = new ProgressRing(this);
    progressRing->setFixedSize(80, 80);
    progressRing->setTextVisible(true);
    progressRing->setValue(75);
    addExampleCard(
        tr("A progress ring"), progressRing,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/progress_bar/demo.py");
}

void StatusInfoInterface::createInfoBarSampleCard()
{
    QWidget* w = new QWidget(this);
    QHBoxLayout* hBoxLayout = new QHBoxLayout(w);
    PushButton* button1 = new PushButton(tr("Top right"), w);
    PushButton* button2 = new PushButton(tr("Top"), w);
    PushButton* button3 = new PushButton(tr("Top left"), w);
    PushButton* button4 = new PushButton(tr("Bottom right"), w);
    PushButton* button5 = new PushButton(tr("Bottom"), w);
    PushButton* button6 = new PushButton(tr("Bottom left"), w);

    connect(button1, &PushButton::clicked, this, &StatusInfoInterface::createTopRightInfoBar);
    connect(button2, &PushButton::clicked, this, &StatusInfoInterface::createTopInfoBar);
    connect(button3, &PushButton::clicked, this, &StatusInfoInterface::createTopLeftInfoBar);
    connect(button4, &PushButton::clicked, this, &StatusInfoInterface::createBottomRightInfoBar);
    connect(button5, &PushButton::clicked, this, &StatusInfoInterface::createBottomInfoBar);
    connect(button6, &PushButton::clicked, this, &StatusInfoInterface::createBottomLeftInfoBar);

    hBoxLayout->addWidget(button1);
    hBoxLayout->addWidget(button2);
    hBoxLayout->addWidget(button3);
    hBoxLayout->addWidget(button4);
    hBoxLayout->addWidget(button5);
    hBoxLayout->addWidget(button6);
    hBoxLayout->setContentsMargins(0, 0, 0, 0);
    hBoxLayout->setSpacing(15);

    addExampleCard(tr("InfoBar with different pop-up locations"), w,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/status_info/info_bar/demo.py");
}

void StatusInfoInterface::createTopRightInfoBar()
{
    InfoBar::info(tr("Lesson 3"), tr("Believe in the spin, just keep believing!"), Qt::Horizontal, this,
                  InfoBarPosition::TopRight, 2000);
}

void StatusInfoInterface::createTopInfoBar()
{
    InfoBar::success(tr("Lesson 4"), tr("With respect, let's advance towards a new stage of the spin."), Qt::Horizontal,
                     this, InfoBarPosition::Top, 2000);
}

void StatusInfoInterface::createTopLeftInfoBar()
{
    InfoBar::warning(tr("Lesson 5"), tr("The shortest shortcut is to take a detour."), Qt::Horizontal, this,
                     InfoBarPosition::TopLeft, 2000);
}

void StatusInfoInterface::createBottomRightInfoBar()
{
    InfoBar::error(tr("No Internet"), tr("An error message which won't disappear automatically."), Qt::Horizontal,
                     this, InfoBarPosition::BottomRight, -1);
}

void StatusInfoInterface::createBottomInfoBar()
{
    InfoBar::success(tr("Lesson 1"), tr("Don't have any strange expectations of me."), Qt::Horizontal, this,
                     InfoBarPosition::Bottom, 2000);
}

void StatusInfoInterface::createBottomLeftInfoBar()
{
    InfoBar::warning(tr("Lesson 2"), tr("Don't let your muscles notice."), Qt::Horizontal, this,
                     InfoBarPosition::BottomLeft, 1500);
}
