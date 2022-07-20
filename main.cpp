#include "mainwindow.h"
#include <iostream>


#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appcore.h"
#include <proj.h>



int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    QQmlApplicationEngine engine; // Создаём движок qml

    AppCore appCore;    // Создаём ядро приложения
    engine.rootContext()->setContextProperty("appCore", &appCore);
    engine.load(QUrl::fromLocalFile("map5.qml"));


    //PJ_INFO vers;
    //vers = proj_info();
    //std::cout << "major_version: " << vers.major << std::endl;





    return app.exec();
}
