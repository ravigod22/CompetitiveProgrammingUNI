#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n;
    cin >> n;
    i64 s, x;
    cin >> s >> x;
    vector<int> a(n);
    vector<i64> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    auto g = [&] (int x) -> i64 {
        map<i64, int> cnt;
        cnt[0] = 1;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                cnt.clear();
            }
            if (cnt.count(pre[i + 1] - s))
                ans += cnt[pre[i + 1] - s];
            cnt[pre[i + 1]] += 1;
        }
        return ans;
    };
    cout << g(x) - g(x - 1) << "\n";
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



