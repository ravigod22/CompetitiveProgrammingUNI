#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + ((a[i] % n) + n) % n;
        prefix[i + 1] %= n;
    }
    i64 ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ans += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    cout << ans << "\n";
    return 0;
}
