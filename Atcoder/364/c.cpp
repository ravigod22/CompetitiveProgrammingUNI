#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    long long x, y; cin >> n >> x >> y;
    vector<int> a(n);
    vector<int> b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int cnt = 0;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans1 = 0, ans2 = 0;
    long long t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i) {
        t1 += 0LL + a[i];
        ans1++;
        if (t1 > x) break;
    }
    for (int i = 0; i < n; ++i) {
        t2 += 0LL + b[i];
        ans2++;
        if (t2 > x) break;
    }
    cout << min(ans1, ans2) << "\n";
    return 0;
}
