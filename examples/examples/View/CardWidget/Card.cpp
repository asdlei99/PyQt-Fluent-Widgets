#include "Card.h"
#include <QFileInfo>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>

using namespace qfluentwidgets;

AppCard::AppCard(const QString& icon, const QString& title, const QString& content, QWidget* parent)
    : CardWidget(parent)
{
    iconWidget_ = new IconWidget(icon, this);
    titleLabel_ = new BodyLabel(title, this);
    contentLabel_ = new CaptionLabel(content, this);
    openButton_ = new PushButton("打开", this);
    moreButton_ = new TransparentToolButton(new FluentIcon(FluentIcon::More), this);
    hBoxLayout_ = new QHBoxLayout(this);
    vBoxLayout_ = new QVBoxLayout();

    setFixedHeight(73);
    iconWidget_->setFixedSize(48, 48);
    contentLabel_->setTextColor("#606060", "#d2d2d2");
    openButton_->setFixedWidth(120);

    hBoxLayout_->setContentsMargins(20, 11, 11, 11);
    hBoxLayout_->setSpacing(15);
    hBoxLayout_->addWidget(iconWidget_);

    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    vBoxLayout_->setSpacing(0);
    vBoxLayout_->addWidget(titleLabel_, 0, Qt::AlignVCenter);
    vBoxLayout_->addWidget(contentLabel_, 0, Qt::AlignVCenter);
    vBoxLayout_->setAlignment(Qt::AlignVCenter);
    hBoxLayout_->addLayout(vBoxLayout_);

    hBoxLayout_->addStretch(1);
    hBoxLayout_->addWidget(openButton_, 0, Qt::AlignRight);
    hBoxLayout_->addWidget(moreButton_, 0, Qt::AlignRight);

    moreButton_->setFixedSize(32, 32);
    connect(moreButton_, &TransparentToolButton::clicked, this, &AppCard::onMoreButtonClicked);
}

void AppCard::onMoreButtonClicked()
{
    RoundMenu* menu = new RoundMenu(this);
    menu->addAction(new Action(new FluentIcon(FluentIcon::Share), "共享", this));
    menu->addAction(new Action(new FluentIcon(FluentIcon::Chat), "写评论", this));
    menu->addAction(new Action(new FluentIcon(FluentIcon::Pin), "固定到任务栏", this));

    int x = (moreButton_->width() - menu->width()) / 2 + 10;
    QPoint pos = moreButton_->mapToGlobal(QPoint(x, moreButton_->height()));
    menu->exec(pos);
}

EmojiCard::EmojiCard(const QString& iconPath, QWidget* parent) : ElevatedCardWidget(parent)
{
    iconWidget_ = new ImageLabel(iconPath, this);
    label_ = new CaptionLabel(QFileInfo(iconPath).baseName(), this);
    vBoxLayout_ = new QVBoxLayout(this);

    iconWidget_->scaledToHeight(68);

    vBoxLayout_->setAlignment(Qt::AlignCenter);
    vBoxLayout_->addStretch(1);
    vBoxLayout_->addWidget(iconWidget_, 0, Qt::AlignCenter);
    vBoxLayout_->addStretch(1);
    vBoxLayout_->addWidget(label_, 0, Qt::AlignHCenter | Qt::AlignBottom);

    setFixedSize(168, 176);
}

AppInfoCard::AppInfoCard(QWidget* parent) : SimpleCardWidget(parent)
{
    iconLabel_ = new ImageLabel(":/qfluentwidgets/images/logo.png", this);
    iconLabel_->setBorderRadius(8, 8, 8, 8);
    iconLabel_->scaledToWidth(120);

    nameLabel_ = new TitleLabel("QFluentWidgets", this);
    installButton_ = new PrimaryPushButton("安装", this);
    companyLabel_ =
        new HyperlinkLabel(QUrl("https://github.com/zhiyiYo/PyQt-Fluent-Widgets"), "Shokokawaii Inc.", this);
    installButton_->setFixedWidth(160);

    scoreWidget_ = new StatisticsWidget("平均", "5.0", this);
    separator_ = new VerticalSeparator(this);
    commentWidget_ = new StatisticsWidget("评论数", "3K", this);

    descriptionLabel_ = new BodyLabel("PyQt-Fluent-Widgets 是一个基于 PyQt/PySide 的 Fluent Design "
                                      "风格组件库，包含许多美观实用的组件，支持亮暗主题无缝切换和自定义主题色，帮助开发"
                                      "者快速实现美观优雅的现代化界面。",
                                      this);
    descriptionLabel_->setWordWrap(true);

    tagButton_ = new PillPushButton("组件库", this);
    tagButton_->setCheckable(false);
    ::setFont(tagButton_, 12);

    shareButton_ = new TransparentToolButton(new FluentIcon(FluentIcon::Share), this);
    shareButton_->setFixedSize(32, 32);
    shareButton_->setIconSize(QSize(14, 14));

    hBoxLayout_ = new QHBoxLayout(this);
    vBoxLayout_ = new QVBoxLayout();
    topLayout_ = new QHBoxLayout();
    statisticsLayout_ = new QHBoxLayout();
    buttonLayout_ = new QHBoxLayout();

    initLayout();
}

