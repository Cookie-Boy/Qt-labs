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
    explicit AddCarDialog(const Car &car, QWidget *parent = nullptr);
    explicit AddCarDialog(QWidget *parent = nullptr);
    ~AddCarDialog() override;

    void fillCarNamesBox();
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

    Ui::AddCarDialog *ui;

    CarService& carService;

    bool carExistsInDatabase(const QString &carName);
    Car getCarDetailsFromDatabase(const QString &carName);
    QString getPhotoForExistingCar(const QString &carName);
    bool addCarToDatabase(const QString &carName, const QString &photoPath);

    void setupDetailField(QGridLayout *layout, const QString &labelText, QLineEdit *&editField, int row, int col);
};

#endif // ADDCARDIALOG_H
