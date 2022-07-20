#include "appcore.h"

AppCore::AppCore(QObject *parent) :
    QObject(parent)
{
}

void AppCore::getOldText(QString text)
{
    emit transmitNewText(text + "Jopa!");

}
