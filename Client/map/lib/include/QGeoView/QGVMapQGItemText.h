
#pragma once

#include "QGVGlobal.h"

#include <QGraphicsItem>

class QGVDrawItem;


class QGV_LIB_DECL QGVMapQGItemText : public QGraphicsItem
{
public:
    explicit QGVMapQGItemText(QGVDrawItem* geoObject);

    static QGVDrawItem* geoObjectFromQGItem(QGraphicsItem* item);

    void resetGeometry();

private:
    QRectF boundingRect() const override final;
    QRectF boundingRectText() const;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override final;

    QPainterPath shape() const override final;
    QPainterPath shapeText() const;

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override final;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override final;

private:
    //QGVDrawItem* mGeoObject;
    QGVDrawItem* mGeoObjectText;


};

