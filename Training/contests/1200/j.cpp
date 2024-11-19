#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n, m, k;

bool solve() {
    cin >> n >> m >> k;
    i64 maxm = 1LL * n * (n - 1) / 2;
    if (m < n - 1) return false;
    if (1LL * m > maxm) return false;
    if (n == 1) return (k > 1);
    if (1LL * m == maxm) return (k >= 3);
    else return (k > 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}

