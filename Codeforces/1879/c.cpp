#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 5;
vector<int> fact(maxn);

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

void init() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fact[i] = mul(i, fact[i - 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        int minop = 0;
        int ans = 1;
        for (int i = 0; i < n; ) {
            char cur = s[i];
            int cnt = 0;
            while (i < n && cur == s[i]) cnt++, i++;
            minop += cnt - 1;
            ans = mul(ans, cnt);
        }
        ans = mul(ans, fact[minop]);
        cout << minop << " " << ans << "\n";
    }
    return 0;
}


