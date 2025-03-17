#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> ans;
    ans.emplace_back(1);
    int cnt = 1;
    int lim = n / 2;
    while (ans.size() < n) {
        ans.emplace_back(cnt);
        if (cnt + 1 > lim) cnt = 1;
        else cnt++;
    }
    for (int e : ans) cout << e << " ";
    cout << "\n";
    pv(ans);
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


