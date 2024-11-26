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
    std::string m_rented = "";

    Book(const std::string &title);
    friend class Library;
};

class Library
{
public:
    Library();
    void PrintTitles();
    void AddTitle(const std::string &title);
    void RemoveBook(const int &index);
    void RentBook(const int &index, const std::string &name);
    void ReturnBook(const int &index);

private:
    std::vector<Book> m_books;

    std::optional<std::reference_wrapper<Book>> GetBook(const int &index);
};

#endif