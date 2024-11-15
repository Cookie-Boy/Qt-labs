#include "mapwindow.h"
#include <QQuickItem>
#include <QJsonDocument>
#include <QJsonObject>

MapWidget::MapWidget(QWidget *parent) : QWidget(parent), networkManager(new QNetworkAccessManager(this)) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Виджет карты
    QQuickView *mapView = new QQuickView;
    mapView->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    QWidget *container = QWidget::createWindowContainer(mapView, this);
    layout->addWidget(container);

    // Метка для отображения адреса
    addressLabel = new QLabel("Адрес будет отображен здесь.", this);
    layout->addWidget(addressLabel);

    // Получаем объект карты и подключаем сигнал
    QObject *mapObject = mapView->rootObject();
    connect(mapObject, SIGNAL(coordinateSelected(QVariant)),
            this, SLOT(onCoordinateSelected(QVariant)));
}

void MapWidget::onCoordinateSelected(const QVariant &coordinate) {
    QGeoCoordinate geoCoord = coordinate.value<QGeoCoordinate>();
    QString url = QString("https://nominatim.openstreetmap.org/reverse?format=json&lat=%1&lon=%2&zoom=18&addressdetails=1")
                      .arg(geoCoord.latitude())
                      .arg(geoCoord.longitude());

    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::UserAgentHeader, "MyQtApp");
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
            QJsonObject jsonObject = jsonResponse.object();
            QJsonObject addressObject = jsonObject["address"].toObject();
            QString street = addressObject["road"].toString();
            addressLabel->setText("Улица: " + street);
        } else {
            addressLabel->setText("Не удалось получить адрес.");
        }
        reply->deleteLater();
    });
}
