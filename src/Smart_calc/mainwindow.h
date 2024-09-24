#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smartcalc.h"
#include "creditcalc.h"
//#include "qcustomplot.h"

class smartCalc;
class creditCalc;
class depositCalc;

#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_calc.h"

#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    smartCalc *smartcalc;
    creditCalc *creditcalc;
    depositCalc *depositcalc;

};
#endif // MAINWINDOW_H
