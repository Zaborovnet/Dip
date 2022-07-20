#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <proj.h>
#include <iostream>
#include <cmath>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appcore.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    ui->quickWidget_2->setSource(QUrl(QStringLiteral("qrc:/map2.qml")));
    ui->quickWidget_2->show();
    //->quickWidget_3->setSource(QUrl(QStringLiteral("qrc:/map3.qml")));
    //ui->quickWidget_3->show();
    ui->quickWidget_4->setSource(QUrl(QStringLiteral("qrc:/map4.qml")));
    ui->quickWidget_4->show();
    ui->quickWidget_5->setSource(QUrl(QStringLiteral("qrc:/map5.qml")));
    ui->quickWidget_5->show();


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(digital()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digital1()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digital2()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digital3()));


    QQmlApplicationEngine engine; // Создаём движок qml

    AppCore appCore;    // Создаём ядро приложения
    QQmlContext *context = engine.rootContext();    // Создаём корневой контекст
    /* Загружаем объект в контекст для установки соединения,
     * а также определяем имя, по которому будет происходить соединение
     * */
    context->setContextProperty("appCore", &appCore);
    engine.load(QUrl(QStringLiteral("qrc:/map5.qml")));



}

MainWindow::~MainWindow()
{



    delete ui;
}

void MainWindow::digital()
{
    char* Massiv; // char Massiv[10000] = {0};



        QString string = ui->textEdit->toPlainText().trimmed();

        Massiv = new char[string.size() + 1];
        memset(Massiv,0, string.size() + 1);
        memcpy(Massiv,string.toLocal8Bit().data(),string.size());
        ui->textEdit_2->insertPlainText(Massiv);

        int i = ui->comboBox->currentIndex(); /// номер текущего итема по счёту начиная с 0
           /// если работа с конвертированием массы то

           switch (i) {
           case 0:{ /// если обычные градусы

           auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                            "+proj=longlat +ellps=WGS84",
                                                            "+proj=merc",
                                                            NULL);

           QString string = ui->textEdit->toPlainText().trimmed();
           QString string1 = ui->textEdit_14->toPlainText().trimmed();



               PJ_COORD in;
               in.xy.x = string.toDouble();
               in.xy.y = string1.toDouble();

               auto out = proj_trans(projectionCtx, PJ_FWD, in);


               ui->textEdit_2->setText(QString("%1,    %2").arg(out.xy.x).arg(out.xy.y));

               break;}
           case 1:{ /// если градусы, минуты, секунды


                      auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                       "+proj=longlat +ellps=WGS84",
                                                                       "+proj=merc",
                                                                       NULL);
           //x
                      QString string = ui->textEdit->toPlainText().trimmed();//градусы
                      QString string1 = ui->textEdit_7->toPlainText().trimmed();//минуты
                      QString string2 = ui->textEdit_8->toPlainText().trimmed();//секунды

           //y
                      QString string3 = ui->textEdit_14->toPlainText().trimmed();//градусы
                      QString string4 = ui->textEdit_15->toPlainText().trimmed();//минуты
                      QString string5 = ui->textEdit_13->toPlainText().trimmed();//секунды


                          PJ_COORD in;
                          in.xy.x = string.toDouble()+(string1.toDouble()/60)+(string2.toDouble()/3600);
                          in.xy.y = string3.toDouble()+(string4.toDouble()/60)+(string5.toDouble()/3600);

                          auto out = proj_trans(projectionCtx, PJ_FWD, in);


                          ui->textEdit_2->setText(QString("%1,    %2").arg(out.xy.x).arg(out.xy.y));

                          break;}
               break;
           case 2: {/// если радианы
               auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                "+proj=longlat +ellps=WGS84 ",
                                                                "+proj=merc",
                                                                NULL);

               QString string = ui->textEdit->toPlainText().trimmed();
               QString string1 = ui->textEdit_14->toPlainText().trimmed();



                   PJ_COORD in;
                   in.xy.x = string.toDouble()*(180/M_PI);
                   in.xy.y = string1.toDouble()*(180/M_PI);

                   auto out = proj_trans(projectionCtx, PJ_FWD, in);


                   ui->textEdit_2->setText(QString("%1,    %2").arg(out.xy.x).arg(out.xy.y));

                   break;}
               break;
           case 3: {/// если Проекция Гаусса-Крюгера
                          auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                           "+proj=tmerc +x_0=3500000 +y_0=0",
                                                                           "+proj=longlat",
                                                                           NULL);

                          QString string = ui->textEdit->toPlainText().trimmed();
                          QString string1 = ui->textEdit_14->toPlainText().trimmed();



                              PJ_COORD in;
                              in.xy.x = string.toDouble();
                              in.xy.y = string1.toDouble();

                              auto out = proj_trans(projectionCtx, PJ_FWD, in);

                              in.xy.x = out.xy.x;
                              in.xy.y = out.xy.y;

                              auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                               "+proj=longlat",
                                                                               "+proj=merc",
                                                                               NULL);

                              auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);


                              ui->textEdit_2->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));

                              break;}
               break;
           default:
               break;
           }





}

