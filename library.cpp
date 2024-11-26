#include <iostream>
#include <cstdio>
#include <optional>
#include "library.h"

#define INITIAL_LIBRARY_SIZE 1000

Book::Book(const std::string &title) : m_title(title) {};

void Book::Print()
{
    printf("%s- rented by: %s \n", m_title.c_str(), m_rented.c_str());
};

Library::Library()
{
    m_books.reserve(INITIAL_LIBRARY_SIZE);
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
    std::printf("\n");
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

std::optional<std::reference_wrapper<Book>> Library::GetBook(const int &index)
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
        Book &book = bookOpt->get();
        m_books.erase(std::find(m_books.begin(), m_books.end(), book));
        std::printf("Book removed");
        std::printf("\n");
    }
    else
    {
        std::printf("Book not found at index %d\n", index);
    }
};

void Library::RentBook(const int &index, const std::string &name)
{
    auto bookOpt = Library::GetBook(index);
    if (bookOpt)
    {
        Book &book = bookOpt->get();
        if (!book.m_rented.empty())
        {
            std::printf("Cannot rent a book. Book rented to: %s \n", book.m_rented.c_str());
            return;
        }
        book.m_rented = name;
        std::printf("Book rented to: %s \n", name.c_str());
        std::printf("\n");
    }
    else
    {
        std::printf("Book not found at index %d\n", index);
    }
};

void Library::ReturnBook(const int &index)
{
    auto bookOpt = Library::GetBook(index);
    if (bookOpt)
    {
        Book &book = bookOpt->get();
        if (book.m_rented.empty())
        {
            std::printf("Book is already in library.\n");
            return;
        }
        book.m_rented = "";
        std::printf("Book returned to library.");
        std::printf("\n");
    }
    else
    {
        std::printf("Book not found at index %d\n", index);
    }
};