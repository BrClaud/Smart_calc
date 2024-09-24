#include "creditcalc.h"
#include "smartcalc.h"
#include "ui_creditcalc.h"
#include "mainwindow.h"
#include "../s21_calc.h"
#include <QDebug>

creditCalc::creditCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditCalc)
{
    ui->setupUi(this);
    ui->interest->setRange(0, 9999999999999);
    ui->month->setRange(0, 9999999999999);
    ui->credit_amount->setRange(0, 9999999999999);
}

creditCalc::~creditCalc()
{
    delete ui;
}

void creditCalc::on_pushButton_clicked()
{
    hide();
    window = new MainWindow();
    window->show();
    this->deleteLater();
}


void creditCalc::on_calc_credit_clicked()
{
    long double month = ui->month->value();
    long double interest = ui->interest->value();
    long double credit_amount = ui->credit_amount->value();
    long double total_payment = 0.;
    long double overpay = 0;
    if (ui->diff->isChecked()){
        long double pay_for_month_min = 0.;
        long double pay_for_month_max = 0.;
        s21_diff_calculation(credit_amount, month, interest, &pay_for_month_min, &pay_for_month_max, &total_payment, &overpay);
        ui->pay_for_month->setText(QString::number(pay_for_month_min, 'g', 7) + "___" + QString::number(pay_for_month_max, 'g', 7));
        QString result_of_overprice = QString::number((overpay), 'g', 7);
        QString result_sum = QString::number((total_payment), 'g', 7);
        ui->res_sum->setText(result_sum);
        ui->overprice->setText(result_of_overprice);
    }else if(ui->annuity->isChecked()){
        long double pay_for_month = 0;
        s21_annuity_calculation(credit_amount, month, interest, &pay_for_month, &total_payment, &overpay);
        ui->pay_for_month->setText(QString::number(pay_for_month, 'g', 7));
        QString result_of_overprice = QString::number((overpay), 'g', 7);
        QString result_sum = QString::number((total_payment), 'g', 7);
        ui->res_sum->setText(result_sum);
        ui->overprice->setText(result_of_overprice);
    }

}