void MainWindow::digital1()
{


        int i = ui->comboBox->currentIndex(); /// номер текущего итема по счёту начиная с 0
           /// если работа с конвертированием массы то

           switch (i) {
           case 0:{ /// если обычные градусы

           auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                            "+proj=longlat +ellps=WGS84",
                                                            "+proj=merc",
                                                            NULL);

           QString string = ui->textEdit->toPlainText().trimmed();
           QString string1 = ui->textEdit_14->toPlainText().trimmed();

        //относительные коардинаты
           QString string2 = ui->textEdit_5->toPlainText().trimmed();
           QString string3 = ui->textEdit_16->toPlainText().trimmed();



               PJ_COORD in;
               in.xy.x = string.toDouble();
               in.xy.y = string1.toDouble();

               auto out = proj_trans(projectionCtx, PJ_FWD, in);

          //прибавляем относительные коардинаты
               in.xy.x=out.xy.x+string2.toDouble();
               in.xy.y=out.xy.y+string3.toDouble();

          //перевод относителых+начальных коардинат в longlat

               auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                "+proj=merc",
                                                                "+proj=longlat",
                                                                NULL);
             auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



               ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));

               break;}
           case 1:{ /// если градусы, минуты, секунды


                      auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                       "+proj=longlat +ellps=WGS84",
                                                                       "+proj=merc",
                                                                       NULL);
           //x
                      QString string = ui->textEdit->toPlainText().trimmed();//градусы
                      QString string1 = ui->textEdit_7->toPlainText().trimmed();//минуты
                      QString string2 = ui->textEdit_8->toPlainText().trimmed();//секунды

           //y
                      QString string3 = ui->textEdit_14->toPlainText().trimmed();//градусы
                      QString string4 = ui->textEdit_15->toPlainText().trimmed();//минуты
                      QString string5 = ui->textEdit_13->toPlainText().trimmed();//секунды

                      //относительные коардинаты
                         QString string6 = ui->textEdit_5->toPlainText().trimmed();
                         QString string7 = ui->textEdit_16->toPlainText().trimmed();


                          PJ_COORD in;
                          in.xy.x = string.toDouble()+(string1.toDouble()/60)+(string2.toDouble()/3600);
                          in.xy.y = string3.toDouble()+(string4.toDouble()/60)+(string5.toDouble()/3600);

                          auto out = proj_trans(projectionCtx, PJ_FWD, in);

                          //прибавляем относительные коардинаты
                               in.xy.x=out.xy.x+string6.toDouble();
                               in.xy.y=out.xy.y+string7.toDouble();

                          //перевод относителых+начальных коардинат в longlat

                            auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                                "+proj=merc",
                                                                                "+proj=longlat",
                                                                                NULL);
                             auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                               ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));
                          break;}
               break;
           case 2: {/// если радианы
               auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                "+proj=longlat +ellps=WGS84 ",
                                                                "+proj=merc",
                                                                NULL);

               QString string = ui->textEdit->toPlainText().trimmed();
               QString string1 = ui->textEdit_14->toPlainText().trimmed();

               //относительные коардинаты
                  QString string2 = ui->textEdit_5->toPlainText().trimmed();
                  QString string3 = ui->textEdit_16->toPlainText().trimmed();



                   PJ_COORD in;
                   in.xy.x = string.toDouble()*(180/M_PI);
                   in.xy.y = string1.toDouble()*(180/M_PI);

                   auto out = proj_trans(projectionCtx, PJ_FWD, in);

                   //прибавляем относительные коардинаты
                        in.xy.x=out.xy.x+string2.toDouble();
                        in.xy.y=out.xy.y+string3.toDouble();

                   //перевод относителых+начальных коардинат в longlat

                        auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                         "+proj=merc",
                                                                         "+proj=longlat",
                                                                         NULL);
                      auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                        ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));
                   break;}
               break;
           case 3: {/// если Проекция Гаусса-Крюгера
                          auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                           "+proj=tmerc +ellps=WGS84 +proj=utm +zone=35",
                                                                           "+proj=merc",
                                                                           NULL);

                          QString string = ui->textEdit->toPlainText().trimmed();
                          QString string1 = ui->textEdit_14->toPlainText().trimmed();


                          //относительные коардинаты
                             QString string2 = ui->textEdit_5->toPlainText().trimmed();
                             QString string3 = ui->textEdit_16->toPlainText().trimmed();

                              PJ_COORD in;
                              in.xy.x = string.toDouble();
                              in.xy.y = string1.toDouble();

                              auto out = proj_trans(projectionCtx, PJ_FWD, in);

                              //прибавляем относительные коардинаты
                                   in.xy.x=out.xy.x+string2.toDouble();
                                   in.xy.y=out.xy.y+string3.toDouble();

                              //перевод относителых+начальных коардинат в longlat

                                   auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                                    "+proj=merc",
                                                                                    "+proj=longlat",
                                                                                    NULL);
                                 auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                                   ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));
                              break;}
               break;
           default:
               break;
           }





}

