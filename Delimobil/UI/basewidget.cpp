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
    const QList<QLabel *> labels = widget->findChildren<QLabel *>();
    for (QLabel *label : labels) {
        if (label->objectName().startsWith("icon")) {
            label->deleteLater();
        }
    }

    QString projectPath = "C:\\Users\\vital\\OneDrive\\My projects\\5 semester\\Qt projects\\Delimobil";
    QLabel *profileIcon = new QLabel(widget);
    QPixmap pixmap(projectPath + "\\images\\user.png");
    profileIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    profileIcon->setFixedSize(35, 35);
    profileIcon->move(1190, 10);
    profileIcon->setAttribute(Qt::WA_Hover);
    profileIcon->setMouseTracking(true);
    profileIcon->setObjectName("icon_profile");
    profileIcon->installEventFilter(widget);
    profileIcon->setCursor(Qt::PointingHandCursor);

    QLabel *exitIcon = new QLabel(widget);
    pixmap.load(projectPath + "\\images\\exit.png");
    exitIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    exitIcon->setFixedSize(35, 35);
    exitIcon->move(1240, 10);
    exitIcon->setAttribute(Qt::WA_Hover);
    exitIcon->setMouseTracking(true);
    exitIcon->setObjectName("icon_exit");
    exitIcon->installEventFilter(widget);
    exitIcon->setCursor(Qt::PointingHandCursor);

    if (AuthorizedUser::instance().getUser() != nullptr && AuthorizedUser::instance().getUser()->getRole() == "Admin") {
        QLabel *adminIcon = new QLabel(widget);
        pixmap.load(projectPath + "\\images\\admin.png");
        adminIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        adminIcon->setFixedSize(35, 35);
        adminIcon->move(1140, 10);
        adminIcon->setAttribute(Qt::WA_Hover);
        adminIcon->setMouseTracking(true);
        adminIcon->setObjectName("icon_admin");
        adminIcon->installEventFilter(widget);
        adminIcon->setCursor(Qt::PointingHandCursor);
    }

    if (AuthorizedUser::instance().getCar() != nullptr) {
        QLabel *rentIcon = new QLabel(widget);
        pixmap.load(projectPath + "\\images\\car-key.png");
        rentIcon->setPixmap(pixmap.scaled(35, 35, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        rentIcon->setFixedSize(35, 35);
        rentIcon->move(100, 10);
        rentIcon->setAttribute(Qt::WA_Hover);
        rentIcon->setMouseTracking(true);
        rentIcon->setObjectName("icon_rent");
        rentIcon->installEventFilter(widget);
        rentIcon->setCursor(Qt::PointingHandCursor);
    }

    foreach (QPushButton *button, widget->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
        button->setStyleSheet("QPushButton { background-color: #A0EACD; border-radius: 10px; }");
    }
}

void BaseWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Установка основного фона
    painter.fillRect(rect(), QColor("#D3D3D3"));  // светло-серый фон

    // Белый треугольник
    painter.setBrush(QColor("#ffffff"));
    painter.setPen(Qt::NoPen);
    QPolygon greyTriangle;
    greyTriangle << QPoint(width(), 0)
                 << QPoint(width() - width() / 3, 0)
                 << QPoint(width(), height() / 10);
    painter.drawPolygon(greyTriangle);

    // Мятный треугольник
    painter.setBrush(QColor("#A0EACD"));
    QPolygon mintTriangle;
    mintTriangle << QPoint(0, 0)
                 << QPoint(width() / 3, 0)
                 << QPoint(0, height() / 10);
    painter.drawPolygon(mintTriangle);
    QWidget::paintEvent(event);
}

bool BaseWidget::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QLabel *label = qobject_cast<QLabel *>(obj);  // Проверяем, является ли объект QLabel
            if (label) {
                if (label->objectName() == "icon_profile") {
                    emit BaseWidget::profileIconClicked();  // Сигнал для иконки профиля
                    return true;
                } else if (label->objectName() == "icon_exit") {
                    emit BaseWidget::exitIconClicked();  // Сигнал для иконки выхода
                    return true;
                } else if (label->objectName() == "icon_admin") {
                    emit BaseWidget::adminIconClicked();
                    return true;
                } else if (label->objectName() == "icon_rent") {
                    emit BaseWidget::rentIconClicked();
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
