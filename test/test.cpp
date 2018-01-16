//
// Created by mf on 15.01.18.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../sortingalgo.h"

TEST_CASE("testujemyvecowe", "[vec]") {
    std::vector<tentyp> our = {5,4,111,6,8,8,56,4,4,5};
    introsort(our);
    for (int &now : our)
        std::cout << now << std::endl;
}

