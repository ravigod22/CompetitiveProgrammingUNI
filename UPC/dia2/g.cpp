#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int g, b; cin >> g >> b;
        if (g == -1) break;
        if (g == 0 && b == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (g == b) {
            cout << 1 << "\n";
            continue;
        }
        int m = max(g, b);
        int n = min(g, b);
        n++;
        cout << (m + n - 1) / n << "\n"; 
    }
    return 0;
}
