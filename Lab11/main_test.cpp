//
// Created by Alexia on 19.05.2025.
//
#include <gtest/gtest.h>
#include <vector>
#include "Sort.h"
using namespace std;

TEST(TesteSort, bubbleSort) {
    Sort<int> sorter;
    vector<int> input = {5, 2, 9, 1, 3};
    vector<int> expected = {1, 2, 3, 5, 9};

    sorter.bubbleSort(input);
    EXPECT_EQ(input, expected);
}

TEST(TesteSort, insertionSort) {
    Sort<int> sorter;
    vector<int> input = {5, 2, 9, 1, 3};
    vector<int> expected = {1, 2, 3, 5, 9};

    sorter.bubbleSort(input);
    EXPECT_EQ(input, expected);
}

TEST(TesteSort, selectionSort) {
    Sort<int> sorter;
    vector<int> input = {5, 2, 9, 1, 3};
    vector<int> expected = {1, 2, 3, 5, 9};

    sorter.selectionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(TesteSort, afisare) {
    Sort<int> sorter;
    vector<int> input = {5, 2, 9, 1, 3};
    vector<int> expected = {5, 2, 9, 1, 3};

    sorter.afisare(input);
    EXPECT_EQ(input, expected);
}