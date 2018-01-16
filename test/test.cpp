//
// Created by mf on 15.01.18.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../sortingalgo.h"

TEST_CASE("testujemyvecoweqs", "[vec qs]") {
    std::vector<tentyp> our = {5, 4, 111, 6, 8, 8, 56, 4, 4, 5};
    quicksort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("testujemyvecselsort", "[vec sel]") {
    std::vector<tentyp> our = {5, 4, 111, 6, 8, 8, 56, 4, 4, 5};
    selection_sort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("testujemyvecowe", "[vec]") {
    std::vector<tentyp> our = {5, 4, 111, 6, 8, 8, 56, 4, 4, 5};
    introsort(our);
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

