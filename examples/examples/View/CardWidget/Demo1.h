#pragma once

#include <QWidget>
#include <QFluentWidgets/Components/Layout/FlowLayout.h>

class Demo1 : public QWidget
{
    Q_OBJECT

public:
    explicit Demo1(QWidget* parent = nullptr);

private:
    FlowLayout* flowLayout_;

    void addCard(const QString& iconPath);
};