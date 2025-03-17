#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 998244353;

i64 add(i64 a, i64 b) {
    return (a + b) % mod;
}
i64 mul(i64 a, i64 b) {
    return 1LL * a * b % mod;
}

i64 binpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<i64> prefix(n + 1, 0), cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (a[i] == 2);
            cnt[i + 1] = cnt[i] + (a[i] == 1);
        }
        vector<i64> tmp = prefix;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] != 1) tmp[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            tmp[i] += tmp[i - 1];
        }
        vector<int> posone;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) posone.emplace_back(i + 1);
        }
        i64 ans = 0;
        i64 remain = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] == 3) {
                cout << "ind -> " << i << "\n";
                int none = cnt[i];
                auto it = lower_bound(posone.begin(), posone.end(), i + 1);
                if (it == posone.begin()) continue;
                it--;
                int pos = *it;
                cout << "pos -> " << pos << "\n";
                cout << "n 2two2 -> " << tmp[pos] << "\n";
                i64 power = none * prefix[i] - tmp[pos];
                cout << power << "\n";
                ans = add(ans, binpow(2, power));
                cout << ans << "\n";
                remain += none;
            }
        }
        ans = add(ans, mod - (remain % mod));
        cout << ans << "\n";
    }
    return 0;
}
