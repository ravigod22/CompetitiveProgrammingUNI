#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, l, r, s; cin >> n >> l >> r >> s;
        int len = r - l + 1;
        long long minsum = 1LL * len * (len + 1) / 2;
        long long maxsum = 0LL;
        for (int i = 0; i < len; ++i) {
            maxsum += 0LL + n - i;
        }
        if (s < minsum || maxsum < s) {
            cout << -1 << "\n";
            continue;
        }

    }
    return 0;
}

