#pragma once

#include "GalleryInterface.h"

class BreadcrumbBar;
class Pivot;
class SegmentedWidget;
class QStackedWidget;
class ComboBox;
class CheckBox;
class TabBar;
class SpinBox;

class NavigationViewInterface : public GalleryInterface
{
    Q_OBJECT

public:
    explicit NavigationViewInterface(QWidget* parent = nullptr);

private:
    BreadcrumbBar* breadcrumb_;
};

class PivotInterface : public QWidget
{
    Q_OBJECT
public:
    explicit PivotInterface(Pivot *pivot, QWidget* parent = nullptr);

protected:
    Pivot* pivot_;
    QStackedWidget* stackedWidget_;
    QVBoxLayout* vBoxLayout_;
    QLabel* songInterface_;
    QLabel* albumInterface_;
    QLabel* artistInterface_;

    void addSubInterface(QLabel* widget, const QString& objectName, const QString& text);

private slots:
    void onCurrentIndexChanged(int index);
};

class SegmentedInterface : public PivotInterface
{
public:
    explicit SegmentedInterface(Pivot *pivot, QWidget* parent = nullptr);
};

class TabInterface : public QWidget
{
    Q_OBJECT

public:
    explicit TabInterface(QWidget* parent = nullptr);

private slots:
    void onDisplayModeChanged(int index);
    void onCurrentIndexChanged(int index);
    void addTab();
    void removeTab(int index);

private:
    int tabCount_;

    TabBar* tabBar_;
    QStackedWidget* stackedWidget_;
    QWidget* tabView_;
    QFrame* controlPanel_;

    CheckBox* movableCheckBox_;
    CheckBox* scrollableCheckBox_;
    CheckBox* shadowEnabledCheckBox_;
    QLabel* tabMaxWidthLabel_;
    SpinBox* tabMaxWidthSpinBox_;
    QLabel* closeDisplayModeLabel_;
    ComboBox* closeDisplayModeComboBox_;

    QHBoxLayout* hBoxLayout_;
    QVBoxLayout* vBoxLayout_;
    QVBoxLayout* panelLayout_;

    QLabel* songInterface_;
    QLabel* albumInterface_;
    QLabel* artistInterface_;

    void initWidget();
    void initLayout();
    void addSubInterface(QLabel* widget, const QString& objectName, const QString& text, const QString& iconPath);
    void connectSignalToSlot();
};