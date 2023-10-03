#include "../../Shared/Widget.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/CommandBar.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QHBoxLayout>
#include <QLabel>

using namespace qfluentwidgets;

class Demo1 : public Widget
{
    Q_OBJECT
public:
    Demo1(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        commandBar = new CommandBar(this);

        hBoxLayout->addWidget(commandBar, 0);

        // change button style
        commandBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        // commandBar->setMenuDropDown(false);
        // commandBar->setButtonTight(true);
        // ::setFont(commandBar, 14);

        addButton(new FluentIcon(FluentIcon::Add), "Add");
        commandBar->addSeparator();

        editAct = new Action(new FluentIcon(FluentIcon::Edit), "Edit", this);
        connect(editAct, &Action::triggered, this, &Demo1::onEdit);
        editAct->setCheckable(true);
        commandBar->addAction(editAct);

        addButton(new FluentIcon(FluentIcon::Copy), "Copy");
        addButton(new FluentIcon(FluentIcon::Share), "Share");

        // add custom widget
        commandBar->addWidget(createDropDownButton());

        // add hidden actions
        commandBar->addHiddenAction(new Action(new FluentIcon(FluentIcon::Scroll), "Sort"));

        auto settingAct = new Action(new FluentIcon(FluentIcon::Setting), "Settings");
        settingAct->setShortcut(QKeySequence::Save);
        commandBar->addHiddenAction(settingAct);

        resize(240, 40);
        setWindowTitle("Drag window");
    }

private slots:
    void onEdit(bool isChecked)
    {
        if (isChecked) {
            qDebug() << "Enter edit mode";
        } else {
            qDebug() << "Exit edit mode";
        }
    }

private:
    void addButton(FluentIconBase* icon, const QString& text)
    {
        auto action = new Action(icon, text, this);
        connect(action, &QAction::triggered, this, [=]() { qDebug() << text; });
        commandBar->addAction(action);
    }

    TransparentDropDownPushButton* createDropDownButton()
    {
        auto menu = new RoundMenu(this);
        menu->addActions(QList<QAction*>{
            new Action(new FluentIcon(FluentIcon::Copy), "Copy"),
            new Action(new FluentIcon(FluentIcon::Cut), "Cut"),
            new Action(new FluentIcon(FluentIcon::Paste), "Paste"),
            new Action(new FluentIcon(FluentIcon::Cancel), "Cancel"),
            new Action("Select all")
        });

        auto button = new TransparentDropDownPushButton(new FluentIcon(FluentIcon::Menu), "Menu");
        button->setMenu(menu);
        return button;
    }

    CommandBar* commandBar;
    Action* editAct;
};

class Demo2 : public QWidget
{
    Q_OBJECT

public:
    explicit Demo2() : QWidget()
    {
        auto hBoxLayout = new QHBoxLayout(this);
        imageLabel = new ImageLabel("Resource/images/pink_memory.jpg");

        imageLabel->scaledToWidth(380);
        connect(imageLabel, &ImageLabel::clicked, this, &Demo2::showCommandBar);
        hBoxLayout->addWidget(imageLabel);

        hBoxLayout->setContentsMargins(0, 80, 0, 0);
        setWindowTitle("Click image 👇️🥵");
        setWindowIcon(QIcon(":/qfluentwidgets/images/logo.png"));
        setStyleSheet("Demo2{background: white}");
    }

private slots:
    void showCommandBar()
    {
        auto view = new CommandBarView(this);

        view->addAction(new Action(new FluentIcon(FluentIcon::Share), "Share"));
        view->addAction(new Action(new FluentIcon(FluentIcon::Heart), "Favorite"));
        view->addAction(new Action(new FluentIcon(FluentIcon::Save), "Save"));
        view->addAction(new Action(new FluentIcon(FluentIcon::Delete), "Delete"));

        auto appAct = new Action(new FluentIcon(FluentIcon::Application), "App");
        appAct->setShortcut(QKeySequence::SelectAll);
        auto settingAct = new Action(new FluentIcon(FluentIcon::Setting), "Settings");
        appAct->setShortcut(QKeySequence::Save);

        view->addHiddenAction(appAct);
        view->addHiddenAction(settingAct);
        view->resizeToSuitableWidth();

        Flyout::make(view, imageLabel, this, FlyoutAnimationType::FadeIn);
    }

private:
    ImageLabel* imageLabel;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo1 w1;
    w1.show();

    Demo2 w2;
    w2.show();

    return app.exec();
}

#include "main.moc"