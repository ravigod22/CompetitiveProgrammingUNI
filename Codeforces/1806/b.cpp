#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> cnt(maxn, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e, cnt[e]++;
        bool another = false;
        for (int e : a) {
            if (e != 1 && e != 0) another = true;
        }
        if (another) cout << (cnt[0] > (n + 1) / 2 ? 1 : 0) << "\n";
        else {
            if (cnt[1] > 0) cout << (cnt[0] > (n + 1) / 2 ? 2 : 0) << "\n";
            else cout << 1 << "\n";
        }
        for (int e : a) cnt[e]--;
    }
    return 0;
}
