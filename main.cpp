#include <iostream>
#include <fstream>
#include "sortingalgo.h"

int main() {
    std::string name;
    std::cin >> name;
    std::ifstream ifs(name.c_str());
    if(!ifs) return 2;
    std::ofstream ofs((name+".out").c_str());
    if(!ofs) return 19;
    withintrosort(ifs,ofs);

    return 0;
}