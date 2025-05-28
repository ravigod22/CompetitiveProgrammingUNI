#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 6;

int m;
int T[4 * N];

void update(int pos, int x, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) T[id] += x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

int query(int k, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (k > T[2 * id]) 
        return query(k - T[2 * id], 2 * id + 1, tm + 1, tr);
    else 
        return query(k, 2 * id, tl, tm);
}


bool is_alive(int pos, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) return T[id];
    int tm = (tl + tr) / 2;
    if (pos <= tm) return is_alive(pos, 2 * id, tl, tm);
    else return is_alive(pos, 2 * id + 1, tm + 1, tr);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int q; cin >> q;
    vector<pair<int,int>> Q;
    vector<int> t;
    for (int i = 0; i < q; i++) {
        int op, x = -1;
        cin >> op;
        if (op != 3) {
            cin >> x;
            t.push_back(x);
        }
        Q.emplace_back(op, x);
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    m = t.size();
    for (auto [op, x] : Q) {
        int pos = lower_bound(t.begin(), t.end(), x) - t.begin();
        if (op == 1) {
            update(pos, 1);
        } else if (op == 2) {
            if (is_alive(pos)) update(pos, -1);
        } else {
            int n = T[1];
            if (n == 0) {
                cout << "Empty!\n";
                continue;
            }
            if (n & 1) {
                int j = query((n + 1) / 2);
                cout << t[j] << "\n";
            } else {
                int j1 = query(n / 2);
                int j2 = query(n / 2 + 1);
                cout << (t[j1] + t[j2]) / 2 << "\n";
            }
        }
    }

    return 0;
}
