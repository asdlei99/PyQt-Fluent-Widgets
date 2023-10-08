#include "../Common/Translator.h"
#include "TextInterface.h"
#include <QFluentWidgets/Components/Widgets/LineEdit.h>
#include <QFluentWidgets/Components/Widgets/TextEdit.h>
#include <QFluentWidgets/Components/Widgets/SpinBox.h>
#include <QCompleter>

TextInterface::TextInterface(QWidget* parent)
    : GalleryInterface(translator.text, "<QFluentWidgets/Components/Widgets>", parent)
{
    setObjectName("textInterface");

    // line edit
    LineEdit* lineEdit = new LineEdit(this);
    lineEdit->setText(tr("ko no dio da!"));
    lineEdit->setClearButtonEnabled(true);
    addExampleCard(tr("A LineEdit with a clear button"), lineEdit,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/line_edit/demo.py");

    // line edit with completer
    SearchLineEdit* lineEditWithCompleter = new SearchLineEdit(this);
    lineEditWithCompleter->setPlaceholderText(tr("Type a stand name"));
    lineEditWithCompleter->setClearButtonEnabled(true);
    lineEditWithCompleter->setFixedWidth(230);
    QStringList stands = {"Star Platinum",  "Hierophant Green", "Made in Haven",     "King Crimson",
                          "Silver Chariot", "Crazy diamond",    "Metallica",         "Another One Bites The Dust",
                          "Heaven's Door",  "Killer Queen",     "The Grateful Dead", "Stone Free",
                          "The World",      "Sticky Fingers",   "Ozone Baby",        "Love Love Deluxe",
                          "Hermit Purple",  "Gold Experience",  "King Nothing",      "Paper Moon King",
                          "Scary Monster",  "Mandom",           "20th Century Boy",  "Tusk Act 4",
                          "Ball Breaker",   "Sex Pistols",      "D4C • Love Train",  "Born This Way",
                          "SOFT & WET",     "Paisley Park",     "Wonder of U",       "Walking Heart",
                          "Cream Starter",  "November Rain",    "Smooth Operators",  "The Matte Kudasai"};
    QCompleter* completer = new QCompleter(stands, lineEditWithCompleter);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setMaxVisibleItems(10);
    lineEditWithCompleter->setCompleter(completer);

    addExampleCard(tr("A autosuggest line edit"), lineEditWithCompleter,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/line_edit/demo.py");

    // password line edit
    auto passwordLineEdit = new PasswordLineEdit(this);
    passwordLineEdit->setPlaceholderText(tr("Enter your password"));
    passwordLineEdit->setFixedWidth(230);
    addExampleCard(tr("A password line edit"), passwordLineEdit,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/line_edit/demo.py");

    // spin box
    addExampleCard(tr("A SpinBox with a spin button"), new SpinBox(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/spin_box/demo.py");

    // double spin box
    addExampleCard(tr("A DoubleSpinBox with a spin button"), new DoubleSpinBox(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/spin_box/demo.py");

    // date edit
    addExampleCard(tr("A DateEdit with a spin button"), new DateEdit(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/spin_box/demo.py");

    // time edit
    addExampleCard(tr("A TimeEdit with a spin button"), new TimeEdit(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/spin_box/demo.py");

    // date time edit
    addExampleCard(tr("A DateTimeEdit with a spin button"), new DateTimeEdit(this),
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/spin_box/demo.py");

    // text edit
    TextEdit* textEdit = new TextEdit(this);
    textEdit->setMarkdown("## Steel Ball Run \n * Johnny Joestar 🦄 \n * Gyro Zeppeli 🐴 ");
    textEdit->setFixedHeight(150);
    addExampleCard(tr("A simple TextEdit"), textEdit,
                   "https://github.com/zhiyiYo/PyQt-Fluent-Widgets/blob/master/examples/text/line_edit/demo.py",
                   1);
}