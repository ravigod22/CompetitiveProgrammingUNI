#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int lo = 0;
    int hi = 1e9 + 5;
    auto f = [&] (int x) -> int {
        vector<char> tmp;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) tmp.emplace_back(s[i]);
        }
        int cnt = 0;
        for (int i = 1; i < (int)tmp.size(); ++i) {
            if (tmp[i - 1] == 'R' && tmp[i] == 'B') cnt++;
        }
        cnt += (!tmp.empty() && tmp.front() == 'B');
        return cnt <= k;
    };
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
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

