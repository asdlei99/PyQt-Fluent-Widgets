#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/Flyout.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/SplitButton.h>
#include <QGridLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto menu = new RoundMenu(this);
        menu->addAction(new Action(new FluentIcon(FluentIcon::Basketball), "Basketball"));
        menu->addAction(new Action(new FluentIcon(FluentIcon::Album), "Sing"));
        menu->addAction(new Action(new FluentIcon(FluentIcon::Music), "Music"));

        auto gridLayout = new QGridLayout(this);

        // push button
        auto pushButton1 = new PushButton("Standard Push button", this);
        auto pushButton2 = new PushButton(new FluentIcon(FluentIcon::Folder), "Standard Push button with icon", this);

        // primary button
        auto primaryButton1 = new PrimaryPushButton("Primary button", this);
        auto primaryButton2 =
            new PrimaryPushButton(new FluentIcon(FluentIcon::Update), "Primary button with icon", this);

        // transparent button
        auto transparentButton1 = new TransparentPushButton("Transparent button", this);
        auto transparentButton2 =
            new TransparentPushButton(new FluentIcon(FluentIcon::BookShelf), "Transparent button with icon", this);

        // toggle button
        auto toggleButton1 = new TogglePushButton("Toggle button", this);
        auto toggleButton2 = new TogglePushButton(new FluentIcon(FluentIcon::Send), "Toggle button with icon", this);

        // transparent toggle button
        auto transparentToggleButton1 = new TransparentTogglePushButton("Transparent toggle button", this);
        auto transparentToggleButton2 = new TransparentTogglePushButton(new FluentIcon(FluentIcon::Send),
                                                                        "Transparent Toggle button with icon", this);

        // drop down button
        auto dropDownButton1 = new DropDownPushButton("Email", this);
        auto dropDownButton2 = new DropDownPushButton(new FluentIcon(FluentIcon::Mail), "Email", this);
        dropDownButton1->setMenu(menu);
        dropDownButton2->setMenu(menu);

        // primary drop down button
        auto primaryDropDownButton1 = new PrimaryDropDownPushButton("Email", this);
        auto primaryDropDownButton2 = new PrimaryDropDownPushButton(new FluentIcon(FluentIcon::Mail), "Email", this);
        primaryDropDownButton1->setMenu(menu);
        primaryDropDownButton2->setMenu(menu);

        // transparent drop down button
        auto transparentDropDownButton1 = new TransparentDropDownPushButton("Email", this);
        auto transparentDropDownButton2 =
            new TransparentDropDownPushButton(new FluentIcon(FluentIcon::Mail), "Email", this);
        transparentDropDownButton1->setMenu(menu);
        transparentDropDownButton2->setMenu(menu);

        // split button
        auto splitButton1 = new SplitPushButton("Email", this);
        auto splitButton2 = new SplitPushButton(new FluentIcon(FluentIcon::Mail), "Email", this);
        splitButton1->setMenu(menu);
        splitButton2->setFlyout(new FlyoutView("Lesson 4", "表达敬意吧，表达出敬意，然后迈向回旋的另一个全新阶段！",
                                               new InfoBarIcon(InfoBarIcon::Success), "", true, this));

        // split button
        auto primarySplitButton1 = new PrimarySplitPushButton("Email", this);
        auto primarySplitButton2 = new PrimarySplitPushButton(new FluentIcon(FluentIcon::Mail), "Email", this);
        primarySplitButton1->setMenu(menu);
        primarySplitButton2->setFlyout(new FlyoutView("Lesson 5", "最短的捷径就是绕远路，绕远路才是我的最短捷径",
                                                      new InfoBarIcon(InfoBarIcon::Warning), "", true, this));

        // hyperlink button
        QUrl url("https://github.com/zhiyiYo/QMaterialWidgets");
        auto hyperlinkButton1 = new HyperlinkPushButton("Hyperlink button", url, this);
        auto hyperlinkButton2 =
            new HyperlinkPushButton(new FluentIcon(FluentIcon::Link), "Hyperlink button", url, this);

        // pill button
        auto pillButton1 = new PillPushButton("Pill button", this);
        auto pillButton2 = new PillPushButton(new FluentIcon(FluentIcon::Calendar), "Pill button", this);

        gridLayout->addWidget(pushButton1, 0, 0, Qt::AlignHCenter);
        gridLayout->addWidget(pushButton2, 0, 1, Qt::AlignHCenter);
        gridLayout->addWidget(primaryButton1, 1, 0, Qt::AlignHCenter);
        gridLayout->addWidget(primaryButton2, 1, 1, Qt::AlignHCenter);
        gridLayout->addWidget(transparentButton1, 2, 0, Qt::AlignHCenter);
        gridLayout->addWidget(transparentButton2, 2, 1, Qt::AlignHCenter);
        gridLayout->addWidget(toggleButton1, 3, 0, Qt::AlignHCenter);
        gridLayout->addWidget(toggleButton2, 3, 1, Qt::AlignHCenter);
        gridLayout->addWidget(transparentToggleButton1, 4, 0, Qt::AlignHCenter);
        gridLayout->addWidget(transparentToggleButton2, 4, 1, Qt::AlignHCenter);
        gridLayout->addWidget(dropDownButton1, 5, 0, Qt::AlignHCenter);
        gridLayout->addWidget(dropDownButton2, 5, 1, Qt::AlignHCenter);
        gridLayout->addWidget(primaryDropDownButton1, 6, 0, Qt::AlignHCenter);
        gridLayout->addWidget(primaryDropDownButton2, 6, 1, Qt::AlignHCenter);
        gridLayout->addWidget(transparentDropDownButton1, 7, 0, Qt::AlignHCenter);
        gridLayout->addWidget(transparentDropDownButton2, 7, 1, Qt::AlignHCenter);
        gridLayout->addWidget(splitButton1, 8, 0, Qt::AlignHCenter);
        gridLayout->addWidget(splitButton2, 8, 1, Qt::AlignHCenter);
        gridLayout->addWidget(primarySplitButton1, 9, 0, Qt::AlignHCenter);
        gridLayout->addWidget(primarySplitButton2, 9, 1, Qt::AlignHCenter);
        gridLayout->addWidget(hyperlinkButton1, 10, 0, Qt::AlignHCenter);
        gridLayout->addWidget(hyperlinkButton2, 10, 1, Qt::AlignHCenter);
        gridLayout->addWidget(pillButton1, 11, 0, Qt::AlignHCenter);
        gridLayout->addWidget(pillButton2, 11, 1, Qt::AlignHCenter);

        resize(600, 700);
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
