#include "../../Shared/Widget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFileSystemModel>
#include <QFluentWidgets/Components/Widgets/TreeView.h>
#include <QHBoxLayout>
#include <QWidget>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        auto hBoxLayout = new QHBoxLayout(this);

        // Create TreeView widget
        TreeView* view = new TreeView(this);

        // Create QFileSystemModel and set root path
        QFileSystemModel* model = new QFileSystemModel(this);
        model->setRootPath(".");

        // Set model for the TreeView
        view->setModel(model);

        // Add TreeView widget to the hBoxLayout
        hBoxLayout->addWidget(view);

        // Set contents margins for the hBoxLayout
        hBoxLayout->setContentsMargins(0, 0, 0, 0);

        // Resize the widget to the desired size
        resize(700, 600);
    };
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