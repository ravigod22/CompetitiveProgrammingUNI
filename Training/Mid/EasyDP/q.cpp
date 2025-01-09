#include <bits/stdc++.h>
using namespace std;

string s, t;
const int maxn = 4e3 + 5;
int dp[maxn][maxn][26];

int main() {
    cin >> s >> t;
    fill(dp[0][0], dp[0][0] + 26, 1);
    for (int i = 0; i < t.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            
        }
    }
    return 0;
}
