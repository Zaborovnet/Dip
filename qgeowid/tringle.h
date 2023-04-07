#ifndef TRINGLE_H
#define TRINGLE_H

#endif // TRINGLE_H


#pragma once

#include <QGeoView/QGVImage.h>

class Tringle : public QGVImage
{
    Q_OBJECT

public:
    explicit Tringle(const QGV::GeoPos& geoPos, int number);

private:
    QTransform projTransform() const override;
    void projOnFlags() override;
};
