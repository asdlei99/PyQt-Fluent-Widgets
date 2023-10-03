#include "../../Shared/Widget.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Widgets/Menu.h>
#include <QHBoxLayout>
#include <QLabel>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto label = new QLabel("Right click your mouse", this);

        qfluentwidgets::setFont(label, 20);
        hBoxLayout->addWidget(label, 0, Qt::AlignCenter);
        resize(300, 150);

        copyAction_ = new Action(new FluentIcon(FluentIcon::Copy), "Copy");
        copyAction_->setCheckable(true);
        copyAction_->setChecked(true);
    }

protected:
    void contextMenuEvent(QContextMenuEvent* event)
    {
        auto menu = new RoundMenu(this);
        // auto menu = new CheckableMenu(this, MenuIndicatorType::CHECK);

        // add actions
        menu->addAction(copyAction_);
        menu->addAction(new Action(new FluentIcon(FluentIcon::Cut), "Cut"));

        // add submenu
        auto subMenu = new RoundMenu("Add to", this);
        subMenu->setIcon(new FluentIcon(FluentIcon::Add));
        subMenu->addActions(QList<QAction *>{
            new Action(new FluentIcon(FluentIcon::Video), "Video"),
            new Action(new FluentIcon(FluentIcon::Music), "Music")
        });
        menu->addMenu(subMenu);

        // add actions
        menu->addActions(QList<QAction *>{
            new Action(new FluentIcon(FluentIcon::Paste), "Paste"),
            // NOTE: You can also use QAction
            new QAction(FluentIcon(FluentIcon::Cancel).icon(), "Undo")
        });

        // add separator
        menu->addSeparator();

        auto selectAllAct = new QAction("Select all");
        selectAllAct->setShortcut(QKeySequence("Ctrl+A"));
        menu->addAction(selectAllAct);

        // insert actions
        menu->insertAction(menu->actions().back(), new Action(new FluentIcon(FluentIcon::Setting), "Settings"));
        menu->insertActions(menu->actions().back(), QList<QAction*>{
            new Action(new FluentIcon(FluentIcon::Help), "Help"),
            new Action(new FluentIcon(FluentIcon::Feedback), "Feedback")
        });

        menu->exec(event->globalPos(), MenuAnimationType::DropDown);
    }

private:
    Action* copyAction_;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"