#include "iec60870.h"


Iec60870::Iec60870(QObject *parent)
    : QObject{parent}
{

}

void Iec60870::run()
{
    for(int i = 0; i < 10; i++)
    {
        emit emitRun(i);
        sleep(1);
    }
};
