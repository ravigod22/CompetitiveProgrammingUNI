#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 1;
    int ini = 1;
    while (2 * (ini + 1) < n) {
        ini++;
        ini *= 2;
        cnt++;
    }
    if (ini != n) cnt++;
    cout << cnt << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

