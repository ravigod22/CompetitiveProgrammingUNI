#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    const int n = s.size();
    int l1 = 1, r1 = n, l2 = 1, r2 = 1;
    int first0 = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            first0 = i;
            break;
        }
    }
    string comp = "0";
    auto f = [&] (string s1, string s2) -> bool {
        if ((int)s1.size() > (int)s2.size()) return 0;
        if ((int)s1.size() < (int)s2.size()) return 1;
        return s2 > s1;
    };
    if (first0 == -1) {
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        return;
    }
    int dis = n - first0;
    for (int i = 0; i + dis <= n; ++i) {
        string tmp = s.substr(i, dis);
        while (tmp.size() != n) tmp = '0' + tmp;
        string result;
        for (int i = 0; i < n; ++i) {
            result += (tmp[i] == s[i] ? '0' : '1');
        }
        if (f(comp, result)) {
            comp = result;
            l2 = i + 1;
            r2 = i + dis;
        }
    }
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
