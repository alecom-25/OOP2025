//
// Created by Alexia on 17.03.2025.
//

#ifndef SORT_H
#define SORT_H

using namespace std;

class Sort
    {
        int lista[100], count;

    public:
        Sort(int nr, int min, int max);
        //Sort();
        Sort(int v[100], int n);
        Sort(int n, ...);
        Sort(char sir[]);

        void InsertSort(bool ascendent=false);
        void QuickSort(bool ascendent=false);
        void BubbleSort(bool ascendent=false);
        void Print();
        int  GetElementsCount();
        int  GetElementFromIndex(int index);
    };





#endif //SORT_H
