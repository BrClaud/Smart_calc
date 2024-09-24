#include "depositcalc.h"
#include "smartcalc.h"
#include "creditcalc.h"
#include "ui_depositcalc.h"
#include "mainwindow.h"
#include "../s21_calc.h"
#include <QDebug>

depositCalc::depositCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depositCalc)
{
    ui->setupUi(this);
    ui->initial_deposit->setRange(0, 9999999999999);
    ui->period_in_months->setRange(0, 9999999999999);
    ui->initial_interest->setRange(0, 9999999999999);
    ui->payment_periodicity->setRange(0, 9999999999999);
    ui->replenishment_amount->setRange(0, 9999999999999);
    ui->withdraw_amount->setRange(0, 9999999999999);
    ui->tax_interest->setRange(0, 9999999999999);
}

depositCalc::~depositCalc()
{
    delete ui;
}

void depositCalc::on_pushButton_clicked()
{
    double initial_deposit = ui->initial_deposit->value();
    int period_in_months = ui->period_in_months->value();
    double initial_interest = ui->initial_interest->value();
    int payment_periodicity = ui->payment_periodicity->value();
    double replenishment_amount = ui->replenishment_amount->value();
    double withdraw_amount = ui->withdraw_amount->value();
    double tax_interest = ui->tax_interest->value();
    int capital = 0;
    double accured_interest = 0;
    double tax_amount = 0;
    double deposit_amount = 0;
    if(ui->is_capitalized->isChecked()) capital = 1;
    s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                       payment_periodicity, capital, replenishment_amount,
                       withdraw_amount, tax_interest, &accured_interest,
                       &tax_amount, &deposit_amount);
    ui->accured_interest->setText(QString::number(accured_interest, 'g', 7));
    ui->tax_amount->setText(QString::number(tax_amount, 'g', 7));
    ui->deposit_amount->setText(QString::number(deposit_amount, 'g', 7));

}

