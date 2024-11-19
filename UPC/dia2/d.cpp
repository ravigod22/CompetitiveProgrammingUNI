#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int nodes = 1;
int trie[maxn][11];

void insert(string& s) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        int nxt = s[i] - '0';
        if (trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
}

bool search(string& s) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        int nxt = s[i] - '0';
        if (trie[pos][nxt] == 0) return false;
        pos = trie[pos][nxt];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        memset(trie, 0, sizeof(trie));
        nodes = 1;
        int n; cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        sort(s.rbegin(), s.rend());
        bool could = true;
        for (int i = 0; i < n; ++i) {
            if (i) {
                if (search(s[i])) could = false;
            }
            insert(s[i]);
        }
        cout << (could ? "YES\n" : "NO\n");
    }
    return 0;
}
