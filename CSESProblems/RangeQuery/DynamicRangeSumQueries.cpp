#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    int n;
    vector<i64> x;
    void build(vector<int>& a) {
        n = a.size();
        x.resize(4 * n + 3);
        build(a, 1, 0, n - 1);
    }
    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            x[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        x[id] = x[2 * id] + x[2 * id + 1];
    }
    void update(int pos, int value) {
        update(pos, value, 1, 0, n - 1);
    }
    void update(int pos, int value, int id, int l, int r) {
        if (l == r) {
            x[id] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(pos, value, 2 * id, l, mid);
        else update(pos, value, 2 * id + 1, mid + 1, r);
        x[id] = x[2 * id] + x[2 * id + 1];
    }
    i64 query(int L, int R) {
        return query(L, R, 1, 0, n - 1);
    }
    i64 query(int L, int R, int id, int l, int r) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return x[id];
        int mid = (l + r) / 2;
        i64 left = query(L, R, 2 * id, l, mid);
        i64 right = query(L, R, 2 * id + 1, mid + 1, r);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    SegTree st;
    st.build(a);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos, value; cin >> pos >> value;
            pos--;
            st.update(pos, value);
        }
        else {
            int L, R; cin >> L >> R;
            L--, R--;
            cout << st.query(L, R) << "\n";
        }
    }
    return 0;
}
