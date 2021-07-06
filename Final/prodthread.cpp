#include "prodthread.h"

ProdThread::ProdThread(int tiempo, QObject *parent)
    :QThread (parent)
{
    mProductor = tiempo;
}

void ProdThread::run()
{
    for (int i=0; i<101; i++) {
        emit valorCambiado(i);
        msleep(mProductor);
    }
    int cont=0;
    while (true) {
        emit desper(cont);
        msleep(mProductor);
        cont++;
    }

}

