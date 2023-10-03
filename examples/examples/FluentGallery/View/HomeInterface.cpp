#include "HomeInterface.h"
#include <QFluentWidgets/Common/Icon.h>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QPainter>
#include <QPainterPath>
#include "../Common/Config.h"
#include "../Components/SampleCard.h"
#include "../Common/StyleSheet.h"

using namespace qfluentwidgets;

BannerWidget::BannerWidget(QWidget* parent) : QWidget(parent)
{
    setFixedHeight(336);

    vBoxLayout_ = new QVBoxLayout(this);
    galleryLabel_ = new QLabel("Fluent Gallery", this);
    banner_ = QPixmap(":/gallery/images/header1.png");
    linkCardView_ = new LinkCardView(this);

    galleryLabel_->setObjectName("galleryLabel");

    vBoxLayout_->setSpacing(0);
    vBoxLayout_->setContentsMargins(0, 20, 0, 0);
    vBoxLayout_->addWidget(galleryLabel_);
    vBoxLayout_->addWidget(linkCardView_, 1, Qt::AlignBottom);
    vBoxLayout_->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    linkCardView_->addCard(":/gallery/images/logo.png", tr("Getting started"),
                           tr("An overview of app development options and samples."), Config::HELP_URL);

    linkCardView_->addCard(new FluentIcon(FluentIcon::GitHub), tr("GitHub repo"),
                           tr("The latest fluent design controls and styles for your applications."), Config::REPO_URL);

    linkCardView_->addCard(new FluentIcon(FluentIcon::Code), tr("Code samples"),
                           tr("Find samples that demonstrate specific tasks, features and APIs."), Config::EXAMPLE_URL);

    linkCardView_->addCard(new FluentIcon(FluentIcon::Feedback), tr("Send feedback"),
                           tr("Help us improve QFluentWidgets by providing feedback."), Config::FEEDBACK_URL);
}

void BannerWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    int w = width();
    int h = 200;
    path.addRoundedRect(QRectF(0, 0, w, h), 10, 10);
    path.addRect(QRectF(0, h - 50, 50, 50));
    path.addRect(QRectF(w - 50, 0, 50, 50));
    path.addRect(QRectF(w - 50, h - 50, 50, 50));
    path = path.simplified();

    // draw background color
    if (!isDarkTheme()) {
        painter.fillPath(path, QColor(206, 216, 228));
    } else {
        painter.fillPath(path, QColor(0, 0, 0));
    }

    // draw banner image
    QPixmap pixmap = banner_.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    path.addRect(QRectF(0, h, w, height() - h));
    painter.fillPath(path, QBrush(pixmap));
}


HomeInterface::HomeInterface(QWidget* parent) : ScrollArea(parent)
{
    banner_ = new BannerWidget(this);
    view_ = new QWidget(this);
    vBoxLayout_ = new QVBoxLayout(view_);

    view_->setObjectName("view");
    setObjectName("homeInterface");
    StyleSheet::applyTo(StyleSheet::HomeInterface, this);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWidget(view_);
    setWidgetResizable(true);

    vBoxLayout_->setContentsMargins(0, 0, 0, 36);
    vBoxLayout_->setSpacing(40);
    vBoxLayout_->addWidget(banner_);
    vBoxLayout_->setAlignment(Qt::AlignTop);

    loadSamples();
}

