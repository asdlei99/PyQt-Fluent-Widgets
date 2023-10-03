#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDebug>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/StyleSheet.h>
#include <QFluentWidgets/Components/DialogBox/Dialog.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        this->resize(950, 500);

        auto btn = new PrimaryPushButton("Click Me-dialog", this);
        auto btn1 = new PrimaryPushButton("Click Me-messageBox", this);

        QString title = "Are you sure you want to delete the folder?";
        QString content = "If you delete the \"Music\" folder from the list, the folder will no longer appear in the "
                       "list, but will not be deleted.";

        connect(btn, &PrimaryPushButton::clicked, this, [=]() {
            auto w = new Dialog(title, content, this);
            if (w->exec())
                qDebug() << ("Yes button is pressed");
            else
                qDebug() << ("Cancel button is pressed");
        });
        connect(btn1, &PrimaryPushButton::clicked, this, [=]() {
            auto w = new MessageBox(title, content, this);
            if (w->exec())
                qDebug() << ("Yes button is pressed");
            else
                qDebug() << ("Cancel button is pressed");
        });

        auto layout = new QVBoxLayout(this);
        layout->addWidget(btn, 0, Qt::AlignHCenter);
        layout->addWidget(btn1, 0, Qt::AlignHCenter);
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