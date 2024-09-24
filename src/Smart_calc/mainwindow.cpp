#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../s21_calc.h"
#include "smartcalc.h"
#include "creditcalc.h"
#include "depositcalc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    smartcalc = new smartCalc(this);
    smartcalc->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    creditcalc = new creditCalc(this);
    creditcalc->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    hide();
    depositcalc = new depositCalc(this);
    depositcalc->show();
}
