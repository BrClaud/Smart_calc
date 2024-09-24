#ifndef CREDITCALC_H
#define CREDITCALC_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class creditCalc;
}

#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_calc.h"

#ifdef __cplusplus
}
#endif

class creditCalc : public QDialog
{
    Q_OBJECT

public:
    explicit creditCalc(QWidget *parent = nullptr);
    ~creditCalc();

private slots:
    void on_pushButton_clicked();

    void on_calc_credit_clicked();

private:
    Ui::creditCalc *ui;
    QMainWindow * window;
};

#endif // CREDITCALC_H
