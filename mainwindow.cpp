#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "wiringPi.h"
#include "stdio.h"
#include "QDebug"
FILE *file;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {color:Red;font-size:36px;}");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
//    wiringPiSetup();
//    pinMode(0,OUTPUT);
}

MainWindow::~MainWindow()
{
    file = fopen("/sys/class/gpio/unexport","rb+");
        if(file == NULL)
        {
            qDebug("Unexport Failed");
        }
        else
        {
            fwrite("17",1,1,file);
            fclose(file);
        }
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("LED ON");
    file = fopen("/sys/class/gpio/export","w"); // set gpio to turn on as 0
        if (file == NULL)
        {
            qDebug("Export Failed");
        }
        else
        {
            fwrite("17",2,1,file);
            fclose(file);
                file = fopen("/sys/class/gpio/gpio17/direction","w"); // set direction of gpio as out
                if (file == NULL)
                {
                    qDebug("Direction Failed");
                }
                else
                {
                    fwrite("out",3,3,file);
                    fclose(file);
                    file = fopen("/sys/class/gpio/gpio17/value","rb+");
                    if (file == NULL)
                    {
                        qDebug("Value Failed");
                    }
                    else
                    {
                        fwrite("1",1,1,file);
                        fclose(file);
                    }

                }
        }

//    digitalWrite(0,HIGH);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("LED OFF");
    file = fopen("/sys/class/gpio/export","w"); // set gpio to turn on as 0
        if (file == NULL)
        {
            qDebug("Export Failed");
        }
        else
        {
            fwrite("17",2,1,file);
            fclose(file);
                file = fopen("/sys/class/gpio/gpio17/direction","w"); // set direction of gpio as out
                if (file == NULL)
                {
                    qDebug("Direction Failed");
                }
                else
                {
                    fwrite("out",3,3,file);
                    fclose(file);
                }
                file = fopen("/sys/class/gpio/gpio17/value","rb+");
                if (file == NULL)
                {
                    qDebug("Value Failed");
                }
                else
                {
                    fwrite("0",1,1,file);
                    fclose(file);
                }
        }
//    digitalWrite(0,LOW);
}
