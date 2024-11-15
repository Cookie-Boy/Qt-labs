#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

class RentDialog : public QDialog {
    Q_OBJECT
public:
    explicit RentDialog(QWidget *parent = nullptr);
    bool isConfirmed() const;

private slots:
    void onConfirm();
    void onCancel();

private:
    bool confirmed;
};

#endif // CONFIRMDIALOG_H
