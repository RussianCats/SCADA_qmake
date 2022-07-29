#include "iec60870.h"
#include <math.h>


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


namespace socket_in {
    //для соединения сокетов

    #include <netinet/in.h> //structure for storing address information
    #include <sys/socket.h> //for socket APIs


}
#define SIZE 255
#define QUANTITY_TRANSFER 96 * 3


Iec60870::Iec60870(QObject *parent)
    : QObject{parent}
{

}

void Iec60870::run()
{
    while(m_running)
    {
        struct socket_in::sockaddr_in servAddr;

        servAddr.sin_family = AF_INET;
        servAddr.sin_port = socket_in::htons(9001); // use some unused port number
        servAddr.sin_addr.s_addr = (socket_in::in_addr_t) 0x00000000 ;

        for (int i = 0; i < 96; i++)
        {
            float floatData[3] = {0, 0, 0};
            for (int j = 0; j < 3; j++)
            {
                int sockD = socket_in::socket(AF_INET, 1, 0);
                int connectStatus =  socket_in::connect(sockD, (struct socket_in::sockaddr *)&servAddr,
                                            sizeof(servAddr));

                if (connectStatus == -1)
                {
                    printf("Error...\n");
                }

                else
                {
                    char strData[SIZE];

                    int num_point = 0;

                    socket_in::recv(sockD, strData, sizeof(strData), 0);

                    //хитровыебанная функция перевода char  в int типа float
                    for (int k = 0; k < strlen(strData); k++)
                    {
                        if (strData[k] == '.')
                            num_point = k;
                    }

                    for (int k = 0; k < num_point; k++)
                    {
                        floatData[j] += ((int)(strData[k]) - 48) * pow(10, (num_point - k - 1));
                    };

                    for (int k = 0; k < strlen(strData) - num_point - 1; k++)
                    {
                        floatData[j] += ((int)(strData[k + num_point + 1]) - 48) / pow(10, (k + 1));
                    }
                }
            }
            //отправка данных в основной поток через connent
            emit emitSendData(floatData[0], floatData[1], floatData[2]);

        }
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
