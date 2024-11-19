#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int p = 31;
const int mod = 1e9 + 7;
string s;
int h[maxn];

int binpow(int a, int b) {
    int result = 1;
    while (b) {
        if (b & 1) result = 1ll * result * a % mod;
        a = 1ll * a * a % mod;
        b = b / 2;
    }
    return result;
}

void init() {
    h[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < (int)s.size(); ++i) {
        h[i] = (h[i - 1] + binpow(p, i) * 1ll * (s[i] - 'a' + 1) % mod) % mod;
    }
}
int inverse(int x) {
    return binpow(x, mod - 2);
}

int get_hash(int l, int r) {
    //l--; r--;
    int L = (l ? h[l - 1] : 0);
    int R = h[r];
    return inverse(binpow(p, l)) * 1ll * ((R - L + mod) % mod) % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> s;
        int n = s.size();
        if (n & 1) {
            cout << "0\n";
            continue;
        }
        fill(h, h + n, 0);
        init();
        int cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (i + 1 == n / 2) {
                int P = get_hash(0, n / 2 - 1);
                int R = get_hash(n / 2, n - 1);
                cnt += 2 * (P == R);
                continue;
            }
            int P1 = get_hash(0, i);
            int P2 = get_hash(i + 1, 2 * i + 1);
            int R1 = get_hash(2 * (i + 1), n / 2 + i);
            int R2 = get_hash(n / 2 + i + 1, n - 1);
            cnt += ((P1 == P2) && (R1 == R2));
        }
        cout << cnt << "\n";
    }
    return 0;
}
