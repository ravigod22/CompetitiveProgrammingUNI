#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    string s; cin >> s;
    const int n = s.size();
    vector<int> prefix(n + 1, 0), suffix(n + 1, 0), zero(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == '1');
        zero[i + 1] = zero[i] + (s[i] == '0');
    }
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + (s[i] == '1');
    }
    int lo = 0;
    int hi = n;
    int cnt1 = count(s.begin(), s.end(), '1');
    auto f = [&] (int x) -> bool {
        if (cnt1 == 0) return true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') continue;
            int it = upper_bound(zero.begin() + i + 1, zero.end(), x + zero[i]) - zero.begin();
            it = max(i + 1, it - 1);
            int nzero = zero[it] - zero[i];
            int none = suffix[it] + prefix[i];
            if (max(nzero, none) <= x) return true;
        }
        return false;
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
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
