#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n;
    cin >> h >> w >> n;
    set<int> R[h];
    set<int> C[w];
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        R[r].insert(c);
        C[c].insert(r);
    }
    int q;
    cin >> q;
    while (q--) {
        int op, a;
        cin >> op >> a;
        a--;
        if (op == 1) {
            cout << (int)R[a].size() << "\n";
            for (int e : R[a]) {
                C[e].extract(a);
            }
            if (!R[a].empty()) R[a].clear();
        }
        else {
            cout << (int)C[a].size() << "\n";
            for (int e : C[a]) {
                R[e].extract(a);
            }
            if (!C[a].empty()) C[a].clear();
        }
    }
    return 0;
}



