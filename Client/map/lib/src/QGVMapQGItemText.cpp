#include "QGVMapQGItemText.h"
#include "QGVDrawItem.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPalette>

QGVMapQGItemText::QGVMapQGItemText(QGVDrawItem* geoObject)
{

    //mGeoObject = geoObject;
    mGeoObjectText = geoObject;


    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

QGVDrawItem* QGVMapQGItemText::geoObjectFromQGItem(QGraphicsItem* item)
{
    QGVMapQGItemText* qGCItem = dynamic_cast<QGVMapQGItemText*>(item);
    //return (qGCItem != nullptr) ? qGCItem->mGeoObject : nullptr;
    return (qGCItem != nullptr) ? qGCItem->mGeoObjectText : nullptr;
}

void QGVMapQGItemText::resetGeometry()
{
    prepareGeometryChange();
}

QRectF QGVMapQGItemText::boundingRect() const
{
    //boundingRectText();
    //return mGeoObject->projShape().boundingRect();
    return mGeoObjectText->projShapeText().boundingRect();


}
QRectF QGVMapQGItemText::boundingRectText() const
{
    return mGeoObjectText->projShapeText().boundingRect();

}


void QGVMapQGItemText::paint(QPainter* painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    //mGeoObject->projPaint(painter);
    mGeoObjectText->projPaintText(painter);


//    if (mGeoObject->isSelected() && !mGeoObject->isFlag(QGV::ItemFlag::SelectCustom)) {
//        QPen pen = QPen(mGeoObject->getMap()->palette().highlight(), 1, Qt::DashLine);
//        pen.setCosmetic(true);
//        QBrush brush = QBrush(mGeoObject->getMap()->palette().light().color(), Qt::Dense4Pattern);
//        painter->setPen(pen);
//        painter->setBrush(brush);
//        painter->drawPath(mGeoObject->projShape());
//    }

//    if (QGV::isDrawDebug()) {
//        mGeoObject->setProperty("paintCount", mGeoObject->property("paintCount").toInt() + 1);
//        QPen pen = QPen(Qt::black);
//        pen.setWidth(1);
//        pen.setCosmetic(true);
//        QBrush brush = QBrush(Qt::white);
//        painter->setPen(pen);
//        painter->setBrush(brush);
//        auto rect = boundingRect().toRect();
//        auto path = QGV::createTextPath(rect, mGeoObject->projDebug(), QFont(), pen.width());
//        path = QGV::createTransfromScale(rect.center(), 0.75).map(path);
//        painter->drawPath(path);

//        pen = QPen(Qt::black);
//        pen.setStyle(Qt::DashLine);
//        pen.setWidth(1);
//        pen.setCosmetic(true);
//        brush = QBrush(Qt::transparent);
//        painter->setPen(pen);
//        painter->setBrush(brush);
//        painter->drawRect(rect);
//    }
    /////

    if (mGeoObjectText->isSelected() && !mGeoObjectText->isFlag(QGV::ItemFlag::SelectCustom)) {
        QPen pen = QPen(mGeoObjectText->getMap()->palette().highlight(), 1, Qt::DashLine);
        pen.setCosmetic(true);
        QBrush brush = QBrush(mGeoObjectText->getMap()->palette().light().color(), Qt::Dense4Pattern);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawPath(mGeoObjectText->projShapeText());
    }

    if (QGV::isDrawDebug()) {
        mGeoObjectText->setProperty("paintCount", mGeoObjectText->property("paintCount").toInt() + 2);
        QPen pen = QPen(Qt::black);
        pen.setWidth(1);
        pen.setCosmetic(true);
        QBrush brush = QBrush(Qt::white);
        painter->setPen(pen);
        painter->setBrush(brush);
        auto rect = boundingRectText().toRect();
        auto path = QGV::createTextPath(rect, mGeoObjectText->projDebug(), QFont(), pen.width());
        path = QGV::createTransfromScale(rect.center(), 0.75).map(path);
        painter->drawPath(path);

        pen = QPen(Qt::black);
        pen.setStyle(Qt::DashLine);
        pen.setWidth(1);
        pen.setCosmetic(true);
        brush = QBrush(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(rect);
    }
}

QPainterPath QGVMapQGItemText::shape() const
{
   //shapeText();
   //return mGeoObject->projShape();

   return mGeoObjectText->projShapeText();


}
QPainterPath QGVMapQGItemText::shapeText() const
{
    return mGeoObjectText->projShapeText();

}

void QGVMapQGItemText::hoverEnterEvent(QGraphicsSceneHoverEvent* /*event*/)
{
//    if (mGeoObject->isFlag(QGV::ItemFlag::Highlightable)) {
//        mGeoObject->setFlag(QGV::ItemFlag::Highlighted);
//    }
    if (mGeoObjectText->isFlag(QGV::ItemFlag::Highlightable)) {
        mGeoObjectText->setFlag(QGV::ItemFlag::Highlighted);
    }
}

void QGVMapQGItemText::hoverLeaveEvent(QGraphicsSceneHoverEvent* /*event*/)
{
//    if (mGeoObject->isFlag(QGV::ItemFlag::Highlightable)) {
//        mGeoObject->setFlag(QGV::ItemFlag::Highlighted, false);
//    }
    if (mGeoObjectText->isFlag(QGV::ItemFlag::Highlightable)) {
        mGeoObjectText->setFlag(QGV::ItemFlag::Highlighted, false);
    }
}
