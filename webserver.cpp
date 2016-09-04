#include "webserver.h"
#include <QWebSocket>

WebServer::WebServer(QObject *parent) :
    QWebSocketServer("MyServer", QWebSocketServer::NonSecureMode, parent)
{
    mSocket = NULL;
    connect(this, SIGNAL(newConnection()),
            this, SLOT(wsNewConnection()));
}

void WebServer::wsNewConnection()
{
    mSocket = nextPendingConnection();
    connect(mSocket, SIGNAL(textMessageReceived(QString)),
             this, SLOT(onMessageReceived(QString)));
}

void WebServer::onMessageReceived(const QString &Value)
{
    emit messageReceived(Value);
}
