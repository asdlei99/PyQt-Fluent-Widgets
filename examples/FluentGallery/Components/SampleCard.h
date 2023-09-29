#pragma once
#include <QFluentWidgets/Components/Widgets/CardWidget.h>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Layout/FlowLayout.h>

class SampleCard : public CardWidget
{
    Q_OBJECT
public:
    SampleCard(const QString& icon,
               const QString& title,
               const QString& content,
               const QString& routeKey,
               int index,
               QWidget* parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    int index_;
    QString routeKey_;
    IconWidget* iconWidget_;
    QLabel* titleLabel_;
    QLabel* contentLabel_;
    QHBoxLayout* hBoxLayout_;
    QVBoxLayout* vBoxLayout_;
};

class SampleCardView : public QWidget
{
    Q_OBJECT
public:
    SampleCardView(const QString& title, QWidget* parent = nullptr);

    void addSampleCard(const QString& icon,
                       const QString& title,
                       const QString& content,
                       const QString& routeKey,
                       int index);

private:
    QLabel* titleLabel_;
    QVBoxLayout* vBoxLayout_;
    FlowLayout* flowLayout_;
};