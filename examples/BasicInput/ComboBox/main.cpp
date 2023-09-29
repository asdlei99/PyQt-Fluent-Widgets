#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/FluentApp.h>
#include <QFluentWidgets/Common/StyleSheet.h>
#include <QFluentWidgets/Components/Widgets/ComboBox.h>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto layout = new QVBoxLayout(this);
        auto comboBox = new ComboBox(this);
        auto editableComboBox = new EditableComboBox(this);

        QList<QString> items = {"shoko 🥰", "西宫硝子", "aiko", "柳井爱子"};
        comboBox->addItems(items);
        editableComboBox->addItems(items);

        connect(comboBox, &ComboBox::currentTextChanged, this, [=](const QString& text) { qDebug() << text; });
        connect(editableComboBox, &EditableComboBox::currentTextChanged, this, [=](const QString& text) { qDebug() << text; });

        layout->addWidget(comboBox, 0, Qt::AlignHCenter);
        layout->addWidget(editableComboBox, 0, Qt::AlignHCenter);

        setFixedSize(600, 600);
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