#include "GalleryInterface.h"
#include "../Common/Config.h"
#include "../Common/SignalBus.h"
#include "../Common/StyleSheet.h"
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/Icon.h>
#include <QFluentWidgets/Components/Widgets/ToolTip.h>
#include <QPainter>
#include <QScrollBar>

using namespace qfluentwidgets;

SeparatorWidget::SeparatorWidget(QWidget* parent) : QWidget(parent)
{
    setFixedSize(6, 16);
}

void SeparatorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen(1);
    pen.setCosmetic(true);
    QColor color = isDarkTheme() ? QColor(255, 255, 255, 21) : QColor(0, 0, 0, 15);
    pen.setColor(color);
    painter.setPen(pen);

    int x = width() / 2;
    painter.drawLine(x, 0, x, height());
}

ToolBar::ToolBar(const QString& title, const QString& subtitle, QWidget* parent) : QWidget(parent)
{
    titleLabel_ = new TitleLabel(title, this);
    subtitleLabel_ = new CaptionLabel(subtitle, this);

    documentButton_ = new PushButton(new FluentIcon(FluentIcon::Document), tr("Documentation"), this);
    sourceButton_ = new PushButton(new FluentIcon(FluentIcon::GitHub), tr("Source"), this);
    themeButton_ = new ToolButton(new FluentIcon(FluentIcon::Constract), this);
    separator_ = new SeparatorWidget(this);
    supportButton_ = new ToolButton(new FluentIcon(FluentIcon::Heart), this);
    feedbackButton_ = new ToolButton(new FluentIcon(FluentIcon::Feedback), this);

    vBoxLayout_ = new QVBoxLayout(this);
    buttonLayout_ = new QHBoxLayout();

    setFixedHeight(138);
    vBoxLayout_->setSpacing(0);
    vBoxLayout_->setContentsMargins(36, 22, 36, 12);
    vBoxLayout_->addWidget(titleLabel_);
    vBoxLayout_->addSpacing(4);
    vBoxLayout_->addWidget(subtitleLabel_);
    vBoxLayout_->addSpacing(4);
    vBoxLayout_->addLayout(buttonLayout_, 1);
    vBoxLayout_->setAlignment(Qt::AlignTop);

    buttonLayout_->setSpacing(4);
    buttonLayout_->setContentsMargins(0, 0, 0, 0);
    buttonLayout_->addWidget(documentButton_, 0, Qt::AlignLeft);
    buttonLayout_->addWidget(sourceButton_, 0, Qt::AlignLeft);
    buttonLayout_->addStretch(1);
    buttonLayout_->addWidget(themeButton_, 0, Qt::AlignRight);
    buttonLayout_->addWidget(separator_, 0, Qt::AlignRight);
    buttonLayout_->addWidget(supportButton_, 0, Qt::AlignRight);
    buttonLayout_->addWidget(feedbackButton_, 0, Qt::AlignRight);
    buttonLayout_->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    themeButton_->installEventFilter(new ToolTipFilter(themeButton_));
    supportButton_->installEventFilter(new ToolTipFilter(supportButton_));
    feedbackButton_->installEventFilter(new ToolTipFilter(feedbackButton_));
    themeButton_->setToolTip(tr("Toggle theme"));
    supportButton_->setToolTip(tr("Support me"));
    feedbackButton_->setToolTip(tr("Send feedback"));

    QObject::connect(themeButton_, &ToolButton::clicked, this, [] { toggleTheme(true); });
    QObject::connect(supportButton_, &ToolButton::clicked, &signalBus, &SignalBus::supported);
    QObject::connect(documentButton_, &PushButton::clicked, this,
                     [] { QDesktopServices::openUrl(QUrl(Config::HELP_URL)); });
    QObject::connect(sourceButton_, &PushButton::clicked, this,
                     [] { QDesktopServices::openUrl(QUrl(Config::EXAMPLE_URL)); });
    QObject::connect(feedbackButton_, &ToolButton::clicked, this,
                     [] { QDesktopServices::openUrl(QUrl(Config::FEEDBACK_URL)); });
}