void AppInfoCard::initLayout()
{
    hBoxLayout_->setSpacing(30);
    hBoxLayout_->setContentsMargins(34, 24, 24, 24);
    hBoxLayout_->addWidget(iconLabel_);
    hBoxLayout_->addLayout(vBoxLayout_);

    vBoxLayout_->setContentsMargins(0, 0, 0, 0);
    vBoxLayout_->setSpacing(0);

    // name label and install button
    vBoxLayout_->addLayout(topLayout_);
    topLayout_->setContentsMargins(0, 0, 0, 0);
    topLayout_->addWidget(nameLabel_);
    topLayout_->addWidget(installButton_, 0, Qt::AlignRight);

    // company label
    vBoxLayout_->addSpacing(3);
    vBoxLayout_->addWidget(companyLabel_);

    // statistics widgets
    vBoxLayout_->addSpacing(20);
    vBoxLayout_->addLayout(statisticsLayout_);
    statisticsLayout_->setContentsMargins(0, 0, 0, 0);
    statisticsLayout_->setSpacing(10);
    statisticsLayout_->addWidget(scoreWidget_);
    statisticsLayout_->addWidget(separator_);
    statisticsLayout_->addWidget(commentWidget_);
    statisticsLayout_->setAlignment(Qt::AlignLeft);

    // description label
    vBoxLayout_->addSpacing(20);
    vBoxLayout_->addWidget(descriptionLabel_);

    // button
    vBoxLayout_->addSpacing(12);
    buttonLayout_->setContentsMargins(0, 0, 0, 0);
    vBoxLayout_->addLayout(buttonLayout_);
    buttonLayout_->addWidget(tagButton_, 0, Qt::AlignLeft);
    buttonLayout_->addWidget(shareButton_, 0, Qt::AlignRight);
}

StatisticsWidget::StatisticsWidget(const QString& title, const QString& value, QWidget* parent) : QWidget(parent)
{
    titleLabel_ = new CaptionLabel(title, this);
    valueLabel_ = new BodyLabel(value, this);
    vBoxLayout_ = new QVBoxLayout(this);

    vBoxLayout_->setContentsMargins(16, 0, 16, 0);
    vBoxLayout_->addWidget(valueLabel_, 0, Qt::AlignTop);
    vBoxLayout_->addWidget(titleLabel_, 0, Qt::AlignBottom);

    ::setFont(valueLabel_, 18, QFont::DemiBold);

    titleLabel_->setTextColor(QColor(96, 96, 96), QColor(206, 206, 206));
}

GalleryCard::GalleryCard(QWidget* parent) : HeaderCardWidget(parent)
{
    setTitle("屏幕截图");

    flipView_ = new HorizontalFlipView(this);
    expandButton_ = new TransparentToolButton(new FluentIcon(FluentIcon::ChevronRightMed), this);
    expandButton_->setFixedSize(32, 32);
    expandButton_->setIconSize(QSize(12, 12));

    flipView_->addImages({
        "Resource/images/shoko1.jpg",
        "Resource/images/shoko2.jpg",
        "Resource/images/shoko3.jpg",
        "Resource/images/shoko4.jpg"
    });
    flipView_->setBorderRadius(8);
    flipView_->setSpacing(10);

    headerLayout_->addWidget(expandButton_, 0, Qt::AlignRight);
    viewLayout_->addWidget(flipView_);
}

DescriptionCard::DescriptionCard(QWidget* parent) : HeaderCardWidget(parent)
{
    descriptionLabel_ = new BodyLabel("PyQt-Fluent-Widgets 是一个基于 PyQt/PySide 的 Fluent Design "
                                     "风格组件库，包含许多美观实用的组件，支持亮暗主题无缝切换和自定义主题色，搭配所见"
                                     "即所得的 QtDesigner，帮助开发者快速实现美观优雅的现代化界面。",
                                     this);
    descriptionLabel_->setWordWrap(true);

    viewLayout_->addWidget(descriptionLabel_);
    setTitle("描述");
}

SystemRequirementCard::SystemRequirementCard(QWidget* parent) : HeaderCardWidget(parent)
{
    setTitle("系统要求");

    infoLabel_ = new BodyLabel("此产品适用于你的设备。具有复选标记的项目符合开发人员的系统要求。", this);
    successIcon_ = new IconWidget(new InfoBarIcon(InfoBarIcon::Success), this);
    detailButton_ = new HyperlinkLabel("详细信息", this);

    auto vBoxLayout = new QVBoxLayout();
    auto hBoxLayout = new QHBoxLayout();

    successIcon_->setFixedSize(16, 16);
    hBoxLayout->setSpacing(10);
    vBoxLayout->setSpacing(16);
    hBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);

    hBoxLayout->addWidget(successIcon_);
    hBoxLayout->addWidget(infoLabel_);
    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addWidget(detailButton_);

    viewLayout_->addLayout(vBoxLayout);
}