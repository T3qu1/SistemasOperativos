#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    ui->textEdit->setText("1");
    ui->textEdit_2->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_leeme_clicked()
{
    ui->TextL->setText("Problema Productor-Consumidor:\n"
                       "Este problema consiste en tener\n"
                       "dos procesos donde el productor\n"
                       "da los elementos y el consumidor\n"
                       "los recibe\n"
                       "Ejecucion: Ingresar la cantidad\n"
                       "para consumidor y productor\n"
                       "Resultados: Mostrara el proceso\n"
                       "de ingresar y extraer elementos\n"
                       "respectivos usando mutex y \n"
                       "variables compartidas para la\n"
                       "correcta ejecucion de ambos casos\n");
}

void MainWindow::on_acerca_clicked()
{
    ui->TextA->setText("Universidad: La Salle\n"
                             "Curso: Sistemas Operativos\n"
                             "Profesor: Richart Escobedo\n"
                             "Alumno: Camila Huamaní\n"
                             "Semestre: V\n"
                             "Año academico: 2021-1\n"
                             "Fecha: 13/06/2021\n");
}

void MainWindow::on_solicitar_clicked()
{
    ui->frame->show();
}

void MainWindow::on_Cancel_clicked()
{
    ui->frame->hide();
    ui->textEdit->setText("1");
    ui->textEdit_2->setText("1");

}

void MainWindow::on_acept_clicked()
{
    Widget *prueba = new Widget();
    prueba->show();
    close();
}
