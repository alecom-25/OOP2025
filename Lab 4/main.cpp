#include <iostream>
#include "Sort.h"
#include<cstring>

using namespace std;

int main() {
    Sort vector1(5, 1, 7);
    cout<<"vector1"<<endl;
    vector1.Print();
    cout<<endl<<vector1.GetElementsCount()<<' '<<vector1.GetElementFromIndex(3)<<endl;
    vector1.QuickSort(true);
    cout<<"vector1 sortat"<<endl;
    vector1.Print();
    cout<<endl<<endl;

    int v[] = {7,3,6,1,8};
    cout<<"vector2"<<endl;
    Sort vector2(v, 5);
    vector2.Print();
    vector2.QuickSort(true);
    vector2.Print();
    cout<<endl;
    cout<<vector2.GetElementsCount()<<' '<<vector2.GetElementFromIndex(2)<<endl;

    Sort vector3(5, 2,4,8,5,9);
    cout<<"vector3"<<endl;
    vector3.Print();
    cout<<endl;
    vector3.BubbleSort(true);
    cout<<"vector3 sortat"<<endl;
    vector3.Print();
    cout<<endl<<endl;

    Sort vector4("2,5,1,7,9");
    cout<<"vector4: "<<endl;
    vector4.Print();
    cout<<"vector4 sortat"<<endl;
    vector4.InsertSort(true);
    vector4.Print();

    return 0;
}