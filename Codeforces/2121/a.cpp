#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int it = upper_bound(a.begin(), a.end(), s) - a.begin();
    if (it == 0) {
        cout << a[n - 1] - s << "\n";
    }
    else if (it == n) {
        cout << s - a[0] << "\n";
    }
    else {
        int mine = min(a[n - 1] - s, s - a[0]);
        cout << mine + a[n - 1] - a[0] << "\n";
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


