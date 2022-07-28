#ifndef IEC60870_H
#define IEC60870_H

#include <QObject>
//для задержки времени
#include <unistd.h>

class Iec60870 : public QObject
{
    Q_OBJECT
public:
    explicit Iec60870(QObject *parent = nullptr);

signals:
    //отправка данных в графическое окно пользователя
    void emitRun(int i);

public slots:
    // слот генерирует числа
    void run();

};

#endif // IEC60870_H
