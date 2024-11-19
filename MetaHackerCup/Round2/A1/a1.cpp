#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

vector<long long> num;

string f(string& tmp, int x) {
    int k = ((int)tmp.size() + 1) / 2;
    string ans(tmp.size(), '0');
    if (x + k > 10) return ans;
    for (int i = 0; i < k; ++i) {
        tmp[i] = (char) (x + '0');
        x++;
    }
    for (int i = k - 1; i < tmp.size(); ++i) {
        x--;
        tmp[i] = (char) (x + '0');
    } 
    return tmp;
}

void init() {
    for (int i = 1; i <= 17; i += 2) {
        // aaaaabaaaaa
        string tmp(i, '0');
        for (int j = 1; j <= 9; ++j) {
            string aux = f(tmp, j);
            if (aux.back() != '0') num.emplace_back(stoll(aux));
        }
    }
}

int solve() {
    long long a, b, m; cin >> a >> b >> m;
    int cnt = 0;
    for (auto& e : num) {
        if (a <= e && e <= b) cnt += (e % m == 0);
    } 
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        cout << "Case #" << i << ": " << solve() << (i == tt ? "" : "\n");
    }
    return 0;
}


