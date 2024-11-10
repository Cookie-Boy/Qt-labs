#include "basewidget.h"
#include "ui_basewidget.h"

BaseWidget::BaseWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {}

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
