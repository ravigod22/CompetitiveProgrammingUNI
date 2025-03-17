#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    if (n == 2) {
        cout << max(a[1] + a[0], abs(a[1] - a[0])) << "\n";
        return;
    }
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    vector<i64> aux = {1, 1};
    int times = n - 2;
    while (times--) {
        int dis = aux.size();
        i64 another = 0;
        for (int i = 0; i <= n - dis; ++i) {
            i64 acc = 0;
            for (int j = i, id = 0; j < i + dis; ++j, id++) {
                acc += (id & 1 ? -1 : 1) * aux[id] * 1LL * a[j];
            }
            another += acc;
        }
        ans = max(ans, abs(another));
        vector<i64> tmp;
        tmp.emplace_back(1);
        for (int j = 1; j < (int)aux.size(); ++j) {
            i64 e = aux[j - 1] + aux[j];
            tmp.emplace_back(e);
        }
        tmp.emplace_back(1);
        aux = tmp;
    }
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 1LL * (i & 1 ? -1 : 1) * aux[i] * 1LL * a[i];
    }
    ans = max(ans, abs(sum));
    cout << ans << "\n";
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


