#include <bits/stdc++.h>
using namespace std;


#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int& e : a) cin >> e;
    int cnt1 = count(a.begin(), a.end(), 1);
    int cnt0 = 2 * n - cnt1;
    int mine, maxe;
    if (cnt1 & 1) mine = 1;
    else mine = 0;
    maxe = min(cnt1, cnt0);
    cout << mine << " " << maxe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


