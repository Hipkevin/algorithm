//
// Created by Kevin on 2021/3/16.
//

#include <vector>
#include <stdlib.h>

#include <iostream>
#include <iomanip>

#ifndef HOMEWORK_SEARCH_H
#define HOMEWORK_SEARCH_H

std::vector<int> generateSequence(unsigned int length);

class Search {
private:
    std::vector<int> arr;

public:
    Search();
    Search(std::vector<int> sequence);

    void resetSequence();
    void resetSequence(std::vector<int> newSequence);
    void viewArray();

    int binarySearch(int query);
};

#endif //HOMEWORK_SEARCH_H
