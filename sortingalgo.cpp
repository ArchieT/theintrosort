//
// Created by mf on 15.01.18.
//

#include <functional>
#include "sortingalgo.h"
#include <cassert>
#include <limits>

//std::__lg used in the libstdc stl_algo.h introsort impl also returns int
// which int is then integer multiplicated by 2
int log2(unsigned long n) {
    switch (n) {
        case 0:
            return -1;
//        case 1:
//            return 0;
        default:
            int r = 0;
            do {
                r++;
                n >>= 1;
            } while (n > 1);
            return r;
    }
}

void sortwith(withfuntyp with, std::istream &i, std::ostream &o) {
    vectyp v;
    int d;
    while (i >> d) v.push_back(d);
    with(v);
}

void swap(itertyp one, itertyp other) {
    tentyp t;
    t = *one;
    *one = *other;
    *other = t;
}

itertyp piv(itertyp first, itertyp end) {
    long d = std::distance(first, end);
    auto middle = first + (d / 2);
    auto last = end - 1;
    if (*last < *first) swap(first, last);
    if (*middle < *first) swap(first, middle);
    if (*middle > *last) swap(last, middle);
    return middle;
}

std::pair<itertyp, itertyp>
partition(itertyp first,
          itertyp middle_left, itertyp middle_right,
          itertyp last) {
    while (true) {
        if (first == middle_left) {
            if (middle_right == last)
                return {first, last};
            else {
                if (*last > *middle_right)
                    //return partition(first, first, middle_right, last - 1);
                {
                    last--;
                    continue;
                }
                else if (*last == *middle_right) {
                    //auto new_middle_right = middle_right + 1;
                    //swap(last, new_middle_right);
                    //return partition(first, first, new_middle_right, last);
                    middle_right++;
                    swap(last, middle_right);
                    continue;
                } else {
                    //auto new_middle_right = middle_right + 1;
                    //swap(first, new_middle_right);
                    //swap(first, last);
                    //return partition(first, first + 1, new_middle_right, last);
                    middle_right++;
                    swap(first, middle_right);
                    swap(first, last);
                    middle_left++;
                    continue;
                }
            }
        } else if (middle_right == last) {
            if (*first < *middle_left)
                //return partition(first + 1, middle_left, last, last);
            {
                first++;
                continue;
            }
            else if (*first == *middle_left) {
//                auto new_middle_left = middle_left - 1;
//                swap(first, new_middle_left);
//                return partition(first, new_middle_left, last, last);
                middle_left--;
                swap(first, middle_left);
                continue;
            } else {
//                auto new_middle_left = middle_left - 1;
//                swap(last, new_middle_left);
//                swap(last, first);
//                return partition(first, new_middle_left, last - 1, last);
                middle_left--;
                swap(last, middle_left);
                swap(last, first);
                middle_right--;
                continue;
            }
        } else if (*first < *middle_left)
//            return partition(first + 1, middle_left, middle_right, last);
        {
            first++;
            continue;
        }
        else if (*last > *middle_left)
//            return partition(first, middle_left, middle_right, last - 1);
        {
            last--;
            continue;
        }
        else if (*first == *middle_left) {
//            auto new_middle_left = middle_left - 1;
//            swap(first, new_middle_left);
//            return partition(first, new_middle_left, middle_right, last);
            middle_left--;
            swap(first, middle_left);
            continue;
        } else if (*last == *middle_right) {
//            auto new_middle_right = middle_right + 1;
//            swap(last, new_middle_right);
//            return partition(first, middle_left, new_middle_right, last);
            middle_right++;
            swap(last, middle_right);
            continue;
        } else {
            swap(first, last);
//            return partition(first + 1, middle_left, middle_right, last - 1);
            first++; last--;
            continue;
        }
//        return {middle_left, middle_right};
    }
}

std::pair<itertyp, itertyp>
min_max(itertyp first, itertyp end) {
    auto min = first;
    auto max = first;
    for (auto oddo = first; oddo != end; oddo++) {
        if (*oddo > *max) max = oddo;
        if (*oddo < *min) min = oddo;
    }
    return {min, max};
}

void selection_sort(itertyp first, itertyp end) {
    auto min_and_max = min_max(first, end);
    if (first != min_and_max.first) swap(first, min_and_max.first);
    auto last = end - 1;
    if (last != min_and_max.second) swap(last, min_and_max.second);
    auto second = first + 1;
    if (second != last) selection_sort(second, last);
}

void heapify(itertyp first, itertyp end, itertyp prev) {
    long i = std::distance(first, prev);
    auto largest_iter = first + i;
    long l = 2 * i + 1;
    auto left = first + l;
    long r = 2 * i + 2;
    auto right = first + r;
    long n = std::distance(first, end);
    if (l < n && *left > *largest_iter) {
        largest_iter = left;
    }
    if (r < n && *right > *largest_iter) {
        largest_iter = right;
    }
    if (largest_iter != prev) {
        swap(prev, largest_iter);
        heapify(first, end, largest_iter);
    }
}

void quicksort(itertyp first, itertyp end) {
    auto last = end - 1;
    if (first != last) {
        auto middle = piv(first, end);
        auto middles = partition(first + 1, middle, middle, last - 1);
        quicksort(first, middles.first);
        assert(middles.second != end);
        if (middles.second != last) quicksort(middles.second + 1, end);
    }
}

void introsort(itertyp first, itertyp end, int remaining) {
    auto last = end - 1;
    if (first != last) {
        auto dist = std::distance(first, end);
        if (dist < 4) {
            selection_sort(first, end);
        } else if (remaining >= 0) {
            auto middle = piv(first, end);
            auto middles = partition(first + 1, middle, middle, last - 1);
            introsort(first, middles.first, remaining - 1);
            introsort(middles.second + 1, end, remaining - 1);
        } else {
            for (long i = dist / 2 - 1; i >= 0; i--)
                heapify(first, end, first + i);
            for (auto cur = last; cur != first; cur--) {
                swap(first, cur);
                heapify(first, cur, first);
            }
        }
    }
}

void introsort(vectyp &v) {
    int l = 2 * log2(v.size());
    introsort(v.begin(), v.end(), l);
}

void withintrosort(std::istream &i, std::ostream &o) {
    sortwith([](vectyp v) { return introsort(v); }, i, o);
}
