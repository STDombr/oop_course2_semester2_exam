#ifndef ADDSERVER_H
#define ADDSERVER_H

#include <QMainWindow>
#include "Server.h"

namespace Ui {
class AddServer;
}

class AddServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddServer(QWidget *parent = nullptr);
    ~AddServer();

private slots:
    void on_set_clicked();

signals:
    void signalElement(Server temp);
private:
    Ui::AddServer *ui;
};

#endif // ADDSERVER_H
