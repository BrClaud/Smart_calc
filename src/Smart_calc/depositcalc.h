#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QDialog>

namespace Ui {
class depositCalc;
}

class depositCalc : public QDialog
{
    Q_OBJECT

public:
    explicit depositCalc(QWidget *parent = nullptr);
    ~depositCalc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::depositCalc *ui;
};

#endif // DEPOSITCALC_H
