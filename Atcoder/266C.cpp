#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define x first
#define y second

int main() {
    array<int, 8> x, y;
    for (int i = 0; i < 4; ++i) {
        cin >> x[i] >> y[i];
        x[i + 4] = x[i];
        y[i + 4] = y[i];
    }
    for (int i = 0; i < 4; ++i) {
        int ang = (x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) - (y[i + 1] - y[i]) * (x[i + 2] - x[i + 1]);
        if (ang <= 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
