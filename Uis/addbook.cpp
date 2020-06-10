#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>


AddBook::AddBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_set_clicked()
{
    std::string name = ui->name->text().toStdString();
    std::string year = ui->year->text().toStdString();
    std::string company = ui->company->text().toStdString();
    std::string genre = ui->genre->text().toStdString();
    std::string author = ui->author->text().toStdString();
    bool b = 1;
    if (year == "")
        b = 0;
    else
    {
        int len = year.size();
        for (int i=0;i<len;i++)
            if (!isdigit(year[i]))
                b = 0;
    }
        if (b)
        {
            Book *temp = new Book( company,  author,  ui->year->text().toInt(),  genre,  name);
            emit signalElement(*temp);
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid data!");
            msgBox.exec();
        }
}
