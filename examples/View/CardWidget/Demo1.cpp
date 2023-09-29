#include "Demo1.h"
#include "Card.h"
#include <QDir>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QIcon>

Demo1::Demo1(QWidget* parent) : QWidget(parent)
{
    setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
    setWindowTitle("Fluent Emoji gallery");

    flowLayout_ = new FlowLayout(this);

    resize(580, 680);
    flowLayout_->setSpacing(6);
    flowLayout_->setContentsMargins(30, 60, 30, 30);
    flowLayout_->setAlignment(Qt::AlignVCenter);

    QDir resourceDir("./Resource/images/emoji");
    QStringList filters;
    filters << "*.png";
    QFileInfoList fileInfoList = resourceDir.entryInfoList(filters, QDir::Files);
    for (const QFileInfo& fileInfo : fileInfoList) {
        addCard(fileInfo.filePath());
    }

    if (qfluentwidgets::isDarkTheme()) {
        setStyleSheet("Demo2{background: rgb(32,32,32)}");
    } else {
        setStyleSheet("Demo2{background: rgb(242,242,242)}");
    }
}

void Demo1::addCard(const QString& iconPath)
{
    EmojiCard* card = new EmojiCard(iconPath, this);
    flowLayout_->addWidget(card);
}