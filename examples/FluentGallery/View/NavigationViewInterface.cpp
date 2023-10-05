#include "NavigationViewInterface.h"
#include "../Common/StyleSheet.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Components/Navigation/Breadcrumb.h>
#include <QFluentWidgets/Components/Navigation/Pivot.h>
#include <QFluentWidgets/Components/Navigation/SegmentedWidget.h>
#include <QFluentWidgets/Components/Widgets/CheckBox.h>
#include <QFluentWidgets/Components/Widgets/ComboBox.h>
#include <QFluentWidgets/Components/Widgets/SpinBox.h>
#include <QFluentWidgets/Components/Widgets/TabView.h>
#include <QStackedWidget>

NavigationViewInterface::NavigationViewInterface(QWidget* parent)
    : GalleryInterface(translator.navigation, "<QFluentWidgets/Components/Navigation>", parent)
{
    setObjectName("navigationViewInterface");

    breadcrumb_ = new BreadcrumbBar(this);
    QStringList items = {tr("Home"),  tr("Documents"),  tr("Study"),   tr("Janpanese Sensei"), tr("Action Film"),
                         tr("G Cup"), tr("Mikami Yua"), tr("Folder1"), tr("Folder2")};
    for (const QString& item : items) {
        breadcrumb_->addItem(item, item);
    }

    addExampleCard(
        tr("Breadcrumb bar"), breadcrumb_,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/navigation/breadcrumb_bar/demo.py", 1);

    addExampleCard(tr("A basic pivot"), new PivotInterface(new Pivot(this), this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/navigation/pivot/demo.py");

    addExampleCard(
        tr("A segmented control"), new SegmentedInterface(new SegmentedWidget(this), this),
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/navigation/segmented_widget/demo.py");

    auto card = addExampleCard(tr("A tab bar"), new TabInterface(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/navigation/tab_view/demo.py",
                   1);
    card->topLayout()->setContentsMargins(12, 0, 0, 0);
}

PivotInterface::PivotInterface(Pivot* pivot, QWidget* parent) : QWidget(parent), pivot_(pivot)
{
    setFixedSize(300, 140);

    stackedWidget_ = new QStackedWidget(this);
    vBoxLayout_ = new QVBoxLayout(this);

    songInterface_ = new QLabel(tr("Song Interface"), this);
    albumInterface_ = new QLabel(tr("Album Interface"), this);
    artistInterface_ = new QLabel(tr("Artist Interface"), this);

    addSubInterface(songInterface_, "songInterface", tr("Song"));
    addSubInterface(albumInterface_, "albumInterface", tr("Album"));
    addSubInterface(artistInterface_, "artistInterface", tr("Artist"));

    vBoxLayout_->addWidget(pivot_, 0, Qt::AlignLeft);
    vBoxLayout_->addWidget(stackedWidget_);
    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    StyleSheet::applyTo(StyleSheet::NavigationViewInterface, this);

    connect(stackedWidget_, &QStackedWidget::currentChanged, this, &PivotInterface::onCurrentIndexChanged);
    stackedWidget_->setCurrentWidget(songInterface_);
    pivot_->setCurrentItem(songInterface_->objectName());

    qrouter.setDefaultRouteKey(stackedWidget_, songInterface_->objectName());
}

void PivotInterface::addSubInterface(QLabel* widget, const QString& objectName, const QString& text)
{
    widget->setObjectName(objectName);
    widget->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    stackedWidget_->addWidget(widget);

    auto item = pivot_->addItem(objectName, text);
    connect(item, &PivotItem::clicked, this, [this, widget]() { stackedWidget_->setCurrentWidget(widget); });
}

void PivotInterface::onCurrentIndexChanged(int index)
{
    QWidget* widget = stackedWidget_->widget(index);
    pivot_->setCurrentItem(widget->objectName());
    qrouter.push(stackedWidget_, widget->objectName());
}

SegmentedInterface::SegmentedInterface(Pivot* pivot, QWidget* parent) : PivotInterface(pivot, parent)
{
    vBoxLayout_->removeWidget(pivot_);
    vBoxLayout_->insertWidget(0, pivot_);
}

TabInterface::TabInterface(QWidget* parent) : QWidget(parent)
{
    tabCount_ = 1;

    tabBar_ = new TabBar(this);
    stackedWidget_ = new QStackedWidget(this);
    tabView_ = new QWidget(this);
    controlPanel_ = new QFrame(this);

    movableCheckBox_ = new CheckBox(tr("IsTabMovable"), this);
    scrollableCheckBox_ = new CheckBox(tr("IsTabScrollable"), this);
    shadowEnabledCheckBox_ = new CheckBox(tr("IsTabShadowEnabled"), this);
    tabMaxWidthLabel_ = new QLabel(tr("TabMaximumWidth"), this);
    tabMaxWidthSpinBox_ = new SpinBox(this);
    closeDisplayModeLabel_ = new QLabel(tr("TabCloseButtonDisplayMode"), this);
    closeDisplayModeComboBox_ = new ComboBox(this);

    hBoxLayout_ = new QHBoxLayout(this);
    vBoxLayout_ = new QVBoxLayout(tabView_);
    panelLayout_ = new QVBoxLayout(controlPanel_);

    songInterface_ = new QLabel("Song Interface", this);
    albumInterface_ = new QLabel("Album Interface", this);
    artistInterface_ = new QLabel("Artist Interface", this);

    initWidget();
}

void TabInterface::onDisplayModeChanged(int index)
{
    int mode = closeDisplayModeComboBox_->itemData(index).toInt();
    tabBar_->setCloseButtonDisplayMode(static_cast<TabItem::TabCloseButtonDisplayMode>(mode));
}

void TabInterface::onCurrentIndexChanged(int index)
{
    QWidget* widget = stackedWidget_->widget(index);
    if (!widget) {
        return;
    }

    tabBar_->setCurrentIndex(index);
    qrouter.push(stackedWidget_, widget->objectName());
}

void TabInterface::addTab()
{
    QString text = QString("硝子酱一级棒卡哇伊×%1").arg(tabCount_);
    QLabel* label = new QLabel("🥰 " + text, this);
    addSubInterface(label, QString::number(tabCount_++), text, ":/gallery/images/Smiling_with_heart.png");
}

void TabInterface::removeTab(int index)
{
    auto item = tabBar_->tabItem(index);
    QLabel* widget = findChild<QLabel*>(item->routeKey());

    stackedWidget_->removeWidget(widget);
    tabBar_->removeTab(index);
    widget->deleteLater();
}

void TabInterface::initWidget()
{
    initLayout();

    shadowEnabledCheckBox_->setChecked(true);

    tabMaxWidthSpinBox_->setRange(60, 400);
    tabMaxWidthSpinBox_->setValue(tabBar_->tabMaximumWidth());

    closeDisplayModeComboBox_->addItem(tr("Always"), QVariant(static_cast<int>(TabItem::Always)));
    closeDisplayModeComboBox_->addItem(tr("OnHover"), QVariant(static_cast<int>(TabItem::OnHover)));
    closeDisplayModeComboBox_->addItem(tr("Never"), QVariant(static_cast<int>(TabItem::Never)));
    connect(closeDisplayModeComboBox_, &ComboBox::currentIndexChanged, this, &TabInterface::onDisplayModeChanged);

    addSubInterface(songInterface_, "tabSongInterface", tr("Song"), ":/gallery/images/MusicNote.png");
    addSubInterface(albumInterface_, "tabAlbumInterface", tr("Album"), ":/gallery/images/Dvd.png");
    addSubInterface(artistInterface_, "tabArtistInterface", tr("Artist"), ":/gallery/images/Singer.png");

    controlPanel_->setObjectName("controlPanel");
    StyleSheet::applyTo(StyleSheet::NavigationViewInterface, this);

    connectSignalToSlot();

    qrouter.setDefaultRouteKey(stackedWidget_, songInterface_->objectName());
}

void TabInterface::connectSignalToSlot()
{
    connect(movableCheckBox_, &QCheckBox::stateChanged,
            [this](int state) { tabBar_->setMovable(state == Qt::Checked); });
    connect(scrollableCheckBox_, &QCheckBox::stateChanged,
            [this](int state) { tabBar_->setScrollable(state == Qt::Checked); });
    connect(shadowEnabledCheckBox_, &QCheckBox::stateChanged,
            [this](int state) { tabBar_->setTabShadowEnabled(state == Qt::Checked); });

    connect(tabMaxWidthSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), tabBar_, &TabBar::setTabMaximumWidth);

    connect(tabBar_, &TabBar::tabAddRequested, this, &TabInterface::addTab);
    connect(tabBar_, &TabBar::tabCloseRequested, this, &TabInterface::removeTab);

    connect(stackedWidget_, &QStackedWidget::currentChanged, this, &TabInterface::onCurrentIndexChanged);
}

void TabInterface::initLayout()
{
    tabBar_->setTabMaximumWidth(200);

    setFixedHeight(280);
    controlPanel_->setFixedWidth(220);
    hBoxLayout_->addWidget(tabView_, 1);
    hBoxLayout_->addWidget(controlPanel_, 0, Qt::AlignRight);
    hBoxLayout_->setContentsMargins(0, 0, 0, 0);

    vBoxLayout_->addWidget(tabBar_);
    vBoxLayout_->addWidget(stackedWidget_);
    vBoxLayout_->setContentsMargins(0, 0, 0, 0);

    panelLayout_->setSpacing(8);
    panelLayout_->setContentsMargins(14, 16, 14, 14);
    panelLayout_->setAlignment(Qt::AlignTop);

    panelLayout_->addWidget(movableCheckBox_);
    panelLayout_->addWidget(scrollableCheckBox_);
    panelLayout_->addWidget(shadowEnabledCheckBox_);

    panelLayout_->addSpacing(4);
    panelLayout_->addWidget(tabMaxWidthLabel_);
    panelLayout_->addWidget(tabMaxWidthSpinBox_);

    panelLayout_->addSpacing(4);
    panelLayout_->addWidget(closeDisplayModeLabel_);
    panelLayout_->addWidget(closeDisplayModeComboBox_);
}

void TabInterface::addSubInterface(QLabel* widget, const QString& objectName, const QString& text, const QString& icon)
{
    widget->setObjectName(objectName);
    widget->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    stackedWidget_->addWidget(widget);

    auto item = tabBar_->addTab(objectName, text, QIcon(icon));
    connect(item, &TabItem::clicked, this, [=]() { this->stackedWidget_->setCurrentWidget(widget); });
}