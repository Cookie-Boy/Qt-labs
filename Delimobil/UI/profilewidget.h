#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QWidget *parent = nullptr);

private slots:
    void onEditButtonClicked();
    void onSaveButtonClicked();

private:
    QLineEdit *lastNameEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *middleNameEdit;
    QLineEdit *emailEdit;
    QPushButton *editButton;
    QPushButton *saveButton;
    QPushButton *tripsButton;
    QPushButton *reviewsButton;
};

#endif // PROFILEWIDGET_H
