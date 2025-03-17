//
// Created by Alexia on 10.03.2025.
//

#include "Canvas.h"

#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->matrice = new char *[height];
    for (int i = 0; i < height; i++) {
        matrice[i] = new char[width];
        for (int j = 0; j < width; j++) {
            matrice[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int raza = ray;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (((i-x)*(i-x)+(j-y)*(j-y) >= raza*(raza-1))&&((i-x)*(i-x)+(j-y)*(j-y)<=raza*(raza+1))) {
                matrice[i][j] = ch;
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    int raza = ray;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i-x)*(i-x)+(j-y)*(j-y) < raza*raza) {
                matrice[i][j] = ch;
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        matrice[i][top] = ch;
        matrice[i][bottom] = ch;
    }
    for (int j = top; j < bottom; j++) {
        matrice[left][j] = ch;
        matrice[right][j] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {

    for (int i = top+1; i < bottom; i++)
    {
        for (int j = left + 1; j < right; j++)
        {
            matrice[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    matrice[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int D = 2*dy - dx;
    int y=y1;
    for (int x = x1; x <= x2; x++) {
        matrice[x][y] = ch;
        if (D >= 0) {
            y ++;
            D -= 2*dx;
        }
        D += 2*dy;
    }
}


void Canvas::Print() {
    cout << width << endl << height << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrice[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrice[i][j] = ' ';
        }
    }
}
