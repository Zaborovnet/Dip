

#include "tringle.h"
#include <QGeoView/QGVImage.h>

#include <QBrush>
#include <QPainter>
#include <QPen>

Tringle::Tringle(const QGV::GeoPos& geoPos, int number)
{

int i =number; /// номер текущего итема по счёту начиная с 0

{


    setFlag(QGV::ItemFlag::IgnoreScale);
    setFlag(QGV::ItemFlag::IgnoreAzimuth);
    setFlag(QGV::ItemFlag::Highlightable);
    setFlag(QGV::ItemFlag::HighlightCustom);
    setFlag(QGV::ItemFlag::Highlightable);
    setFlag(QGV::ItemFlag::Transformed);
    setGeometry(geoPos, QSize(32, 32), QPoint(16, 32));
    switch (i) {
    case 0:{

    const QImage url0 =QImage("./pictures/Priority.png");
    loadImage(url0);

    break;}
    case 1:{
        const QImage url1 =QImage("./pictures/TargetFriend.png");
        loadImage(url1);
        break;}
    case 2:{
        const QImage url2 =QImage("./pictures/NoReadyMFR.png");
        loadImage(url2);
        break;}
    }








    }
}

QTransform Tringle::projTransform() const
{
    return isFlag(QGV::ItemFlag::Highlighted) ? QGV::createTransfromScale(projAnchor(), 1.2) : QTransform();
}

void Tringle::projOnFlags()
{
    setOpacity(isFlag(QGV::ItemFlag::Highlighted) ? 0.3 : 1.0);
}

