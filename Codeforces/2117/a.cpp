#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int p = 0;
    while (p < n && a[p] == 0) p++;
    while (p < n && x) p++, x--;
    while (p < n && a[p] == 0) p++;
    cout << (p == n ? "YES" : "NO") << "\n";
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


