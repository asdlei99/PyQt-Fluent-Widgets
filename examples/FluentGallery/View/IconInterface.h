#pragma once
#include "GalleryInterface.h"
#include <QFluentWidgets/Common/Icon.h>
#include <QFluentWidgets/Components/Widgets/LineEdit.h>
#include <QFluentWidgets/Components/Widgets/IconWidget.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>
#include <QFluentWidgets/Components/Layout/FlowLayout.h>
#include <QFrame>
#include <QLabel>
#include "../Common/Trie.h"

class IconLineEdit : public SearchLineEdit
{
    Q_OBJECT

public:
    explicit IconLineEdit(QWidget* parent = nullptr);

signals:
    void search(const QString& text);
};

class IconCard : public QFrame
{
    Q_OBJECT
public:
    explicit IconCard(qfluentwidgets::FluentIcon* icon, QWidget* parent = nullptr);

    void setSelected(bool isSelected, bool force = false);

signals:
    void clicked(const QString& iconName);

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    qfluentwidgets::FluentIcon* icon_;
    bool isSelected_;
    IconWidget* iconWidget_;
    QLabel* nameLabel_;
    QVBoxLayout* vBoxLayout_;
};

class IconInfoPanel : public QFrame
{
    Q_OBJECT
public:
    explicit IconInfoPanel(qfluentwidgets::FluentIcon* icon, QWidget* parent = nullptr);

public slots:
    void setIcon(qfluentwidgets::FluentIcon* icon);

private:
    QLabel* nameLabel_;
    IconWidget* iconWidget_;
    QLabel* iconNameTitleLabel_;
    QLabel* iconNameLabel_;
    QLabel* enumNameTitleLabel_;
    QLabel* enumNameLabel_;
    QVBoxLayout* vBoxLayout_;
};

class IconCardView : public QWidget
{
    Q_OBJECT
public:
    explicit IconCardView(QWidget* parent = nullptr);

public slots:
    void setSelectedIcon(const QString& iconName);
    void search(QString keyword);
    void showAllIcons();

private:
    void addIcon(qfluentwidgets::FluentIcon* icon);
    void initWidget();
    void setQss();

    Trie trie_;
    StrongBodyLabel* iconLibraryLabel_;
    IconLineEdit* searchLineEdit_;

    QFrame* view_;
    SmoothScrollArea* scrollArea_;
    QWidget* scrollWidget_;
    IconInfoPanel* infoPanel_;

    QVBoxLayout* vBoxLayout_;
    QHBoxLayout* hBoxLayout_;
    FlowLayout* flowLayout_;

    QList<IconCard*> cards_;
    QList<QString> icons_;
    int currentIndex_{-1};
};

class IconInterface: public GalleryInterface {
    Q_OBJECT

public:
    explicit IconInterface(QWidget* parent = nullptr);

private:
    IconCardView* iconView_;
};