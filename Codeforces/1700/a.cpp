#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        long long result = 1ll * m * (m + n * n + n - 1) / 2;
        cout << result << "\n";
    }
    return 0;
}
