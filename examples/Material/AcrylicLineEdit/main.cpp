#include "../../Shared/Widget.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Widgets/LineEdit.h>
#include <QFluentWidgets/Components/Widgets/PushButton.h>
#include <QHBoxLayout>
#include <QLabel>
#include <QCompleter>
#include <QStringList>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto button = new PushButton("Search", this);
        auto lineEdit = new AcrylicSearchLineEdit();

        QStringList stands = {"Star Platinum",  "Hierophant Green", "Made in Haven",     "King Crimson",
                              "Silver Chariot", "Crazy diamond",    "Metallica",         "Another One Bites The Dust",
                              "Heaven's Door",  "Killer Queen",     "The Grateful Dead", "Stone Free",
                              "The World",      "Sticky Fingers",   "Ozone Baby",        "Love Love Deluxe",
                              "Hermit Purple",  "Gold Experience",  "King Nothing",      "Paper Moon King",
                              "Scary Monster",  "Mandom",           "20th Century Boy",  "Tusk Act 4",
                              "Ball Breaker",   "Sex Pistols",      "D4C • Love Train",  "Born This Way",
                              "SOFT & WET",     "Paisley Park",     "Wonder of U",       "Walking Heart",
                              "Cream Starter",  "November Rain",    "Smooth Operators",  "The Matte Kudasai"};

        auto completer = new QCompleter(stands);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setMaxVisibleItems(10);
        lineEdit->setCompleter(completer);

        lineEdit->setFixedWidth(200);
        lineEdit->setPlaceholderText("Search stands");

        hBoxLayout->addWidget(lineEdit, 0, Qt::AlignCenter);
        hBoxLayout->addWidget(button, 0, Qt::AlignCenter);
        hBoxLayout->setAlignment(Qt::AlignCenter);
        resize(400, 400);
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