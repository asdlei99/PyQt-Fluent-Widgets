#include "LinkCard.h"
#include "../Common/StyleSheet.h"
#include <QDesktopServices>
#include <QFluentWidgets/Common/AutoWrap.h>

using namespace qfluentwidgets;

LinkCard::LinkCard(const QString& icon,
                   const QString& title,
                   const QString& content,
                   const QString& url,
                   QWidget* parent)
    : QFrame(parent),
      url_(url),
      iconWidget_(new IconWidget(icon, this)),
      titleLabel_(new QLabel(title, this)),
      contentLabel_(new QLabel(TextWrap::wrap(content, 28, false).first, this)),
      urlWidget_(new IconWidget(new FluentIcon(FluentIcon::Link), this)),
      vBoxLayout_(new QVBoxLayout(this))
{
    init();
}

LinkCard::LinkCard(FluentIconBase* icon,
                   const QString& title,
                   const QString& content,
                   const QString& url,
                   QWidget* parent)
    : QFrame(parent),
      url_(url),
      iconWidget_(new IconWidget(icon, this)),
      titleLabel_(new QLabel(title, this)),
      contentLabel_(new QLabel(TextWrap::wrap(content, 28, false).first, this)),
      urlWidget_(new IconWidget(new FluentIcon(FluentIcon::Link), this)),
      vBoxLayout_(new QVBoxLayout(this))
{
    init();
}

void LinkCard::mouseReleaseEvent(QMouseEvent* event)
{
    QFrame::mouseReleaseEvent(event);
    QDesktopServices::openUrl(url_);
}

void LinkCard::init() {
    setFixedSize(198, 220);
    setCursor(Qt::PointingHandCursor);

    iconWidget_->setFixedSize(54, 54);
    urlWidget_->setFixedSize(16, 16);

    vBoxLayout_->setSpacing(0);
    vBoxLayout_->setContentsMargins(24, 24, 0, 13);
    vBoxLayout_->addWidget(iconWidget_);
    vBoxLayout_->addSpacing(16);
    vBoxLayout_->addWidget(titleLabel_);
    vBoxLayout_->addSpacing(8);
    vBoxLayout_->addWidget(contentLabel_);
    vBoxLayout_->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    urlWidget_->move(170, 192);

    titleLabel_->setObjectName("titleLabel");
    contentLabel_->setObjectName("contentLabel");
}

LinkCardView::LinkCardView(QWidget* parent) : SingleDirectionScrollArea(parent, Qt::Horizontal)
{
    view_ = new QWidget(this);
    hBoxLayout_ = new QHBoxLayout(view_);

    hBoxLayout_->setContentsMargins(36, 0, 0, 0);
    hBoxLayout_->setSpacing(12);
    hBoxLayout_->setAlignment(Qt::AlignLeft);

    setWidget(view_);
    setWidgetResizable(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view_->setObjectName("view");
    StyleSheet::applyTo(StyleSheet::LinkCard, this);
}

void LinkCardView::addCard(const QString& icon, const QString& title, const QString& content, const QString& url)
{
    LinkCard* card = new LinkCard(icon, title, content, url, view_);
    hBoxLayout_->addWidget(card, 0, Qt::AlignLeft);
}

void LinkCardView::addCard(FluentIconBase* icon, const QString& title, const QString& content, const QString& url)
{
    LinkCard* card = new LinkCard(icon, title, content, url, view_);
    hBoxLayout_->addWidget(card, 0, Qt::AlignLeft);
}