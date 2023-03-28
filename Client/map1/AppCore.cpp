#include "AppCore.h"

AppCore::AppCore(QObject* parent) : QObject(parent)
{
}

void AppCore::receiveFromQml()
{
    // We increase the counter and send a signal with its value
    ++m_counter;
    emit sendToQml(m_counter);
}
