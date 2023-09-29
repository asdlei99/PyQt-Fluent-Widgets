#include "../Common/Translator.h"
#include "LayoutInterface.h"
#include <QFluentWidgets/Components/Layout/FlowLayout.h>

LayoutInterface::LayoutInterface(QWidget* parent)
    : GalleryInterface(translator.layout, "<QFluentWidgets/Components/Layout>", parent)
{
    setObjectName("layoutInterface");

    addExampleCard(tr("Flow layout without animation"), createWidget(),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/layout/flow_layout/demo.py", 1);

    addExampleCard(tr("Flow layout with animation"), createWidget(true),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/layout/flow_layout/demo.py", 1);
}

QWidget* LayoutInterface::createWidget(bool ani)
{
    QStringList texts = {tr("Star Platinum"),   tr("Hierophant Green"),
                         tr("Silver Chariot"),  tr("Crazy diamond"),
                         tr("Heaven's Door"),   tr("Killer Queen"),
                         tr("Gold Experience"), tr("Sticky Fingers"),
                         tr("Sex Pistols"),     tr("Dirty Deeds Done Dirt Cheap")};

    QWidget* widget = new QWidget();
    FlowLayout* layout = new FlowLayout(widget, ani);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setVerticalSpacing(20);
    layout->setHorizontalSpacing(10);

    for (const QString& text : texts) {
        layout->addWidget(new PushButton(text));
    }

    return widget;
}
