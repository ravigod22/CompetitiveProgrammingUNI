#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        int maxdiff = 0;
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            int tmp = b[i] - a[i];
            if (tmp > maxdiff) {
                maxdiff = tmp;
                pos = i;
            }
        }
        bool can = true;
        if (pos != -1) {
            for (int i = 0; i < n; ++i) {
                if (i == pos) continue;
                if (a[i] - maxdiff < b[i]) can = false;
            }
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}

