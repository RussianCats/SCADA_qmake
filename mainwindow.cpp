#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<QDebug>

//// для сокетов
//#include <netinet/in.h> //structure for storing address information
//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/socket.h> //for socket APIs
//#include <sys/types.h>
//#include <cmath>
//#include <string.h>
//#define SIZE 255
//#define QUANTITY_TRANSFER 96 * 3



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

void MainWindow::update(int num)
{
    ui->textEdit->insertPlainText(QString::number(num));
}

//вкл
void MainWindow::on_pushButton_3_clicked()
{
    //ui->textEdit->insertPlainText("добавил текст\n");
    //выделяем динпамять для потока протокола iec60870
    pThread = new QThread;
    pIec60870 = new Iec60870;
    //операция перемещения объекта в поток pThread
    pIec60870->moveToThread(pThread);
    connect(pIec60870, SIGNAL(emitRun(int)), this, SLOT(update(int)));
    // когда поток стартует то запускается функция run
    connect(pThread, SIGNAL(started()), pIec60870, SLOT(run()));
    //запускаем поток
    pThread->start();




}


//выкл
void MainWindow::on_pushButton_6_clicked()
{
    on_pushButton_3_clicked();
}






