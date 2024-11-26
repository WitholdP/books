#include <string>
#include <vector>
#include <optional>
#include "library.h"

#ifndef LIBRARY_UTILS_H
#define LIBRARY_UTILS_H

namespace library_utils
{
    void RenderWelcome();
    void HandleChoice(const int &choice, Library &library);
}

#endif