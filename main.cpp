#include "mainwindow.h"
#include <iostream>


#include <QApplication>
#include <proj.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //PJ_INFO vers;
    //vers = proj_info();
    //std::cout << "major_version: " << vers.major << std::endl;





    return a.exec();
}
