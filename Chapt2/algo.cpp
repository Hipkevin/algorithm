//
// Created by Kevin on 2021/4/19.
//

#include "algo.h"
#include <iostream>

int Sum(std::vector<int> array) {
    int result = 0;

    for (int a : array) {
        result += a;
    }

    return result;
}

void backpack(std::vector<int> array, int sum) {
    std::vector<int> stack;

    int currentSum;
    int i;
    int start = 0;
    int end = array.size() - 1;


    while (array.size() != 0) {

        while (stack.size() != 0) {
            for (i = start; start < end; start++) {
                currentSum = Sum(stack);

                if (array[i] + currentSum < sum) {
                    stack.push_back(array[i]);
                }

                if (array[i] + currentSum == sum) {
                    for (int s : stack) {
                        std::cout << s << " ";
                    }
                    std::cout << array[i] << std::endl;
                }
            }

            stack.pop_back();
            start = stack.size() - 1;
        }

        array.erase(array.begin());
    }
}