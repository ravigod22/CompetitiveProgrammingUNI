einclude <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, p; cin >> n >> k >> p;
    vector<int> a(n);
    vector<int> b(k);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 1e18;
    for (int i = n - 1; i < k; ++i) {
        long long mx = 0;
        for (int j = 0; j < n; ++j) {
            long long tmp = abs(a[j] - b[i - n + 1]);
            tmp += 0LL + abs(b[i - n + 1] - p);
            mx = max(mx, tmp);
        }
        ans = min(ans, mx);
    }
    cout << ans << "\n";
    return 0;
}
