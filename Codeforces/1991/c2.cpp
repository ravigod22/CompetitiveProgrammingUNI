#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (auto& e : a) cin >> e;
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (a[i] & 1) cnt++;
        if (cnt != 0 && cnt != n) {
            cout << -1 << "\n";
            continue;
        }
        int k = 0;
        vector<long long> choose;
        if (count(a.begin(), a.end(), 0) == n) {
            cout << k << "\n";
            for (int i = 0; i < k; ++i) cout << choose[i] << " ";
            cout << "\n";
            continue;
        }
        while (k < 40) {
            k++;
            set<long long> s;
            for (int i = 0; i < n; ++i) s.emplace(a[i]);
            long long tmp = accumulate(s.begin(), s.end(), 0LL);
            long long op = (tmp / s.size());
            for (int i = 0; i < n; ++i) {
                a[i] = abs(a[i] - op);
            }
            int ans = count(a.begin(), a.end(), 0);
            choose.emplace_back(op);
            if (ans == n) {
                break;
            }
        }
        if (k == 40) cout << -1 << "\n";
        else {
            cout << k << "\n";
            if (k != 0) for (int i = 0; i < k; ++i) cout << choose[i] << " \n"[i + 1 == k];
        }
    }
    return 0;
}


