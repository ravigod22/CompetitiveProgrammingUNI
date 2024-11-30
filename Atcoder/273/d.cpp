#include <bits/stdc++.h>
using namespace std;

int n, q, h, w, rs, cs;

int main() {
    cin >> h >> w >> rs >> cs >> n;
    map<int, vector<int>> R;
    map<int, vector<int>> C;
    for (int i = 0; i < n; ++i) {
        int r, c; cin >> r >> c;
        R[r].emplace_back(c);
        C[c].emplace_back(r);
    }
    for (auto &[e, v] : R) {
        v.emplace_back(0);
        v.emplace_back(w + 1);
        sort(v.begin(), v.end());
    }
    for (auto &[e, v] : C) {
        v.emplace_back(0);
        v.emplace_back(h + 1);
        sort(v.begin(), v.end());
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char op;
        int t;
        cin >> op >> t;
        if (op == 'L' || op == 'R') {
            int l, r;
            if (R.count(rs)) {
                l = lower_bound(R[rs].begin(), R[rs].end(), cs) - R[rs].begin() - 1;
                r = lower_bound(R[rs].begin(), R[rs].end(), cs) - R[rs].begin();
                l = R[rs][l] + 1;
                r = R[rs][r] - 1;
            }
            else {
                l = 1, r = w;
            }
            if (op == 'L') {
                cs = max(l, cs - t);
            }
            else {
                cs = min(r, cs + t);
            }
        }
        else {
            int u, d;
            if (C.count(cs)) {
                d = lower_bound(C[cs].begin(), C[cs].end(), rs) - C[cs].begin() - 1;
                u = lower_bound(C[cs].begin(), C[cs].end(), rs) - C[cs].begin();
                d = C[cs][d] + 1;
                u = C[cs][u] - 1;
            }
            else {
                d = 1, u = h;
            }
            if (op == 'D') {
                rs = min(u, rs + t);
            }
            else {
                rs = max(d, rs - t);
            }
        }
        cout << rs << " " << cs << "\n";
    }
    return 0;
}
