#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    i64 lo = *max_element(a.begin(), a.end());
    i64 hi = accumulate(a.begin(), a.end(), 0LL);
    auto f = [&] (i64 sum) -> int {
        int buckets = 0;
        i64 acc = 0;
        for (int i = 0; i < n; ++i) {
            if (acc + a[i] > sum) {
                buckets += 1;
                acc = 1LL * a[i];
            }
            else acc += a[i];
        }
        return buckets + 1;
    };
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (f(mid) <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
