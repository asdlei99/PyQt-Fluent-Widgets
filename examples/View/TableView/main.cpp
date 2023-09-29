#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Components/Widgets/TableView.h>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QWidget>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto tableView = new TableWidget(this);

        // NOTE: select row on right-click
        // tableView->setSelectRightClickedRow(true);

        tableView->setWordWrap(false);
        tableView->setRowCount(60);
        tableView->setColumnCount(5);

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
                tableView->setItem(i, j, new QTableWidgetItem(songInfos[i][j]));
            }
        }

        tableView->verticalHeader()->hide();
        tableView->setHorizontalHeaderLabels({"Title", "Artist", "Album", "Year", "Duration"});
        tableView->resizeColumnsToContents();

        // tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        // tableView->setSortingEnabled(true);

        hBoxLayout->addWidget(tableView);
        hBoxLayout->setContentsMargins(0, 0, 0, 0);
        resize(635, 700);
    }
};

int main(int argc, char* argv[])
{
    // enable dpi scale
#if (QT_VERSION > QT_VERSION_CHECK(5, 14, 0))
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"