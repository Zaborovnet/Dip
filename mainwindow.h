#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcore.h"

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





private:
    Ui::MainWindow *ui;
};



;
#endif // MAINWINDOW_H
