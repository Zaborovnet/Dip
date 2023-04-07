/***************************************************************************
 * QGeoView is a Qt / C ++ widget for visualizing geographic data.
 * Copyright (C) 2018-2020 Andrey Yaroshenko.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see https://www.gnu.org/licenses.
 ****************************************************************************/

#include "QGVImage.h"
#include "QGVMap.h"

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPainter>

QGVImage::QGVImage()
    : mGeometryType(GeometryType::ByRect)

  {
      }

void QGVImage::setGeometry(const QGV::GeoRect& geoRect)
{
    mGeometryType = GeometryType::ByRect;
    mGeoRect = geoRect;
    mGeoRectText =geoRect;
    calculateGeometry();
}

void QGVImage::setGeometry(const QGV::GeoPos& geoPos, const QSize& imageSize, const QPoint& imageAnchor)
{
    mGeometryType = GeometryType::ByPos;
    mGeoPos = geoPos;
    mImageSize = imageSize;
    mImageSizeText=imageSize;
    mImageAnchor = imageAnchor;
    mImageAnchorText = imageAnchor;
    calculateGeometry();
}
void QGVImage::setGeometry(const QGV::GeoPos& geoPos, const QSize& imageSize,const QString& text, const QPoint& imageAnchor)
{
    mGeometryType = GeometryType::ByText;
    mGeoPos = geoPos;
    mImageSize = imageSize;
    mImageAnchor = imageAnchor;
    mImageAnchorText = imageAnchor;
    mText=text;
    calculateGeometry();

}


QImage QGVImage::getImage() const
{
    return mImage;
}

bool QGVImage::isImage() const
{
    return !mImage.isNull();
}

void QGVImage::load(const QString& url)
{
    Q_ASSERT(QGV::getNetworkManager());
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent",
                         "Mozilla/5.0 (Windows; U; MSIE "
                         "6.0; Windows NT 5.1; SV1; .NET "
                         "CLR 2.0.50727)");
    request.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    mReply.reset(QGV::getNetworkManager()->get(request));
    connect(mReply.data(), &QNetworkReply::finished, this, &QGVImage::onReplyFinished);
    qgvDebug() << "request" << url;
}

void QGVImage::loadImage(const QByteArray& rawData)
{
    QImage image;
    image.loadFromData(rawData);
    loadImage(image);
}

void QGVImage::loadImage(const QImage& image)
{
    mImage = image;
}

void QGVImage::onProjection(QGVMap* geoMap)
{
    QGVDrawItem::onProjection(geoMap);
    calculateGeometry();
}

QPainterPath QGVImage::projShape() const
{
    QPainterPath path;
    path.addRect(mProjRect);
    return path;
}
QPainterPath QGVImage::projShapeText() const
{
    QPainterPath path;
    path.addRect(mProjRectText);
    return path;
}

QPointF QGVImage::projAnchor() const
{
    if (mProjAnchor.isNull()) {
        return QGVDrawItem::projAnchor();
    }
    return mProjAnchor;
}

QPointF QGVImage::projAnchorText() const
{
    if (mProjAnchorText.isNull()) {
        return QGVDrawItem::projAnchorText();
    }
    return mProjAnchorText;
}


