#include <iostream>
#include "Math.h"
using namespace std;

int main() {
    cout<<Math::Add(2,5)<<endl;
    cout<<Math::Add(3,5,6)<<endl;
    cout<<Math::Add(2.4, 5.4)<<endl;
    cout<<Math::Add(3.4, 5.4, 6.1)<<endl;
    cout<<Math::Mul(12,4)<<endl;
    cout<<Math::Mul(3,5,6)<<endl;
    cout<<Math::Mul(2.6, 8.1)<<endl;
    cout<<Math::Mul(3.4, 5.4, 6.1)<<endl;
    cout<<Math::Add(5, 1,2,3,4,5)<<endl;
    cout<<Math::Add("hello","hello")<<endl;
    return 0;
}