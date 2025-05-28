#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                if (s[i] > s[j] && k) {
                    swap(s[i], s[j]);
                    k--;
                    break;
                }
            }
        }
        string p = s;
        reverse(p.begin(), p.end());
        if (s == p) cout << "NO\n";
        else if (min(s, p) == s) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

