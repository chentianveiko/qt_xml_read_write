#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configXmlReadWrite/configxmlreadwrite.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("praser.xml");

    configXmlReadWrite reader(ui->textBrowser_dis_par);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"File has loaded...";
        reader.read(&file);
    }
    else
    {
        qDebug()<<"No file to read...";
    }
    file.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
