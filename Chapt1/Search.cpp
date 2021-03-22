//
// Created by Kevin on 2021/3/16.
//

#include "Search.h"

std::vector<int> generateSequence(unsigned int length){
    /*
     * generate an array of specified length
     * a_n+1 = a_n + random_step
     */
    std::vector<int> arr;

    for(int i = 0; i != length; ++i){
        // the step of random number
        // generate in a specified range -> [a, b]: rand() % (b - a + 1) + a
        int random_step = rand() % 5 + 1;

        if(i){
            // increase by step
            arr.push_back(arr[i-1] + random_step);
        } else{
            // the first item initialized to 1
            arr.push_back(1);
        }
    }

    return arr;
}

Search::Search(std::vector<int> sequence) {
    /*
     * initialize with params
     */
    this->arr = sequence;
}

void Search::resetSequence() {
    /*
     * reset the sequence without changing the length
     */
    unsigned length = this->arr.size();
    this->arr = generateSequence(length);
}

void Search::resetSequence(std::vector<int> newSequence) {
    /*
     * reset the sequence with param
     */
    this->arr = newSequence;
}

void Search::viewArray() {
    /*
     * show the element in the array
     */
    int length = this->arr.size();

    for (int i = 0; i < length; ++i) {
        std::cout << std::left << std::setw(5) << this->arr[i];

        if ((i+1) % 5 == 0) {
            std::cout << std::endl;
        }
    }
}

int Search::binarySearch(int query) {
    /*
     * binary search
     */
    int length = this->arr.size();  // get the size of the array
    int lhs = 0;  // left hand side
    int rhs = length - 1;  // right hand side

    const std::vector<int> arr = this->arr;  // create a query array

    while (lhs <= rhs){
        int mid = (lhs + rhs) / 2;  // calculate mid
        int num = arr[mid];

        if(num == query){
            return mid;
        } else if (num < query){  // query is greater than mid -> lhs moves to the next element of mid
            lhs = mid + 1;
        } else{ // query is less than mid -> rhs moves to the element before mid
            rhs = mid - 1;
        }
    }

    return 0;
}