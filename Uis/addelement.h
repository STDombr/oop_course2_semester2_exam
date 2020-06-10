#ifndef ADDELEMENT_H
#define ADDELEMENT_H

#include <QMainWindow>

namespace Ui {
class AddElement;
}

/**
  *The AddElement is the form which you can set element
  */
class AddElement : public QMainWindow
{
    Q_OBJECT
public:
    /**
          *This constructor created window to set element
          */
    explicit AddElement(QWidget *parent = nullptr);
    ~AddElement();

private slots:
    /**
       *Set element when the button is clicked
       */
    void on_set_clicked();

private:
    Ui::AddElement *ui;

signals:
    void signalElement(QString temp);
};

/**
   *Function that check if the number is double
   */
bool is_double(std::string in);

#endif // ADDELEMENT_H
