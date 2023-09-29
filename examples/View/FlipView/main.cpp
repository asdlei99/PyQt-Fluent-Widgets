#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Widgets/FlipView.h>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QWidget>
#include <QPainter>

using namespace qfluentwidgets;

class CustomFlipImageDelegate: public FlipImageDelegate
{
    Q_OBJECT

public:
    using FlipImageDelegate::FlipImageDelegate;

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        FlipImageDelegate::paint(painter, option, index);
        painter->save();

        // draw mask
        painter->setBrush(QColor(255, 255, 255, 200));
        painter->setPen(Qt::NoPen);
        QRect rect(option.rect.x(), option.rect.y(), 200, option.rect.height());
        painter->drawRect(rect);

        // draw text
        painter->setPen(Qt::black);
        painter->setFont(getFont(16, QFont::Bold));
        painter->drawText(rect, Qt::AlignCenter, "🥰\n硝子酱一级棒卡哇伊");

        painter->restore();
    }
};

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto flipView = new HorizontalFlipView(this);

        // adjust view size
        // flipView->setItemSize(QSize(320, 180));
        // flipView->setFixedSize(QSize(320, 180));

        // !NOTE: use custom delegate
        // flipView->setItemDelegate(new CustomFlipImageDelegate(flipView));

        // add images
        flipView->addImages({
            "Resource/images/shoko2.jpg",
            "Resource/images/shoko3.jpg",
            "Resource/images/shoko4.jpg",
            "Resource/images/shoko5.jpg"
        });

        // adjust border radius
        // flipView->setBorderRadius(15);
        // flipView->setFixedSize(QSize(710, 270));
        // flipView->setSpacing(15);

        hBoxLayout->addWidget(flipView, 0, Qt::AlignCenter);
        resize(600, 600);
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