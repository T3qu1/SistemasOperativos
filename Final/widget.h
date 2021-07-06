#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVariant>

namespace Ui {
class Widget;
}

class ProdThread;
class ConsThread;


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startProd_clicked();

    void on_stopProd_clicked();

    void on_startConsu_clicked();

    void on_stopConsu_clicked();

private:
    Ui::Widget *ui;
    ProdThread *mprod;
    ProdThread *mbar;
    ProdThread *mdesProd;
    ProdThread *mcons;
    ConsThread *mbar2;
    ConsThread *mdesCons;
};

#endif // WIDGET_H
