#include "CalendarDialog.h"
#include "ui_calendardialog.h"
#include <QMessageBox>
#include <QPushButton>

CalendarDialog::CalendarDialog(QDate startDate, QDate endDate, QWidget *parent)
    : QDialog(parent),
      ui(new Ui::CalendarDialog),
      unblockRequested(false) {
    ui->setupUi(this);

    // Настройка календарей
    ui->startCalendar->setSelectedDate(startDate);
    ui->endCalendar->setSelectedDate(endDate);

    QPushButton *unlockButton = new QPushButton("Разблокировать");
    ui->buttonBox->addButton(unlockButton, QDialogButtonBox::ActionRole);

    // Подключение кнопок
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &CalendarDialog::onAccept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &CalendarDialog::reject);
    connect(unlockButton, &QPushButton::clicked, this, &CalendarDialog::onUnlock);
}

CalendarDialog::~CalendarDialog() {
    delete ui;
}

QPair<QDate, QDate> CalendarDialog::selectedDates() const {
    return qMakePair(ui->startCalendar->selectedDate(), ui->endCalendar->selectedDate());
}

bool CalendarDialog::isUnblockRequested() const {
    return unblockRequested;
}

void CalendarDialog::onAccept() {
    if (ui->startCalendar->selectedDate() > ui->endCalendar->selectedDate()) {
        QMessageBox::warning(this, "Ошибка", "Дата начала не может быть позже даты конца.");
    } else {
        accept();
    }
}

void CalendarDialog::onUnlock() {
    // Устанавливаем флаг разблокировки
    unblockRequested = true;

    // Закрываем диалог
    accept();
}
