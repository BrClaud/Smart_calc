#ifndef SMARTCALC_H
#define SMARTCALC_H

//#include "mainwindow.h"
//#include "../s21_calc.h"
#include <QDialog>
#include<QVector>
#include<QLineEdit>
#include "qcustomplot.h"

namespace Ui {
class smartCalc;
}

class smartCalc : public QDialog
{
    Q_OBJECT

public:
    explicit smartCalc(QWidget *parent = nullptr);
    ~smartCalc();

private slots:
    void on_pushButton_clicked();
    void digits_numbers();

    void on_pushButton_ac_clicked();

    void on_pushButton_eq_clicked();

    void on_radioButton_plot_clicked();

private:
    Ui::smartCalc *ui;
    QMainWindow * window;
};

#endif // SMARTCALC_H
