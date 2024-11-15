#include "basewidget.h"
#include "ui_basewidget.h"
#include <QPushButton>

BaseWidget::BaseWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {
}

BaseWidget::~BaseWidget()
{
    delete ui;
}

void BaseWidget::setAllTools(BaseWidget *widget) {
    QString projectPath = "C:\\Users\\vital\\OneDrive\\My projects\\5 semester\\Qt projects\\Delimobil";
    QLabel *profileIcon = new QLabel(widget);
    QPixmap pixmap(projectPath + "\\images\\user.png");
    profileIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    profileIcon->setFixedSize(35, 35);
    profileIcon->move(1200, 10);
    profileIcon->setAttribute(Qt::WA_Hover);
    profileIcon->setMouseTracking(true);
    profileIcon->installEventFilter(widget);
}

bool BaseWidget::eventFilter(QObject *obj, QEvent *event) {
    // Проверяем, что событие произошло для QLabel и это клик мыши
    if (obj->inherits("QLabel") && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            emit profileIconClicked();  // Вызываем нужный слот при клике
            return true;  // Указываем, что событие обработано
        }
    }
    return QWidget::eventFilter(obj, event);  // Обработка остальных событий по умолчанию
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
