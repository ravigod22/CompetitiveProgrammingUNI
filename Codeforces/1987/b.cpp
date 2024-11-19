#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> emax(n);
        emax[0] = a[0];
        for (int i = 1; i < n; ++i) {
            emax[i] = max(a[i], emax[i - 1]);
        }
        long long coins = 0;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (emax[i] - a[i]) b.emplace_back(emax[i] - a[i]); 
        }
        sort(b.begin(), b.end());
        long long carry = 0;
        for (int i = 0; i < b.size(); ++i) {
            long long r = (b[i] - carry);
            if (r != 0) {
                coins += r * 1ll * (b.size() - i + 1);
                carry += r;
            }
        }
        cout << coins << "\n";
    }
    return 0;
}

