#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_leeme_clicked();

    void on_acerca_clicked();

    void on_solicitar_clicked();

    void on_Cancel_clicked();

    void on_acept_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
