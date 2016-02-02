#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    observable = new Observable();
    ui->setupUi(this);
    // connect the window to the observer
    connect(this, SIGNAL(signal_valueChanged(int)), observable, SLOT(slot_setValue(int)));
    // connect the observer to the window
    connect(observable, SIGNAL(signal_valueChanged(int)), this, SLOT(slot_maj(int)));
    // connect button to quit the application
    connect(ui->quitPushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    // emit the signal to the observer
    emit signal_valueChanged(arg1);
}

void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    // emit the signal to the observer
    emit signal_valueChanged(time.hour());
}

void MainWindow::slot_maj(int val)
{
    // maj all ui elements when we receive the signal form the observer
    ui->spinBox->setValue(val);
    ui->timeEdit->setTime(QTime(val,0));
    ui->horizontalSlider->setValue(val);
    ui->lcdNumber->display(val);
    ui->progressBar->setValue(val);
    ui->statusBar->showMessage("Value = "+QString::number(val));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    // emit the signal to the observer
    emit signal_valueChanged(value);
}

void MainWindow::on_pushButton_clicked()
{
    // Reset all the observable ui to the default value
    observable->slot_setValue(12);
}

void MainWindow::on_dial_valueChanged(int value)
{
    // emit the signal to the observer
    emit signal_valueChanged(value);
}
