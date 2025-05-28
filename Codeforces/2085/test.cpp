#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y; cin >> x >> y;
    if (x < y) swap(x, y);
    for (int i = 63; i >= 0; --i) {
        cout << ((x >> i) & 1);
    }
    cout << endl;
    for (int i = 63; i >= 0; --i) {
        cout << ((y >> i) & 1);
    }
    cout << "\n";
    return 0;
}
