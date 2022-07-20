#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void transmitNewText(QString text);

public slots:
    // Слот для приёма данных из qml-интерфейса
    void getOldText(QString text);

};

#endif //APPCORE_H
