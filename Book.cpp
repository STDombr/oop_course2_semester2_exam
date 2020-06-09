//
// Created by User on 09.06.2020.
//

#include "Book.h"

Book::Book() = default;


Book::Book(string company, string author, int year, string genre, string name) {
    this->publishingCompany = std::move(company);
    this->author = std::move(author);
    this->year = year;
    this->genre = std::move(genre);
    this->bookName = std::move(name);
}

string Book::get_publishingCompany() {
    return this->publishingCompany;
}

string Book::get_author() {
    return this->author;
}

int Book::get_year() {
    return this->year;
}

string Book::get_genre() {
    return this->genre;
}

string Book::get_bookName() {
    return this->bookName;
}

void Book::set_genre(string genre) {
    this->genre = std::move(genre);
}

void Book::random() {
    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    string temp1, temp2, temp3, temp4;
    int temp5;
    int string_length;              //the length of the string
    string_length = rand() % 7 + 3;
    for(int k = 0; k < string_length; k++){
        temp1.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp2.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp3.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp4.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
    }
    temp5 = rand()%20 +2000;
    this->bookName = temp1;
    this->author = temp2;
    this->genre = temp3;
    this->publishingCompany = temp4;
    this->year = temp5;
}

bool operator==(Book left, Book right) {
    return (left.bookName == right.bookName);
}
bool operator>(Book left, Book right) {
    return (left.bookName > right.bookName);
}
bool operator>=(Book left, Book right) {
    return (left.bookName >= right.bookName);
}
bool operator<(Book left, Book right) {
    return (left.bookName < right.bookName);
}
bool operator<=(Book left, Book right) {
    return (left.bookName <= right.bookName);
}