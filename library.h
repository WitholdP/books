#include <string>
#include <vector>
#include <optional>

#ifndef LIBRARY_H
#define LIBRARY_H

class Book
{
public:
    bool operator==(const Book &book) const { return this->m_title == book.m_title; }
    void Print();

private:
    std::string m_title;

    Book(const std::string &title);
    friend Library;
};

class Library
{
public:
    Library();
    void PrintTitles();
    void AddTitle(const std::string &title);
    void RemoveBook(const int &index);

private:
    std::vector<Book> m_books;

    std::optional<Book> GetBook(const int &index);
};

#endif