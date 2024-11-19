#ifndef ADDCARWIDGET_H
#define ADDCARWIDGET_H

#include <QWidget>
#include <QString>
#include <QStackedWidget>

#include "basewidget.h"
#include "models/car.h"

class QComboBox;
class QPushButton;
class QLineEdit;
class QCheckBox;
class QLabel;

namespace Ui {
class AddCarWidget;
}

class AddCarWidget : public BaseWidget {
    Q_OBJECT

public:
    explicit AddCarWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~AddCarWidget() override;

    void loadCarNames();
    void updateCarDetails(const QString &carName);

private slots:
    void selectPhoto();
    void addCar();

private:
    QComboBox *carNameCombo;
    QPushButton *photoButton;
    QLabel *photoPreview;
    QPushButton *addButton;

    QLineEdit *engineCapacityEdit;
    QLineEdit *powerEdit;
    QLineEdit *categoryEdit;
    QLineEdit *transmissionEdit;
    QLineEdit *driveTypeEdit;
    QCheckBox *heatedSeatsCheckBox;
    QCheckBox *heatedSteeringWheelCheckBox;
    QCheckBox *parkingSensorsCheckBox;

    QString selectedPhotoPath;

    Ui::AddCarWidget *ui;

    bool carExistsInDatabase(const QString &carName);
    Car getCarDetailsFromDatabase(const QString &carName);
    QString getPhotoForExistingCar(const QString &carName);
    bool addCarToDatabase(const QString &carName, const QString &photoPath);
};

#endif // ADDCARWIDGET_H
