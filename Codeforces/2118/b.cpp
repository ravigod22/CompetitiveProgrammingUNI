#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> steps;
    steps.emplace_back(1, 1, n);
    for (int i = 2; i <= n; ++i) {
        steps.emplace_back(i, i, n);
        steps.emplace_back(i, 1, i - 1);
    }
    cout << (int)steps.size() << "\n";
    for (auto [ind, l, r] : steps) {
        cout << ind << " " << l << " " << r << "\n";
    }
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


