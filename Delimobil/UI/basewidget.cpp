#include "basewidget.h"
#include "ui_basewidget.h"
#include "models/authorizeduser.h"
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
    profileIcon->move(1190, 10);
    profileIcon->setAttribute(Qt::WA_Hover);
    profileIcon->setMouseTracking(true);
    profileIcon->setObjectName("profileIcon");
    profileIcon->installEventFilter(widget);

    QLabel *exitIcon = new QLabel(widget);
    pixmap.load(projectPath + "\\images\\exit.png");
    exitIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    exitIcon->setFixedSize(35, 35);
    exitIcon->move(1240, 10);
    exitIcon->setAttribute(Qt::WA_Hover);
    exitIcon->setMouseTracking(true);
    exitIcon->setObjectName("exitIcon");
    exitIcon->installEventFilter(widget);

    if (AuthorizedUser::instance().getUser()->getRole() != "Admin")
        return;

    QLabel *adminIcon = new QLabel(widget);
    pixmap.load(projectPath + "\\images\\admin.png");
    adminIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    adminIcon->setFixedSize(35, 35);
    adminIcon->move(1140, 10);
    adminIcon->setAttribute(Qt::WA_Hover);
    adminIcon->setMouseTracking(true);
    adminIcon->setObjectName("adminIcon");
    adminIcon->installEventFilter(widget);
}

bool BaseWidget::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QLabel *label = qobject_cast<QLabel *>(obj);  // Проверяем, является ли объект QLabel
            if (label) {
                if (label->objectName() == "profileIcon") {
                    emit profileIconClicked();  // Сигнал для иконки профиля
                    return true;
                } else if (label->objectName() == "exitIcon") {
                    emit exitIconClicked();  // Сигнал для иконки выхода
                    return true;
                } else if (label->objectName() == "adminIcon") {
                    emit adminIconClicked();
                    return true;
                } else if (label->objectName() == "rentIcon") {
                    emit rentIconClicked();
                    return true;
                }
            }
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
