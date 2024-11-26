#include <iostream>
#include <map>
#include <string>
#include "library.h"

using namespace std;

int main()
{
    Library library;
    library.AddTitle("LOTR TFOTR");
    library.AddTitle("LOTR TT");
    library.AddTitle("LOTR ROTK");

    library.PrintTitles();
    library.RentBook(0, "Witold Piecewicz");

    library.PrintTitles();

    library.ReturnBook(0);

    library.PrintTitles();

    return 0;
}
