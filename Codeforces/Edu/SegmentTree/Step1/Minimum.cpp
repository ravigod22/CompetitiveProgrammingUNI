#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9;

struct Node {
    int mine;
    Node() {
        mine = inf;
    }
    Node(int x) {
        mine = x;
    }
    Node operator + (const Node& rhs) const {
        Node q;
        q.mine = min(mine, rhs.mine); 
        return q;
    }
};

struct SegTree {
    int n;
    vector<Node> x;
    Node nil;
    void build(vector<int> &a) {
        n = a.size();
        x.resize(4 * n + 3);
        build(a, 1, 0, n - 1);
    }
    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            x[id] = Node(a[l]);
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
            x[id] = Node(value);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(pos, value, 2 * id, l, mid);
        else update(pos, value, 2 * id + 1, mid + 1, r);
        x[id] = x[2 * id] + x[2 * id + 1];
    }
    Node query(int L, int R) {
        return query(L, R, 1, 0, n - 1);
    }
    Node query(int L, int R, int id, int l, int r) {
        if (R < l or r < L) return nil;
        if (L <= l and r <= R) return x[id];
        int mid = (l + r) / 2;
        return query(L, R, 2 * id, l, mid) + query(L, R, 2 * id + 1, mid + 1, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    SegTree st;
    st.build(a);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int pos, v; cin >> pos >> v;
            st.update(pos, v);
        }
        else {
            int L, R; cin >> L >> R;
            R--;
            cout << st.query(L, R).mine << "\n";
        }
    }
    return 0;
}

