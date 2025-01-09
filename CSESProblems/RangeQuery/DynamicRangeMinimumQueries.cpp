#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    const int inf = 2e9;
    vector<int> x;
    
    void build(vector<int> &a) {
        n = a.size();
        x.resize(4 * n + 3);
        build(a, 1, 0, n - 1);
    }
    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            x[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        x[id] = min(x[2 * id], x[2 * id + 1]);
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
        x[id] = min(x[2 * id], x[2 * id + 1]);
    }
    int query(int L, int R) {
        return query(L, R, 1, 0, n - 1);
    }
    int query(int L, int R, int id, int l, int r) {
        if (R < l or r < L) return inf;
        if (L <= l and r <= R) return x[id];
        int mid = (l + r) / 2;
        return min(query(L, R, 2 * id, l, mid), query(L, R, 2 * id + 1, mid + 1, r));
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
