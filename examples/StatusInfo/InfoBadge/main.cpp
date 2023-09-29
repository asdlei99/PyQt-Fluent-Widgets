#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/InfoBadge.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QHBoxLayout>
#include <QWidget>
#include <QDesktopServices>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);

        // info badge
        auto hBoxLayout1 = new QHBoxLayout();
        hBoxLayout1->setSpacing(20);
        hBoxLayout1->setSizeConstraint(QHBoxLayout::SetMinimumSize);

        hBoxLayout1->addStretch(1);
        hBoxLayout1->addWidget(InfoBadge::info("1"));
        hBoxLayout1->addWidget(InfoBadge::success("10"));
        hBoxLayout1->addWidget(InfoBadge::attention("100"));
        hBoxLayout1->addWidget(InfoBadge::warning("1000"));
        hBoxLayout1->addWidget(InfoBadge::error("10000"));
        hBoxLayout1->addWidget(InfoBadge::custom("1w+", "#005fb8", "#60cdff"));
        hBoxLayout1->addStretch(1);
        vBoxLayout->addLayout(hBoxLayout1);

        // dot info badge
        auto hBoxLayout2 = new QHBoxLayout();
        hBoxLayout2->setSpacing(20);
        hBoxLayout2->setSizeConstraint(QHBoxLayout::SetMinimumSize);

        hBoxLayout2->addStretch(1);
        hBoxLayout2->addWidget(DotInfoBadge::info());
        hBoxLayout2->addWidget(DotInfoBadge::success());
        hBoxLayout2->addWidget(DotInfoBadge::attention());
        hBoxLayout2->addWidget(DotInfoBadge::warning());
        hBoxLayout2->addWidget(DotInfoBadge::error());
        hBoxLayout2->addWidget(DotInfoBadge::custom("#005fb8", "#60cdff"));
        hBoxLayout2->addStretch(1);
        vBoxLayout->addLayout(hBoxLayout2);

        // icon info badge
        auto hBoxLayout3 = new QHBoxLayout();
        hBoxLayout3->setSpacing(20);
        hBoxLayout3->setSizeConstraint(QHBoxLayout::SetMinimumSize);

        hBoxLayout3->addStretch(1);
        hBoxLayout3->addWidget(IconInfoBadge::info(new FluentIcon(FluentIcon::AcceptMedium)));
        hBoxLayout3->addWidget(IconInfoBadge::success(new FluentIcon(FluentIcon::AcceptMedium)));
        hBoxLayout3->addWidget(IconInfoBadge::attention(new FluentIcon(FluentIcon::AcceptMedium)));
        hBoxLayout3->addWidget(IconInfoBadge::warning(new FluentIcon(FluentIcon::AcceptMedium)));
        hBoxLayout3->addWidget(IconInfoBadge::error(new FluentIcon(FluentIcon::AcceptMedium)));

        auto badge = IconInfoBadge::custom(new FluentIcon(FluentIcon::Ringer), "#005fb8", "#60cdff");
        badge->setFixedSize(32, 32);
        badge->setIconSize(QSize(16, 16));
        hBoxLayout3->addWidget(badge);

        hBoxLayout3->addStretch(1);
        vBoxLayout->addLayout(hBoxLayout3);

        // Using an InfoBadge in another control
        auto button = new ToolButton(new FluentIcon(FluentIcon::Basketball), this);
        vBoxLayout->addWidget(button, 0, Qt::AlignHCenter);
        InfoBadge::success("1", this, button);

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