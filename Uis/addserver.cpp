#include "addserver.h"
#include "ui_addserver.h"

AddServer::AddServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddServer)
{
    ui->setupUi(this);
}

AddServer::~AddServer()
{
    delete ui;
}

void AddServer::on_set_clicked()
{
    std::string id = ui->id->text().toStdString();
    std::string model = ui->model->text().toStdString();
    std::string company = ui->company->text().toStdString();
    std::string address = ui->address->text().toStdString();

    Server *temp = new Server( company,  address,  model,  id);
    emit signalElement(*temp);
    this->close();
}
