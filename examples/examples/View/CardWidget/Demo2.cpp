#include "Demo2.h"
#include "Card.h"
#include <QFluentWidgets/Common/FluentApp.h>

Demo2::Demo2(QWidget* parent) : QWidget(parent)
{
    resize(600, 600);
    vBoxLayout_ = new QVBoxLayout(this);
    vBoxLayout_->setSpacing(6);
    vBoxLayout_->setContentsMargins(30, 60, 30, 30);
    vBoxLayout_->setAlignment(Qt::AlignTop);

    QString suffix = ":/qfluentwidgets/images/controls";
    addCard(":/qfluentwidgets/images/logo.png", "PyQt-Fluent-Widgets", "Shokokawaii Inc.");
    addCard(suffix + "/TitleBar.png", "PyQt-Frameless-Window", "Shokokawaii Inc.");
    addCard(suffix + "/RatingControl.png", "反馈中心", "Microsoft Corporation");
    addCard(suffix + "/Checkbox.png", "Microsoft 使用技巧", "Microsoft Corporation");
    addCard(suffix + "/Pivot.png", "MSN 天气", "Microsoft Corporation");
    addCard(suffix + "/MediaPlayerElement.png", "电影和电视", "Microsoft Corporation");
    addCard(suffix + "/PersonPicture.png", "照片", "Microsoft Corporation");

    if (qfluentwidgets::isDarkTheme()) {
        setStyleSheet("Demo2{background: rgb(32,32,32)}");
    } else {
        setStyleSheet("Demo2{background: rgb(242,242,242)}");
    }
}

void Demo2::addCard(const QString& icon, const QString& title, const QString& content)
{
    AppCard* card = new AppCard(icon, title, content, this);
    vBoxLayout_->addWidget(card, Qt::AlignTop);
}