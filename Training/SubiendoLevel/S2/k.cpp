#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1e6 + 6;
int cnt[maxn];

int main() {
    int n, x; cin >> n >> x;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ans += cnt[x ^ a];
        cnt[a] += 1;
    }
    cout << ans << "\n";
    return 0;
}
