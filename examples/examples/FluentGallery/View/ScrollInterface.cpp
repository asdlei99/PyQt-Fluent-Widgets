#include "ScrollInterface.h"
#include "../Common/Translator.h"
#include <QFluentWidgets/Components/Widgets/PipsPager.h>
#include <QFluentWidgets/Components/Widgets/ScrollArea.h>
#include <QFluentWidgets/Components/Widgets/ToolTip.h>
#include <QScrollBar>

ScrollInterface::ScrollInterface(QWidget* parent)
    : GalleryInterface(translator.scroll, "<QFluentWidgets/Components/Widgets/ScrollArea.h>", parent)
{
    setObjectName("scrollInterface");

    // scroll area
    ScrollArea* w = new ScrollArea(this);
    ImageLabel* label = new ImageLabel(":/gallery/images/chidanta2.jpg", this);
    label->scaledToWidth(775);
    label->setBorderRadius(8, 8, 8, 8);

    w->horizontalScrollBar()->setValue(0);
    w->setWidget(label);
    w->setFixedSize(775, 430);

    auto card = addExampleCard(
        tr("Smooth scroll area"), w,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/scroll/scroll_area/demo.py");
    card->card()->installEventFilter(new ToolTipFilter(card->card(), 500));
    card->card()->setToolTip(tr("Chitanda Eru is too hot 🥵"));
    card->card()->setToolTipDuration(2000);

    // smooth scroll area
    SmoothScrollArea* w2 = new SmoothScrollArea(this);
    ImageLabel* label2 = new ImageLabel(":/gallery/images/chidanta3.jpg", this);
    label2->setBorderRadius(8, 8, 8, 8);

    w2->setWidget(label2);
    w2->setFixedSize(660, 540);

    card = addExampleCard(
        tr("Smooth scroll area implemented by animation"), w2,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/scroll/scroll_area/demo.py");
    card->card()->installEventFilter(new ToolTipFilter(card->card(), 500));
    card->card()->setToolTip(tr("Chitanda Eru is so hot 🥵🥵"));
    card->card()->setToolTipDuration(2000);

    // single direction scroll area
    SingleDirectionScrollArea* w3 = new SingleDirectionScrollArea(this, Qt::Horizontal);
    ImageLabel* label3 = new ImageLabel(":/gallery/images/chidanta4.jpg", this);
    label3->setBorderRadius(8, 8, 8, 8);

    w3->setWidget(label3);
    w3->setFixedSize(660, 498);

    card = addExampleCard(
        tr("Single direction scroll scroll area"), w3,
        "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/scroll/scroll_area/demo.py");
    card->card()->installEventFilter(new ToolTipFilter(card->card(), 500));
    card->card()->setToolTip(tr("Chitanda Eru is so hot 🥵🥵🥵"));
    card->card()->setToolTipDuration(2000);

    // pips pager
    HorizontalPipsPager* pager = new HorizontalPipsPager(this);
    pager->setPageNumber(15);
    pager->setPreviousButtonDisplayMode(PipsPager::Always);
    pager->setNextButtonDisplayMode(PipsPager::Always);
    card =
        addExampleCard(tr("Pips pager"), pager,
                       "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/scroll/pips_pager/demo.py");
    card->topLayout()->setContentsMargins(12, 20, 12, 20);
}