#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int d, c, r; cin >> d >> c >> r;
    vector<int> a(c), b(r);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    i64 sum = d + accumulate(b.begin(), b.end(), 0LL);
    int ans = r;
    for (int i = 0; i < c; ++i) {
        if (sum >= a[i]) {
            sum -= a[i];
            ans += 1;
        }
        else break;
    }
    cout << ans << "\n";
    return 0;
}
