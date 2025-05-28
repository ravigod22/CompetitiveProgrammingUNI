#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int ans = 0;
    for (int i = 0; i < n; i += 2) ans += a[i];
    cout << ans << "\n";
    return 0;
}
