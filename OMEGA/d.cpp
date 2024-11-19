#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        int square = n * (n + 1) * (2 * n + 1) / 6;
        int rectangles = (n * (n + 1)) / 2;
        cout << square << " " << rectangles * rectangles << "\n";
    }
    return 0;
}
