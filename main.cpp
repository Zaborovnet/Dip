#include "mainwindow.h"
#include <iostream>

#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "AppCore.h"
#include <proj.h>

#include <QQmlComponent>



int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);



    QApplication app(argc, argv);


    MainWindow w;
    w.show();




    //PJ_INFO vers;
    //vers = proj_info();
    //std::cout << "major_version: " << vers.major << std::endl;





    return app.exec();
    //return a.exec();

}
