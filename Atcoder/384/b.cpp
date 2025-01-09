#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r; cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int d, a; cin >> d >> a;
        if (d == 1) {
            if (r >= 1600 && r <= 2799) r += a;
        }
        else {
            if (r >= 1200 && r <= 2399) r += a;
        }
    }
    cout << r << "\n";
    return 0;
}
