#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for (int& e : x) cin >> e;
    sort(x.begin(), x.end());
    int lo = 1;
    int hi = x[n - 1] - x[0];
    auto f = [&] (int dis) -> int {
        int cnt = 1;
        int last = x[0];
        for (int i = 1; i < n; ++i) {
            if (x[i] - last >= dis) {
                cnt += 1;
                last = x[i];
            }
        }
        return cnt;
    };
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid) >= c) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}

