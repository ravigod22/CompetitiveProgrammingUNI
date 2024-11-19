#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + 1ll * a[i];
        int mx = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            mx = max(a[i - 1], mx);
            long long tmp = prefix[i];
            if (tmp == 1ll * 2 * mx) cnt++; 
        }
        cout << cnt << "\n";
    }
    return 0;
}

