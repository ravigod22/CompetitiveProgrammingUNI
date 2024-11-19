#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
char grid[maxn][maxn];

vector<string> f(int k) {
    if (k == 1) {
        return {"#"};
    }
    vector<string> grid = f(k - 1);
    int tmp = grid.size();
    int n = 3 * tmp;
    vector<string> result(n, string(n, ' '));
    for (int i = tmp; i < 2 * tmp; ++i) {
        for (int j = tmp; j < 2 * tmp; ++j) {
            result[i][j] = '.';
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            for (int a = 0; a < tmp; ++a) {
                for (int b = 0; b < tmp; ++b) {
                    result[i * tmp + a][j * tmp + b] = grid[a][b];
                }
            }
        }
    }
    return result;
}
void print(vector<string>& s) {
    for (string e : s) {
        cout << e << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;  
    vector<string> ans = f(n + 1);
    print(ans);
    return 0;
}


