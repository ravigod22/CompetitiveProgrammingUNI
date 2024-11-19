#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int cnt[maxn];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] && cnt[i] & 1) ans--; 
    }
    cout << ans << "\n";
    return 0;
}
