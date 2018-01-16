//
// Created by mf on 15.01.18.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../sortingalgo.h"

TEST_CASE("testujemyvecoweqs", "[vec qs]") {
    std::vector<tentyp> our = {5,4,111,6,8,8,56,4,4,5};
    quicksort(our.begin(),our.end());
    bool nope = true;
    int *prev = nullptr;
    for (int &now : our) {
        if (nope) {
            nope = false;
            prev = &now;
        }
        REQUIRE(*prev <= now);
        std::cout << now << std::endl;
    }
}

TEST_CASE("testujemyvecowe", "[vec]") {
    std::vector<tentyp> our = {5,4,111,6,8,8,56,4,4,5};
    introsort(our);
    bool nope = true;
    int *prev = nullptr;
    for (int &now : our) {
        if (nope) {
            nope = false;
            prev = &now;
        }
        REQUIRE(*prev <= now);
        std::cout << now << std::endl;
    }
}

