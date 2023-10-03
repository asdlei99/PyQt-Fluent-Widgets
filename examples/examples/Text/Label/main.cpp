#include "../../Shared/Widget.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QHBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
        vBoxLayout->setContentsMargins(30, 30, 30, 30);
        vBoxLayout->setSpacing(20);

        auto hyperlinkLabel = new HyperlinkLabel(QUrl("https://github.com/"), "GitHub");
        // hyperlinkLabel->setUrl('https://github->com/zhiyiYo/QMaterialWidgets');
        // hyperlinkLabel->setUnderlineVisible(True);
        // setFont(hyperlinkLabel, 18);

        vBoxLayout->addWidget(hyperlinkLabel);
        vBoxLayout->addWidget(new CaptionLabel("Caption"));
        vBoxLayout->addWidget(new BodyLabel("Body"));
        vBoxLayout->addWidget(new StrongBodyLabel("Body Strong"));
        vBoxLayout->addWidget(new SubtitleLabel("Subtitle"));
        vBoxLayout->addWidget(new TitleLabel("Title"));
        vBoxLayout->addWidget(new LargeTitleLabel("Title Large"));
        vBoxLayout->addWidget(new DisplayLabel("Display"));
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