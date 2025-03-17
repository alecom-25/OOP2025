#include <iostream>
#include<cmath>
#include "Canvas.h"

using namespace std;

int main() {
    Canvas canvas(40,40);

    canvas.DrawCircle(30, 30, 5, '#');
    canvas.FillCircle(30, 30, 5, '$');
    canvas.DrawRect(10, 10, 20, 20, '%' );
    canvas.FillRect(10, 10, 20, 20, '*' );
    canvas.SetPoint(5, 5, '^');
    canvas.DrawLine(10, 10, 30, 30, '@');
    canvas.Print();
    return 0;
}