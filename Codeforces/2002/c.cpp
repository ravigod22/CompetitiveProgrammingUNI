#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pll = pair<i64, i64>;

i64 square(i64 x) {
    return x * x;
}
i64 dis(pll a, pll b) {
    return square(a.first - b.first) + square(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pll> a(n);
        for (auto& e : a) cin >> e.first >> e.second;
        pll s;
        pll t;
        cin >> s.first >> s.second;
        cin >> t.first >> t.second;
        i64 lim = dis(s, t);
        bool could = true;
        for (auto e : a) {
            if (dis(e, t) <= lim) could = false;
        }
        cout << (could ? "YES\n" : "NO\n");
    }
    return 0;
}

