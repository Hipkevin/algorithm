//
// Created by Kevin on 2021/3/16.
//

#include "Sort.h"

Sort::Sort(unsigned int length) {
    /*
     * generate an array randomly
     */
    for(int i = 0; i != length; ++i){
        this->arr.push_back(rand() % 101);
    }
}

void Sort::shuffle() {
    /*
     * coverage the array randomly
     */
    unsigned int length = this->arr.size();

    for(int i = 0; i != length; ++i){
        this->arr[i] = (rand() % 101);
    }
}

void Sort::viewArray() {
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

std::vector<int> Sort::bubbleSort(bool ascending) {
    /*
     * sort a random array with bubble algorithm
     *
     * the sort algorithm include two main loops
     * loop1: change the sort section
     * loop2: search the largest or the smallest element in the section
     *
     * param ascending: change the direction of the sort
     */
    int temp;  // a temp variable in triangle exchange
    int length = this->arr.size();
    std::vector<int> &arr = this->arr;

    // change the sort range
    for (int i = length; i != 0; --i) {

        // find the largest number in the array and move it to the end
        // notice the (i-1), which leave an element at the end of the sequence
        // cause there's (j+1) operate in the loop
        // also (i = length - 1)
        for (int j = 0; j < i - 1; ++j) {

            // triangle exchange in ascending order
            // change the sort direction with a xor operator
            if (!ascending ^ (arr[j] > arr[j+1])) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return arr;
}

std::vector<int> Sort::insertSort(bool ascending) {
    /*
     * sort a random array with insert sort algorithm
     *
     * sort with two main loops
     * loop1: travel the array to get the element waiting for inserting
     * loop2: travel the ordered array and insert the element got in loop1
     *
     * [The difference between bubble and insert]
     * bubble: exchange the adjacent element to make the largest/smallest to the end in every loop
     * [target] find the L/S
     *
     * insert: suppose an ordered sequence and insert the next element into the sequence
     * [target] find an appropriate position (bubble to the position)
     *
     * param ascending: change the direction of the sort
     *
     */
    int temp;
    int length = this->arr.size();
    std::vector<int> &arr = this->arr;

    int i, j;  // global variable for two loops

    // get the element after the sequence
    for (i = 1; i < length; ++i) {
        temp = arr[i];

        // move the sequence until finding the position
        // change the sort direction with a xor operator
        // also j >= 0 && (ascending ^ (temp < arr[j]))  [NOT recommend]
        for (j = i - 1; j >= 0; --j) {
            if (ascending ^ (temp < arr[j])){
                break;
            }
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

    return arr;
}

std::vector<int> Sort::binaryInsertSort(bool ascending) {
    /*
     * optimize the algorithm with binary search
     * [from O(n^2) to O(nlogn)]
     */
    int temp;
    int length = this->arr.size();
    std::vector<int> &arr = this->arr;


    int i, j;
    for (i = 1; i < length; ++i) {
        temp = arr[i];
        int lhs = 0;
        int rhs = i - 1;

        // using binary search to find the position for new element to insert
        while (lhs <= rhs) {
            int mid = (lhs + rhs) / 2;
            int num = arr[mid];

            if (!ascending ^ (num < temp)){
                lhs = mid + 1;
            } else{
                rhs = mid - 1;
            }

        }

        for (j = i - 1; j >= rhs+1; --j) {
            if (ascending ^ (temp < arr[j])){
                break;
            }
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

    return arr;
}

std::vector<int> Sort::shellSort(bool ascending) {
    /*
     * sort a sequence with shell algorithm
     *
     * it is a promotion of insert sort algo
     * reduce the movement times by grouping the sequence
     * which uses insert algo in every group
     * in the last group, the movement is less much more than before
     *
     * there are two new added loops in shell sort:
     * loop1: calculate the group span
     * loop2: use insert algo to every group
     *
     * [NOTE] the span must be 1 at last group
     *
     */
    int temp;
    int length = this->arr.size();
    std::vector<int> &arr = this->arr;

    int i, j;
    int span = int(length / 2);

    while (span != 0) {

        for (int k = 0; k < span; ++k) {

            // insert sort in each group
            for (i = k+span; i < length; i = i+span) {
                temp = arr[i];

                for (j = i - span; j >= 0; j = j-span) {
                    if (ascending ^ (temp < arr[j])){
                        break;
                    }
                    arr[j+span] = arr[j];
                }
                arr[j+span] = temp;
            }
        }

        span = span / 2;
    }

    return arr;

}

int Partition(std::vector<int> &arr, int lhs, int rhs, bool ascending) {
    /*
     * accept the sequence rand subsequence range
     * move the element and return the standard location
     *
     * lhs will be equal to rhs at last (while loop stop)
     *
     */
    int standard;
    standard = arr[lhs];

    while (lhs < rhs) {

        // find the element less(larger) than standard in right hand side
        // xor condition control
        while (lhs < rhs && (!ascending ^ (arr[rhs] >= standard)))
            rhs--;

        if (lhs < rhs)
            // move the element to left pointer and then move the pointer to next position
            arr[lhs++] = arr[rhs];

        // find the element larger(less) than standard in left hand side
        while (lhs < rhs && (!ascending ^ (arr[lhs] <= standard)))
            lhs++;

        if (lhs < rhs)
            // move the element to right pointer and then move the pointer to next position
            arr[rhs--] = arr[lhs];
    }

    arr[lhs] = standard;
    return rhs;
}

void Qsort(std::vector<int> &arr, int lhs, int rhs, bool ascending) {
    /*
     * 3 steps in the recurrent part
     * step1: partition
     * step2: sort left hand side
     * step3: sort right hand side
     */
    int standardLocation;
    if (lhs < rhs) {
        standardLocation = Partition(arr, lhs, rhs, ascending);
        Qsort(arr, lhs, standardLocation-1, ascending);
        Qsort(arr, standardLocation+1, rhs, ascending);
    }
}

std::vector<int> Sort::quickSort(bool ascending) {
    /*
     * quick sort algorithm
     *
     * the main idea: chose a number randomly (usually to be the first one)
     * partition the sequence recurrently
     *
     */
    int length = this->arr.size();
    std::vector<int> &arr = this->arr;

    Qsort(arr, 0, length-1, ascending);

    return arr;
}