#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "observable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_timeEdit_timeChanged(const QTime &time);
    void slot_maj(int val);
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_clicked();

    void on_dial_valueChanged(int value);

signals:
    void signal_valueChanged(int i);

private:
    Ui::MainWindow *ui;
    Observable * observable;
};

#endif // MAINWINDOW_H