ExampleCard::ExampleCard(const QString& title, QWidget* widget, const QString& sourcePath, int stretch, QWidget* parent)
    : QWidget(parent), widget_(widget), stretch_(stretch), sourcePath_(sourcePath)
{
    titleLabel_ = new StrongBodyLabel(title, this);
    card_ = new QFrame(this);

    sourceWidget_ = new QFrame(card_);
    sourcePathLabel_ = new BodyLabel(tr("Source code"), sourceWidget_);
    linkIcon_ = new IconWidget(new FluentIcon(FluentIcon::Link), sourceWidget_);

    vBoxLayout_ = new QVBoxLayout(this);
    cardLayout_ = new QVBoxLayout(card_);
    topLayout_ = new QHBoxLayout();
    bottomLayout_ = new QHBoxLayout(sourceWidget_);

    initWidget();
}

void ExampleCard::initWidget()
{
    linkIcon_->setFixedSize(16, 16);
    initLayout();

    sourceWidget_->setCursor(Qt::PointingHandCursor);
    sourceWidget_->installEventFilter(this);

    card_->setObjectName("card");
    sourceWidget_->setObjectName("sourceWidget");
}

void ExampleCard::initLayout()
{
    vBoxLayout_->setSizeConstraint(QVBoxLayout::SetMinimumSize);
    cardLayout_->setSizeConstraint(QVBoxLayout::SetMinimumSize);
    topLayout_->setSizeConstraint(QHBoxLayout::SetMinimumSize);

    vBoxLayout_->setSpacing(12);
    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    topLayout_->setContentsMargins(12, 12, 12, 12);
    bottomLayout_->setContentsMargins(18, 18, 18, 18);
    cardLayout_->setContentsMargins(0, 0, 0, 0);

    vBoxLayout_->addWidget(titleLabel_, 0, Qt::AlignTop);
    vBoxLayout_->addWidget(card_, 0, Qt::AlignTop);
    vBoxLayout_->setAlignment(Qt::AlignTop);

    cardLayout_->setSpacing(0);
    cardLayout_->setAlignment(Qt::AlignTop);
    cardLayout_->addLayout(topLayout_, 0);
    cardLayout_->addWidget(sourceWidget_, 0, Qt::AlignBottom);

    widget_->setParent(card_);
    topLayout_->addWidget(widget_);
    if (stretch_ == 0) {
        topLayout_->addStretch(1);
    }

    widget_->show();

    bottomLayout_->addWidget(sourcePathLabel_, 0, Qt::AlignLeft);
    bottomLayout_->addStretch(1);
    bottomLayout_->addWidget(linkIcon_, 0, Qt::AlignRight);
    bottomLayout_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

bool ExampleCard::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == sourceWidget_) {
        if (event->type() == QEvent::MouseButtonRelease) {
            QDesktopServices::openUrl(QUrl(sourcePath_));
        }
    }

    return QWidget::eventFilter(obj, event);
}

GalleryInterface::GalleryInterface(const QString& title, const QString& subtitle, QWidget* parent) : ScrollArea(parent)
{
    view_ = new QWidget(this);
    toolBar_ = new ToolBar(title, subtitle, this);
    vBoxLayout_ = new QVBoxLayout(view_);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(0, toolBar_->height(), 0, 0);
    setWidget(view_);
    setWidgetResizable(true);

    vBoxLayout_->setSpacing(30);
    vBoxLayout_->setAlignment(Qt::AlignTop);
    vBoxLayout_->setContentsMargins(36, 20, 36, 36);

    view_->setObjectName("view");
    StyleSheet::applyTo(StyleSheet::GalleryInterface, this);
}

ExampleCard*
GalleryInterface::addExampleCard(const QString& title, QWidget* widget, const QString& sourcePath, int stretch)
{
    ExampleCard* card = new ExampleCard(title, widget, sourcePath, stretch, view_);
    vBoxLayout_->addWidget(card, 0, Qt::AlignTop);
    return card;
}

void GalleryInterface::scrollToCard(int index)
{
    QWidget* w = vBoxLayout_->itemAt(index)->widget();
    verticalScrollBar()->setValue(w->y());
}

void GalleryInterface::resizeEvent(QResizeEvent* event)
{
    QScrollArea::resizeEvent(event);
    toolBar_->resize(width(), toolBar_->height());
}