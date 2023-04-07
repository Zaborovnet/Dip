#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QNetworkAccessManager>
#include <QNetworkDiskCache>

#include <QGeoView/QGVWidgetCompass.h>
#include <QGeoView/QGVWidgetScale.h>
#include <QGeoView/QGVWidgetZoom.h>

#include <QMainWindow>
#include "demoitem.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //MainWindow();
    ~MainWindow();


private Q_SLOTS:
    void init();

signals:
  void changeCoord(double lon, double lat);

private slots:
    void digital();
    void digital1();
    void digital2();
    void digital3();
    int long2tilex(double lon, int z);
    int lat2tiley(double lat, int z);
    double tilex2long(int x, int z);
    double tiley2lat(int y, int z);
    void onOkBtnClick();



private:
    void stopCurrent();
    void onItemDoubleClick();
    void onItemStarted(DemoItem* item);
    void onItemEnded(DemoItem* item);




private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* mManager;
    QNetworkDiskCache* mCache;
    DemoItem* mCurrentItem;
    QList<DemoItem*> mDemo;
};



;
#endif // MAINWINDOW_H
