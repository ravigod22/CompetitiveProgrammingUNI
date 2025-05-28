#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 18);
int n, m;
int st[4 * maxn];
int a[maxn];

void build(int id, int l, int r, int deep) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid, deep - 1);
    build(2 * id + 1, mid + 1, r, deep - 1);
    st[id] = (deep & 1 ? st[2 * id] | st[2 * id + 1] : st[2 * id] ^ st[2 * id + 1]);
}

void update(int pos, int id, int l, int r, int deep) {
    if (l == r) {
        st[id] = a[pos];
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(pos, 2 * id, l, mid, deep - 1);
    else update(pos, 2 * id + 1, mid + 1, r, deep - 1);
    st[id] = (deep & 1 ? st[2 * id] | st[2 * id + 1] : st[2 * id] ^ st[2 * id + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= (1 << n); ++i) cin >> a[i];
    build(1, 1, 1 << n, n);
    while (m--) {
        int p, b; cin >> p >> b;
        a[p] = b;
        update(p, 1, 1, 1 << n, n);
        cout << st[1] << "\n";
    }
    return 0;
}

