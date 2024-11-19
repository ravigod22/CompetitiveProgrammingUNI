#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
int matrix[maxn][maxn];

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " \n"[j + 1 == n];
        }
    }
}
int main() {
    cin >> n >> m;
    vector<int> column(n, m), row(n, m);
    vector<pair<int,int>> ones;
    map<pair<int,int>,bool> exist;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        ones.emplace_back(x, y);
        row[x]--;
        column[y]--;
        exist[{x, y}] = true;
        matrix[x][y] = 1;
    }
    print();
    // columns
    vector<pair<int,int>> result;
    for (int i = 0; i < min(n, 10); ++i) {
        for (int j = 0; j < n; ++j) {
            pair<int,int> tmp = {i, j};
            if (exist[tmp] == false && row[i] > 0 && column[j] > 0) {
                result.emplace_back(i, j);
                exist[tmp] = true;
                row[i]--;
                column[j]--;
            }
        }
    }
    // rows
    for (int j = 0; j < min(n, 10); ++j) {
        for (int i = 0; i < n; ++i) {
            pair<int,int> tmp = {j, i};
            if (!exist[tmp] && column[j] > 0 && row[i] > 0) {
                result.emplace_back(j, i);
                exist[tmp] = true;
                column[j]--;
                row[i]--;
            }
        }
    }
    for (auto e : result) {
        matrix[e.first][e.second] = 1;
    }
    print();
    return 0;
}
