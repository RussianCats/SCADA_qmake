#include "iec60870.h"


Iec60870::Iec60870(QObject *parent)
    : QObject{parent}
{

}

void Iec60870::run()
{
    while(m_running)
    {
        qInfo() << "работает" ;
        sleep(1);
        //отправка данных в основной поток через connent
         emit emitSendData(1.2, 3.2, 4.5);
    }
    //остановка потока
    emit emitStop();
};

bool Iec60870::running() const
{
    return m_running;
}

void Iec60870::setRunning(bool newRunning)
{
    if (m_running == newRunning)
        return;
    m_running = newRunning;
    emit runningChanged();
}