void HomeInterface::loadSamples()
{
    // basic input samples
    SampleCardView* basicInputView = new SampleCardView(tr("Basic input samples"), view_);
    basicInputView->addSampleCard(":/gallery/images/controls/Button.png", tr("Button"),
                                  tr("A control that responds to user input and emit clicked signal."),
                                  "basicInputInterface", 0);
    basicInputView->addSampleCard(":/gallery/images/controls/Checkbox.png", tr("CheckBox"),
                                  tr("A control that a user can select or clear."), "basicInputInterface", 8);
    basicInputView->addSampleCard(":/gallery/images/controls/ComboBox.png", tr("ComboBox"),
                                  tr("A drop-down list of items a user can select from."), "basicInputInterface", 10);
    basicInputView->addSampleCard(":/gallery/images/controls/DropDownButton.png", tr("DropDownButton"),
                                  tr("A button that displays a flyout of choices when clicked."), "basicInputInterface",
                                  12);
    basicInputView->addSampleCard(
        ":/gallery/images/controls/HyperlinkButton.png", tr("HyperlinkButton"),
        tr("A button that appears as hyperlink text, and can navigate to a URI or handle a Click event."),
        "basicInputInterface", 18);
    basicInputView->addSampleCard(":/gallery/images/controls/RadioButton.png", tr("RadioButton"),
                                  tr("A control that allows a user to select a single option from a group of options."),
                                  "basicInputInterface", 19);
    basicInputView->addSampleCard(
        ":/gallery/images/controls/Slider.png", tr("Slider"),
        tr("A control that lets the user select from a range of values by moving a Thumb control along a track."),
        "basicInputInterface", 20);
    basicInputView->addSampleCard(":/gallery/images/controls/SplitButton.png", tr("SplitButton"),
                                  tr("A two-part button that displays a flyout when its secondary part is clicked."),
                                  "basicInputInterface", 21);
    basicInputView->addSampleCard(":/gallery/images/controls/ToggleSwitch.png", tr("SwitchButton"),
                                  tr("A switch that can be toggled between 2 states."), "basicInputInterface", 25);
    basicInputView->addSampleCard(":/gallery/images/controls/ToggleButton.png", tr("ToggleButton"),
                                  tr("A button that can be switched between two states like a CheckBox."),
                                  "basicInputInterface", 26);
    vBoxLayout_->addWidget(basicInputView);

    // date time samples
    SampleCardView* dateTimeView = new SampleCardView(tr("Date & time samples"), view_);
    dateTimeView->addSampleCard(":/gallery/images/controls/CalendarDatePicker.png", "CalendarPicker",
                                tr("A control that lets a user pick a date value using a calendar."),
                                "dateTimeInterface", 0);
    dateTimeView->addSampleCard(":/gallery/images/controls/DatePicker.png", "DatePicker",
                                tr("A control that lets a user pick a date value."), "dateTimeInterface", 2);
    dateTimeView->addSampleCard(":/gallery/images/controls/TimePicker.png", "TimePicker",
                                tr("A configurable control that lets a user pick a time value."), "dateTimeInterface",
                                4);
    vBoxLayout_->addWidget(dateTimeView);

    // dialog samples
    SampleCardView* dialogView = new SampleCardView(tr("Dialog samples"), view_);
    dialogView->addSampleCard(":/gallery/images/controls/Flyout.png", "Dialog", tr("A frameless message dialog."),
                              "dialogInterface", 0);
    dialogView->addSampleCard(":/gallery/images/controls/ContentDialog.png", "MessageBox",
                              tr("A message dialog with mask."), "dialogInterface", 1);
    dialogView->addSampleCard(":/gallery/images/controls/ColorPicker.png", "ColorDialog",
                              tr("A dialog that allows user to select color."), "dialogInterface", 2);
    dialogView->addSampleCard(":/gallery/images/controls/Flyout.png", "Flyout",
                              tr("Shows contextual information and enables user interaction."), "dialogInterface", 3);
    dialogView->addSampleCard(":/gallery/images/controls/TeachingTip.png", "TeachingTip",
                              tr("A content-rich flyout for guiding users and enabling teaching moments."),
                              "dialogInterface", 5);
    vBoxLayout_->addWidget(dialogView);

    // layout samples
    SampleCardView* layoutView = new SampleCardView(tr("Layout samples"), view_);
    layoutView->addSampleCard(":/gallery/images/controls/Grid.png", "FlowLayout",
                              tr("A layout arranges components in a left-to-right flow, wrapping to the next row when "
                                 "the current row is full."),
                              "layoutInterface", 0);
    vBoxLayout_->addWidget(layoutView);

    // material samples
    SampleCardView* materialView = new SampleCardView(tr("Material samples"), view_);
    materialView->addSampleCard(":/gallery/images/controls/Acrylic.png", "AcrylicLabel",
                                tr("A translucent material recommended for panel background."), "materialInterface", 0);
    vBoxLayout_->addWidget(materialView);

    // menu samples
    SampleCardView* menuView = new SampleCardView(tr("Menu & toolbars samples"), view_);
    menuView->addSampleCard(":/gallery/images/controls/MenuFlyout.png", "RoundMenu",
                            tr("Shows a contextual list of simple commands or options."), "menuInterface", 0);
    menuView->addSampleCard(":/gallery/images/controls/CommandBar.png", "CommandBar",
                            tr("Shows a contextual list of simple commands or options."), "menuInterface", 2);
    menuView->addSampleCard(":/gallery/images/controls/CommandBarFlyout.png", "CommandBarFlyout",
                            tr("A mini-toolbar displaying proactive commands, and an optional menu of commands."),
                            "menuInterface", 3);
    vBoxLayout_->addWidget(menuView);

    // navigation
    SampleCardView* navigationView = new SampleCardView(tr("Navigation"), view_);
    navigationView->addSampleCard(":/gallery/images/controls/BreadcrumbBar.png", "BreadcrumbBar",
                                  tr("Shows the trail of navigation taken to the current location."),
                                  "navigationViewInterface", 0);
    navigationView->addSampleCard(":/gallery/images/controls/Pivot.png", "Pivot",
                                  tr("Presents information from different sources in a tabbed view."),
                                  "navigationViewInterface", 1);
    navigationView->addSampleCard(":/gallery/images/controls/TabView.png", "TabView",
                                  tr("Presents information from different sources in a tabbed view."),
                                  "navigationViewInterface", 3);
    vBoxLayout_->addWidget(navigationView);

    // scroll samples
    SampleCardView* scrollView = new SampleCardView(tr("Scrolling samples"), view_);
    scrollView->addSampleCard(":/gallery/images/controls/ScrollViewer.png", "ScrollArea",
                              tr("A container control that lets the user pan and zoom its content smoothly."),
                              "scrollInterface", 0);
    scrollView->addSampleCard(":/gallery/images/controls/PipsPager.png", "PipsPager",
                              tr("A control to let the user navigate through a paginated collection when the page "
                                 "numbers do not need to be visually known."),
                              "scrollInterface", 3);
    vBoxLayout_->addWidget(scrollView);

    // state info samples
    SampleCardView* stateInfoView = new SampleCardView(tr("Status & info samples"), view_);
    stateInfoView->addSampleCard(":/gallery/images/controls/ProgressRing.png", "StateToolTip",
                                 tr("Shows the apps progress on a task, or that the app is performing ongoing work "
                                    "that does block user interaction."),
                                 "statusInfoInterface", 0);
    stateInfoView->addSampleCard(":/gallery/images/controls/InfoBadge.png", "InfoBadge",
                                 tr("An non-intrusive Ul to display notifications or bring focus to an area."),
                                 "statusInfoInterface", 3);
    stateInfoView->addSampleCard(":/gallery/images/controls/InfoBar.png", "InfoBar",
                                 tr("An inline message to display app-wide status change information."),
                                 "statusInfoInterface", 4);
    stateInfoView->addSampleCard(":/gallery/images/controls/ProgressBar.png", "ProgressBar",
                                 tr("Shows the apps progress on a task, or that the app is performing ongoing work "
                                    "that doesn't block user interaction."),
                                 "statusInfoInterface", 8);
    stateInfoView->addSampleCard(":/gallery/images/controls/ProgressRing.png", "ProgressRing",
                                 tr("Shows the apps progress on a task, or that the app is performing ongoing work "
                                    "that doesn't block user interaction."),
                                 "statusInfoInterface", 10);
    stateInfoView->addSampleCard(":/gallery/images/controls/ToolTip.png", "ToolTip",
                                 tr("Displays information for an element in a pop-up window."), "statusInfoInterface",
                                 1);
    vBoxLayout_->addWidget(stateInfoView);

    // text samples
    SampleCardView* textView = new SampleCardView(tr("Text samples"), view_);
    textView->addSampleCard(":/gallery/images/controls/TextBox.png", "LineEdit", tr("A single-line plain text field."),
                            "textInterface", 0);
    textView->addSampleCard(":/gallery/images/controls/NumberBox.png", "SpinBox",
                            tr("A text control used for numeric input and evaluation of algebraic equations."),
                            "textInterface", 1);
    textView->addSampleCard(
        ":/gallery/images/controls/RichEditBox.png", "TextEdit",
        tr("A rich text editing control that supports formatted text, hyperlinks, and other rich content."),
        "textInterface", 6);
    vBoxLayout_->addWidget(textView);

    // view samples
    SampleCardView* collectionView = new SampleCardView(tr("View samples"), view_);
    collectionView->addSampleCard(":/gallery/images/controls/ListView.png", "ListView",
                                  tr("A control that presents a collection of items in a vertical list."),
                                  "viewInterface", 0);
    collectionView->addSampleCard(
        ":/gallery/images/controls/DataGrid.png", "TableView",
        tr("The DataGrid control provides a flexible way to display a collection of data in rows and columns."),
        "viewInterface", 1);
    collectionView->addSampleCard(":/gallery/images/controls/TreeView.png", "TreeView",
                                  tr("The TreeView control is a hierarchical list pattern with expanding and "
                                     "collapsing nodes that contain nested items."),
                                  "viewInterface", 2);
    collectionView->addSampleCard(
        ":/gallery/images/controls/FlipView.png", "FlipView",
        tr("Presents a collection of items that the user can flip through, one item at a time."), "viewInterface", 4);
    vBoxLayout_->addWidget(collectionView);
}