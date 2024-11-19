#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == -1) break;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % n != 0) {
            cout << -1 << "\n";
            continue;
        } 
        int tmp = sum / n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > tmp) ans += a[i] - tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}
