#include "SampleCard.h"
#include "../Common/StyleSheet.h"
#include "../Common/SignalBus.h"
#include <QFluentWidgets/Common/AutoWrap.h>

using namespace qfluentwidgets;

SampleCard::SampleCard(const QString& icon,
                       const QString& title,
                       const QString& content,
                       const QString& routeKey,
                       int index,
                       QWidget* parent)
    : CardWidget(parent), index_(index), routeKey_(routeKey)
{
    iconWidget_ = new IconWidget(icon, this);
    titleLabel_ = new QLabel(title, this);
    contentLabel_ = new QLabel(TextWrap::wrap(content, 45, false).first, this);

    setFixedSize(360, 90);
    iconWidget_->setFixedSize(48, 48);

    hBoxLayout_ = new QHBoxLayout(this);
    vBoxLayout_ = new QVBoxLayout();

    hBoxLayout_->setSpacing(28);
    hBoxLayout_->setContentsMargins(20, 0, 0, 0);
    vBoxLayout_->setSpacing(2);
    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    vBoxLayout_->setAlignment(Qt::AlignVCenter);

    hBoxLayout_->setAlignment(Qt::AlignVCenter);
    hBoxLayout_->addWidget(iconWidget_);
    hBoxLayout_->addLayout(vBoxLayout_);
    vBoxLayout_->addStretch(1);
    vBoxLayout_->addWidget(titleLabel_);
    vBoxLayout_->addWidget(contentLabel_);
    vBoxLayout_->addStretch(1);

    titleLabel_->setObjectName("titleLabel");
    contentLabel_->setObjectName("contentLabel");
}

void SampleCard::mouseReleaseEvent(QMouseEvent* event)
{
    CardWidget::mouseReleaseEvent(event);
    signalBus.switchToSampleCard(routeKey_, index_);
}


SampleCardView::SampleCardView(const QString& title, QWidget* parent) : QWidget(parent)
{
    titleLabel_ = new QLabel(title, this);
    vBoxLayout_ = new QVBoxLayout(this);
    flowLayout_ = new FlowLayout();

    vBoxLayout_->setContentsMargins(36, 0, 36, 0);
    vBoxLayout_->setSpacing(10);
    flowLayout_->setContentsMargins(0, 0, 0, 0);
    flowLayout_->setHorizontalSpacing(12);
    flowLayout_->setVerticalSpacing(12);

    vBoxLayout_->addWidget(titleLabel_);
    vBoxLayout_->addLayout(flowLayout_, 1);

    titleLabel_->setObjectName("viewTitleLabel");
    StyleSheet::applyTo(StyleSheet::SampleCard, this);
}

void SampleCardView::addSampleCard(const QString& icon,
                                   const QString& title,
                                   const QString& content,
                                   const QString& routeKey,
                                   int index)
{
    SampleCard* card = new SampleCard(icon, title, content, routeKey, index, this);
    flowLayout_->addWidget(card);
}