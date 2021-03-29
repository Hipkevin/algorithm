#include <iostream>
#include "Chapt1/Search.h"
#include "Chapt1/Sort.h"

void testBinarySearch();

using namespace std;


int main() {
    // test the binary search algorithm
    // testBinarySearch();

    bool ascending = true;

    Sort sortOperator = Sort(25);
    cout << "Before sort:" << endl;
    sortOperator.viewArray();

    // sortOperator.bubbleSort(ascending);
    // sortOperator.insertSort(ascending);
    // sortOperator.binaryInsertSort(ascending);
    // sortOperator.shellSort(ascending);
    // sortOperator.quickSort(ascending);
    sortOperator.heapSort(ascending);

    cout << "After sort:" << endl;
    sortOperator.viewArray();

    return 0;
}

void testBinarySearch(){
    // generate random sequence
    vector<int> arr = generateSequence(25);

    // initialize a search algorithm selector
    Search searchOperator = Search(arr);

    // view the arr
    searchOperator.viewArray();

    // invoke binary search function
    int flag = searchOperator.binarySearch(11.);

    cout << "Result: ";
    if (flag) {
        cout << "The number index: " << flag << endl;
    } else{
        cout << "NOT FOUND" << endl;
    }
}