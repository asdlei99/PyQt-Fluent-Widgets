#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Components/Widgets/TextEdit.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto textEdit = new TextEdit();

        textEdit->setFixedSize(300, 300);
        textEdit->setPlaceholderText("Enter something...");

        hBoxLayout->addWidget(textEdit, 0, Qt::AlignCenter);
        hBoxLayout->setAlignment(Qt::AlignCenter);
        resize(400, 400);

        if (!isDarkTheme()) {
            setStyleSheet("Demo{background:rgb(242,242,242)}");
        }
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