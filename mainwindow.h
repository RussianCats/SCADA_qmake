#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <iec60870.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void update(int);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_3_clicked();



    void on_pushButton_6_clicked();





private:
    Ui::MainWindow *ui;
     // указатель на поток
    QThread *pThread;
    // указатель на поток класса iec60870
    Iec60870 *pIec60870;

};
#endif // MAINWINDOW_H
