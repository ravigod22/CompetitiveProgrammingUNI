#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int k; cin >> k;
    vector<pair<int, int>> p;
    int x = 0, y = 0;
    while (k > 0) {
        int tmp = 0;
        while ((tmp + 1) * tmp / 2 <= k) tmp++;
        for (int j = 0; j < tmp; ++j) {
            p.emplace_back(x, y);
            y++;
        }
        x++;
        k -= (tmp - 1) * tmp / 2;
    }
    cout << (int)p.size() << "\n";
    for (auto [a, b] : p) cout << a << " " << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


