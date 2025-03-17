#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        sort(b.begin(), b.end());
        bool can = true;
        a.emplace_back(1e9 + 5);
        for (int i = n - 1; i >= 0; --i) {
            int lo = 0;
            int hi = m - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (b[mid] - a[i] <= a[i + 1]) lo = mid;
                else hi = mid - 1;
            }
            if (b[lo] - a[i] <= a[i + 1] && a[i] <= a[i + 1]) a[i] = max(b[lo] - a[i], a[i]);
            else if (b[lo] - a[i] > a[i + 1] && a[i] > a[i + 1]) {
                can = false;
                break;
            }
            else if (b[lo] - a[i] <= a[i + 1] && a[i] > a[i + 1]) a[i] = b[lo] - a[i];
        }
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}


