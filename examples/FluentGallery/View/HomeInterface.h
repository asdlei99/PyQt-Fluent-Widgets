#pragma once

#include "../Components/LinkCard.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class BannerWidget : public QWidget
{
    Q_OBJECT
public:
    BannerWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVBoxLayout* vBoxLayout_;
    QLabel* galleryLabel_;
    QPixmap banner_;
    LinkCardView* linkCardView_;
};

class HomeInterface : public ScrollArea
{
    Q_OBJECT
public:
    HomeInterface(QWidget* parent = nullptr);

private:
    BannerWidget* banner_;
    QWidget* view_;
    QVBoxLayout* vBoxLayout_;

    void loadSamples();
};