#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int nodes;
int trie[11 * N][10];
bool terminal[11 * N];

void insert(string &s) {
    int pos = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int nxt = s[i] - '0';
        if (!trie[pos][nxt]) trie[pos][nxt] = nodes++;
        pos = trie[pos][nxt];
    }
    terminal[pos] = true;
}

bool search(string &s) {
    int pos = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int nxt = s[i] - '0';
        if (trie[pos][nxt] == 0) return false;
        pos = trie[pos][nxt];
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    memset(trie, 0, sizeof(trie));
    memset(terminal, false, sizeof(terminal));
    vector<pair<int,string>> v;
    nodes = 1;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int k = s.size();
        v.emplace_back(k, s);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; ++i) {
        if (search(v[i].second)) ans = false;
        insert(v[i].second);
    }
    cout << (ans ? "YES\n" : "NO\n");
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
