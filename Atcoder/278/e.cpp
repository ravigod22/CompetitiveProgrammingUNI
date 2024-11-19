#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
int H, W, N, h, w;
int grid[maxn][maxn];
int prefix[maxn][maxn][maxn];

void print(int v) {
    cout << "------------------------------------\n";
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cout << prefix[v][i][j] << " \n"[j == W];
        }
    }
    cout << "------------------------------------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W >> N >> h >> w;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int k = 1; k <= 300; ++k) {
        for (int i = 1; i <= 305; ++i) {
            for (int j = 1; j <= 305; ++j) {
                if (i == 1 && j == 1) {
                    prefix[k][i][j] = (grid[i][j] == k ? 1 : 0);
                    continue;
                }
                prefix[k][i][j] = (grid[i][j] == k ? 1 : 0) + prefix[k][i - 1][j] + prefix[k][i][j - 1] - prefix[k][i - 1][j - 1];
            }
        }
    }
    for (int i = 1; i <= H - h + 1; ++i) {
        for (int j = 1; j <= W - w + 1; ++j) {
            int ans = 0;
            for (int k = 1; k <= N; ++k) {
                int cnt = prefix[k][i + h - 1][j + w - 1] + prefix[k][i - 1][j - 1] - prefix[k][i - 1][j + w - 1] - prefix[k][i + h - 1][j - 1]; 
                int total = prefix[k][H][W];
                if (total == 0) continue;
                if (total > cnt) ans++;
            }
            cout << ans << " \n"[j == W - w + 1];
        }
    }
    return 0;
}

