#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Sort.h"
using namespace std;

int main() {
    vector<int> arr = {3,5,12,9,31,16,3,75};
    Sort<int> sort;
    sort.insertionSort(arr);
    sort.afisare(arr);
    return 0;
}