void QGVImage::projPaint(QPainter* painter)
{
    if (mImage.isNull() || mProjRect.isEmpty()) {
        return;
    }
    QRectF paintRect = mProjRect;
    paintRect.setSize(mProjRect.size());

    if (!isFlag(QGV::ItemFlag::IgnoreScale)) {
        const double pixelFactor = 1.0 / getMap()->getCamera().scale();
        paintRect.setSize(paintRect.size() + QSizeF(pixelFactor, pixelFactor));


    }


    painter->setRenderHint(QPainter::SmoothPixmapTransform);

    painter->drawImage(paintRect, getImage());
    //painter->drawText(paintRect, _FullName_str);

}
void QGVImage::projPaintText(QPainter* painterText)
{
    qDebug() << (int)mProjRectText.x() << "1xy" << (int)mProjRectText.y();
    qDebug() << mProjRectText.width() << "1wh" << mProjRectText.height();
    if (mImage.isNull() || mProjRectText.isEmpty()) {
        return;
    }
    QRectF paintRectText = mProjRectText;

    if (!isFlag(QGV::ItemFlag::IgnoreScale)) {
        const double pixelFactor = 1.0 / getMap()->getCamera().scale();
        paintRectText.setSize(paintRectText.size() + QSizeF(pixelFactor, pixelFactor));


    }
    painterText->setRenderHint(QPainter::SmoothPixmapTransform);
    //----- Рисуем наименование -----
    _FullName_str=mText;

    painterText->setFont(QFont(painterText->font().family(), 10));
    painterText->setPen(QPen(_IsConfiguration_b ? Qt::black : Qt::darkGray));
//    QFontMetrics fm(QFont(painterText->font().family(), 10));
    qDebug() << paintRectText.x() << "xy" << paintRectText.y();
    qDebug() << paintRectText.width() << "wh" << paintRectText.height();



    //painterText->drawText( paintRectText.x(),  paintRectText.y(), _FullName_str);
    //painterText->drawImage(paintRectText, getImage());
                //DT_CALCRECT(_FullName_str);
//    qreal sw, sh;
//    sw=fm.horizontalAdvance(_FullName_str);
//    sh=fm.height();
//    paintRectText.setWidth(sw);
//    paintRectText.setHeight(sw);
    //paintRectText=fm.boundingRect(_FullName_str);
    painterText->drawText(paintRectText, _FullName_str);
    //painterText->drawText(paintRectText.x(),  paintRectText.y(),sw,sh,Qt::AlignVCenter,_FullName_str);
    qDebug() << paintRectText.x() << "1xy1" << paintRectText.y();
    qDebug() << paintRectText.width() << "1wh1" << paintRectText.height();



}

void QGVImage::onReplyFinished()
{
    if (mReply.isNull()) {
        return;
    }
    if (mReply->error() != QNetworkReply::NoError) {
        qgvCritical() << "ERROR" << mReply->errorString();
        mReply.reset(nullptr);
        return;
    }
    loadImage(mReply->readAll());
    mReply.reset(nullptr);
}

void QGVImage::calculateGeometry()
{
    mProjRect = {};
    mProjRectText= {};
    mProjAnchor = {};
    mProjAnchorText = {};
    mImageSizeText={};

    if (mGeometryType == GeometryType::None || getMap() == nullptr) {
        return;
    }
    if (mGeometryType == GeometryType::ByRect) {
        mProjRect = getMap()->getProjection()->geoToProj(mGeoRect);
        resetBoundary();
        refresh();
    } else if (mGeometryType == GeometryType::ByPos) {
        if (mImageSize.isEmpty() && mImage.isNull()) {
            return;
        }
        const QPointF anchor =
                (mImageAnchor.isNull()) ? QPointF(mImageSize.width(), mImageSize.height()) : mImageAnchor;
//нахождения центра у прямоугольника
        //нахождения центра у прямоугольника
        const QPointF basePos = getMap()->getProjection()->geoToProj(mGeoPos);
        mProjRect = QRectF(basePos - anchor, mImageSize);//отрисовка прямоугольника в который будет помещена картинка
        mProjAnchor = basePos;
        resetBoundary();
        refresh();
    }
    else if (mGeometryType == GeometryType::ByText) {
        QFontMetrics fm(QFont("Times",10));
        qreal sw, sh;
        sw=fm.horizontalAdvance(mText);
        sh=fm.height();
        mImageSizeText=QSize(sw, sh);
            if (mImageSize.isEmpty() && mImage.isNull()) {
                return;
            }
            if (mImageSizeText.isEmpty() && mImageSizeText.isNull()) {
                return;
            }
            const QPointF anchor =
                    (mImageAnchor.isNull()) ? QPointF(mImageSize.width(), mImageSize.height()) : mImageAnchor;
            const QPointF anchortext =
                    (mImageAnchorText.isNull()) ? QPointF(mImageSizeText.width(), mImageSizeText.height()) : mImageAnchorText; //нахождения центра у прямоугольника
            //нахождения центра у прямоугольника
            const QPointF basePos = getMap()->getProjection()->geoToProj(mGeoPos);
            mProjRect = QRectF(basePos - anchor, mImageSize);//отрисовка прямоугольника в который будет помещена картинка
            mProjRectText= QRectF(basePos, mImageSizeText*2);
            mProjAnchor = basePos;
            mProjAnchorText = basePos;
            qDebug() << mProjRectText.width() << "mProjRectText" << mProjRectText.height();
            resetBoundary();
            refresh();
        }

}
