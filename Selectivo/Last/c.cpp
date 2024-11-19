#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = 0LL + a[i] + b[i];
    }
    sort(c.begin(), c.end());
    cout << c[n - 1] - c[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    while (tt--) {
        solve();
    }
    return 0;
}



