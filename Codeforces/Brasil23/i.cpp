#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int cnt[2] {1, 0};
    int sum = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum % 2 == 0) {
            ans += cnt[1];
        }
        else ans += cnt[0];
        cnt[sum % 2]++;
    }
    cout << ans << "\n";
    return 0;
}
