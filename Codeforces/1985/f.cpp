#include <bits/stdc++.h>
using namespace std;

bool f(long long t, long long h, vector<int>& a, vector<int>& c) {
    int n = a.size();
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (t + c[i] - 1) / c[i] * a[i];
        if (sum >= h) return 1;
    }
    return (sum >= h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int h, n; cin >> h >> n;
        vector<int> a(n);
        vector<int> c(n);
        for (int& e : a) cin >> e;
        for (int& e : c) cin >> e;
        long long lo = 0;
        long long hi = 1e11;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (f(mid, 1ll * h, a, c)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
    return 0;
}
