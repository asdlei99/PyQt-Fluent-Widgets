#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Components/Widgets/ListView.h>
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
        auto listView = new ListWidget(this);

        // NOTE: select row on right-click
        // listView->setSelectRightClickedRow(true);

        // listView->setAlternatingRowColors(true);

        QList<QString> stands = {
            "金之星", "绿色法皇", "天堂制造", "绯红之王",
            "银色战车", "疯狂钻石", "壮烈成仁", "败者食尘",
            "黑蚊子多", "杀手皇后", "金属制品", "石之自由",
            "砸瓦鲁多", "钢链手指", "臭氧宝宝", "华丽挚爱",
            "隐者之紫", "黄金体验", "虚无之王", "纸月之王",
            "骇人恶兽", "男子领域", "20世纪男孩", "牙 Act 4",
            "铁球破坏者", "性感手枪", "D4C • 爱之列车", "天生完美",
            "软又湿", "佩斯利公园", "奇迹于你", "行走的心",
            "护霜旅行者", "十一月雨", "调情圣手", "片刻静候"
        };

        for (auto &stand: stands) {
            auto item = new QListWidgetItem(stand);
            item->setIcon(QIcon(":/qfluentwidgets/images/logo.png"));
            item->setCheckState(Qt::Unchecked);
            listView->addItem(item);
        }

        hBoxLayout->addWidget(listView);
        hBoxLayout->setContentsMargins(0, 0, 0, 0);
        resize(300, 400);
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