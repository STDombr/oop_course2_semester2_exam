//
// Created by User on 09.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_BOOK_H
#define OOP_COURSE2_SEMESTER2_EXAM_BOOK_H
#include <string>
using namespace std;

class Book {
private:
    string publishingCompany;
    string author;
    int year;
    string genre; // VALUE
    string bookName;  // KEY

public:
    Book();
    Book(string, string, int, string, string);

    string get_publishingCompany();
    string get_author();
    int get_year();
    string get_genre();
    string get_bookName();

    void random();

    void set_genre(string genre);

    friend bool operator == (Book left, Book right);
    friend bool operator > (Book left, Book right);
    friend bool operator >= (Book left, Book right);
    friend bool operator < (Book left, Book right);
    friend bool operator <= (Book left, Book right);
    friend std::ostream& operator << (std::ostream &out, Book temp);
};


#endif //OOP_COURSE2_SEMESTER2_EXAM_BOOK_H
