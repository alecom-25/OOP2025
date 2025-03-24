//
// Created by Alexia on 17.03.2025.
//

#include "Sort.h"
#include <cstdlib>
#include <cstdarg>
#include <iostream>


using namespace std;

Sort::Sort(int nr, int min, int max)
{
    int range = max - min;
    for (int i=0; i< nr; i++)
        lista[i] = min + rand() % range;
    count = nr;
}

Sort::Sort(int v[100], int n) {
    for (int i=0; i< n; i++)
        lista[i] = v[i];
    count = n;
}

Sort::Sort(int n, ...) {
    count = n;
    va_list ap;
    va_start(ap, n);
    for (int i=0; i< n; i++)
        lista[i] = va_arg(ap, int);
    va_end(ap);
}

Sort::Sort( char sir[]) {
/*
    int i=0;
    char *p;
    p=strtok(sir, ",");
    while (p!=NULL) {
        lista[i]=*p;
        i++;
        p=strtok(NULL, ",");
    }
    count = i;
*/
    int i = 0, nr = 0, p = 1, index = 0;
    //nr elem din sir
    while (sir[i] != '\0') {
        i++;
    }
    int elem_sir = i;
    i = 0; index = 0;
    // i = elem din sir ; index = nr de numere
    while (i < elem_sir) {
        if (sir[i] >= '0' && sir[i] <= '9') {
            nr = nr * 10 + (sir[i] - '0');
            i++;
        }
        else {
            lista[index] = nr;
            nr = 0;
            i++;
            index++;
        }
    }
    count = index;
}

void Sort::InsertSort(bool ascendent) {
    int temp=0;

    for (int i=0; i< count; i++) {
        temp = lista[i];
        int j = i-1;
        while (j>=0 && (ascendent?lista[j]>temp:lista[j]<temp)) {
            lista[j+1]=lista[j];
            j--;
        }
        if (lista[j+1]!=temp) {
            lista[j+1]=temp;
        }
    }
}
/*
void partitionare(int lista[], int &p, int &q, int &k, bool ascendent) {
    int x = lista[p];
    int i = p+1;
    int j = q;
    int ok = true;
    while (i<=j && ok) { ok = false;
        if ((ascendent?(lista[i]<=x):lista[i]>x)) {
            i++; ok = true;
        }
        if (ascendent?(lista[j]>=x):lista[j]<x) {
            j--; ok = true;
        }
        if (i<j && (ascendent?(lista[i]>=x):lista[i]<x) && (ascendent?(lista[j]<=x):lista[j]>x)) {
            swap(lista[i],lista[j]);
            i++;
            j--;
        }

        cout<<"string "<<i<<' '<<j<<endl;
    }
    k = i-1;
    lista[p] = lista[k];
    lista[k] = x;

}
*/
int partition(int lista[], int low, int high, bool ascendent) {
    // Choose the pivot
    int pivot = lista[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move elements based on ascendent flag
    for (int j = low; j <= high - 1; j++) {
        if (ascendent ? (lista[j] < pivot) : (lista[j] > pivot)) {
            i++;
            swap(lista[i], lista[j]);
        }
    }

    // Move pivot to its correct position and return its index
    swap(lista[i + 1], lista[high]);
    return i + 1;
}
/*
void quicksort(int lista[], int &p, int &q, int &k, bool ascendent) {
    cout<<k<<endl;
    while (p<q) {
        partitionare(lista, p, q, k, ascendent);
        quicksort(lista, p, q, k-1, ascendent);
        quicksort(lista, p, q, k+1, ascendent);
    }
}*/
void quickSort(int lista[], int low, int high, bool ascendent) {

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(lista, low, high, ascendent);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(lista, low, pi - 1, ascendent);
        quickSort(lista, pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSort(lista, 0, count-1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    int ultim = count-1;
    while (ultim>0) {
        int n1 = ultim - 1;
        ultim = 0;
        for (int i=0; i< n1; i++) {
            if (ascendent?(lista[i]>lista[i+1]):lista[i]<lista[i+1]) {
                swap(lista[i],lista[i+1]);
                ultim = i;
            }
        }
    }
}

void Sort::Print() {
    for (int i=0; i< count; i++)
        cout << lista[i] << " ";
    cout<<endl;
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    return lista[index];
}

