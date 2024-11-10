#include "basewidget.h"
#include "ui_basewidget.h"
#include <QPushButton>

BaseWidget::BaseWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {
    QString buttonStyle = R"(
        QPushButton {
            background-color: #a6f2d1; /* Основной цвет кнопки */
            border: 1px solid transparent; /* Прозрачная рамка, чтобы border-radius сработал */
            border-radius: 20px;
            padding: 10px;
            color: black;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #87C4AA; /* Более темный цвет при наведении */
        }
    )";

    this->setStyleSheet(buttonStyle);
}

BaseWidget::~BaseWidget()
{
    delete ui;
}

void BaseWidget::navigateTo(QWidget *widget) {
        // Добавляем текущий виджет в историю и переходим к новому
        history.push(stackedWidget->currentWidget());
        stackedWidget->setCurrentWidget(widget);
    }

void BaseWidget::goBack() {
    // Переход назад, если есть история
    if (!history.isEmpty()) {
        QWidget *previousWidget = history.pop();
        stackedWidget->setCurrentWidget(previousWidget);
    }
}
