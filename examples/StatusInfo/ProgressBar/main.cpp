#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/ProgressBar.h>
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
          progressBar(new ProgressBar),
          inProgressBar(new IndeterminateProgressBar),
          timer(new QTimer(this))
    {
        auto vBoxLayout = new QVBoxLayout(this);

        progressBar->setValue(50);

        vBoxLayout->addWidget(progressBar, 0);
        vBoxLayout->addWidget(inProgressBar, 0);
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
        if (inProgressBar->isPaused()) {
            button->setIcon(new FluentIcon(FluentIcon::PauseBold));
            inProgressBar->resume();
            progressBar->resume();
            timer->start(200);
        } else {
            button->setIcon(new FluentIcon(FluentIcon::PlaySolid));
            inProgressBar->pause();
            progressBar->pause();
            timer->stop();
        }
    }

    void onTimeout() { progressBar->setValue((progressBar->value() + 1) % 101); }

private:
    ToggleToolButton* button;
    ProgressBar* progressBar;
    IndeterminateProgressBar* inProgressBar;
    QTimer* timer;
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