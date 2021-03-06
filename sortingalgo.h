//
// Created by mf on 15.01.18.
//

#ifndef THEINTROSORT_SORTINGALGO_H
#define THEINTROSORT_SORTINGALGO_H

#endif //THEINTROSORT_SORTINGALGO_H

#include <iostream>
#include <vector>

typedef int tentyp;
typedef std::vector<tentyp> vectyp;
typedef vectyp::iterator itertyp;

void selection_sort(itertyp first, itertyp end);
void quicksort(itertyp first, itertyp end);
void introsort(vectyp &v);

void withintrosort(std::istream &i, std::ostream &o);
