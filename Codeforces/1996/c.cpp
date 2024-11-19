#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        string s[2]; cin >> s[0] >> s[1];
        int prefix[2][26][n + 1];
        memset(prefix, 0, sizeof(prefix));
        for (char tmp = 'a'; tmp <= 'z'; ++tmp) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    prefix[j][tmp - 'a'][i + 1] = prefix[j][tmp - 'a'][i] + (s[j][i] == tmp ? 1 : 0);
                }
            }
        }
        for (int i = 0; i < q; ++i) {
            int l, r; cin >> l >> r;
            vector<int> cntA(26, 0);
            vector<int> cntB(26, 0);
            int ans = 0;
            for (int j = 0; j < 26; ++j) {
                cntA[j] = prefix[0][j][r] - prefix[0][j][l - 1];
                cntB[j] = prefix[1][j][r] - prefix[1][j][l - 1];
            }
            for (int j = 0; j < 26; ++j) {
                if (cntB[j] < cntA[j]) ans += cntA[j] - cntB[j];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

