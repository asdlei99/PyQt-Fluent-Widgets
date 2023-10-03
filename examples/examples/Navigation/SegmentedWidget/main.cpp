#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Navigation/SegmentedWidget.h>
#include <QStackedWidget>
#include <QTimer>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class SubInterface : public BodyLabel
{
    Q_OBJECT

public:
    explicit SubInterface(const QString& text, QWidget* parent = nullptr) : BodyLabel(text, parent)
    {
        ::setFont(this, 20);
        setObjectName(text);
        setAlignment(Qt::AlignCenter);
        setStyleSheet(QString("QLabel{background:%1; border-radius: 8px}").arg(isDarkTheme() ? "#202020" : "#f2f2f2"));
    }
};

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr)
        : Widget(parent),
          vBoxLayout(new QVBoxLayout(this)),
          pivot(new SegmentedWidget(this)),
          stackedWidget(new QStackedWidget(this))
    {
        auto songInterface = new SubInterface("Song Interface", this);
        auto albumInterface = new SubInterface("Album Interface", this);
        auto artistInterface = new SubInterface("Artist Interface", this);

        addSubInterface(songInterface, "Song");
        addSubInterface(albumInterface, "Album");
        addSubInterface(artistInterface, "Artist");

        vBoxLayout->addWidget(pivot);
        vBoxLayout->addWidget(stackedWidget);
        vBoxLayout->setContentsMargins(30, 10, 30, 30);

        pivot->setCurrentItem(songInterface->objectName());

        resize(400, 400);
    }

private:
    void addSubInterface(SubInterface* interface, const QString& text)
    {
        stackedWidget->addWidget(interface);
        stackedWidget->addWidget(interface);

        auto item = pivot->addItem(interface->objectName(), text);
        connect(item, &PivotItem::itemClicked, this, [=](bool t) { this->stackedWidget->setCurrentWidget(interface); });
    }

private:
    QVBoxLayout* vBoxLayout;
    QStackedWidget* stackedWidget;
    SegmentedWidget* pivot;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"