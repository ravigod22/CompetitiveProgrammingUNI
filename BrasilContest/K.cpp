#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    auto f = [&] (ll k) -> ll {
        ll ans = 0;
        while (k) {
            ans += (k / 5);
            k /= 5;
        }
        return ans;
    };
    ll lo = 1; 
    ll hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid) >= n) hi = mid;
        else lo = mid + 1;
    }
    if (f(lo) == n) cout << lo << "\n";
    else cout << -1 << "\n";
    return 0;
}
