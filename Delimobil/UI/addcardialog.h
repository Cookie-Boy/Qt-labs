#ifndef ADDCARDIALOG_H
#define ADDCARDIALOG_H

#include <QDialog>
#include <QString>
#include <QGridLayout>
#include "models/car.h"
#include "services/carservice.h"

class QComboBox;
class QPushButton;
class QLineEdit;
class QCheckBox;
class QLabel;

namespace Ui {
class AddCarDialog;
}

class AddCarDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddCarDialog(QWidget *parent = nullptr, const Car *car = nullptr);
    ~AddCarDialog() override;

    void fillCarNamesBox();
    void updateCarDetails(const QString &carName);
    void updateCarDetails(const Car *car);

private slots:
    void selectPhoto();
    void addCar();
    void changeCar();

private:
    QComboBox *carNameCombo;
    QPushButton *photoButton;
    QLabel *photoPreview;
    QPushButton *addButton;

    QLineEdit *engineCapacityEdit;
    QLineEdit *powerEdit;
    QComboBox *categoryCombo;
    QComboBox *transmissionCombo;
    QComboBox *driveTypeCombo;
    QCheckBox *heatedSeatsCheckBox;
    QCheckBox *heatedSteeringWheelCheckBox;
    QCheckBox *parkingSensorsCheckBox;

    QString selectedPhotoPath;

    Ui::AddCarDialog *ui;

    CarService& carService;

    const Car *editingCar;

    bool carExistsInDatabase(const QString &carName);
    Car getCarDetailsFromDatabase(const QString &carName);
    QString getPhotoForExistingCar(const QString &carName);
    bool addCarToDatabase(const QString &carName, const QString &photoPath);

    void setupDetailField(QGridLayout *layout, const QString &labelText, QComboBox *&comboBox, QVector<QString> items, int row, int col);
};

#endif // ADDCARDIALOG_H
