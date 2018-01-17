//
// Created by mf on 15.01.18.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../sortingalgo.h"

std::vector<tentyp> shorter = {5, 4, 111, 6, 8, 8, 56, 4, 4, 5};
std::vector<tentyp> longer = {5, 4, 111, 6, 8, 8, 56, 4, 4, 5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
std::string stringified = "4 612  56 3546 2345 23 564  54675 34    2345345 5467  2345 2345 5464 562 2345 567 4 1 1 1 1 1 1 1 1 1 1 1 1  1";

TEST_CASE("shortervecoweqs", "[vec qs shorter]") {
    std::vector<tentyp> our = shorter;
    quicksort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("longervecoweqs", "[vec qs longer]") {
    std::vector<tentyp> our = longer;
    quicksort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("shortervecselsort", "[vec sel shorter]") {
    std::vector<tentyp> our = shorter;
    selection_sort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("longervecselsort", "[vec sel longer]") {
    std::vector<tentyp> our = longer;
    selection_sort(our.begin(), our.end());
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("shortervecowe", "[vec iso shorter]") {
    std::vector<tentyp> our = shorter;
    introsort(our);
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("longervecowe", "[vec iso longer]") {
    std::vector<tentyp> our = longer;
    introsort(our);
    int prev = -1;
    for (int &now : our) {
        std::cout << prev << "<=" << now << std::endl;
        REQUIRE(prev <= now);
        prev = now;
    }
}

TEST_CASE("stringowo", "[str, iso, stringified, cout]") {
    std::istringstream in(stringified);
    std::ostringstream out;
    withintrosort(in,out);
    auto output = out.str();
    std::cout << output << std::endl;
}

