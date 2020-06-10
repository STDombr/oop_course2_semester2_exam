#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addelement.h"
#include "addbook.h"
#include "addserver.h"

int radio_link = 1;
int radio_data = 1;

template<typename T>
ContainerInterface<T> *I1;
template<typename T>
ContainerInterface<T> *I2;
template<typename T>
DLList<T> *DL1;
template<typename T>
DLList<T> *DL2;
template<typename T>
DLList<T> *DL3;
template<typename T>
DLCircularList<T> *DLC1;
template<typename T>
DLCircularList<T> *DLC2;
template<typename T>
DLCircularList<T> *DLC3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_DL->click();
    ui->radioButton_Books->click();
    DL1<Book> = new DLList<Book>;
    I1<Book> = DL1<Book>;
    DL2<Book> = new DLList<Book>;
    I2<Book> = DL2<Book>;

}

MainWindow::~MainWindow()
{
    delete ui;
}

template<typename T>
void MainWindow::add_list(ContainerInterface<T> *temp)
{
    ui->List->clear();
    for(int i=0;i<temp->get_curr_size();i++)
        ui->List->addItem(QString::fromStdString(temp->to_string(i)));
    ui->List->setCurrentRow(0);
}

template<typename T>
void MainWindow::add_list2(ContainerInterface<T> *temp)
{
    ui->List_2->clear();
    for(int i=0;i<temp->get_curr_size();i++)
        ui->List_2->addItem(QString::fromStdString(temp->to_string(i)));
    ui->List_2->setCurrentRow(0);
}

template<typename T>
void MainWindow::add_list3(ContainerInterface<T> *temp)
{
    ui->List_3->clear();
    for(int i=0;i<temp->get_curr_size();i++)
        ui->List_3->addItem(QString::fromStdString(temp->to_string(i)));
    ui->List_3->setCurrentRow(0);
}

void MainWindow::on_pushButton_clicked()
{
    if (radio_data == 3)
    {
        AddElement *AE = new AddElement(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddElement::signalElement,this,&MainWindow::connect_element1);
    }
    else if (radio_data == 1)
    {
        AddBook *AE = new AddBook(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddBook::signalElement,this,&MainWindow::connect_book1);
    }
    else
    {
        AddServer *AE = new AddServer(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddServer::signalElement,this,&MainWindow::connect_server1);
    }
}

void MainWindow::on_pushButton_random_clicked()
{
    if (radio_data == 1)
    {
        I1<Book>->generate(rand()%10);
        add_list(I1<Book>);
    }
    else if (radio_data == 2)
    {
        I1<Server>->generate(rand()%10);
        add_list(I1<Server>);
    }
    else
    {
        I1<int>->generate(rand()%10);
        add_list(I1<int>);
    }
}

void MainWindow::on_pushButton_random_2_clicked()
{
    if (radio_data == 1)
    {
        I2<Book>->generate(rand()%10);
        add_list2(I2<Book>);
    }
    else if (radio_data == 2)
    {
        I2<Server>->generate(rand()%10);
        add_list2(I2<Server>);
    }
    else
    {
        I2<int>->generate(rand()%10);
        add_list2(I2<int>);
    }
}

void MainWindow::on_pushButton_sort_clicked()
{
    if (radio_data == 1)
    {
        I1<Book>->quicksort();
        add_list(I1<Book>);
    }
    else if (radio_data == 2)
    {
        I1<Server>->quicksort();
        add_list(I1<Server>);
    }
    else
    {
        I1<int>->quicksort();
        add_list(I1<int>);
    }
}

void MainWindow::connect_element1(QString temp)
{
    I1<int>->add_node(temp.toInt());
    ui->List->addItem(temp);
}

void MainWindow::connect_element2(QString temp)
{
    I2<int>->add_node(temp.toInt());
    ui->List_2->addItem(temp);
}

void MainWindow::connect_book1(Book temp)
{
    I1<Book>->add_node(temp);
    ui->List->addItem(QString::fromStdString(temp.get_bookName()));
}

void MainWindow::connect_book2(Book temp)
{
    I2<Book>->add_node(temp);
    ui->List_2->addItem(QString::fromStdString(temp.get_bookName()));
}

void MainWindow::connect_server1(Server temp)
{
    I1<Server>->add_node(temp);
    ui->List->addItem(QString::fromStdString(temp.get_serverID()));
}

void MainWindow::connect_server2(Server temp)
{
    I2<Server>->add_node(temp);
    ui->List_2->addItem(QString::fromStdString(temp.get_serverID()));
}

void MainWindow::on_pushButton_sort_2_clicked()
{
    if (radio_data == 1)
    {
        I2<Book>->quicksort();
        add_list2(I2<Book>);
    }
    else if (radio_data == 2)
    {
        I2<Server>->quicksort();
        add_list2(I2<Server>);
    }
    else
    {
        I2<int>->quicksort();
        add_list2(I2<int>);
    }
}

void MainWindow::on_radioButton_DL_clicked()
{
    ui->List->clear();
    ui->List_2->clear();
    if (radio_data == 1)
    {
        DL1<Book> = new DLList<Book>;
        I1<Book> = DL1<Book>;
        DL2<Book> = new DLList<Book>;
        I2<Book> = DL2<Book>;
    }
    else if (radio_data == 2)
    {
        DL1<Server> = new DLList<Server>;
        I1<Server> = DL1<Server>;
        DL2<Server> = new DLList<Server>;
        I2<Server> = DL1<Server>;
    }
    else if (radio_data == 3)
    {
        DL1<int> = new DLList<int>;
        I1<int> = DL1<int>;
        DL2<int> = new DLList<int>;
        I2<int> = DL2<int>;
    }
    radio_link = 1;
}

