#include "Trie.h"


void Trie::insert(const QString& key, int value)
{
    QString lowerKey = key.toLower();

    Trie* node = this;
    for (QChar c : lowerKey) {
        int i = c.toLatin1() - 'a';
        if (!(0 <= i && i < 26)) {
            return;
        }

        if (!node->children[i]) {
            node->children[i] = new Trie();
        }

        node = node->children[i];
    }

    node->isEnd = true;
    node->key = lowerKey;
    node->value = value;
}

int Trie::get(const QString& key, int defaultValue)
{
    Trie* node = searchPrefix(key.toLower());
    if (!(node && node->isEnd)) {
        return defaultValue;
    }

    return node->value;
}

QVector<QPair<QString, int>> Trie::items(const QString& prefix)
{
    Trie* node = searchPrefix(prefix.toLower());
    if (!node) {
        return {};
    }

    QQueue<Trie*> q;
    QVector<QPair<QString, int>> result;
    q.enqueue(node);

    while (!q.isEmpty()) {
        node = q.dequeue();

        if (node->isEnd) {
            result.append({node->key, node->value});
        }

        for (Trie* child : node->children) {
            if (child) {
                q.enqueue(child);
            }
        }
    }

    return result;
}

Trie* Trie::searchPrefix(const QString& prefix)
{
    Trie* node = this;
    for (QChar c : prefix) {
        int i = c.toLatin1() - 'a';
        if (!(0 <= i && i < 26 && node->children[i])) {
            return nullptr;
        }

        node = node->children[i];
    }

    return node;
}