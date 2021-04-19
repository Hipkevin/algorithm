#include <iostream>

#include "Chapt2/algo.h"

using namespace std;


int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 14;

    backpack(array, sum);

    return 0;
}