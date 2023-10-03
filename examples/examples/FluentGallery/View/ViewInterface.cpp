#include "../Common/Translator.h"
#include "../Common/StyleSheet.h"
#include "ViewInterface.h"
#include <QFluentWidgets/Components/Widgets/FlipView.h>
#include <QFluentWidgets/Components/Widgets/TreeView.h>
#include <QFluentWidgets/Components/Widgets/ListView.h>
#include <QFluentWidgets/Components/Widgets/TableView.h>
#include <QHeaderView>

ViewInterface::ViewInterface(QWidget* parent)
    : GalleryInterface(translator.view, "<QFluentWidgets/Components/Widgets>", parent)
{
    setObjectName("viewInterface");

    // list view
    auto listFrame = new ListFrame(this);
    addExampleCard(tr("A simple ListView"), listFrame,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/view/list_view/demo.py");

    // table view
    auto tableFrame = new TableFrame(this);
    addExampleCard(tr("A simple TableView"), tableFrame,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/view/table_view/demo.py");

    // tree view
    auto treeFrame1 = new TreeFrame(this);
    addExampleCard(tr("A simple TreeView"), treeFrame1,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/view/tree_view/demo.py");

    auto treeFrame2 = new TreeFrame(this, true);
    addExampleCard(tr("A TreeView with Multi-selection enabled"), treeFrame2,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/view/tree_view/demo.py");

    // flip view
    auto flipView = new HorizontalFlipView(this);
    flipView->addImages({":/gallery/images/Shoko1.jpg", ":/gallery/images/Shoko2.jpg", ":/gallery/images/Shoko3.jpg",
                          ":/gallery/images/Shoko4.jpg"});
    addExampleCard(tr("Flip view"), flipView,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/view/flip_view/demo.py");
}

Frame::Frame(QWidget* parent) : QFrame(parent)
{
    hBoxLayout_ = new QHBoxLayout(this);
    hBoxLayout_->setContentsMargins(0, 8, 0, 0);
    setObjectName("frame");
    StyleSheet::applyTo(StyleSheet::ViewInterface, this);
}

void Frame::addWidget(QWidget* widget)
{
    hBoxLayout_->addWidget(widget);
}

ListFrame::ListFrame(QWidget* parent) : Frame(parent)
{
    listWidget_ = new ListWidget(this);
    addWidget(listWidget_);

    QStringList stands = {
        tr("Star Platinum"),  tr("Hierophant Green"), tr("Made in Haven"),     tr("King Crimson"),
        tr("Silver Chariot"), tr("Crazy diamond"),    tr("Metallica"),         tr("Another One Bites The Dust"),
        tr("Heaven's Door"),  tr("Killer Queen"),     tr("The Grateful Dead"), tr("Stone Free"),
        tr("The World"),      tr("Sticky Fingers"),   tr("Ozone Baby"),        tr("Love Love Deluxe"),
        tr("Hermit Purple"),  tr("Gold Experience"),  tr("King Nothing"),      tr("Paper Moon King"),
        tr("Scary Monster"),  tr("Mandom"),           tr("20th Century Boy"),  tr("Tusk Act 4"),
        tr("Ball Breaker"),   tr("Sex Pistols"),      tr("D4C • Love Train"),  tr("Born This Way"),
        tr("SOFT & WET"),     tr("Paisley Park"),     tr("Wonder of U"),       tr("Walking Heart"),
        tr("Cream Starter"),  tr("November Rain"),    tr("Smooth Operators"),  tr("The Matte Kudasai")};

    for (const QString& stand : stands) {
        listWidget_->addItem(new QListWidgetItem(stand));
    }

    setFixedSize(300, 380);
}

TreeFrame::TreeFrame(QWidget* parent, bool enableCheck) : Frame(parent)
{
    tree_ = new TreeWidget(this);
    addWidget(tree_);


    QTreeWidgetItem* item1 = new QTreeWidgetItem(QStringList(tr("JoJo 1 - Phantom Blood")));
    item1->addChildren({new QTreeWidgetItem(QStringList(tr("Jonathan Joestar"))),
                        new QTreeWidgetItem(QStringList(tr("Dio Brando"))),
                        new QTreeWidgetItem(QStringList(tr("Will A. Zeppeli")))});
    tree_->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem(QStringList(tr("JoJo 3 - Stardust Crusaders")));
    QTreeWidgetItem* item21 = new QTreeWidgetItem(QStringList(tr("Jotaro Kujo")));
    item21->addChildren({new QTreeWidgetItem(QStringList("空条承太郎")), new QTreeWidgetItem(QStringList("空条蕉太狼")),
                         new QTreeWidgetItem(QStringList("阿强")), new QTreeWidgetItem(QStringList("卖鱼强")),
                         new QTreeWidgetItem(QStringList("那个无敌的男人"))});
    item2->addChild(item21);
    tree_->addTopLevelItem(item2);

    tree_->expandAll();
    tree_->setHeaderHidden(true);

    setFixedSize(300, 380);

        if (enableCheck) {
        QTreeWidgetItemIterator it(tree_);
        while (*it) {
            (*it)->setCheckState(0, Qt::Unchecked);
            ++it;
        }
    }
}

TableFrame::TableFrame(QWidget* parent):Frame(parent) {
    table_ = new TableWidget(this);
    addWidget(table_);

    table_->verticalHeader()->hide();
    table_->setColumnCount(5);
    table_->setRowCount(60);
    table_->setHorizontalHeaderLabels({tr("Title"), tr("Artist"), tr("Album"), tr("Year"), tr("Duration")});

    QList<QList<QString>> songInfos = {
        {"かばん", "aiko", "かばん", "2004", "5:04"},
        {"爱你", "王心凌", "爱你", "2004", "3:39"},
        {"星のない世界", "aiko", "星のない世界/横顔", "2007", "5:30"},
        {"横顔", "aiko", "星のない世界/横顔", "2007", "5:06"},
        {"秘密", "aiko", "秘密", "2008", "6:27"},
        {"シアワセ", "aiko", "秘密", "2008", "5:25"},
        {"二人", "aiko", "二人", "2008", "5:00"},
        {"スパークル", "RADWIMPS", "君の名は。", "2016", "8:54"},
        {"なんでもないや", "RADWIMPS", "君の名は。", "2016", "3:16"},
        {"前前前世", "RADWIMPS", "人間開花", "2016", "4:35"},
        {"恋をしたのは", "aiko", "恋をしたのは", "2016", "6:02"},
        {"夏バテ", "aiko", "恋をしたのは", "2016", "4:41"},
        {"もっと", "aiko", "もっと", "2016", "4:50"},
        {"問題集", "aiko", "もっと", "2016", "4:18"},
        {"半袖", "aiko", "もっと", "2016", "5:50"},
        {"ひねくれ", "鎖那", "Hush a by little girl", "2017", "3:54"},
        {"シュテルン", "鎖那", "Hush a by little girl", "2017", "3:16"},
        {"愛は勝手", "aiko", "湿った夏の始まり", "2018", "5:31"},
        {"ドライブモード", "aiko", "湿った夏の始まり", "2018", "3:37"},
        {"うん。", "aiko", "湿った夏の始まり", "2018", "5:48"},
        {"キラキラ", "aikoの詩。", "2019", "5:08", "aiko"},
        {"恋のスーパーボール", "aiko", "aikoの詩。", "2019", "4:31"},
        {"磁石", "aiko", "どうしたって伝えられないから", "2021", "4:24"},
        {"食べた愛", "aiko", "食べた愛/あたしたち", "2021", "5:17"},
        {"列車", "aiko", "食べた愛/あたしたち", "2021", "4:18"},
        {"花の塔", "さユり", "花の塔", "2022", "4:35"},
        {"夏恋のライフ", "aiko", "夏恋のライフ", "2022", "5:03"},
        {"あかときリロード", "aiko", "あかときリロード", "2023", "4:04"},
        {"荒れた唇は恋を失くす", "aiko", "今の二人をお互いが見てる", "2023", "4:07"},
        {"ワンツースリー", "aiko", "今の二人をお互いが見てる", "2023", "4:47"},
    };

    songInfos += songInfos;

    for (int i = 0; i < songInfos.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            table_->setItem(i, j, new QTableWidgetItem(songInfos[i][j]));
        }
    }

    setFixedSize(650, 440);
    table_->resizeColumnsToContents();
}
