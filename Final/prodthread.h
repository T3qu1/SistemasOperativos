#ifndef PRODTHREAD_H
#define PRODTHREAD_H

#include <QThread>

class ProdThread : public QThread
{
    Q_OBJECT
public:
    ProdThread(int tiempo, QObject *parent = nullptr);
signals:
    void valorCambiado(int);
    void desper(int);
protected:
    void run() override;
private:
    int mProductor; //milisegundos

};

#endif // PRODTHREAD_H
