#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<long long> prefix(n);
    if (n > m) return false;
    if (a[0] >= m / 2) return false;
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = 1LL + a[i] + prefix[i - 1];
    }
    if (prefix[n - 1] + 0LL + a[n - 1] < 0LL + a[0] + m) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");   
    }
    return 0;
}

