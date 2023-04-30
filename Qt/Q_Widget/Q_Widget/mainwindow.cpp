#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rb_up->setText("UP");
    ui->rb_down->setText("DOWN");
    ui->pb_pBarUp->setText("UP Progress Bar");

        for(int i = 0; i < 10; ++i)
        {
            ui->cBox_box->addItem("Элемент " + QString::number(i));
        }

    ui->pBar_bar->setMaximum(10);
    ui->pBar_bar->setMinimum(0);
    ui->pBar_bar->setValue(0);
    ui->pBar_bar->setFormat("%p%");

    ui->pb_pBarUp->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_pBarUp_toggled(bool checked)
{
    if(checked == true)
    {
        if(ui->pBar_bar->value() < 10)
        {
            ui->pBar_bar->setValue(ui->pBar_bar->value() + 1);
        }
        else
        {
            ui->pBar_bar->setValue(0);
        }
        qDebug() << QString::number(ui->pBar_bar->value());
    }
}


