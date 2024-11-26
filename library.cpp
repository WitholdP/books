#include <iostream>
#include <cstdio>
#include <optional>
#include "library.h"

Book::Book(const std::string &title) : m_title(title) {};

void Book::Print()
{
    printf("%s\n", m_title.c_str());
};

Library::Library()
{
    m_books.reserve(1000);
};

void Library::PrintTitles()
{
    int i = 0;
    for (auto book : m_books)
    {
        std::printf("%d. ", i);
        book.Print();
        i++;
    }
}

void Library::AddTitle(const std::string &title)
{
    if (title.empty())
    {
        std::printf("Book cannot have an empty title.\n");
        return;
    }

    Book book = Book(title);
    m_books.push_back(book);
    std::printf("Book has been added %s \n", title.c_str());
};

std::optional<Book> Library::GetBook(const int &index)
{
    if (index >= 0 && index < m_books.size())
    {
        return m_books[index];
    }
    else
    {
        return std::nullopt;
    }
};

void Library::RemoveBook(const int &index)
{
    auto bookOpt = Library::GetBook(index);
    if (bookOpt)
    {
        Book &book = *bookOpt;
        m_books.erase(std::find(m_books.begin(), m_books.end(), book));
    }
    else
    {
        std::printf("Book not found at index %d\n", index);
    }
};
