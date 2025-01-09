#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    i64 s; cin >> s;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<i64> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + a[i];
    for (int i = 1; i <= n; ++i) {
        if (s % pre[i] == 0) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
    return 0;
}
