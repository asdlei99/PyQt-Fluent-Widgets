#pragma once

#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>
#include <QFrame>
#include <QLabel>
#include <QUrl>
#include <QVBoxLayout>

class LinkCard : public QFrame
{
    Q_OBJECT
public:
    explicit LinkCard(const QString& icon,
                      const QString& title,
                      const QString& content,
                      const QString& url,
                      QWidget* parent = nullptr);
    LinkCard(qfluentwidgets::FluentIconBase* icon,
                      const QString& title,
                      const QString& content,
                      const QString& url,
                      QWidget* parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QUrl url_;
    IconWidget* iconWidget_;
    QLabel* titleLabel_;
    QLabel* contentLabel_;
    IconWidget* urlWidget_;
    QVBoxLayout* vBoxLayout_;

    void init();
};

class LinkCardView : public SingleDirectionScrollArea
{
    Q_OBJECT
public:
    explicit LinkCardView(QWidget* parent = nullptr);

    void addCard(const QString& icon, const QString& title, const QString& content, const QString& url);
    void addCard(qfluentwidgets::FluentIconBase* icon, const QString& title, const QString& content, const QString& url);

private:
    QWidget* view_;
    QHBoxLayout* hBoxLayout_;
};