#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Components/Widgets/Flyout.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QWidget>

using namespace qfluentwidgets;

class CustomFlyoutView : public FlyoutViewBase
{
    Q_OBJECT

public:
    explicit CustomFlyoutView(QWidget* parent = nullptr) : FlyoutViewBase(parent)
    {
        auto vBoxLayout = new QVBoxLayout(this);
        auto label = new BodyLabel(
            "这是一场「试炼」，我认为这就是一场为了战胜过去的「试炼」，\n只有战胜了那些幼稚的过去，人才能有所成长。");
        auto button = new PrimaryPushButton("Action");

        button->setFixedWidth(140);
        vBoxLayout->setSpacing(12);
        vBoxLayout->setContentsMargins(20, 16, 20, 16);
        vBoxLayout->addWidget(label);
        vBoxLayout->addWidget(button);
    }
};

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        button1 = new PushButton("Click me", this);
        button2 = new PushButton("Click me", this);
        button3 = new PushButton("Click me", this);

        resize(750, 550);
        button1->setFixedWidth(150);
        button2->setFixedWidth(150);
        button3->setFixedWidth(150);
        hBoxLayout->addWidget(button1, 0, Qt::AlignBottom);
        hBoxLayout->addWidget(button2, 0, Qt::AlignBottom);
        hBoxLayout->addWidget(button3, 0, Qt::AlignBottom);
        hBoxLayout->setContentsMargins(30, 50, 30, 50);

        connect(button1, &QPushButton::clicked, this, &Demo::showFlyout1);
        connect(button2, &QPushButton::clicked, this, &Demo::showFlyout2);
        connect(button3, &QPushButton::clicked, this, &Demo::showCustomFlyout);
    }

private slots:
    void showFlyout1()
    {
        auto view = new FlyoutView("Lesson 4", "表达敬意吧，表达出敬意，然后迈向回旋的另一个全新阶段！",
                                   new InfoBarIcon(InfoBarIcon::Success), "", true, this);
        auto flyout = Flyout::make(view, button1, this, FlyoutAnimationType::DropDown);
        connect(view, &FlyoutView::closed, flyout, &Flyout::close);
    }

    void showFlyout2()
    {
        auto view = new FlyoutView("杰洛·齐贝林",
                                   "触网而起的网球会落到哪一侧，谁也无法知晓。\n如果那种时刻到来，我希望「女神」是存在"
                                   "的。\n这样的话，不管网球落到哪一边，我都会坦然接受的吧。",
                                   nullptr, "Resource/images/SBR.jpg", true, this);
        Flyout::make(view, button2, this, FlyoutAnimationType::PullUp);
    }

    void showCustomFlyout()
    {
        Flyout::make(new CustomFlyoutView(this), button3, this, FlyoutAnimationType::SlideLeft);
    }

private :
PushButton* button1;
    PushButton* button2;
    PushButton* button3;
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