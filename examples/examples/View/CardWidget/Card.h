#pragma once
#include <QFluentWidgets/Components/Widgets/CardWidget.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Widgets/Separator.h>
#include <QFluentWidgets/Components/Widgets/FlipView.h>

class AppCard : public CardWidget
{
    Q_OBJECT

public:
    explicit AppCard(const QString& icon, const QString& title, const QString& content, QWidget* parent = nullptr);

private slots:
    void onMoreButtonClicked();

private:
    IconWidget* iconWidget_;
    BodyLabel* titleLabel_;
    CaptionLabel* contentLabel_;
    PushButton* openButton_;
    TransparentToolButton* moreButton_;
    QHBoxLayout* hBoxLayout_;
    QVBoxLayout* vBoxLayout_;
};

class EmojiCard : public ElevatedCardWidget
{
    Q_OBJECT

public:
    explicit EmojiCard(const QString& iconPath, QWidget* parent = nullptr);

private:
    ImageLabel* iconWidget_;
    CaptionLabel* label_;
    QVBoxLayout* vBoxLayout_;
};

class StatisticsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWidget(const QString& title, const QString& value, QWidget* parent = nullptr);

private:
    CaptionLabel* titleLabel_;
    BodyLabel* valueLabel_;
    QVBoxLayout* vBoxLayout_;
};

class AppInfoCard : public SimpleCardWidget
{
    Q_OBJECT

public:
    explicit AppInfoCard(QWidget* parent = nullptr);

private:
    ImageLabel* iconLabel_;
    TitleLabel* nameLabel_;
    PrimaryPushButton* installButton_;
    HyperlinkLabel* companyLabel_;
    StatisticsWidget* scoreWidget_;
    VerticalSeparator* separator_;
    StatisticsWidget* commentWidget_;
    BodyLabel* descriptionLabel_;
    PillPushButton* tagButton_;
    TransparentToolButton* shareButton_;
    QHBoxLayout* hBoxLayout_;
    QVBoxLayout* vBoxLayout_;
    QHBoxLayout* topLayout_;
    QHBoxLayout* statisticsLayout_;
    QHBoxLayout* buttonLayout_;

    void initLayout();
};

class GalleryCard : public HeaderCardWidget
{
    Q_OBJECT

public:
    explicit GalleryCard(QWidget* parent = nullptr);

    HorizontalFlipView* flipView() { return flipView_; }

private:
    HorizontalFlipView* flipView_;
    TransparentToolButton* expandButton_;
};

class DescriptionCard : public HeaderCardWidget
{
    Q_OBJECT

public:
    explicit DescriptionCard(QWidget* parent = nullptr);

private:
    BodyLabel* descriptionLabel_;
};

class SystemRequirementCard : public HeaderCardWidget
{
    Q_OBJECT

public:
    explicit SystemRequirementCard(QWidget* parent = nullptr);

private:
    BodyLabel* infoLabel_;
    IconWidget* successIcon_;
    HyperlinkLabel* detailButton_;
};