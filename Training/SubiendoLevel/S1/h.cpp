#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1e5 + 5;
const i64 lim = 1e18 + 10;
const char comillas = 34;
i64 tabulacion[maxn];
string base = "What are you doing at the end of the world? Are you busy? Will you save us?";
string p1 = "What are you doing while sending ";
string p2 = "? Are you busy? Will you send ";
string p3 = "?";

char kthesimo(int n, i64 find_pos) {
    if (n == 0) {
        return base[find_pos];
    }
    else if (find_pos < 1LL * p1.size()) {
        return p1[find_pos];
    }
    else if (find_pos < 1LL * p1.size() + tabulacion[n - 1]) {
        return kthesimo(n - 1, find_pos - 1LL * p1.size());
    }
    else if (find_pos < 1LL * p1.size() + tabulacion[n - 1] + 1LL * p2.size()) {
        i64 remain = find_pos - 1LL * p1.size() - tabulacion[n - 1];
        return p2[remain];
    }
    else if (find_pos < 1LL * p1.size() + 2LL * tabulacion[n - 1] + 1LL * p2.size()) {
        return kthesimo(n - 1, find_pos - 1LL * p1.size() - tabulacion[n - 1] - 1LL * p2.size());
    }
    else {
        i64 remain = find_pos - 1LL * p1.size() - 2 * tabulacion[n - 1] - 1LL * p2.size();
        return p3[remain];
    }
}

int main() {
    p1 += comillas;
    p2 = comillas + p2 + comillas;
    p3 = comillas + p3;
    tabulacion[0] = 1LL * base.size(); 
    for (int i = 1; i < maxn; ++i) {
        if (tabulacion[i - 1] > lim) {
            tabulacion[i] = lim;
        }
        else {
            tabulacion[i] = 2 * tabulacion[i - 1] + p1.size() + p2.size() + p3.size();
        }
    }
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        i64 k; cin >> k;
        if (tabulacion[n] < k) cout << ".";
        else {
            k--;
            cout << kthesimo(n, k);
        }
    }
    cout << "\n";
    return 0;
}
