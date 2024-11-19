#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    while (true) {
        string s, t; cin >> s >> t;
        if (s == "*") break;
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) a[i] = 1;
            else a[i] = 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; ) {
            int tmp = a[i];
            while (i < n && tmp == a[i]) ++i;
            if (tmp == 0) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
