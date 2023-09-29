#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/Flyout.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QFluentWidgets/Components/Widgets/SplitButton.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QGridLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto menu = new RoundMenu(this);
        menu->addAction(new Action(new FluentIcon(FluentIcon::SendFill), "Send"));
        menu->addAction(new Action(new FluentIcon(FluentIcon::Save), "Save"));

        auto gridLayout = new QGridLayout(this);

        // tool button
        auto toolButton = new ToolButton(new FluentIcon(FluentIcon::Setting), this);

        // drop down tool button
        auto dropDownButton = new DropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
        dropDownButton->setMenu(menu);

        // split tool button
        auto splitButton = new SplitToolButton(new FluentIcon(FluentIcon::GitHub), this);
        splitButton->setMenu(menu);

        // primary tool button
        auto primaryButton = new PrimaryToolButton(new FluentIcon(FluentIcon::Mail), this);

        // primary drop down tool button
        auto primaryDropDownButton = new PrimaryDropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
        primaryDropDownButton->setMenu(menu);

        // primary split tool button
        auto primarySplitButton = new PrimarySplitToolButton(new FluentIcon(FluentIcon::GitHub), this);
        primarySplitButton->setFlyout(new FlyoutView("Lesson 4",
                                                     "表达敬意吧，表达出敬意，然后迈向回旋的另一个全新阶段！",
                                                     new InfoBarIcon(InfoBarIcon::Success), "", true, this));

        // toggle tool button
        auto toggleButton = new ToggleToolButton(new FluentIcon(FluentIcon::GitHub), this);

        // transparent tool button
        auto transparentButton = new TransparentToolButton(new FluentIcon(FluentIcon::BookShelf), this);

        // transparent drop down tool button
        auto transparentDropDownButton = new TransparentDropDownToolButton(new FluentIcon(FluentIcon::Mail), this);
        transparentDropDownButton->setMenu(menu);

        // transparent toggle tool button
        auto transparentToggleButton = new TransparentToggleToolButton(new FluentIcon(FluentIcon::BookShelf), this);

        // pill tool button
        auto pillButton1 = new PillToolButton(new FluentIcon(FluentIcon::Calendar), this);
        auto pillButton2 = new PillToolButton(new FluentIcon(FluentIcon::Calendar), this);
        auto pillButton3 = new PillToolButton(new FluentIcon(FluentIcon::Calendar), this);
        pillButton2->setDisabled(true);
        pillButton3->setChecked(true);
        pillButton3->setDisabled(true);

        gridLayout->addWidget(toolButton, 0, 0, Qt::AlignHCenter);
        gridLayout->addWidget(dropDownButton, 0, 1, Qt::AlignHCenter);
        gridLayout->addWidget(splitButton, 0, 2, Qt::AlignHCenter);
        gridLayout->addWidget(primaryButton, 1, 0, Qt::AlignHCenter);
        gridLayout->addWidget(primaryDropDownButton, 1, 1, Qt::AlignHCenter);
        gridLayout->addWidget(primarySplitButton, 1, 2, Qt::AlignHCenter);
        gridLayout->addWidget(transparentButton, 2, 0, Qt::AlignHCenter);
        gridLayout->addWidget(transparentDropDownButton, 2, 1, Qt::AlignHCenter);
        gridLayout->addWidget(toggleButton, 3, 0, Qt::AlignHCenter);
        gridLayout->addWidget(transparentToggleButton, 3, 1, Qt::AlignHCenter);
        gridLayout->addWidget(pillButton1, 4, 0, Qt::AlignHCenter);
        gridLayout->addWidget(pillButton2, 4, 1, Qt::AlignHCenter);
        gridLayout->addWidget(pillButton3, 4, 2, Qt::AlignHCenter);

        resize(300, 300);
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
