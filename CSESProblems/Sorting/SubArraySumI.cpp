#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    i64 sum = 0;
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        sum += a[i];
        while (j < n && sum > 1LL * x) {
            sum -= a[j];
            j++;
        }
        if (sum == 1LL * x) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
