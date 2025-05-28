#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e9;

int main() {
    int n, m; cin >> n >> m;
    i64 ans = 0;
    for (int i = 0; i <= m; ++i) {
        i64 pow = 1;
        for (int j = 0; j < i; ++j) {
            pow *= 1LL * n;
            if (pow > inf) {
                pow = inf;
                break;
            }
        }
        if (pow == inf) {
            cout << "inf\n";
            return 0;
        }
        ans += pow;
        if (ans > inf) {
            cout << "inf\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}

