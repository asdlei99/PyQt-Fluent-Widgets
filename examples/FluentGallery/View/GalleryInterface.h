#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>

class SeparatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SeparatorWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBar(const QString& title, const QString& subtitle, QWidget* parent = nullptr);

private:
    void init();

    TitleLabel* titleLabel_;
    CaptionLabel* subtitleLabel_;
    PushButton* documentButton_;
    PushButton* sourceButton_;
    ToolButton* themeButton_;
    SeparatorWidget* separator_;
    ToolButton* supportButton_;
    ToolButton* feedbackButton_;
    QVBoxLayout* vBoxLayout_;
    QHBoxLayout* buttonLayout_;
};

class ExampleCard : public QWidget
{
    Q_OBJECT
public:
    explicit ExampleCard(const QString& title,
                         QWidget* widget,
                         const QString& sourcePath,
                         int stretch = 0,
                         QWidget* parent = nullptr);

    QHBoxLayout* topLayout() { return topLayout_; }

    QFrame* card() { return card_; }

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    void initWidget();
    void initLayout();

    QWidget* widget_;
    int stretch_;

    StrongBodyLabel* titleLabel_;
    QFrame* card_;

    QFrame* sourceWidget_;
    QString sourcePath_;
    BodyLabel* sourcePathLabel_;
    IconWidget* linkIcon_;

    QVBoxLayout* vBoxLayout_;
    QVBoxLayout* cardLayout_;
    QHBoxLayout* topLayout_;
    QHBoxLayout* bottomLayout_;
};

class GalleryInterface : public ScrollArea
{
    Q_OBJECT
public:
    explicit GalleryInterface(const QString& title, const QString& subtitle, QWidget* parent = nullptr);

    ExampleCard* addExampleCard(const QString& title, QWidget* widget, const QString& sourcePath, int stretch = 0);
    void scrollToCard(int index);

protected:
    void resizeEvent(QResizeEvent* event) override;

protected:
    QWidget* view_;
    ToolBar* toolBar_;
    QVBoxLayout* vBoxLayout_;
};