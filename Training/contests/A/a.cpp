#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 10;
int ft[26][mxn];

void update(int pos, int value, int ch) {
    for (++pos; pos < mxn; pos += pos & -pos) ft[ch][pos] += value;
}
int sum(int pos, int ch) {
    int ans = 0;
    for (++pos; pos > 0; pos -= pos & -pos) ans += ft[ch][pos];
    return ans;
}
int range(int l, int r, int ch) {
    return sum(r, ch) - sum(l - 1, ch);
}

int main() {
    memset(ft, 0, sizeof(ft));
    string s; cin >> s;
    int n = s.size();
    for (int j = 0; j < n; ++j) {
        update(j, 1, s[j] - 'a');
    }
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos; 
            char ch;
            cin >> pos >> ch;
            --pos;
            // update sobre el string sin iterar los 26 caracteres
            update(pos, -1, s[pos] - 'a');
            update(pos, 1, ch - 'a');
            s[pos] = ch;
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;
            int cnt = 0;
            for (int i = 0; i < 26; ++i) {
                cnt += (range(l, r, i) > 0);
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}
