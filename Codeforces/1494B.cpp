#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    int a[4];
    for (int i = 0; i < 4; ++i) cin >> a[i];
    for (int i = 0; i < (1 << 4); ++i) {
        int b[4];
        memcpy(b, a, sizeof(a));
        if (i & 1) b[0]--, b[3]--;
        if (i & 2) b[1]--, b[0]--;
        if (i & 4) b[1]--, b[2]--;
        if (i & 8) b[2]--, b[3]--;
        if (*min_element(b, b + 4) >= 0 && *max_element(b, b + 4) <= n - 2) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
