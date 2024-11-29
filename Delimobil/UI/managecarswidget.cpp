#include "managecarswidget.h"
#include "ui_managecarswidget.h"
#include "../services/carservice.h"
#include "careditordialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

ManageCarsWidget::ManageCarsWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::ManageCarsWidget)
{
    ui->setupUi(this);

    // Кнопка "Добавить машину"
    QPushButton *addCarButton = new QPushButton("Добавить машину", this);
    addCarButton->setStyleSheet(
        "QPushButton { font-size: 14px; padding: 10px; }"
    );
    ui->verticalLayout->addWidget(addCarButton);
    connect(addCarButton, &QPushButton::clicked, this, &ManageCarsWidget::onAddCarButtonClicked);

    setAllTools(this);
}

ManageCarsWidget::~ManageCarsWidget()
{
    delete ui;
}

void ManageCarsWidget::displayCars()
{
    QVector<Car> cars = CarService::instance().getAllCars();
    qDebug() << cars.size();
    QGridLayout *layout = ui->layout;

    layout->setHorizontalSpacing(18);
    layout->setVerticalSpacing(20);
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    int row = 0, col = 0, maxCols = 5;

    for (Car &car : cars) {
        createCarCard(car, layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}

void ManageCarsWidget::updateCarList(const QVector<Car> &cars)
{
    // Очистка текущего отображения
    QLayoutItem *child;
    while ((child = ui->layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Отображение машин из нового списка
    int row = 0, col = 0, maxCols = 5;

    for (Car car : cars) {
        createCarCard(car, ui->layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}

void ManageCarsWidget::createCarCard(Car &car, QGridLayout *layout, int row, int col)
{
    QString projectPath = "C:\\Users\\vital\\OneDrive\\My projects\\5 semester\\Qt projects\\Delimobil";

    QWidget *commonWidget = new QWidget(this);
    QVBoxLayout *commonLayout = new QVBoxLayout(commonWidget);

    // Карточка
    QWidget *cardWidget = new QWidget(commonWidget);
    cardWidget->setFixedSize(205, 250);
    if (!car.isBlocked())
        cardWidget->setStyleSheet("QWidget { background-color: #f5f5f5; border-radius: 20px; }");
    else
        cardWidget->setStyleSheet("QWidget { background-color: #CFD8DC; border-radius: 20px; }");

    QLabel *imageLabel = new QLabel(cardWidget);
    QPixmap pixmap(car.getImagePath());
    imageLabel->setPixmap(pixmap.scaled(205, 120, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    imageLabel->setFixedSize(205, 120);

    QLabel *nameLabel = new QLabel(car.getName(), cardWidget);
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setStyleSheet("QLabel { font-size: 16px; font-weight: bold }");

    QLabel *infoLabel = new QLabel(QString("Класс: %1\nПривод: %2\nМощность: %3 л.с.")
                                       .arg(car.getCategory())
                                       .arg(car.getDriveType())
                                       .arg(car.getPower()), cardWidget);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("QLabel { font-size: 14px; }");

    QLabel *blockedLabel = nullptr;
    if (car.isBlocked()) {
        QPair<QDate, QDate> blockedPeriod = car.getBlockedPeriod();
        QString blockedLine = "\tЗаблокирована с " + blockedPeriod.first.toString() + " по " + blockedPeriod.second.toString() + "\t";
        blockedLabel = new QLabel(blockedLine, cardWidget);
        blockedLabel->setAlignment(Qt::AlignCenter);
        blockedLabel->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: red }");
        blockedLabel->setWordWrap(true);
    }

    Car *carPtr = AuthorizedUser::instance().getCar();
    bool hasRent = carPtr != nullptr && carPtr->equals(car);

    QPushButton *editButton = new QPushButton("Изменить", cardWidget);
    editButton->setStyleSheet(
        QString("QPushButton { background-color: %1; border-radius: 10px }")
            .arg(hasRent ? "#C0C0C0" : "#f9ecb6"));
    editButton->setCursor(Qt::PointingHandCursor);
    QPushButton *deleteButton = new QPushButton("Удалить", cardWidget);
    deleteButton->setStyleSheet(
        QString("QPushButton { background-color: %1; border-radius: 10px }")
            .arg(hasRent ? "#C0C0C0" : "#E48F94"));
    deleteButton->setCursor(Qt::PointingHandCursor);

    editButton->setEnabled(!hasRent);
    deleteButton->setEnabled(!hasRent);

    QVBoxLayout *cardLayout = new QVBoxLayout(cardWidget);
    cardLayout->setSpacing(5);
    cardLayout->setContentsMargins(0, 0, 0, 0);

    cardLayout->addWidget(imageLabel);
    cardLayout->addWidget(nameLabel);
    if (blockedLabel == nullptr) {
//        cardLayout->addStretch();
        cardLayout->addWidget(infoLabel);
//        cardLayout->addStretch();
    } else {
        cardLayout->addWidget(infoLabel);
        cardLayout->addWidget(blockedLabel);
    }

    commonLayout->addWidget(cardWidget);
    commonLayout->addWidget(editButton);
    commonLayout->addWidget(deleteButton);

    layout->addWidget(commonWidget, row, col);

    connect(editButton, &QPushButton::clicked, [this, car]() {
        CarEditorDialog carEditorDialog(this, &car);
        carEditorDialog.updateCarDetails(&car);
        if (carEditorDialog.exec() == QDialog::Accepted) {
            qDebug() << "Машина подтверждена";
        } else {
            qDebug() << "Машина отменена";
        }
        updateCarList(CarService::instance().getAllCars());
    });
    connect(deleteButton, &QPushButton::clicked, [this, car]() {
        confirmDeleteCar(car);
    });
}

void ManageCarsWidget::onAddCarButtonClicked()
{
    CarEditorDialog carEditorDialog(this);
    if (carEditorDialog.exec() == QDialog::Accepted) {
        qDebug() << "Машина подтверждена";
        updateCarList(CarService::instance().getAllCars());
    } else {
        qDebug() << "Машина отменена";
    }
}

void ManageCarsWidget::confirmDeleteCar(const Car &car) {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Удаление машины");
    msgBox.setText(QString("Вы уверены, что хотите удалить %1?").arg(car.getName()));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    // Получение кнопок и явное приведение типа
    QPushButton *yesButton = qobject_cast<QPushButton*>(msgBox.button(QMessageBox::Yes));
    QPushButton *noButton = qobject_cast<QPushButton*>(msgBox.button(QMessageBox::No));

    // Настройка кнопок
    if (yesButton) {
        yesButton->setText("Да");
        yesButton->setStyleSheet(
            "background-color: #A0EACD; color: #333; border: none; "
            "padding: 5px 10px; font-size: 14px; border-radius: 5px;"
        );
        yesButton->setCursor(Qt::PointingHandCursor);
    }
    if (noButton) {
        noButton->setText("Нет");
        noButton->setStyleSheet(
            "background-color: #A0EACD; color: #333; border: none; "
            "padding: 5px 10px; font-size: 14px; border-radius: 5px;"
        );
        noButton->setCursor(Qt::PointingHandCursor);
    }

    // Применение стиля ко всему диалогу
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #F5F5F5; border-radius: 10px; }"
        "QMessageBox QLabel { font-size: 14px; color: #333; }"
        "QPushButton:hover { background-color: #88D4B0; }"
        "QPushButton:pressed { background-color: #76C7A0; }"
    );

    // Отображение диалога
    if (msgBox.exec() == QMessageBox::Yes) {
        CarService::instance().deleteCar(car);
        updateCarList(CarService::instance().getAllCars());
    }
}



