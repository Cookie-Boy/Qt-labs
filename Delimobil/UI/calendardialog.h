#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>
#include <QDate>
#include <QPair>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalendarDialog;
}
QT_END_NAMESPACE

class CalendarDialog : public QDialog {
    Q_OBJECT

public:
    explicit CalendarDialog(QDate startDate, QDate endDate, QWidget *parent = nullptr);
    ~CalendarDialog();

    QPair<QDate, QDate> selectedDates() const;
    bool isUnblockRequested() const;

private slots:
    void onAccept();
    void onUnlock();

private:
    Ui::CalendarDialog *ui;
    QDate startDate;
    QDate endDate;
    bool unblockRequested;
};

#endif // CALENDARDIALOG_H
