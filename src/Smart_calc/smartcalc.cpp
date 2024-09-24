#include "smartcalc.h"
#include "creditcalc.h"
#include "ui_smartcalc.h"
#include "mainwindow.h"
#include "../s21_calc.h"
#include <QDebug>

smartCalc::smartCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::smartCalc)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_atan, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_asin, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_acos, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sin, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cos, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_tan, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_log, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_ln, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pow, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mul, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_div, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_x, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_dot, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_openBracket, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_closeBracket, SIGNAL(clicked()),this,SLOT(digits_numbers()));

    ui->doubleSpinBox_x_max->setValue(10.0);
       ui->doubleSpinBox_y_max->setValue(10.0);
       ui->doubleSpinBox_x_min->setValue(-10.0);
       ui->doubleSpinBox_y_min->setValue(-10.0);

}

smartCalc::~smartCalc()
{
    delete ui;
}

void smartCalc::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

     if (ui->result_show->text() == "0" && button->text() != ".") {
       ui->result_show->setText("");
       if (button->text() == ".") ui->result_show->setText("0");
     }

     ui->result_show->setText(ui->result_show->text() + button->text());
}

void smartCalc::on_pushButton_clicked()
{
    hide();
    window = new MainWindow();
    window->show();
    this->deleteLater();
}



void smartCalc::on_pushButton_ac_clicked()
{
     ui->result_show->setText("0");
}


void smartCalc::on_pushButton_eq_clicked()
{
      QString input = ui->result_show->text();
      QString in_x = ui->lineEdit_x->text();
      bool ok = 1;
      int status = SUCCESS;
      double result = 0.;
      double x = in_x.toDouble(&ok);
      if(x < 0.00001){
          status = s21_smart_calc((char *)input.toStdString().c_str(), &result);
      }else{
          elem_node *output_list = NULL;
          status = convert_to_PRN(&output_list, (char *)input.toStdString().c_str());
          if(status == SUCCESS){
            status =  calculate(output_list, &result, x, GRAPH_ON);
          }
          s21_free_stack(&output_list);
      }


      if (std::isnan(result) || status != SUCCESS) {
        ui->result_show->setText("ERROR");
      } else {
        ui->result_show->setText(QString::number(result, 'g', 10));
      }

}

void smartCalc::on_radioButton_plot_clicked()
{

    double x_min = ui->doubleSpinBox_x_min->value();
    double x_max = ui->doubleSpinBox_x_max->value();
    double y_min = ui->doubleSpinBox_y_min->value();
    double y_max = ui->doubleSpinBox_y_max->value();

    double h = 0.1;
    QVector<double> x, y;
    QString input = ui->result_show->text();

     for (double i = x_min; i < x_max;) {
    x.push_back(i);
    double result = 0.;
    elem_node *output_list = NULL;
    convert_to_PRN(&output_list, (char *)input.toStdString().c_str());
    calculate(output_list, &result, i, GRAPH_ON);
    s21_free_stack(&output_list);
    //        s21_smart_calc((char *)input.toStdString().c_str(), &result, i);
    y.push_back(result);
    i += h;
  }
    ui->widget_plot->addGraph();
    ui->widget_plot->graph(0)->setData(x, y);

    QCPScatterStyle scatterStyle;
    scatterStyle.setShape(QCPScatterStyle::ssCircle);
    scatterStyle.setSize(1.2);
    ui->widget_plot->graph(0)->setScatterStyle(scatterStyle);

    ui->widget_plot->xAxis->setRange(x_min, x_max);
    ui->widget_plot->yAxis->setRange(y_min, y_max);

    ui->widget_plot->setInteraction(QCP::iRangeZoom, true);

    ui->widget_plot->graph(0)->setPen(QColor(61, 82, 62, 255));
    QPen graphPen = ui->widget_plot->graph(0)->pen();
    graphPen.setWidth(2);
    ui->widget_plot->graph(0)->setPen(graphPen);
    ui->widget_plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_plot->replot();

}

