#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, m;
string s;
int ft[maxn];

void update(int pos, int value) {
    for (++pos; pos < maxn; pos += pos & -pos) ft[pos] += value;
}

int sum(int pos) {
    int ans = 0;
    for (++pos; pos > 0; pos -= pos & -pos) ans += ft[pos];
    return ans;
}

int query(int l, int r) {
    return sum(r) - sum(l - 1);
}
int same(int x) {
    return query(x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') update(i, 1);
        else update(i, -1);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        if (k != 0) {
            k--;
            if (s[k] == ')') {
                s[k] = '(';
                update(k, 2);
            }
            else {
                s[k] = ')';
                update(k, -2);
            }
        }
        else {
            cout << (query(0, n - 1) == 0 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
