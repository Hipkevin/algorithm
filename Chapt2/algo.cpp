//
// Created by Kevin on 2021/4/19.
//

#include "algo.h"
#include <iostream>

int Sum(std::vector<int> array) {
    int result = 0;

    for (auto a : array) {
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

        do {
            for (i = start; start < end; start++) {
                currentSum = Sum(stack);

                if (array[i] + currentSum < sum) {
                    stack.push_back(array[i]);
                }

                if (array[i] + currentSum == sum) {
                    for (auto s : stack) {
                        std::cout << s << " ";
                    }
                    std::cout << array[i] << std::endl;
                }
            }

            stack.pop_back();
            start = stack.size() - 1;
        } while (stack.size() != 0);

        array.erase(array.begin());
    }
}

void testBackpack(){
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 14;

    std::vector<int> stack;

    int currentSum;
    int i;
    int hold;

    int start = 0;
    bool flag;

    int end = array.size() - 1;


    while (array.size() != 0) {

        do {
            flag = false;
            for (i = start; i < end; i++) {
                currentSum = Sum(stack);

                if (array[i] + currentSum < sum) {
                    stack.push_back(array[i]);
                }

                if (array[i] + currentSum == sum) {
                    for (auto s : stack) {
                        std::cout << s << " ";
                    }
                    std::cout << array[i] << std::endl;
                    flag = true;
                }
            }

            stack.pop_back();

            if (start == 0) {
                start = stack.size() + 1;
                hold = start;
            } else {
                start += 1;
            }

            if (flag) {
                hold += 1;
                start = hold;
            }

        } while (stack.size() != 0);


        array.erase(array.begin());
    }
}