#include <iostream>
#include <string>
#include "library.h"
#include "libraryUtils.h"

int main()
{
    Library library;
    library.AddTitle("LOTR TFOTR");
    library.AddTitle("LOTR TT");
    library.AddTitle("LOTR ROTK");

    while (true)
    {
        library_utils::RenderWelcome();

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::printf("Invalid input. Please enter a number.\n");
            continue;
        }

        library_utils::HandleChoice(choice, library);
    }

    return 0;
}