void MainWindow::digital2()
{


    auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                 "+proj=longlat +ellps=WGS84",
                                                 "+proj=merc",
                                                 NULL);



    PJ_COORD in;
    in.xy.x = 45;
    in.xy.y = 45;

    auto out = proj_trans(projectionCtx, PJ_FWD, in);


    ui->textEdit_3->setText(QString("%1,    %2").arg(out.xy.x).arg(out.xy.y));


    PJ_INFO vers;
    vers = proj_info();
    ui->textEdit_4->setText(QString::number(vers.major));
    proj_destroy(projectionCtx);

    PJ_COORD proj_trans(PJ *P, PJ_DIRECTION direction, PJ_COORD coord);


}

void MainWindow::digital3()
{

    auto rad = 6372795;

    int i = ui->comboBox->currentIndex(); /// номер текущего итема по счёту начиная с 0

       switch (i) {
       case 0:{ /// если обычные градусы

       auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                        "+proj=longlat +ellps=WGS84",
                                                        "+proj=merc",
                                                        NULL);

       QString string = ui->textEdit->toPlainText().trimmed();
       QString string1 = ui->textEdit_14->toPlainText().trimmed();

    //относительные коардинаты
       QString string2 = ui->textEdit_5->toPlainText().trimmed();
       QString string3 = ui->textEdit_16->toPlainText().trimmed();




           PJ_COORD in;
           in.xy.x = string.toDouble();
           in.xy.y = string1.toDouble();

           auto out = proj_trans(projectionCtx, PJ_FWD, in);

      //прибавляем относительные коардинаты
           in.xy.x=out.xy.x+string2.toDouble();
           in.xy.y=out.xy.y+string3.toDouble();

      //перевод относителых+начальных коардинат в longlat

           auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                            "+proj=merc",
                                                            "+proj=longlat",
                                                            NULL);
         auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



           ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));

        //координаты двух точек
        auto llat1 = string.toDouble();
        auto llong1 = string1.toDouble();

        auto llat2 = out2.xy.x;
        auto llong2 = out2.xy.y;

        //в радианах
         auto lat1 = llat1*M_PI/180;
         auto lat2 = llat2*M_PI/180;
         auto long1 = llong1*M_PI/180;
         auto long2 = llong2*M_PI/180;

        //косинусы и синусы широт и разницы долгот
        auto cl1 = cos(lat1);
        auto cl2 = cos(lat2);
        auto sl1 = sin(lat1);
        auto sl2 = sin(lat2);
        auto delta = long2 - long1;
        auto cdelta = cos(delta);
        auto sdelta = sin(delta);

        //вычисления длины большого круга
        auto y = sqrt(pow(cl2*sdelta,2)+pow(cl1*sl2-sl1*cl2*cdelta,2));
        auto x = sl1*sl2+cl1*cl2*cdelta;
        auto ad = atan2(y,x);
        auto dist = ad*rad;

        //вычисление начального азимута
        x = (cl1*sl2) - (sl1*cl2*cdelta);
        y = sdelta*cl2;
        double z = (atan(-y/x))*(180/M_PI);

        if (x < 0){
            z = z+180;
        }

         auto z2 = fmod((z+180), 360) - 180;
         z2 = -(z2)*(M_PI/180);
         auto anglerad2 = z2 - ((2*M_PI)*floor((z2/(2*M_PI))) );
         auto angledeg = (anglerad2*180)/M_PI;

         ui->textEdit_17->setText(QString("%1").arg(dist));
         ui->textEdit_18->setText(QString("%1").arg(angledeg));




           break;}
       case 1:{ /// если градусы, минуты, секунды


                  auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                   "+proj=longlat +ellps=WGS84",
                                                                   "+proj=merc",
                                                                   NULL);
       //x
                  QString string = ui->textEdit->toPlainText().trimmed();//градусы
                  QString string1 = ui->textEdit_7->toPlainText().trimmed();//минуты
                  QString string2 = ui->textEdit_8->toPlainText().trimmed();//секунды

       //y
                  QString string3 = ui->textEdit_14->toPlainText().trimmed();//градусы
                  QString string4 = ui->textEdit_15->toPlainText().trimmed();//минуты
                  QString string5 = ui->textEdit_13->toPlainText().trimmed();//секунды

                  //относительные коардинаты
                     QString string6 = ui->textEdit_5->toPlainText().trimmed();
                     QString string7 = ui->textEdit_16->toPlainText().trimmed();


                      PJ_COORD in;
                      in.xy.x = string.toDouble()+(string1.toDouble()/60)+(string2.toDouble()/3600);
                      in.xy.y = string3.toDouble()+(string4.toDouble()/60)+(string5.toDouble()/3600);

                      auto out = proj_trans(projectionCtx, PJ_FWD, in);

                      //прибавляем относительные коардинаты
                           in.xy.x=out.xy.x+string6.toDouble();
                           in.xy.y=out.xy.y+string7.toDouble();

                      //перевод относителых+начальных коардинат в longlat

                        auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                            "+proj=merc",
                                                                            "+proj=longlat",
                                                                            NULL);
                         auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                           ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));

                           //координаты двух точек
                           auto llat1 = in.xy.x;
                           auto llong1 = in.xy.y;

                           auto llat2 = out2.xy.x;
                           auto llong2 = out2.xy.y;

                           //в радианах
                            auto lat1 = llat1*M_PI/180;
                            auto lat2 = llat2*M_PI/180;
                            auto long1 = llong1*M_PI/180;
                            auto long2 = llong2*M_PI/180;

                           //косинусы и синусы широт и разницы долгот
                           auto cl1 = cos(lat1);
                           auto cl2 = cos(lat2);
                           auto sl1 = sin(lat1);
                           auto sl2 = sin(lat2);
                           auto delta = long2 - long1;
                           auto cdelta = cos(delta);
                           auto sdelta = sin(delta);

                           //вычисления длины большого круга
                           auto y = sqrt(pow(cl2*sdelta,2)+pow(cl1*sl2-sl1*cl2*cdelta,2));
                           auto x = sl1*sl2+cl1*cl2*cdelta;
                           auto ad = atan2(y,x);
                           auto dist = ad*rad;

                           //вычисление начального азимута
                           x = (cl1*sl2) - (sl1*cl2*cdelta);
                           y = sdelta*cl2;
                           double z = (atan(-y/x))*(180/M_PI);

                           if (x < 0){
                               z = z+180;
                           }

                            auto z2 = fmod((z+180), 360) - 180;
                            z2 = -(z2)*(M_PI/180);
                            auto anglerad2 = z2 - ((2*M_PI)*floor((z2/(2*M_PI))) );
                            auto angledeg = (anglerad2*180)/M_PI;

                            ui->textEdit_17->setText(QString("%1").arg(dist));
                            ui->textEdit_18->setText(QString("%1").arg(angledeg));

                      break;}
           break;
       case 2: {/// если радианы
           auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                            "+proj=longlat +ellps=WGS84 ",
                                                            "+proj=merc",
                                                            NULL);

           QString string = ui->textEdit->toPlainText().trimmed();
           QString string1 = ui->textEdit_14->toPlainText().trimmed();

           //относительные коардинаты
              QString string2 = ui->textEdit_5->toPlainText().trimmed();
              QString string3 = ui->textEdit_16->toPlainText().trimmed();



               PJ_COORD in;
               in.xy.x = string.toDouble()*(180/M_PI);
               in.xy.y = string1.toDouble()*(180/M_PI);

               auto out = proj_trans(projectionCtx, PJ_FWD, in);

               //прибавляем относительные коардинаты
                    in.xy.x=out.xy.x+string2.toDouble();
                    in.xy.y=out.xy.y+string3.toDouble();

               //перевод относителых+начальных коардинат в longlat

                    auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                     "+proj=merc",
                                                                     "+proj=longlat",
                                                                     NULL);
                  auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                    ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));


                    //координаты двух точек
                    auto llat1 = in.xy.x;
                    auto llong1 = in.xy.y;

                    auto llat2 = out2.xy.x;
                    auto llong2 = out2.xy.y;

                    //в радианах
                     auto lat1 = llat1*M_PI/180;
                     auto lat2 = llat2*M_PI/180;
                     auto long1 = llong1*M_PI/180;
                     auto long2 = llong2*M_PI/180;

                    //косинусы и синусы широт и разницы долгот
                    auto cl1 = cos(lat1);
                    auto cl2 = cos(lat2);
                    auto sl1 = sin(lat1);
                    auto sl2 = sin(lat2);
                    auto delta = long2 - long1;
                    auto cdelta = cos(delta);
                    auto sdelta = sin(delta);

                    //вычисления длины большого круга
                    auto y = sqrt(pow(cl2*sdelta,2)+pow(cl1*sl2-sl1*cl2*cdelta,2));
                    auto x = sl1*sl2+cl1*cl2*cdelta;
                    auto ad = atan2(y,x);
                    auto dist = ad*rad;

                    //вычисление начального азимута
                    x = (cl1*sl2) - (sl1*cl2*cdelta);
                    y = sdelta*cl2;
                    double z = (atan(-y/x))*(180/M_PI);

                    if (x < 0){
                        z = z+180;
                    }

                     auto z2 = fmod((z+180), 360) - 180;
                     z2 = -(z2)*(M_PI/180);
                     auto anglerad2 = z2 - ((2*M_PI)*floor((z2/(2*M_PI))) );
                     auto angledeg = (anglerad2*180)/M_PI;

                     ui->textEdit_17->setText(QString("%1").arg(dist));
                     ui->textEdit_18->setText(QString("%1").arg(angledeg));

               break;}
           break;
       case 3: {/// если Проекция Гаусса-Крюгера
                      auto *projectionCtx = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                       "+proj=tmerc +ellps=WGS84 +proj=utm +zone=35",
                                                                       "+proj=merc",
                                                                       NULL);

                      QString string = ui->textEdit->toPlainText().trimmed();
                      QString string1 = ui->textEdit_14->toPlainText().trimmed();


                      //относительные коардинаты
                         QString string2 = ui->textEdit_5->toPlainText().trimmed();
                         QString string3 = ui->textEdit_16->toPlainText().trimmed();

                          PJ_COORD in;
                          in.xy.x = string.toDouble();
                          in.xy.y = string1.toDouble();

                          auto out = proj_trans(projectionCtx, PJ_FWD, in);

                          //прибавляем относительные коардинаты
                               in.xy.x=out.xy.x+string2.toDouble();
                               in.xy.y=out.xy.y+string3.toDouble();

                          //перевод относителых+начальных коардинат в longlat

                               auto *projectionCtx1 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                                "+proj=merc",
                                                                                "+proj=longlat",
                                                                                NULL);
                             auto out2 = proj_trans(projectionCtx1, PJ_FWD, in);



                               ui->textEdit_6->setText(QString("%1,    %2").arg(out2.xy.x).arg(out2.xy.y));

                               //координаты двух точек

                               in.xy.x = string.toDouble();
                               in.xy.y = string1.toDouble();

                             auto *projectionCtx2 = proj_create_crs_to_crs(PJ_DEFAULT_CTX,
                                                                                "+proj=tmerc +ellps=WGS84 +proj=utm +zone=35",
                                                                                "+proj=longlat",
                                                                                NULL);
                             auto out3 = proj_trans(projectionCtx2, PJ_FWD, in);



                               auto llat1 = out3.xy.x;
                               auto llong1 = out3.xy.y;

                               auto llat2 = out2.xy.x;
                               auto llong2 = out2.xy.y;

                               //в радианах
                                auto lat1 = llat1*M_PI/180;
                                auto lat2 = llat2*M_PI/180;
                                auto long1 = llong1*M_PI/180;
                                auto long2 = llong2*M_PI/180;

                               //косинусы и синусы широт и разницы долгот
                               auto cl1 = cos(lat1);
                               auto cl2 = cos(lat2);
                               auto sl1 = sin(lat1);
                               auto sl2 = sin(lat2);
                               auto delta = long2 - long1;
                               auto cdelta = cos(delta);
                               auto sdelta = sin(delta);

                               //вычисления длины большого круга
                               auto y = sqrt(pow(cl2*sdelta,2)+pow(cl1*sl2-sl1*cl2*cdelta,2));
                               auto x = sl1*sl2+cl1*cl2*cdelta;
                               auto ad = atan2(y,x);
                               auto dist = ad*rad;

                               //вычисление начального азимута
                               x = (cl1*sl2) - (sl1*cl2*cdelta);
                               y = sdelta*cl2;
                               double z = (atan(-y/x))*(180/M_PI);

                               if (x < 0){
                                   z = z+180;
                               }

                                auto z2 = fmod((z+180), 360) - 180;
                                z2 = -(z2)*(M_PI/180);
                                auto anglerad2 = z2 - ((2*M_PI)*floor((z2/(2*M_PI))) );
                                auto angledeg = (anglerad2*180)/M_PI;

                                ui->textEdit_17->setText(QString("%1").arg(dist));
                                ui->textEdit_18->setText(QString("%1").arg(angledeg));


                          break;}
           break;
       default:
           break;
       }




}


