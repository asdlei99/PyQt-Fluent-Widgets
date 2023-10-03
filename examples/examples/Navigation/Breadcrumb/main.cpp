#include "../../Shared/Widget.h"
#include <QApplication>
#include <QFluentWidgets/Common/Font.h>
#include <QFluentWidgets/Components/Navigation/Breadcrumb.h>
#include <QFluentWidgets/Components/Widgets/Label.h>
#include <QFluentWidgets/Components/Widgets/LineEdit.h>
#include <QFluentWidgets/Components/Widgets/ToolButton.h>
#include <QStackedWidget>
#include <QVBoxLayout>

using namespace qfluentwidgets;

class Demo : public Widget
{
    Q_OBJECT
public:
    Demo(QWidget* parent = nullptr) : Widget(parent)
    {
        breadcrumbBar = new BreadcrumbBar(this);
        stackedWidget = new QStackedWidget(this);
        lineEdit = new LineEdit(this);
        auto addButton = new ToolButton(new FluentIcon(FluentIcon::Send), this);

        auto vBoxLayout = new QVBoxLayout(this);
        auto lineEditLayout = new QHBoxLayout();

        connect(addButton, &QToolButton::clicked, this, [=] { addInterface(lineEdit->text()); });
        connect(lineEdit, &QLineEdit::returnPressed, this, [=] { addInterface(lineEdit->text()); });
        lineEdit->setPlaceholderText("Enter the name of interface");

        // NOTE: adjust the size of breadcrumb item
        ::setFont(breadcrumbBar, 26);
        breadcrumbBar->setSpacing(20);
        connect(breadcrumbBar, &BreadcrumbBar::currentItemChanged, this, &Demo::switchInterface);

        addInterface("Home");
        addInterface("Documents");

        vBoxLayout->setContentsMargins(20, 20, 20, 20);
        vBoxLayout->addWidget(breadcrumbBar);
        vBoxLayout->addWidget(stackedWidget);
        vBoxLayout->addLayout(lineEditLayout);

        lineEditLayout->addWidget(lineEdit, 1);
        lineEditLayout->addWidget(addButton);
        resize(500, 500);
    }

private slots:
    void addInterface(const QString& text)
    {
        if (text.isEmpty()) {
            return;
        }

        auto w = new SubtitleLabel(text, this);
        w->setObjectName(QString("%1").arg(counter++));
        w->setAlignment(Qt::AlignCenter);

        lineEdit->clear();
        stackedWidget->addWidget(w);
        stackedWidget->setCurrentWidget(w);

        breadcrumbBar->addItem(w->objectName(), text);
    }

    void switchInterface(const QString& objectName)
    {
        stackedWidget->setCurrentWidget(findChild<SubtitleLabel*>(objectName));
    }

private:
    QStackedWidget* stackedWidget;
    BreadcrumbBar* breadcrumbBar;
    LineEdit* lineEdit;
    int counter;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Demo w;
    w.show();

    return app.exec();
}

#include "main.moc"