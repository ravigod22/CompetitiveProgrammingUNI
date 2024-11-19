#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int p = 311;
const int mod = 1e9 + 7;

int n;
string s;

int h[2][N];
int pot[N];
int pot_inv[N];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int binpow(int a, int e) {
    int result = 1;
    while (e) {
        if (e & 1) result = mul(result, a);
        a = mul(a, a);
        e >>= 1;
    }
    return result;
}

void init() {
    pot[0] = 1;
    for (int i = 1; i < N; ++i) {
        pot[i] = mul(pot[i - 1], p);
    }
    pot_inv[N - 1] = binpow(pot[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i) {
        pot_inv[i] = mul(pot_inv[i + 1], p);
    }
}

void init_pre_hashes() {
    for (int i = 0; i < n; ++i) {
        h[0][i + 1] = add(h[0][i], mul(s[i] - 'A' + 1, pot[i]));
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        h[1][i + 1] = add(h[1][i], mul(s[i] - 'A' + 1, pot[i]));
    }
    reverse(s.begin(), s.end());
}

int get_hash(int i, int j, int op) {
    int hash = (h[op][j] - h[op][i - 1] + mod) % mod;
    hash = mul(hash, pot_inv[i - 1]);
    return hash;
}

int main() {
    init();
    while (cin >> s) {
        n = s.size();
        auto is_palandromic = [&] (string s) -> bool {
            int k = s.size();
            for (int i = 0; i < k; ++i) {
                if (s[i] != s[k - i - 1]) return false;
            }
            return true;
        };
        if (is_palandromic(s)) {
            cout << s << "\n";
            continue;
        }
        if (n == 2) {
            cout << s + s[0] << "\n";
            continue;
        }
        // Hash
        init_pre_hashes();
        bool could = false;
        string ans;
        for (int i = (n / 2); i + 1 < n; ++i) {
            if (s[i] == s[i - 1]) {
                int dis = n - i;
                if (get_hash(i - dis + 1, i, 0) == get_hash(1, dis, 1)) {
                    string tmp = s.substr(0, i);
                    ans += tmp;
                    reverse(tmp.begin(), tmp.end());
                    ans += tmp;
                    could = true;
                    break;
                }
            }
            int dis = n - i - 1;
            if (get_hash(i - dis + 1, i, 0) == get_hash(1, dis, 1)) {
                string tmp = s.substr(0, i);
                ans += tmp;
                reverse(tmp.begin(), tmp.end());
                ans += s[i];
                ans += tmp;
                could = true;
                break;
            }
        }
        if (could) cout << ans << "\n";
        else {
            if (s[n - 1] == s[n - 2]) {
                string aux = s.substr(0, n - 1);
                ans += aux;
                reverse(aux.begin(), aux.end());
                ans += aux;
            }
            else {
                string aux = s.substr(0, n - 1);
                ans += aux;
                ans += s[n - 1];
                reverse(aux.begin(), aux.end());
                ans += aux;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
