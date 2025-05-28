#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    i64 sum = 0;
    i64 res = 0;
    for (int i = 0; i < n; ++i) {
        res += 1LL * a[i] * sum;
        sum += a[i];
    }
    cout << res << "\n";
    return 0;
}
