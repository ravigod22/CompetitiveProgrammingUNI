#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int a = 1; a < 500; ++a) {
        for (int b = a + 1; b < 500; ++b) {
            int c = 1000 - a - b;
            if (c <= a or c <= b) continue;
            if (a * a + b * b == c * c) {
                cout << a * b * c << "\n";
                break;
            }
        }
    }
    return 0;
}
