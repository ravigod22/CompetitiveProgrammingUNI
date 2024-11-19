#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (k - a[i] >= 0) {
            k = k - a[i];
            cnt++;
        }
        else break;
    }
    cout << cnt << "\n";
    return 0;
}
