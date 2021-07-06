#include "widget.h"
#include "ui_widget.h"
#include "prodthread.h"
#include "consthread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mprod = new ProdThread(100, this);
    mbar = new ProdThread(100, this);
    mdesProd = new ProdThread(100, this);
    mcons = new ProdThread(100, this);
    mbar2 = new ConsThread(100, this);
    mdesCons = new ConsThread(100, this);

    ui->progressBar->setValue(0);
    ui->contProd->display(0);
    ui->contConsu->display(0);

    connect(mbar, &ProdThread::valorCambiado, ui->progressBar, &QProgressBar::setValue);
    connect(mprod, SIGNAL(valorCambiado(int)), ui->contProd, SLOT(display(int)));
    connect(mdesProd, SIGNAL(desper(int)), ui->perProd, SLOT(display(int)));

    connect(mbar2, &ConsThread::valorCambiado, ui->progressBar, &QProgressBar::setValue);
    connect(mcons, SIGNAL(valorCambiado(int)), ui->contConsu, SLOT(display(int)));
    connect(mdesCons, SIGNAL(desper(int)), ui->perConsu, SLOT(display(int)));



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startProd_clicked()
{
    mprod->start();
    mbar->start();
    mdesProd->start();
}

void Widget::on_stopProd_clicked()
{
    mprod->terminate();
    mbar->terminate();
    mdesProd->terminate();

}

void Widget::on_startConsu_clicked()
{
    mcons->start();
    mbar2->start();
    mdesCons->start();
}

void Widget::on_stopConsu_clicked()
{
    mcons->terminate();
    mbar2->terminate();
    mdesCons->terminate();
}
