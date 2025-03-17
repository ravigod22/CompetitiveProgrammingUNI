#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int cnt1 = count(a.begin(), a.end(), 1);
        i64 acc = accumulate(a.begin(), a.end(), 0LL);
        acc -= n;
        cout << (acc >= cnt1 && n != 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}
