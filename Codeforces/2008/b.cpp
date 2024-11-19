#include <bits/stdc++.h>
using namespace std;

int n;
bool solve() {
    cin >> n;
    string s; cin >> s;
    int cnt = 0;
    if ((int)s.size() < 4) return false;
    if ((int)s.size() == 4) return true;
    vector<int> one;
    int zero = 0;
    for (int i = 0; i < n; ) {
        char tmp = s[i];
        int aux = 0;
        while (i < n && tmp == s[i]) {
            i++, aux++;
        }
        if (tmp == '0') {
            cnt = max(cnt, aux);
            zero++;
        }
        else one.emplace_back(aux);
    }
    if (zero != cnt) return false;
    if (one.size() == 2) {
        if (one.front() == cnt + 3 && one.back() == cnt + 3) return true;
        else return false;
    }
    int k = cnt - 1;
    for (int i = 1; i < one.size() - 1; ++i) {
        if (one[i] == 2) k--;
    }
    if (k != 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}

