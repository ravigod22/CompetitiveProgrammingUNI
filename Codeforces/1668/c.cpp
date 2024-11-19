#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) {
            vector<long long> tmp(n);
            tmp[i] = 0;
            long long cnt = 0;
            for (int j = i - 1; j >= 0; --j) {
                long long aux = 1LL * (tmp[j + 1] - a[j]) / a[j];
                cnt += abs(aux);
                tmp[j] = 1LL * a[j] * aux;
            }
            for (int j = i + 1; j < n; ++j) {
                long long aux = 1LL * (tmp[j - 1] + a[j]) / a[j];
                cnt += aux;
                tmp[j] = 1LL * aux * a[j];
            }
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}

