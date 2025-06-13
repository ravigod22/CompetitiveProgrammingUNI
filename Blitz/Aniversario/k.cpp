#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
string num;
map<tuple<int, int, bool>, int> dp;

int f(int pos, int sum, bool same) {
    if (pos == (int)num.size()) return abs(sum);
    if (dp.count({pos, sum , same})) return dp[{pos, sum, same}];
    int &ans = dp[{pos, sum, same}] = 0;
    int number = num[pos] - '0';
    if (same) {
        for (int i = 0; i <= number; ++i) {
            if (i == 4) { 
                ans += f(pos + 1, sum + 1, i == number);
            }
            else if (i == 7) {
                ans += f(pos + 1, sum - 1, i == number);
            }
            else ans += f(pos + 1, sum, i == number);
        }
    }
    else {
        for (int i = 0; i < 10; ++i) {
            if (i == 4) {
                ans += f(pos + 1, sum + 1, 0);
            }
            else if (i == 7) {
                ans += f(pos + 1, sum - 1, 0);
            }
            else ans += f(pos + 1, sum, 0);
        }
    }
    return ans;
}


void solve() {
    int l, r;
    cin >> l >> r;
    l--;
    num = to_string(r);
    int preR = f(0, 0, 1);
    dp.clear();
    num = to_string(l);
    int preL = f(0, 0, 1);
    dp.clear();
    cout << preR - preL << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

