#include "consthread.h"


ConsThread::ConsThread(int tiempo, QObject *parent)
    : QThread (parent)
{
    mConsumidor = tiempo;
}

void ConsThread::run()
{
    for (int i=100; i>=0; i--) {
        emit valorCambiado(i);
        msleep(mConsumidor);
    }
    int cont=0;
    while (true) {
        emit desper(cont);
        msleep(mConsumidor);
        cont++;
    }
}
