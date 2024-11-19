#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i] % k].emplace_back(a[i]);
        }
        int cntodd = 0;
        for (auto e : mp) {
            vector<int> tmp = e.second;
            if ((int)tmp.size() & 1) cntodd++; 
        }
        if (cntodd > 1) {
            cout << -1 << "\n";
            continue;
        }
        long long op = 0;
        for (auto e : mp) {
            vector<int> tmp = e.second;
            sort(tmp.begin(), tmp.end());
            int l = tmp.size();
            if (l & 1) {
                vector<long long> odd(l + 1, 0);
                vector<long long> even(l + 1, 0);
                for (int i = 0; i < l; ++i) {
                    odd[i + 1] = odd[i] + (i + 1 & 1 ? tmp[i] : 0);
                    even[i + 1] = even[i] + (i + 1 & 1 ? 0 : tmp[i]);
                }
                long long total = odd[l] + even[l];
                long long ans = 1e16;
                for (int i = 1; i <= l; ++i) {
                    long long remain = total - tmp[i - 1];
                    long long need = even[i - 1] + odd[l] - odd[i];
                    ans = min(ans, (2 * need - remain) / k);
                }
                op += ans;
            }
            else {
                for (int i = 0; i < l; i += 2) {
                    op += 1ll * (tmp[i + 1] - tmp[i]) / k;
                }
            }
        }
        cout << op << "\n";
    }
    return 0;
}

