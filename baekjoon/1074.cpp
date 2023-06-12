#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
void solution(int startNumber, int n, int x, int y){
    // cout << "pow(2, n) / 2 : " << pow(2,n) / 2 <<  "   start : " << startNumber << "  n: " << n << "  x: " << x << "  y: " << y << endl;
    if (x < 2 && y < 2){
        cout << startNumber + x + (y * 2) << endl;
        return ;
    }

    if (x >= pow(2, n) / 2 && y >= pow(2, n) / 2){
        startNumber = startNumber + (pow(4, n)/ 4 * 3);
        x = x % (int)(pow(2, n) / 2);
        y = y % (int)(pow(2, n) / 2);
    }
    else if (x >= pow(2, n) / 2){
        startNumber = startNumber + (pow(4, n) / 4 * 1);
        x = x % (int)(pow(2, n) / 2);
        y = y % (int)(pow(2, n) / 2);
    }
    else if (y >= pow(2, n) / 2){
        startNumber = startNumber + (pow(4, n) / 4 * 2);
        x = x % (int)(pow(2, n) / 2);
        y = y % (int)(pow(2, n) / 2);
    }
    solution(startNumber, n - 1, x , y);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, y;
    cin >> n >> y >> x;

    solution(0, n, x, y);
}

