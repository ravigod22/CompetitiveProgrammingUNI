#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l, r; cin >> l >> r;
    long long ans = 0;
    long long tmp = l ^ r;
    for (int i = 60; i >= 0; --i) {
        if (tmp & (1ll << i)) {
            ans |= (1ll << (i + 1)) - 1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
