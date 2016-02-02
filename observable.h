#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QObject>
#include <QDebug>

class Observable : public QObject
{
    Q_OBJECT
public:
    explicit Observable(QObject *parent = 0);

public slots:
    void slot_setValue(int i){
        // receive the signal from the window and print it
        qDebug() << "Observable spin value : " << i;
        // emit the signal to the window
        emit signal_valueChanged(i);
    }

signals:
    void signal_valueChanged(int i);

private:
    int value;
};

#endif // OBSERVABLE_H
