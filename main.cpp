#include <iostream>
#include <map>
#include <string>
#include "library.h"

using namespace std;

int main()
{
    Library library;
    library.AddTitle("");
    library.AddTitle("LOTR TT");
    library.AddTitle("LOTR ROTK");

    library.PrintTitles();
    library.RemoveBook(10);
    library.PrintTitles();

    return 0;
}
