#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "webserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mWebServer = new WebServer(this);
    mWebServer->listen(QHostAddress::Any,1234);

    connect(mWebServer, SIGNAL(messageReceived(QString)),
            this, SLOT(_messageReceived(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_messageReceived(const QString &Message)
{
    ui->listWidget->addItem(Message);
}
