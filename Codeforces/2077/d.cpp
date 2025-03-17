#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<vector<char>> op(2, vector<char> (n));
    vector<vector<int>> num(2, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        cin >> op[0][i] >> num[0][i] >> op[1][i] >> num[1][i];
    }
    map<tuple<i64, i64, int>, i64> dp;
    auto f = [&] (auto& self, int pos) -> i64 {
        if (pos == 0) return 1;
        i64 L = 0, R = 0;
    };
    i64 res = f(f, 1, 1, 0);
    cout << res << "\n";
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


