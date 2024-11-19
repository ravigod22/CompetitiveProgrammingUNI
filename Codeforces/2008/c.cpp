#include <bits/stdc++.h>
using namespace std;

int l, r;
void solve() {
    cin >> l >> r;
    /*
    long long diff = r - l;
    long long lo = 1;
    long long hi = 1e5;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (mid * (mid + 1) / 2 >= diff) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    */
    int init = l;
    int accu = 1;
    int cnt = 1;
    while (init + accu <= r) {
        init += accu;
        cnt++;
        accu++;
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


