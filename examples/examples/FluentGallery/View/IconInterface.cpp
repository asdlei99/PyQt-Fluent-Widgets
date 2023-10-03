#include "IconInterface.h"
#include "../Common/StyleSheet.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Common/FluentApp.h>
#include <QMetaEnum>

using namespace qfluentwidgets;

IconLineEdit::IconLineEdit(QWidget* parent) : SearchLineEdit(parent)
{
    setPlaceholderText(tr("Search icons"));
    setFixedWidth(304);
    connect(this, &QLineEdit::textChanged, this, &SearchLineEdit::search);
}

IconCard::IconCard(FluentIcon* icon, QWidget* parent)
    : QFrame(parent), icon_(dynamic_cast<FluentIcon*>(icon->clone())), isSelected_(false)
{
    iconWidget_ = new IconWidget(icon, this);
    nameLabel_ = new QLabel(this);
    vBoxLayout_ = new QVBoxLayout(this);

    setFixedSize(96, 96);
    vBoxLayout_->setSpacing(0);
    vBoxLayout_->setContentsMargins(8, 28, 8, 0);
    vBoxLayout_->setAlignment(Qt::AlignTop);
    iconWidget_->setFixedSize(28, 28);
    vBoxLayout_->addWidget(iconWidget_, 0, Qt::AlignHCenter);
    vBoxLayout_->addSpacing(14);
    vBoxLayout_->addWidget(nameLabel_, 0, Qt::AlignHCenter);

    QString text = nameLabel_->fontMetrics().elidedText(icon->name(), Qt::ElideRight, 90);
    nameLabel_->setText(text);
}

void IconCard::mouseReleaseEvent(QMouseEvent* event)
{
    if (isSelected_)
        return;

    emit clicked(icon_->name());
}

void IconCard::setSelected(bool isSelected, bool force)
{
    if (isSelected == isSelected_ && !force)
        return;

    isSelected_ = isSelected;

    if (!isSelected)
        iconWidget_->setFluentIcon(icon_->clone());
    else {
        Theme theme = isDarkTheme() ? Theme::Light : Theme::Dark;
        iconWidget_->setIcon(icon_->icon(theme));
    }

    setProperty("isSelected", isSelected);
    setStyle(QApplication::style());
}

IconInfoPanel::IconInfoPanel(FluentIcon* icon, QWidget* parent) : QFrame(parent)
{
    nameLabel_ = new QLabel(icon->name(), this);
    iconWidget_ = new IconWidget(icon, this);
    iconNameTitleLabel_ = new QLabel(tr("Icon name"), this);
    iconNameLabel_ = new QLabel(icon->name(), this);
    enumNameTitleLabel_ = new QLabel(tr("Enum member"), this);
    enumNameLabel_ = new QLabel("FluentIcon." + icon->name(), this);
    vBoxLayout_ = new QVBoxLayout(this);

    vBoxLayout_->setContentsMargins(16, 20, 16, 20);
    vBoxLayout_->setSpacing(0);
    vBoxLayout_->setAlignment(Qt::AlignTop);

    vBoxLayout_->addWidget(nameLabel_);
    vBoxLayout_->addSpacing(16);
    vBoxLayout_->addWidget(iconWidget_);
    vBoxLayout_->addSpacing(45);
    vBoxLayout_->addWidget(iconNameTitleLabel_);
    vBoxLayout_->addSpacing(5);
    vBoxLayout_->addWidget(iconNameLabel_);
    vBoxLayout_->addSpacing(34);
    vBoxLayout_->addWidget(enumNameTitleLabel_);
    vBoxLayout_->addSpacing(5);
    vBoxLayout_->addWidget(enumNameLabel_);

    iconWidget_->setFixedSize(48, 48);
    setFixedWidth(216);

    nameLabel_->setObjectName("nameLabel");
    iconNameTitleLabel_->setObjectName("subTitleLabel");
    enumNameTitleLabel_->setObjectName("subTitleLabel");
}

void IconInfoPanel::setIcon(FluentIcon* icon)
{
    auto name = icon->name();
    iconWidget_->setFluentIcon(icon);
    nameLabel_->setText(name);
    iconNameLabel_->setText(name);
    enumNameLabel_->setText("FluentIcon::" + name);
}

