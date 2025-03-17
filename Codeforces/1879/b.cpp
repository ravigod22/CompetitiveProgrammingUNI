#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        i64 sum1 = accumulate(a.begin(), a.end(), 0LL);
        i64 sum2 = accumulate(b.begin(), b.end(), 0LL);
        i64 res = sum1 + 1LL * n * (*min_element(b.begin(), b.end()));
        res = min(res, sum2 + 1LL * n * (*min_element(a.begin(), a.end())));
        cout << res << "\n";
    }
    return 0;
}
