#pragma once

#include <QPair>
#include <QQueue>
#include <QString>
#include <QVector>

class Trie
{
private:
public:
    Trie(): children(26, nullptr) {}

    void insert(const QString& key, int value);

    int get(const QString& key, int defaultValue = -1);

    QVector<QPair<QString, int>> items(const QString& prefix);

private:
    Trie* searchPrefix(const QString& prefix);

    QString key;
    int value{0};
    bool isEnd{false};
    QVector<Trie*> children;
};
