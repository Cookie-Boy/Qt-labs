#include "carrepository.h"

CarRepository::CarRepository() {}

CarRepository& CarRepository::instance() {
    static CarRepository instance;
    return instance;
}

long CarRepository::getFreeId() {
    QSqlQuery query;
    long freeId = 0;

    if (!query.exec("SELECT * FROM cars")) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        return -1;
    }

    while (query.next()) {
        long id = static_cast<long>(query.value(0).toLongLong());
        if (id != freeId)
            return freeId;
        freeId++;
    }

    return freeId;
}

bool CarRepository::saveCar(const Car& car) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO cars
        (id, name, rating, category, transmission, driveType, engineCapacity,
         power, hasSpaciousTrunk, hasHeatedSeats, hasHeatedSteeringWheel,
         hasParkingSensors)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )");

    long id = car.getId();
    if (id == -1)
        id = getFreeId();

    // Привязываем значения полей
    query.addBindValue(QVariant::fromValue(static_cast<long>(id)));
    query.addBindValue(car.getName());
    query.addBindValue(car.getRating());
    query.addBindValue(car.getCategory());
    query.addBindValue(car.getTransmission());
    query.addBindValue(car.getDriveType());
    query.addBindValue(car.getEngineCapacity());
    query.addBindValue(car.getPower());
    query.addBindValue(car.getHasSpaciousTrunk());
    query.addBindValue(car.getHasHeatedSeats());
    query.addBindValue(car.getHasHeatedSteeringWheel());
    query.addBindValue(car.getHasParkingSensors());

    // Выполняем запрос и проверяем на ошибки
    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении автомобиля:" << query.lastError().text();
        return false;
    }

    return true;
}

QVector<Car> CarRepository::findAll() {
    QVector<Car> cars;
    QSqlQuery query("SELECT * FROM cars");

    while (query.next()) {
        long id = static_cast<long>(query.value("id").toLongLong());
        QString name = query.value("name").toString();
        short rating = static_cast<short>(query.value("rating").toInt());
        QString category = query.value("category").toString();
        QString transmission = query.value("transmission").toString();
        QString driveType = query.value("driveType").toString();
        double engineCapacity = query.value("engineCapacity").toDouble();
        double power = query.value("power").toDouble();
        bool hasSpaciousTrunk = query.value("hasSpaciousTrunk").toBool();
        bool hasHeatedSeats = query.value("hasHeatedSeats").toBool();
        bool hasHeatedSteeringWheel = query.value("hasHeatedSteeringWheel").toBool();
        bool hasParkingSensors = query.value("hasParkingSensors").toBool();
        cars.append(Car(id, name, rating, category, transmission, driveType, engineCapacity, power,
                           hasSpaciousTrunk, hasHeatedSeats, hasHeatedSteeringWheel, hasParkingSensors));
    }

    // Выполняем запрос и проверяем на ошибки
    if (!query.exec()) {
        qDebug() << "Ошибка при получении всех автомобилей:" << query.lastError().text();
    }

    return cars;
}


