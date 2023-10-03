#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QFluentWidgets/Components/Widgets/InfoBar.h>
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
        auto hBoxLayout = new QHBoxLayout(this);
        PushButton* button1 = new PushButton("Information", this);
        PushButton* button2 = new PushButton("Success", this);
        PushButton* button3 = new PushButton("Warning", this);
        PushButton* button4 = new PushButton("Error", this);

        hBoxLayout->addWidget(button1);
        hBoxLayout->addWidget(button2);
        hBoxLayout->addWidget(button3);
        hBoxLayout->addWidget(button4);

        connect(button1, &PushButton::clicked, this, &Demo::createInfo);
        connect(button2, &PushButton::clicked, this, &Demo::createSuccess);
        connect(button3, &PushButton::clicked, this, &Demo::createWarning);
        connect(button4, &PushButton::clicked, this, &Demo::createError);

        resize(600, 600);
    }

private slots:
    void createInfo()
    {
        QString content =
            "My name is kira yoshikake, 33 years old. Living in the villa area northeast of duwangting, unmarried. I "
            "work in Guiyou chain store. Every day I have to work overtime until 8 p.m. to go home. I don't smoke. The "
            "wine is only for a taste. Sleep at 11 p.m. for 8 hours a day. Before I go to bed, I must drink a cup of "
            "warm milk, then do 20 minutes of soft exercise, get on the bed, and immediately fall asleep. Never leave "
            "fatigue and stress until the next day. Doctors say I'm normal.";

        auto w = new InfoBar(new InfoBarIcon(InfoBarIcon::Info), "Title", content, Qt::Vertical, this,
                             InfoBarPosition::TopRight, 2000);
        w->addWidget(new PushButton("Action", w));
        w->show();
    }

    void createSuccess()
    {
        InfoBar::success("Lesson 4", "With respect, let's advance towards a new stage of the spin", Qt::Horizontal,
                         this, InfoBarPosition::Top, 2000);
    }

    void createWarning()
    {
        InfoBar::warning("Lesson 3", "Believe in the spin, just keep believing!", Qt::Horizontal, this,
                         InfoBarPosition::TopLeft, 2000, false);
    }

    void createError()
    {
        InfoBar::error("Lesson 5", "最短的捷径就是绕远路，绕远路才是我的最短捷径", Qt::Horizontal, this,
                       InfoBarPosition::BottomRight, -1, true);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"