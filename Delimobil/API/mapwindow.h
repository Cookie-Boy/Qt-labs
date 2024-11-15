#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QQuickView>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QGeoCoordinate>

class MapWidget : public QWidget {
    Q_OBJECT
public:
    MapWidget(QWidget *parent = nullptr);

public slots:
    void onCoordinateSelected(const QVariant &coordinate);

private:
    QNetworkAccessManager *networkManager;
    QLabel *addressLabel;
};
