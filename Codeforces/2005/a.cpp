#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string tmp = "aeiou";
    int cnt[5] = {};
    int k = n / 5;
    for (int i = 0; i < 5; ++i) {
        cnt[i] = k;
    }
    for (int i = 0; i < n % 5; ++i) {
        cnt[i]++;
    }
    string ans;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            ans += tmp[i];
        }
    }
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
