#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, q;

int ft[maxn];
int zero[maxn];

void update(int pos, int value) {
    for (++pos; pos < maxn; pos += pos & -pos) ft[pos] += value;
}
void update0(int pos, int value) {
    for (++pos; pos < maxn; pos += pos & -pos) zero[pos] += value;
}

int sum(int pos) {
    int result = 0;
    for (++pos; pos > 0; pos -= pos & -pos) result += ft[pos];
    return result;
}
int sum0(int pos) {
    int result = 0;
    for (++pos; pos > 0; pos -= pos & -pos) result += zero[pos];
    return result;
}
int query(int l, int r) {
    if (sum0(r) - sum0(l - 1) > 0) return 0;
    int ans = sum(r) - sum(l - 1);
    return ans & 1 ? -1 : 1; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) update(i, 1);
        if (a[i] == 0) update0(i, 1);
    }
    for (int i = 0; i < q; ++i) {
        char op; cin >> op;
        if (op == 'C') {
            int pos, value; cin >> pos >> value;
            pos--;
            int tmp1 = sum(pos) - sum(pos - 1);
            int tmp2 = sum0(pos) - sum0(pos - 1);
            if (value < 0) {
                update(pos, 1 - tmp1);
                update0(pos, -tmp2);
            }
            else if (value == 0) {
                update(pos, -tmp1);
                update0(pos, 1 - tmp2);
            }
            else if (value > 0) {
                update(pos, -tmp1);
                update0(pos, -tmp2);
            }
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;
            int tmp = query(l, r);
            if (tmp > 0) cout << "+\n";
            if (tmp == 0) cout << "0\n";
            if (tmp < 0) cout << "-\n";
        }
    }
    return 0;  
}
