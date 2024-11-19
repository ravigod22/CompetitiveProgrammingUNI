#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int& e : x) cin >> e;
    i64 lo = *max_element(x.begin(), x.end());
    i64 hi = accumulate(x.begin(), x.end(), 0LL);
    
    auto f = [&] (i64 sum) -> int {
        int cnt = 0;
        for (int i = 0; i < n; ) {
            i64 acc = 0;
            while (i < n && acc + x[i] <= sum) {
                acc += x[i];
                ++i;
            }
            cnt++;
        }
        return cnt;
    };
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (f(mid) <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
