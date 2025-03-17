#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> b(2 * n);
    for (int& e : b) cin >> e;
    sort(b.begin(), b.end());
    auto f1 = [&] () -> vector<i64> {
        vector<i64> odd, even;
        for (int i = 0; i < n; ++i) odd.emplace_back(b[i]);
        for (int i = n; i < 2 * n; ++i) even.emplace_back(b[i]);
        i64 tmp = accumulate(even.begin(), even.end(), 0LL) - accumulate(odd.begin(), odd.end(), 0LL);
        for (int e : b) {
            if (tmp == 1LL * e) return vector<i64> ();
        }
        odd.emplace_back(tmp);
        vector<i64> ans;
        for (int i = 1; i <= 2 * n + 1; ++i) {
            i64 aux;
            if (i & 1) aux = odd.back(), odd.pop_back();
            else aux = even.back(), even.pop_back();
            ans.push_back(aux);
        }
        return ans;
    };
    auto f2 = [&] () -> vector<i64> {
        vector<i64> odd, even;
        for (int i = 0; i < n - 1; ++i) even.emplace_back(b[i]);
        for (int i = n - 1; i < 2 * n; ++i) odd.emplace_back(b[i]);
        i64 tmp = accumulate(odd.begin(), odd.end(), 0LL) - accumulate(even.begin(), even.end(), 0LL);
        for (int e : b) {
            if (tmp == 1LL * e) return vector<i64> ();
        }
        even.emplace_back(tmp);
        vector<i64> ans;
        for (int i = 1; i <= 2 * n + 1; ++i) {
            if (i & 1) ans.emplace_back(odd.back()), odd.pop_back();
            else ans.emplace_back(even.back()), even.pop_back();
        }
        return ans;
    };
    vector<i64> res = f1();
    if (res.empty()) res = f2();
    assert(res.size() == 2 * n + 1);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " \n"[i + 1 == res.size()];
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