void MainWindow::on_radioButton_DLC_clicked()
{
    ui->List->clear();
    ui->List_2->clear();
    if (radio_data == 1)
    {
        DLC1<Book> = new DLCircularList<Book>;
        I1<Book> = DLC1<Book>;
        DLC2<Book> = new DLCircularList<Book>;
        I2<Book> = DLC2<Book>;
    }
    else if (radio_data == 2)
    {
        DLC1<Server> = new DLCircularList<Server>;
        I1<Server> = DLC1<Server>;
        DLC2<Server> = new DLCircularList<Server>;
        I2<Server> = DLC2<Server>;
    }
    else if (radio_data == 3)
    {
        DLC1<int> = new DLCircularList<int>;
        I1<int> = DLC1<int>;
        DLC2<int> = new DLCircularList<int>;
        I2<int> = DLC2<int>;
    }
    radio_link = 2;
}

void MainWindow::on_radioButton_Books_clicked()
{
    ui->List->clear();
    ui->List_2->clear();
    if (radio_link == 1)
    {
        DL1<Book> = new DLList<Book>;
        I1<Book> = DL1<Book>;
        DL2<Book> = new DLList<Book>;
        I2<Book> = DL2<Book>;
    } else
    {
        DLC1<Book> = new DLCircularList<Book>;
        I1<Book> = DLC1<Book>;
        DLC2<Book> = new DLCircularList<Book>;
        I2<Book> = DLC2<Book>;
    }
    radio_data = 1;
}

void MainWindow::on_radioButton_Servers_clicked()
{
    ui->List->clear();
    ui->List_2->clear();
    if (radio_link == 1)
    {
        DL1<Server> = new DLList<Server>;
        I1<Server> = DL1<Server>;
        DL2<Server> = new DLList<Server>;
        I2<Server> = DL2<Server>;
    } else
    {
        DLC1<Server> = new DLCircularList<Server>;
        I1<Server> = DLC1<Server>;
        DLC2<Server> = new DLCircularList<Server>;
        I2<Server> = DLC2<Server>;
    }
    radio_data = 2;
}

void MainWindow::on_radioButton_int_clicked()
{
    ui->List->clear();
    ui->List_2->clear();
    if (radio_link == 1)
    {
        DL1<int> = new DLList<int>;
        I1<int> = DL1<int>;
        DL2<int> = new DLList<int>;
        I2<int> = DL2<int>;
    } else
    {
        DLC1<int> = new DLCircularList<int>;
        I1<int> = DLC1<int>;
        DLC2<int> = new DLCircularList<int>;
        I2<int> = DLC2<int>;
    }
    radio_data = 3;
}

void MainWindow::on_pushButton_delete_clicked()
{
    if (radio_data == 1)
    {
        I1<Book>->pop_node();
        delete ui->List->takeItem(I1<Book>->get_curr_size());
    }
    else if (radio_data == 2)
    {
        I1<Server>->pop_node();
        delete ui->List->takeItem(I1<Server>->get_curr_size());
    }
    else if (radio_data == 3)
    {
        I1<int>->pop_node();
        delete ui->List->takeItem(I1<int>->get_curr_size());
    }
}

void MainWindow::on_pushButton_delete_2_clicked()
{
    if (radio_data == 1)
    {
        I2<Book>->pop_node();
        delete ui->List_2->takeItem(I2<Book>->get_curr_size());
    }
    else if (radio_data == 2)
    {
        I2<Server>->pop_node();
        delete ui->List_2->takeItem(I2<Server>->get_curr_size());
    }
    else if (radio_data == 3)
    {
        I2<int>->pop_node();
        delete ui->List_2->takeItem(I2<int>->get_curr_size());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (radio_data == 3)
    {
        AddElement *AE = new AddElement(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddElement::signalElement,this,&MainWindow::connect_element2);
    }
    else if (radio_data == 1)
    {
        AddBook *AE = new AddBook(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddBook::signalElement,this,&MainWindow::connect_book2);
    }
    else
    {
        AddServer *AE = new AddServer(this);
        AE->setWindowModality(Qt::ApplicationModal);
        AE->show();
        connect(AE,&AddServer::signalElement,this,&MainWindow::connect_server2);
    }
}

void MainWindow::on_pushButton_union_clicked()
{
    if (radio_data == 1 && radio_link == 1)
    {
        DL3<Book> = DL1<Book>->union_operation(DL2<Book>);
        add_list3(DL3<Book>);
    }
    else if (radio_data == 2 && radio_link == 1)
    {
        DL3<Server> = DL1<Server>->union_operation(DL2<Server>);
        add_list3(DL3<Server>);
    }
    else if (radio_data == 3 && radio_link == 1)
    {
        DL3<Book> = DL1<Book>->union_operation(DL2<Book>);
        add_list3(DL3<int>);
    }
    else if (radio_data == 1 && radio_link == 2)
    {
        //DLC3<Book> = DLC1<Book>->union_operation(DLC2<Book>);
        add_list3(DLC3<Book>);
    }
    else if (radio_data == 2 && radio_link == 2)
    {
        //DLC3<Server> = DLC1<Server>->union_operation(DLC2<Server>);
        add_list3(DLC3<Server>);
    }
    else if (radio_data == 2 && radio_link == 2)
    {
        //DLC3<int> = DLC1<Server>->union_operation(DLC2<int>);
        add_list3(DLC3<int>);
    }
}
