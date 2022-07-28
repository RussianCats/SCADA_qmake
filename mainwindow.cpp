#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

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




// iec60870-5-104
void MainWindow::on_checkBox_stateChanged(int arg1)
{
   qInfo() << "нажали 1:" << arg1;
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    qInfo() << "нажали 2:"  << arg1;
}


void MainWindow::on_pushButton_3_clicked()
{

}


// iec61850
void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    qInfo() << "нажали 1:" << arg1;
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    qInfo() << "нажали 2:" << arg1;
}


void MainWindow::on_pushButton_4_clicked()
{

}


// opc ua

void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    qInfo() << "нажали 1:" << arg1;
}


void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    qInfo() << "нажали 2:" << arg1;
}


void MainWindow::on_pushButton_5_clicked()
{

}

