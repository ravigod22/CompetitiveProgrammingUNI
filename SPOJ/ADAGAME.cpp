#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 110;
string n;
int m;
bool vis[M][N][2];
bool dp[M][N][2];

void add(char &e) {
    if (e == '9') e = '0';
    else e = char(e + 1);
}
void res(char &e) {
    if (e == '0') e = '9';
    else e = char(e - 1);
}

bool f(int turn, string num, int player) {
    int number = stoi(num);
    if (turn == m) {
        if (player) return stoi(n) >= number;
        else return stoi(n) < number;
    }
    if (vis[turn][number][player]) return dp[turn][number][player];
    vis[turn][number][player] = true;
    bool &ans = dp[turn][number][player] = false;
    for (char &e : num) {
        add(e);
        ans |= 1 ^ f(turn + 1, num, player ^ 1);
        res(e);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= 1e4; ++j) {
                for (int k : {0, 1}) {
                    dp[i][j][k] = false;
                    vis[i][j][k] = false;
                }
            }
        }
        cout << (f(0, n, 0) ? "Ada" : "Vinit") << "\n";
    }
    return 0;
}
