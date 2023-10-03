#pragma once

#include "GalleryInterface.h"
#include <QFrame>

class ListWidget;
class TableWidget;
class TreeWidget;

class ViewInterface : public GalleryInterface
{
    Q_OBJECT

public:
    explicit ViewInterface(QWidget* parent = nullptr);
};

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget* parent = nullptr);

    void addWidget(QWidget* widget);

private:
    QHBoxLayout* hBoxLayout_;
};

class ListFrame : public Frame
{
    Q_OBJECT

public:
    explicit ListFrame(QWidget* parent = nullptr);

private:
    ListWidget* listWidget_;
};

class TreeFrame : public Frame
{
    Q_OBJECT

public:
    explicit TreeFrame(QWidget* parent = nullptr, bool enableCheck = false);

private:
    TreeWidget* tree_;
};

class TableFrame : public Frame
{
    Q_OBJECT

public:
    explicit TableFrame(QWidget* parent = nullptr);

private:
    TableWidget* table_;
};