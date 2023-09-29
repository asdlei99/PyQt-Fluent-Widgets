#include "Demo3.h"
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/Font.h>
#include <QPainter>

using namespace qfluentwidgets;

LightBox::LightBox(QWidget* parent)
    : QWidget(parent),
      acrylicBrush(this, 100, isDarkTheme() ? QColor(32, 32, 32, 200) : QColor(255, 255, 255, 160), QColor(0, 0, 0, 0))
{
    vBoxLayout_ = new QVBoxLayout(this);
    closeButton_ = new TransparentToolButton(new FluentIcon(FluentIcon::Close), this);
    flipView_ = new HorizontalFlipView(this);
    nameLabel_ = new BodyLabel("屏幕截图 1", this);
    pageNumButton_ = new PillPushButton("1 / 4", this);

    pageNumButton_->setCheckable(false);
    pageNumButton_->setFixedSize(80, 32);
    ::setFont(nameLabel_, 16, QFont::DemiBold);

    closeButton_->setFixedSize(32, 32);
    closeButton_->setIconSize(QSize(14, 14));
    connect(closeButton_, &TransparentToolButton::clicked, this, &LightBox::hide);

    vBoxLayout_->setContentsMargins(26, 28, 26, 28);
    vBoxLayout_->addWidget(closeButton_, 0, Qt::AlignRight | Qt::AlignTop);
    vBoxLayout_->addWidget(flipView_, 1);
    vBoxLayout_->addWidget(nameLabel_, 0, Qt::AlignHCenter);
    vBoxLayout_->addSpacing(10);
    vBoxLayout_->addWidget(pageNumButton_, 0, Qt::AlignHCenter);

    flipView_->addImages({"Resource/images/shoko1.jpg", "Resource/images/shoko2.jpg", "Resource/images/shoko3.jpg",
                          "Resource/images/shoko4.jpg"});
    connect(flipView_, &HorizontalFlipView::currentIndexChanged, this, &LightBox::setCurrentIndex);
}

void LightBox::setCurrentIndex(int index)
{
    nameLabel_->setText(QString("屏幕截图 %1").arg(index + 1));
    pageNumButton_->setText(QString("%1 / %2").arg(index + 1).arg(flipView_->count()));
    flipView_->setCurrentIndex(index);
}

void LightBox::paintEvent(QPaintEvent* e)
{
    acrylicBrush.paint();
}

void LightBox::resizeEvent(QResizeEvent* e)
{
    int w = width() - 52;
    flipView_->setItemSize(QSize(w, w * 9 / 16));
}

void LightBox::showEvent(QShowEvent* e)
{
    acrylicBrush.grabImage(QRect(mapToGlobal(QPoint()), size()));
    QWidget::showEvent(e);
}

Demo3::Demo3(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QFluentWidgets");
    setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));

    if (isDarkTheme()) {
        setStyleSheet("Demo3{background: rgb(32,32,32)}");
    } else {
        setStyleSheet("Demo3{background: rgb(242,242,242)}");
    }

    hBoxLayout_ = new QHBoxLayout(this);
    scrollArea_ = new SingleDirectionScrollArea(this);
    view_ = new QWidget(this);

    vBoxLayout_ = new QVBoxLayout(view_);
    appCard_ = new AppInfoCard(this);
    galleryCard_ = new GalleryCard(this);
    descriptionCard_ = new DescriptionCard(this);
    systemCard_ = new SystemRequirementCard(this);

    lightBox_ = new LightBox(this);
    lightBox_->hide();
    connect(galleryCard_->flipView(), &HorizontalFlipView::itemClicked, this, &Demo3::showLightBox);

    scrollArea_->setWidget(view_);
    scrollArea_->setWidgetResizable(true);

    hBoxLayout_->setContentsMargins(0, 48, 0, 0);
    hBoxLayout_->addWidget(scrollArea_);

    vBoxLayout_->setSpacing(10);
    vBoxLayout_->setContentsMargins(30, 0, 30, 30);
    vBoxLayout_->addWidget(appCard_, 0, Qt::AlignTop);
    vBoxLayout_->addWidget(galleryCard_, 0, Qt::AlignTop);
    vBoxLayout_->addWidget(descriptionCard_, 0, Qt::AlignTop);
    vBoxLayout_->addWidget(systemCard_, 0, Qt::AlignTop);

    resize(780, 800);
    scrollArea_->setStyleSheet("QScrollArea {border: none; background:transparent}");
    view_->setStyleSheet("QWidget {background:transparent}");
}

void Demo3::showLightBox()
{
    int index = galleryCard_->flipView()->currentIndex();
    lightBox_->setCurrentIndex(index);
    lightBox_->show();
}

void Demo3::resizeEvent(QResizeEvent* e)
{
    QWidget::resizeEvent(e);
    lightBox_->resize(width(), height() - 48);
    lightBox_->move(0, 48);
}