IconCardView::IconCardView(QWidget* parent) : QWidget(parent), trie_()
{
    iconLibraryLabel_ = new StrongBodyLabel(tr("Fluent Icons Library"), this);
    searchLineEdit_ = new IconLineEdit(this);
    view_ = new QFrame(this);

    scrollArea_ = new SmoothScrollArea(this->view_);
    scrollWidget_ = new QWidget(this->scrollArea_);
    infoPanel_ = new IconInfoPanel(new FluentIcon(FluentIcon::Menu), this);

    vBoxLayout_ = new QVBoxLayout(this);
    hBoxLayout_ = new QHBoxLayout(this->view_);
    flowLayout_ = new FlowLayout(this->scrollWidget_);

    initWidget();
}

void IconCardView::setSelectedIcon(const QString& iconName)
{
    int index = icons_.indexOf(iconName);

    if (currentIndex_ >= 0) {
        cards_.at(currentIndex_)->setSelected(false);
    }

    currentIndex_ = index;
    cards_.at(index)->setSelected(true);

    QMetaEnum e = QMetaEnum::fromType<FluentIcon::Type>();
    infoPanel_->setIcon(new FluentIcon(static_cast<FluentIcon::Type>(e.keyToValue(iconName.toStdString().data()))));
}

void IconCardView::search(QString keyword)
{
    QVector<QPair<QString, int>> items = trie_.items(keyword.toLower());
    QSet<int> indexes;

    for (const auto& item : items) {
        indexes.insert(item.second);
    }

    flowLayout_->removeAllWidgets();

    for (int i = 0; i < cards_.size(); i++) {
        IconCard* card = cards_.at(i);
        bool isVisible = indexes.contains(i);
        card->setVisible(isVisible);

        if (isVisible) {
            flowLayout_->addWidget(card);
        }
    }
}

void IconCardView::showAllIcons()
{
    flowLayout_->removeAllWidgets();

    for (IconCard* card : cards_) {
        card->show();
        flowLayout_->addWidget(card);
    }
}

void IconCardView::addIcon(FluentIcon* icon)
{
    IconCard* card = new IconCard(icon, this);
    QObject::connect(card, &IconCard::clicked, this, &IconCardView::setSelectedIcon);

    trie_.insert(icon->name(), cards_.size());
    cards_.append(card);
    icons_.append(icon->name());
    flowLayout_->addWidget(card);
}

void IconCardView::initWidget()
{
    scrollArea_->setWidget(scrollWidget_);
    scrollArea_->setViewportMargins(0, 5, 0, 5);
    scrollArea_->setWidgetResizable(true);
    scrollArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    vBoxLayout_->setSpacing(12);
    vBoxLayout_->addWidget(iconLibraryLabel_);
    vBoxLayout_->addWidget(searchLineEdit_);
    vBoxLayout_->addWidget(view_);

    hBoxLayout_->setSpacing(0);
    hBoxLayout_->setContentsMargins(0, 0, 0, 0);
    hBoxLayout_->addWidget(scrollArea_);
    hBoxLayout_->addWidget(infoPanel_, 0, Qt::AlignRight);

    flowLayout_->setVerticalSpacing(8);
    flowLayout_->setHorizontalSpacing(8);
    flowLayout_->setContentsMargins(8, 3, 8, 8);

    setQss();

    QMetaEnum metaEnum = QMetaEnum::fromType<FluentIcon::Type>();
    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        addIcon(new FluentIcon(static_cast<FluentIcon::Type>(metaEnum.value(i))));
    }

    setSelectedIcon(icons_.at(0));

    QObject::connect(searchLineEdit_, &SearchLineEdit::searched, this, &IconCardView::search);
    QObject::connect(searchLineEdit_, &SearchLineEdit::cleared, this, &IconCardView::showAllIcons);
}

void IconCardView::setQss()
{
    view_->setObjectName("iconView");
    scrollWidget_->setObjectName("scrollWidget");

    StyleSheet::applyTo(StyleSheet::IconInterface, this);
    StyleSheet::applyTo(StyleSheet::IconInterface, scrollWidget_);

    if (currentIndex_ >= 0) {
        cards_.at(currentIndex_)->setSelected(true, true);
    }
}

IconInterface::IconInterface(QWidget* parent)
    : GalleryInterface(translator.icons, "<QFluentWidgets/Common/Icon.h>", parent)
{
    setObjectName("iconInterface");
    iconView_ = new IconCardView(this);
    vBoxLayout_->addWidget(iconView_);
}
