#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 8;
int table[maxn][maxn];

void init() {
    int tmp = 0;
    for (int i = 0; i < maxn; i += 2) {
        for (int j = 0; j < maxn; j += 2) {
            table[i][j] = tmp;
            table[i][j + 1] = tmp + 1;
            table[i + 1][j] = tmp + 2;
            table[i + 1][j + 1] = tmp + 3;
            tmp += 4;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        cout << n * m << "\n";
        bool exist = 1;
        for (int i = 0; i + 4 <= n; ++i) {
            bool can = 0;
            for (int j = 0; j + 4 <= m; ++j) {
                int A = table[i][j] ^ table[i][j + 1] ^ table[i + 1][j] ^ table[i + 1][j + 1];
                int B = table[i][j + 2] ^ table[i][j + 3] ^ table[i + 1][j + 2] ^ table[i + 1][j + 3];
                int C = table[i + 2][j] ^ table[i + 2][j + 1] ^ table[i + 3][j] ^ table[i + 3][j + 1];
                int D = table[i + 2][j + 2] ^ table[i + 2][j + 3] ^ table[i + 3][j + 2] ^ table[i + 3][j + 3];
                can = (A == D) && (B == C);
            }
            exist = exist && can;
        }
        assert(exist);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << table[i][j] << " \n"[j + 1 == m];
            }
        }
    }
    return 0;
}
