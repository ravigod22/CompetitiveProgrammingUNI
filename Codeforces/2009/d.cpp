#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int cnt[2][maxn];

void solve() {
    cin >> n;
    vector<int> one;
    vector<int> zero;
    map<int, int> times;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        times[x]++;
        if (y) {
            one.emplace_back(x);
            cnt[1][x]++;
        }
        else {
            zero.emplace_back(x);
            cnt[0][x]++;
        }
    }
    long long ans = 0;
    for (auto e : times) {
        if (e.second == 2) ans += n - 2;
    }
    for (int i = 0; i < one.size(); ++i) {
        if (one[i] == 0) continue;
        ans += (cnt[0][one[i] - 1] == 1 && cnt[0][one[i] + 1] == 1);
    }
    for (int i = 0; i < zero.size(); ++i) {
        if (zero[i] == 0) continue;
        ans += (cnt[1][zero[i] - 1] == 1 && cnt[1][zero[i] + 1] == 1);
    }
    for (auto e : one) cnt[1][e]--;
    for (auto e : zero) cnt[0][e]--;
    cout << ans << "\n";
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

