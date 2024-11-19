#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

string s;
vector<i64> num;
vector<i64> total;

int ndigit(i64 x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}
i64 fir(i64 x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

void f(int pos) {
    if (pos == 8) {
        bool exist[10];
        memset(exist, 0, sizeof(exist));
        int in = 0;
        for (auto e : s) exist[e - '0'] = true, in = max(in, e - '0');
        for (int i = in + 1; i <= 9; ++i) {
            if (exist[i]) continue;
            string tmp = s;
            tmp += to_string(i);
            num.emplace_back(stoll(tmp));
        }
        return;
    }
    int init = (s.empty() ? 0 : s.back() - '0');
    for (int i = init; i <= 9; ++i) {
        s += to_string(i);
        f(pos + 1);
        s.pop_back();
    } 
}

void init() {
    f(0);
    for (auto x : num) {
        for (auto y : num) {
            if (ndigit(x) != ndigit(y)) continue;
            if (x % 10 != y % 10) continue;
            string xp = to_string(x / 10);
            string yp = to_string(y);
            reverse(yp.begin(), yp.end());
            string ans = xp + yp;
            total.emplace_back(stoll(ans));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    init();
    for (int i = 1; i <= tt; ++i) {
        i64 A, B, M;
        cin >> A >> B >> M;
        int cnt = 0;
        for (auto e : total) {
            if (A <= e && e <= B) {
                cnt += (e % M == 0);
            }
        }
        cout << "Case #" << i << ": " << cnt << "\n";
    }
    return 0;
}


