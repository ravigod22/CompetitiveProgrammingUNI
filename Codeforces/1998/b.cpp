#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int& e : p) cin >> e;
        for (int i = 0; i < n; ++i) {
            cout << (p[i] == n ? 1 : p[i] + 1) << " \n"[i + 1 == n];
        }
    }
    return 0;
}
