#include "addelement.h"
#include "ui_addelement.h"
#include <QMessageBox>
#include <sstream>
#include <iostream>

extern int radio_data;
/**
      *This constructor created window to set element
      */
AddElement::AddElement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddElement)
{
    ui->setupUi(this);
}

AddElement::~AddElement()
{
    delete ui;
}
/**
   *Set element when the button is clicked
   */
void AddElement::on_set_clicked()
{
    std::string temp = ui->lineEdit->text().toStdString();
    bool b = 1;
    if (temp == "")
        b = 0;
    else
    {
        int len = temp.size();
        for (int i=0;i<len;i++)
            if (!isdigit(temp[i]))
                b = 0;
    }
        if (b)
        {

            emit signalElement(ui->lineEdit->text());
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid data!");
            msgBox.exec();
        }
}
/**
   *Function that check if the number is int
   */
bool is_int(std::string temp)
{
    if (temp == "")
        return 0;
    int len = temp.size();
    for (int i=0;i<len;i++)
        if (!isdigit(temp[i]))
            return 0;
    return 1;
}

/**
   *Function that check if the number is double
   */
bool is_double(std::string in)
{
    std::istringstream iss(in);
    double f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}
