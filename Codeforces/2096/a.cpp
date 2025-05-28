#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int p = 0, q = n - 1;
    reverse(s.begin(), s.end());
    vector<int> ans;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            ans.emplace_back(a[p]);
            p++;
        }
        else {
            ans.emplace_back(a[q]);
            q--;
        }
    }
    ans.emplace_back(a[p]);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
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


