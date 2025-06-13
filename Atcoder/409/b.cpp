#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= j) cnt += 1;
        }
        if (cnt >= j) ans = j;
    }
    cout << ans << "\n";
    return 0;
}

