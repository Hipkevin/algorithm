//
// Created by Kevin on 2021/3/16.
//

#include <vector>
#include <stdlib.h>

#include <iostream>
#include <iomanip>

#ifndef HOMEWORK_SORT_H
#define HOMEWORK_SORT_H


class Sort {
private:
    std::vector<int> arr;

public:
    Sort(unsigned int length);
    void shuffle();
    void viewArray();

    std::vector<int> bubbleSort(bool ascending);
    std::vector<int> insertSort(bool ascending);
    std::vector<int> binaryInsertSort(bool ascending);
    std::vector<int> shellSort(bool ascending);
    std::vector<int> quickSort(bool ascending);
    std::vector<int> heapSort(bool ascending);

};


#endif //HOMEWORK_SORT_H