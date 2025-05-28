#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    map<string, int> id;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        id[names[i]] = i;
    }
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < m; ++i) {
        string s, t; cin >> s >> t;
        int ids = id[s], idt = id[t];
        matrix[ids][idt] = matrix[idt][ids] = 1;
    }
    vector<string> res;
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        bool team = true;
        vector<int> pos;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) pos.push_back(j);
        }
        for (int a = 0; a < (int)pos.size(); ++a) {
            for (int b = a + 1; b < (int)pos.size(); ++b) {
                if (matrix[pos[a]][pos[b]] == 1) team = false;
            }
        }
        if (team) {
            if (ans < (int)pos.size()) {
                ans = pos.size();
                res.clear();
                for (int e : pos) res.push_back(names[e]);
            }
        }
    }
    cout << ans << "\n";
    sort(res.begin(), res.end());
    for (auto e : res) cout << e << "\n";
    return 0;
}
