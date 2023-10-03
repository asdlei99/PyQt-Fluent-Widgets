#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/ProgressRing.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QVBoxLayout>
#include <QTimer>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr)
        : Widget(parent),
          button(new ToggleToolButton(new FluentIcon(FluentIcon::PauseBold))),
          progressRing(new ProgressRing),
          inProgressRing(new IndeterminateProgressRing),
          timer(new QTimer(this))
    {
        auto vBoxLayout = new QVBoxLayout(this);

        progressRing->setValue(50);
        progressRing->setTextVisible(true);

        vBoxLayout->addWidget(progressRing, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(inProgressRing, 0, Qt::AlignHCenter);
        vBoxLayout->addWidget(button, 0, Qt::AlignHCenter);
        vBoxLayout->setContentsMargins(30, 30, 30, 30);
        resize(400, 400);

        connect(button, &QToolButton::clicked, this, &Demo::onButtonClicked);
        connect(timer, &QTimer::timeout, this, &Demo::onTimeout);
        timer->start(200);
    }

private slots:
    void onButtonClicked(bool checked)
    {
        if (progressRing->isPaused()) {
            button->setIcon(new FluentIcon(FluentIcon::PauseBold));
            progressRing->resume();
            inProgressRing->resume();
            timer->start(200);
        } else {
            button->setIcon(new FluentIcon(FluentIcon::PlaySolid));
            progressRing->pause();
            inProgressRing->pause();
            timer->stop();
        }
    }

    void onTimeout() { progressRing->setValue((progressRing->value() + 1) % 101); }

private:
    ToggleToolButton* button;
    ProgressRing* progressRing;
    IndeterminateProgressRing* inProgressRing;
    QTimer* timer;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"