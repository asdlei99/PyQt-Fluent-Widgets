#pragma once

#include <QWidget>
#include <QVBoxLayout>

class Demo2 : public QWidget
{
    Q_OBJECT

public:
    explicit Demo2(QWidget* parent = nullptr);

private:
    QVBoxLayout* vBoxLayout_;

    void addCard(const QString& icon, const QString& title, const QString& content);
};