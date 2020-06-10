#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QMainWindow>
#include "Book.h"

namespace Ui {
class AddBook;
}

class AddBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();
signals:
    void signalElement(Book temp);
private slots:
    void on_set_clicked();

private:
    Ui::AddBook *ui;
    bool is_int(std::string temp);
};

#endif // ADDBOOK_H
