#include "managecarswidget.h"
#include "ui_managecarswidget.h"
#include "../services/carservice.h"
#include "addcardialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

ManageCarsWidget::ManageCarsWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::ManageCarsWidget)
{
    ui->setupUi(this);

//    setAllTools(this);

    // Кнопка "Добавить машину"
    QPushButton *addCarButton = new QPushButton("Добавить машину", this);
    addCarButton->setStyleSheet(
        "QPushButton { font-size: 14px; padding: 10px; }"
    );
    ui->verticalLayout->addWidget(addCarButton);
    connect(addCarButton, &QPushButton::clicked, this, &ManageCarsWidget::onAddCarButtonClicked);

    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
        button->setStyleSheet("QPushButton { background-color: #A0EACD; border-radius: 10px; }");
    }
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
    QWidget *cardWidget = new QWidget(this);
    cardWidget->setFixedSize(205, 300);
    cardWidget->setStyleSheet("QWidget { background-color: #f5f5f5; border-radius: 20px; }");

    QLabel *imageLabel = new QLabel(cardWidget);
    QPixmap pixmap(car.getImagePath());
    imageLabel->setPixmap(pixmap.scaled(205, 120, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    imageLabel->setFixedSize(205, 120);

    QLabel *nameLabel = new QLabel(car.getName(), cardWidget);
    nameLabel->setAlignment(Qt::AlignCenter);

    QLabel *infoLabel = new QLabel(QString("Класс: %1\nПривод: %2\nМощность: %3 л.с.")
                                       .arg(car.getCategory())
                                       .arg(car.getDriveType())
                                       .arg(car.getPower()), cardWidget);
    infoLabel->setAlignment(Qt::AlignCenter);

    QPushButton *editButton = new QPushButton("Изменить", cardWidget);
    editButton->setStyleSheet("QPushButton { background-color: #A0EACD; border-radius: 10px }");
    QPushButton *deleteButton = new QPushButton("Удалить", cardWidget);
    deleteButton->setStyleSheet("QPushButton { background-color: #E48F94; border-radius: 10px }");

    QVBoxLayout *cardLayout = new QVBoxLayout(cardWidget);
    cardLayout->setSpacing(10);
    cardLayout->setContentsMargins(5, 5, 5, 5);

    cardLayout->addWidget(imageLabel);
    cardLayout->addWidget(nameLabel);
    cardLayout->addWidget(infoLabel);
    cardLayout->addWidget(editButton);
    cardLayout->addWidget(deleteButton);

    layout->addWidget(cardWidget, row, col);

    connect(editButton, &QPushButton::clicked, [this, car]() {
        emit changeCarButtonClicked(&car);
//        openAddCarWidget(&car);
    });
    connect(deleteButton, &QPushButton::clicked, [this, car]() {
        confirmDeleteCar(car);
    });
}

void ManageCarsWidget::onAddCarButtonClicked()
{
    AddCarDialog addCarDialog(this);
    if (addCarDialog.exec() == QDialog::Accepted) {
        qDebug() << "Машина подтверждена";
    } else {
        qDebug() << "Машина отменена";
    }
}

void ManageCarsWidget::confirmDeleteCar(const Car &car)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Удаление машины",
        QString("Вы уверены, что хотите удалить %1?").arg(car.getName()),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Удаление машины из базы данных
//        CarService::instance().deleteCar(car);
        updateCarList(CarService::instance().getAllCars());
    }
}
