#pragma once

#include <QWidget>
#include "Card.h"
#include <QFluentWidgets/Components/Widgets/AcrylicBrush.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/FlipView.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>
#include <QVBoxLayout>

class LightBox : public QWidget
{
    Q_OBJECT

public:
    explicit LightBox(QWidget* parent = nullptr);

    void setCurrentIndex(int index);

protected:
    void paintEvent(QPaintEvent* e) override;
    void resizeEvent(QResizeEvent* e) override;
    void showEvent(QShowEvent* e) override;

private:
    AcrylicBrush acrylicBrush;

    QVBoxLayout* vBoxLayout_;
    TransparentToolButton* closeButton_;
    HorizontalFlipView* flipView_;
    BodyLabel* nameLabel_;
    PillPushButton* pageNumButton_;
};

class Demo3 : public QWidget
{
    Q_OBJECT

public:
    explicit Demo3(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* e) override;

private slots:
    void showLightBox();

private:
    QHBoxLayout* hBoxLayout_;
    SingleDirectionScrollArea* scrollArea_;
    QWidget* view_;

    QVBoxLayout* vBoxLayout_;
    AppInfoCard* appCard_;
    GalleryCard* galleryCard_;
    DescriptionCard* descriptionCard_;
    SystemRequirementCard* systemCard_;

    LightBox* lightBox_;
};