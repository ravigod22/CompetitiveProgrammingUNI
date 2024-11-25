#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int S = 10010;
int n, s;
int card[N][2];
bool dp[N][S];
bool vis[N][S];
string path;

bool f(int pos, int sum) {
    if (pos == n) return sum == 0;
    if (sum < 0) return 0;
    if (vis[pos][sum]) return dp[pos][sum];
    vis[pos][sum] = 1;
    bool &ans = dp[pos][sum] = 0;
    ans = ans || f(pos + 1, sum - card[pos][0]);
    ans = ans || f(pos + 1, sum - card[pos][1]);
    return ans;
}

void build(int pos, int sum) {
    if (pos == n) return;
    if (sum < 0) return;
    if (f(pos + 1, sum - card[pos][0])) {
        path += "H";
        build(pos + 1, sum - card[pos][0]);
    }
    else {
        path += "T";
        build(pos + 1, sum - card[pos][1]);
    }
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> card[i][0] >> card[i][1];
    }
    bool ans = f(0, s);
    build(0, s);
    if (ans) {
        cout << "Yes\n";
        cout << path;
    }
    else cout << "No\n";
    return 0;
}
