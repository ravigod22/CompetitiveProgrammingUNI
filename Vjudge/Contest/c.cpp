#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int inf = 2e9;
int grid[maxn][maxn];

int main() {
    int n, t; cin >> n >> t;
    vector<int> a(t);
    map<int, int> row;
    map<int, int> col;
    map<int, int> dia;
    map<int, int> anti;
    for (int& e : a) cin >> e;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = n * (i) + j + 1;
            row[grid[i][j]] = i;
            col[grid[i][j]] = j;
            if (i == j) {
                dia[grid[i][j]] = 1;
            }
            if (i + j == n - 1) {
                anti[grid[i][j]] = 1;
            }
        }
    }
    int cnt_row[n];
    int cnt_col[n];
    int ans_col = inf;
    int ans_dia = inf;
    int ans_row = inf;
    int ans_anti = inf;
    int cnt_anti = 0;
    int cnt_dia = 0;
    memset(cnt_row, 0, sizeof(cnt_row));
    memset(cnt_col, 0, sizeof(cnt_col));
    for (int i = 0; i < t; ++i) {
        cnt_row[row[a[i]]]++;
        cnt_col[col[a[i]]]++;
        if (dia[a[i]]) cnt_dia++;
        if (anti[a[i]]) cnt_anti++;
        if (cnt_row[row[a[i]]] == n) ans_row = min(ans_row, i + 1);
        if (cnt_col[col[a[i]]] == n) ans_col = min(ans_col, i + 1);
        if (cnt_dia == n) ans_dia = min(ans_dia, i + 1);
        if (cnt_anti == n) ans_anti = min(ans_anti, i + 1);
    }
    int total = min({ans_anti, ans_dia, ans_row, ans_col});
    cout << (total == inf ? -1 : total) << "\n";
    return 0;
}

