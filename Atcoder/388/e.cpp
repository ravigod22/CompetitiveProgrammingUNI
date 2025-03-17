#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> vis(n, 0);
    for (int& e : a) cin >> e;
    auto f = [&] (int dis) -> bool {
        for (int i = 0; i < dis; ++i) {
            if (a[i] * 2 > a[i + n - dis]) return 0;
        }  
        return 1;
    };

    int lo = 0;
    int hi = n / 2;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}


