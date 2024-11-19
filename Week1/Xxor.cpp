#include <bits/stdc++.h>
using namespace std;
const int l = 31;
long long m = 0;

long long max_xor(int n, vector<vector<long long>> &trie) {
    long long ans = 0;
    int r = 0;
    for (int i = l; i >= 0; --i) {
        int ch = (n >> i) & 1;
        if (trie[r][1 - ch]) {
            ans += (1ll << i);
            r = trie[r][1 - ch];
        }
        else {
            r = trie[r][ch];
        }
    }
    return ans;
}

void add(int n, vector<vector<long long>> &trie) {
    int r = 0;
    for (int i = l; i >= 0; i--) {
        int ch = (n >> i) & 1;
        if (!trie[r][ch]) trie[r][ch] = ++m;
        r = trie[r][ch];
    }
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<vector<long long>> trie(l * (n + 1), vector<long long> (2));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] ^ a[i];
    }
    m = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        add(a[i], trie);
        ans = max(ans, max_xor(k ^ a[i], trie));
    }
    cout << (ans ^ k) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
