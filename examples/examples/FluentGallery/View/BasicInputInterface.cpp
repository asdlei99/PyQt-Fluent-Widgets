#include "BasicInputInterface.h"
#include "../Common/Translator.h"
#include <QButtonGroup>
#include <QFluentWidgets/Components/Widgets/CheckBox.h>
#include <QFluentWidgets/Components/Widgets/ComboBox.h>
#include <QFluentWidgets/Components/Widgets/RadioButton.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QFluentWidgets/Components/Widgets/Slider.h>
#include <QFluentWidgets/Components/Widgets/SplitButton.h>
#include <QFluentWidgets/Components/Widgets/SwitchButton.h>

using namespace qfluentwidgets;

BasicInputInterface::BasicInputInterface(QWidget* parent)
    : GalleryInterface(translator.basicInput, "<QFluentWidgets/Components/Widgets>", parent)
{
    setObjectName("basicInputInterface");

    // simple push button
    addExampleCard(tr("A simple button with text content"), new PushButton(tr("Standard push button")),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // tool button
    ToolButton* button = new ToolButton(QIcon(":/gallery/images/kunkun.png"));
    button->setIconSize(QSize(40, 40));
    button->resize(70, 70);
    addExampleCard(tr("A button with graphical content"), button,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // primary color push button
    addExampleCard(tr("Accent style applied to push button"), new PrimaryPushButton(tr("Accent style button")),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // primary color tool button
    addExampleCard(tr("Accent style applied to tool button"),
                   new PrimaryToolButton(new FluentIcon(FluentIcon::Basketball)),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // pill push button
    addExampleCard(tr("Pill push button"), new PillPushButton(new FluentIcon(FluentIcon::Tag), tr("Tag"), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // pill tool button
    addExampleCard(tr("Pill tool button"), new PillToolButton(new FluentIcon(FluentIcon::Basketball), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // transparent push button
    addExampleCard(tr("A transparent push button"),
                   new TransparentPushButton(new FluentIcon(FluentIcon::BookShelf), tr("Transparent push button")),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // transparent tool button
    addExampleCard(tr("A transparent tool button"), new TransparentToolButton(new FluentIcon(FluentIcon::BookShelf)),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // 2-state check box
    addExampleCard(tr("A 2-state CheckBox"), new CheckBox(tr("Two-state CheckBox")),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/check_box/demo.py");

    // 3-state check box
    auto checkBox = new CheckBox(tr("Three-state CheckBox"));
    checkBox->setTristate(true);
    addExampleCard(tr("A 3-state CheckBox"), checkBox,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/check_box/demo.py");

    // combo box
    ComboBox* comboBox = new ComboBox();
    QList<QString> items = {"shoko 🥰", "西宫硝子 😊", "一级棒卡哇伊的硝子酱 😘"};
    comboBox->addItems(items);
    comboBox->setCurrentIndex(0);
    comboBox->setMinimumWidth(210);
    addExampleCard(tr("A ComboBox with items"), comboBox,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/combo_box/demo.py");

    // editable combo box
    EditableComboBox* editableComboBox = new EditableComboBox();
    items = {tr("Star Platinum"), tr("Crazy Diamond"), tr("Gold Experience"), tr("Sticky Fingers")};
    editableComboBox->addItems(items);
    editableComboBox->setPlaceholderText(tr("Choose your stand"));
    editableComboBox->setMinimumWidth(210);
    addExampleCard(tr("An editable ComboBox"), editableComboBox,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/combo_box/demo.py");

    // drop down button
    RoundMenu* menu = new RoundMenu(this);
    menu->addAction(new Action(new FluentIcon(FluentIcon::Send), tr("Send")));
    menu->addAction(new Action(new FluentIcon(FluentIcon::Save), tr("Save")));
    DropDownPushButton* dropDownPushButton =
        new DropDownPushButton(new FluentIcon(FluentIcon::Mail), tr("Email"), this);
    dropDownPushButton->setMenu(menu);
    addExampleCard(tr("A push button with drop down menu"), dropDownPushButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    DropDownToolButton* dropDownToolButton = new DropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
    dropDownToolButton->setMenu(menu);
    addExampleCard(tr("A tool button with drop down menu"), dropDownToolButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // primary color drop down button
    PrimaryDropDownPushButton* primaryDropDownPushButton =
        new PrimaryDropDownPushButton(new FluentIcon(FluentIcon::Mail), tr("Email"), this);
    primaryDropDownPushButton->setMenu(menu);
    addExampleCard(tr("A primary color push button with drop down menu"), primaryDropDownPushButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    PrimaryDropDownToolButton* primaryDropDownToolButton =
        new PrimaryDropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
    primaryDropDownToolButton->setMenu(menu);
    addExampleCard(tr("A primary color tool button with drop down menu"), primaryDropDownToolButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // transparent drop down button
    TransparentDropDownPushButton* transparentDropDownPushButton =
        new TransparentDropDownPushButton(new FluentIcon(FluentIcon::Mail), tr("Email"), this);
    transparentDropDownPushButton->setMenu(menu);
    addExampleCard(tr("A transparent push button with drop down menu"), transparentDropDownPushButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // transparent drop down tool button
    TransparentDropDownToolButton* transparentDropDownToolButton =
        new TransparentDropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
    transparentDropDownToolButton->setMenu(menu);
    addExampleCard(tr("A transparent tool button with drop down menu"), transparentDropDownToolButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // hyperlink button
    addExampleCard(tr("A hyperlink button that navigates to a URI"),
                   new HyperlinkPushButton(new FluentIcon(FluentIcon::Link), tr("GitHub home page"),
                                           QUrl("https://github.com/zhiyiYo/QMaterialWidgets"), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Radio Button
    QWidget* radioWidget = new QWidget();
    QVBoxLayout* radioLayout = new QVBoxLayout(radioWidget);
    radioLayout->setContentsMargins(2, 0, 0, 0);
    radioLayout->setSpacing(15);
    auto radioButton1 = new RadioButton(tr("Star Platinum"), radioWidget);
    auto radioButton2 = new RadioButton(tr("Crazy Diamond"), radioWidget);
    auto radioButton3 = new RadioButton(tr("Soft and Wet"), radioWidget);
    auto buttonGroup = new QButtonGroup(radioWidget);
    buttonGroup->addButton(radioButton1);
    buttonGroup->addButton(radioButton2);
    buttonGroup->addButton(radioButton3);
    radioLayout->addWidget(radioButton1);
    radioLayout->addWidget(radioButton2);
    radioLayout->addWidget(radioButton3);
    radioButton1->click();
    addExampleCard(
        tr("A group of RadioButton controls in a button group"), radioWidget,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/radio_button/demo.py");

    // Horizontal Slider
    auto slider = new Slider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(30);
    slider->setMinimumWidth(200);
    addExampleCard(tr("A simple horizontal slider"), slider,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/slider/demo.py");

    // Split Button
    SplitPushButton* splitPushButton =
        new SplitPushButton(new FluentIcon(FluentIcon::Basketball), tr("Choose your stand"), this);
    splitPushButton->setMenu(createStandMenu(splitPushButton));
    addExampleCard(tr("A split push button with drop down menu"), splitPushButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    RoundMenu* ikunMenu = new RoundMenu(this);
    ikunMenu->addActions(
        QList<QAction*>{new Action(tr("Sing")), new Action(tr("Jump")), new Action(tr("Rap")), new Action(tr("Music"))});
    SplitToolButton* splitToolButton = new SplitToolButton(QIcon(":/gallery/images/kunkun.png"), this);
    splitToolButton->setIconSize(QSize(30, 30));
    splitToolButton->setMenu(ikunMenu);
    addExampleCard(tr("A split tool button with drop down menu"), splitToolButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Primary Color Split Button
    PrimarySplitPushButton* primarySplitPushButton =
        new PrimarySplitPushButton(new FluentIcon(FluentIcon::Basketball), tr("Choose your stand"), this);
    primarySplitPushButton->setMenu(createStandMenu(primarySplitPushButton));
    addExampleCard(tr("A primary color split push button with drop down menu"), primarySplitPushButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    PrimarySplitToolButton* primarySplitToolButton =
        new PrimarySplitToolButton(new FluentIcon(FluentIcon::Basketball), this);
    primarySplitToolButton->setMenu(ikunMenu);
    addExampleCard(tr("A primary color split tool button with drop down menu"), primarySplitToolButton,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Switch Button
    switchButton_ = new SwitchButton(this);
    // connect(switchButton_, &SwitchButton::checkedChanged, this, &BasicInputInterface::onSwitchCheckedChanged);
    addExampleCard(
        tr("A simple switch button"), switchButton_,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/switch_button/demo.py");

    // Toggle Push Button
    addExampleCard(tr("A simple toggle push button"),
                   new TogglePushButton(new FluentIcon(FluentIcon::Basketball), tr("Start practicing"), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Toggle Tool Button
    addExampleCard(tr("A simple toggle tool button"),
                   new ToggleToolButton(new FluentIcon(FluentIcon::Basketball), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Transparent Toggle Button
    addExampleCard(
        tr("A transparent toggle push button"),
        new TransparentTogglePushButton(new FluentIcon(FluentIcon::Basketball), tr("Start practicing"), this),
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");

    // Transparent Toggle Tool Button
    addExampleCard(tr("A transparent toggle tool button"),
                   new TransparentToggleToolButton(new FluentIcon(FluentIcon::Basketball), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/basic_input/button/demo.py");
}

RoundMenu* BasicInputInterface::createStandMenu(SplitPushButton* button)
{
    auto menu = new RoundMenu(this);
    menu->addActions(QList<QAction*>{
        createAction(tr("Star Platinum"), button),
        createAction(tr("Crazy Diamond"), button),
        createAction(tr("Gold Experience"), button),
        createAction(tr("Sticky Fingers"), button),
    });
    return menu;
}

Action* BasicInputInterface::createAction(const QString& text, SplitPushButton* button)
{
    auto act = new Action(text, this);
    connect(act, &QAction::triggered, this, [=] { button->setText(text); });
    return act;
}

void BasicInputInterface::onSwitchCheckedChanged(bool isChecked)
{
    if (isChecked) {
        switchButton_->setText(tr("On"));
    } else {
        switchButton_->setText(tr("Off"));
    }
}