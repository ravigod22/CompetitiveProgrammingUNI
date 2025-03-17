#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 binpow(int a, int e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res *= a;
        a *= a;
        e /= 2;
    }
    return res;
}

int main() {
    i64 l, r; cin >> l >> r;
    auto pot = [&] (int dig, int nexp) -> i64 {
        i64 sum = 0;
        for (int i = 1; i <= dig; ++i) {
            if (i == 1) sum += nexp;
            else sum += (binpow(i, nexp) - 1) / (i - 1);
        }
        return sum;
    };
    auto f = [&] (i64 lim) -> i64 {
        if (lim == 0) return 0;
        if (lim <= 9) return lim;
        string num = to_string(lim);
        int maxe = num[0] - '0';
        bool change = false;
        for (int i = 1; i < (int)num.size(); ++i) {
            if (change) {
                num[i] = char(maxe - 1 + '0');
                continue;
            }
            if (num[i] - '0' >= maxe) {
                num[i] = char(maxe - 1 + '0');
                change = true;
            }
        }
        i64 sum = num.back() - '0' + 1;
        cout << sum << endl;
        for (int i = (int)num.size() - 2; i >= 0; --i) {
            int dis = (int)num.size() - i - 1;
            if (i > 0) sum += 1LL * (num[i] - '0') * binpow(maxe, dis);
            else {
                for (int j = 1; j < (num[i] - '0'); ++j) sum += 1LL * binpow(j, dis);
            }
        }
        cout << sum << "\n";
        sum += pot(9, (int)num.size() - 1);
        return sum;
    };
    cout << f(r) << endl;
    // cout << f(r) - f(l - 1) << "\n";
    return 0;
}


