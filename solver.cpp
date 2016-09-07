#include<iostream>
#include<random>
using namespace std;
int to[5][5] = { 0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0 };

bool p[5][5] = { false, };

void c(int x, int y) {
    if (to[y][x] == 0) {
        to[y][x] = 1;
    }
    else
        to[y][x] = 0;
    
}

void press(int x, int y) {
    c(x, y);
    if (x - 1 >= 0) {
        c(x - 1, y);
        
    }
    if (y - 1 >= 0) {
        c(x, y - 1);
    }
    if (x + 1 < 5) {
        c(x + 1, y);
        
    }
    if (y + 1 < 5) {
        c(x, y + 1);
    }
    p[y][x] = !p[y][x];
}

bool isallzero(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (to[i][j] == 1)
                return false;
        }
    }
    return true;
}

void main(void) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(0, 4); // distribute results between 1 and 6 inclusive.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (p[i][j]) {
                cout << "y:" << i << " x:" << j << endl;
            }
        }
    }
    while (!isallzero()) {
        int i, j;
        i = dist(gen);
        j = dist(gen);
        press(i, j);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (p[i][j]) {
                cout << "y:" << i << " x:" << j << endl;
            }
        }
    }
    getchar();
}