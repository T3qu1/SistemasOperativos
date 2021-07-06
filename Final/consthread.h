#ifndef CONSTHREAD_H
#define CONSTHREAD_H

#include <QThread>

class ConsThread : public QThread
{
    Q_OBJECT
public:
    ConsThread(int tiempo, QObject *parent = nullptr);
signals:
    void valorCambiado(int);
    void desper(int);
protected:
    void run() override;
private:
    int mConsumidor; //milisegundos

};

#endif // PRODTHREAD_H
