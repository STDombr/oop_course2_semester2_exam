#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ContainerInterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_random_clicked();

    void on_pushButton_random_2_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_intersect_clicked();

    void on_pushButton_except_clicked();

    void on_pushButton_Sexcept_clicked();

    void on_pushButton_sort_2_clicked();

    void on_radioButton_DL_clicked();

    void on_radioButton_DLC_clicked();

    void on_radioButton_Books_clicked();

    void on_radioButton_Servers_clicked();

    void on_radioButton_int_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_delete_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_union_clicked();

private:
    Ui::MainWindow *ui;
    template<typename T>
    void add_list(ContainerInterface<T> *temp);
    template<typename T>
    void add_list2(ContainerInterface<T> *temp);
    template<typename T>
    void add_list3(ContainerInterface<T> *temp);
    void connect_element1(QString temp);
    void connect_element2(QString temp);
    void connect_book1(Book temp);
    void connect_book2(Book temp);
    void connect_server1(Server temp);
    void connect_server2(Server temp);
};

#endif // MAINWINDOW_H
