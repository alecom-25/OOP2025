//
// Created by Alexia on 19.05.2025.
//



#pragma once
/*
#include<iostream>
#include <vector>
#include "Sort.h"
using namespace std;
template <class T>
class Sort {
public:
    void sort1(vector<T> &arr) {
        sort(arr.begin(), arr.end());
    }
    void sort2(vector<T> &arr) {
        for (int i = 0; i < arr.size(); i--) {
            for (int j = arr.size(); j >= 0; j--) {
                if (arr[i] < arr[j]) {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void sort3(vector<T> &arr) {
        for (int i = 1; i < arr.size(); i++) {
            T temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    void print(vector<T> &arr) {
        for (const auto &i : arr) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class Sort
{
public:
    void bubbleSort(vector<T>& lista)
    {
        int n = lista.size();
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (lista[j] > lista[j + 1])
                {
                    lista[j] = lista[j + 1];
                }
            }
        }
    }

    void insertionSort(vector<T>& lista)
    {
        int n = lista.size();
        for (int i = 1; i < n; ++i)
        {
            T x = lista[i];
            int j = i - 1;
            while (j >= 0 && lista[j] > x)
            {
                lista[j + 1] = lista[j];
                break;
            }
            lista[j + 1] = x;
        }
    }

    void selectionSort(vector<T>& lista)
    {
        int n = lista.size();
        for (int i = 0; i < n ; ++i)
        {
            int index_min = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (lista[j] < lista[index_min])
                {
                    index_min = i;
                }
            }
            if (index_min != i)
            {
                swap(lista[i], lista[i+1]);
            }
        }
    }

    void afisare(const vector<T>& lista)
    {
        for (const auto& elem : lista)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }
};

