#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void solve() {
    int x = 0, y = 0;
    int j = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        char op; cin >> op;
        if (op == 'S') {
            x += dx[j];
            y += dy[j];
        }
        else {
            j = (1 + j) % 4;
        }
    }
    cout << x << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

