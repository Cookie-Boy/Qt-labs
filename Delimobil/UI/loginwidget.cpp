#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QPainter>
#include <QRegExp>
#include <QRegExpValidator>

LoginWidget::LoginWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
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
    // Устанавливаем курсор для всех QPushButton в MainWindow
    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
    }

//    QRegExp regExp("[0-9]*");  // Разрешает только цифры
//    QRegExpValidator *validator = new QRegExpValidator(regExp, this);
//    ui->lineEdit_4->setValidator(validator);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginButtonClicked);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Установка основного фона
    painter.fillRect(rect(), QColor("#D3D3D3"));  // светло-серый фон

    // Серый треугольник (на заднем плане)
    painter.setBrush(QColor("#ffffff"));
    painter.setPen(Qt::NoPen);
    QPolygon greyTriangle;
    greyTriangle << QPoint(width() / 2, height())       // верхняя точка немного ниже верха
                 << QPoint(0, height() / 2)           // нижний левый угол
                 << QPoint(0, height());    // нижний правый угол
    painter.drawPolygon(greyTriangle);

    // Мятный треугольник (на переднем плане)
    painter.setBrush(QColor("#A0EACD"));
    QPolygon mintTriangle;
    mintTriangle << QPoint(width() / 2, height()) // нижняя точка по центру
                 << QPoint(width(), height() / 2) // точка справа в середине высоты
                 << QPoint(width(), height());    // нижний правый угол
    painter.drawPolygon(mintTriangle);
}

void LoginWidget::onLoginButtonClicked() {
    QString email = ui->lineEdit_4->text();
    if (!UserService::instance().authorizeUser(email)) {
        emit userNotFound();
    }
}
