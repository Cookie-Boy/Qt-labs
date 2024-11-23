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

Car* CarRepository::getCarByQuery(QSqlQuery& query) {
    long id = static_cast<long>(query.value("id").toLongLong());
    QString name = query.value("name").toString();
    short rating = static_cast<short>(query.value("rating").toInt());
    QString category = query.value("category").toString();
    QString transmission = query.value("transmission").toString();
    QString driveType = query.value("driveType").toString();
    double engineCapacity = query.value("engineCapacity").toDouble();
    double power = query.value("power").toDouble();
    QString imagePath = query.value("imagePath").toString();
    bool hasHeatedSeats = query.value("hasHeatedSeats").toBool();
    bool hasHeatedSteeringWheel = query.value("hasHeatedSteeringWheel").toBool();
    bool hasParkingSensors = query.value("hasParkingSensors").toBool();
    QPair<QDate, QDate> blockedPeriod;

    QVariant value = query.value("blockedPeriod");
    if (!value.isNull()) {
        QStringList dates = value.toString().split(',');
        if (dates.size() == 2) { // Убедитесь, что есть два элемента
            QDate startDate = QDate::fromString(dates.at(0), Qt::ISODate);
            QDate endDate = QDate::fromString(dates.at(1), Qt::ISODate);
            blockedPeriod = qMakePair(startDate, endDate);
        } else {
            qWarning() << "blockedPeriod format invalid:" << value.toString();
            blockedPeriod = qMakePair(QDate(), QDate()); // Значения по умолчанию
        }
    } else {
        qWarning() << "blockedPeriod is NULL";
        blockedPeriod = qMakePair(QDate(), QDate()); // Значения по умолчанию
    }

    return new Car(id, name, rating, category, transmission, driveType, engineCapacity, power, imagePath,
                   hasHeatedSeats, hasHeatedSteeringWheel, hasParkingSensors, blockedPeriod);
}

bool CarRepository::saveCar(const Car& car) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO cars
        (id, name, rating, category, transmission, driveType, engineCapacity,
         power, imagePath, hasHeatedSeats, hasHeatedSteeringWheel,
         hasParkingSensors, blockedPeriod)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
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
    query.addBindValue(car.getImagePath());
    query.addBindValue(car.getHasHeatedSeats());
    query.addBindValue(car.getHasHeatedSteeringWheel());
    query.addBindValue(car.getHasParkingSensors());

    QPair<QDate, QDate> blockedPeriod = car.getBlockedPeriod();
    query.addBindValue(blockedPeriod.first.toString(Qt::ISODate) + "," + blockedPeriod.second.toString(Qt::ISODate));

    // Выполняем запрос и проверяем на ошибки
    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении автомобиля:" << query.lastError().text();
        return false;
    }

    return true;
}

bool CarRepository::updateCar(const Car &oldCar, const Car &newCar) {
    QSqlQuery query;
    query.prepare(R"(
        UPDATE cars
        SET name = ?, rating = ?, category = ?, transmission = ?, driveType = ?,
            engineCapacity = ?, power = ?, imagePath = ?, hasHeatedSeats = ?,
            hasHeatedSteeringWheel = ?, hasParkingSensors = ?, blockedPeriod = ?
        WHERE id = ?
    )");

    // Привязываем значения нового объекта Car
    query.addBindValue(newCar.getName());
    query.addBindValue(newCar.getRating());
    query.addBindValue(newCar.getCategory());
    query.addBindValue(newCar.getTransmission());
    query.addBindValue(newCar.getDriveType());
    query.addBindValue(newCar.getEngineCapacity());
    query.addBindValue(newCar.getPower());
    query.addBindValue(newCar.getImagePath());
    query.addBindValue(newCar.getHasHeatedSeats());
    query.addBindValue(newCar.getHasHeatedSteeringWheel());
    query.addBindValue(newCar.getHasParkingSensors());

    QPair<QDate, QDate> blockedPeriod = newCar.getBlockedPeriod();
    if (blockedPeriod.first.isNull() || blockedPeriod.second.isNull())
        query.addBindValue(NULL);
    else
        query.addBindValue(blockedPeriod.first.toString(Qt::ISODate) + "," + blockedPeriod.second.toString(Qt::ISODate));

    // Привязываем ID старого объекта для поиска записи в базе
    query.addBindValue(QVariant::fromValue(static_cast<long>(oldCar.getId())));

    // Выполняем запрос и проверяем на ошибки
    if (!query.exec()) {
        qDebug() << "Ошибка при обновлении автомобиля:" << query.lastError().text();
        return false;
    }

    return true;
}

bool CarRepository::deleteCarById(long id) {
    QSqlQuery query;
    query.prepare(R"(
        DELETE FROM cars
        WHERE id = ?
    )");

    query.addBindValue(QVariant::fromValue(static_cast<long>(id)));

    // Выполняем запрос
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении автомобиля с ID" << id << ":" << query.lastError().text();
        return false;
    }

    // Проверяем, был ли удален автомобиль
    if (query.numRowsAffected() == 0) {
        qDebug() << "Автомобиль с ID" << id << "не найден.";
        return false;
    }

    return true;
}

QVector<QString> CarRepository::getUniqueNames() {
    QVector<QString> names;
    QSqlQuery query("SELECT DISTINCT name FROM cars");

    while (query.next()) {
        names.push_back(query.value("name").toString());
    }

    return names;
}

Car* CarRepository::findCarByName(QString name) {
    QSqlQuery query;
    query.prepare("SELECT * FROM cars WHERE name = :name LIMIT 1");
    query.bindValue(":name", name);
    if (query.exec() && query.next()) {
        return getCarByQuery(query);
    }
    return nullptr;
}

QVector<Car> CarRepository::findAll() {
    QVector<Car> cars;
    QSqlQuery query("SELECT * FROM cars");

    while (query.next()) {
        cars.append(*getCarByQuery(query));
    }

    // Выполняем запрос и проверяем на ошибки
    if (!query.exec()) {
        qDebug() << "Ошибка при получении всех автомобилей:" << query.lastError().text();
    }

    return cars;
}


