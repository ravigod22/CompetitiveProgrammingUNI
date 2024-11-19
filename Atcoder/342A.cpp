#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[s[i] - '0'] == 1) {
            cout << i + 1;
            break;
        }
    }
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
