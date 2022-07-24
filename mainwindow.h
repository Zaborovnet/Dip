#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AppCore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//namespace Ui { class Map; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digital();
    void digital1();
    void digital2();
    void digital3();
    int long2tilex(double lon, int z);
    int lat2tiley(double lat, int z);
    double tilex2long(int x, int z);
    double tiley2lat(int y, int z);








private:
    Ui::MainWindow *ui;
};



;
#endif // MAINWINDOW_H
