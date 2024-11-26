#include <iostream>
#include <string>
#include "libraryUtils.h"
#include "library.h"

void library_utils::RenderWelcome()
{
    std::printf("\n");
    std::printf("Welcome to the Library! \n");
    std::printf("1: Add new book \n");
    std::printf("2: Remove a book \n");
    std::printf("3. Rent a book \n");
    std::printf("4. Return a book \n");
    std::printf("5. Show all books \n");
    std::printf("0. To exit the program \n");
    std::printf("\n");
    std::printf("Your choice: \n");
}

void library_utils::HandleChoice(const int &choice, Library &library)
{
    std::string stringInput;
    int bookIndex;

    switch (choice)
    {
    case 1:
        std::printf("Book title\n");
        std::cin >> stringInput;
        library.AddTitle(stringInput);
        library.PrintTitles();
        break;
    case 2:
        library.PrintTitles();
        std::printf("Type number of the book you want to remove: \n");
        std::cin >> bookIndex;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::printf("Invalid input.\n");
        }
        else
        {
            library.RemoveBook(bookIndex);
        }
        break;
    case 3:
        library.PrintTitles();
        std::printf("Type number of the book you want to rent: \n");
        std::cin >> bookIndex;

        std::printf("Who is renting this book?\n");
        std::cin >> stringInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::printf("Invalid input.\n");
        }
        else
        {
            library.RentBook(bookIndex, stringInput);
        }
        break;
    case 4:
        library.PrintTitles();
        std::printf("Type number of the book you want to return: \n");
        std::cin >> bookIndex;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::printf("Invalid input.\n");
        }
        else
        {
            library.ReturnBook(bookIndex);
        }
        break;
    case 5:
        library.PrintTitles();
        break;
    case 0:
        std::printf("Goodbye.\n");
        exit(0);
    default:
        std::printf("Wrong choice\n");
        break;
    }
};
