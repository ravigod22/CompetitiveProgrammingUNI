#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

const int maxn = 20;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, k;
char grid[maxn][maxn];
char G[maxn][maxn];


vector<pair<int, int>> ans;
set<u64> res;

void solve(u64 mask) {
    if (__builtin_popcount(mask) == k) {
        if (res.count(mask)) return;
        res.insert(mask);
        return;
    }
    for (auto& [i, j] : ans) {
        for (int d = 0; d < 4; ++d) {
            int newi = i + dx[d];
            int newj = j + dy[d];
            if (newi < 0 || newj < 0 || newi >= n || newj >= n) continue;
            if (grid[newi][newj] == '.') {
                int id = newi * n + newj;
                ans.emplace_back(newi, newj);
                grid[newi][newj] = '*';
                mask |= (1LL << id);
                solve(mask);
                grid[newi][newj] = '.';
                mask ^= (1LL << id);
                ans.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(grid, '.', sizeof(grid));
    cin >> n >> k;
    u64 bits = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != '.') continue;
            ans.emplace_back(i, j);
            int id = j * n + i;
            bits |= (1LL << id);
            grid[i][j] = '*';
            solve(bits);
            bits ^= (1LL << id);
            ans.pop_back();
            grid[i][j] = '.';
        }
    }

    return 0;
}
