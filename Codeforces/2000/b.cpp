#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) {
            cin >> e;
            e--;
        }
        bool can = true;
        vector<bool> sit(n, false);
        sit[a[0]] = true;
        for (int i = 1; i < n; ++i) {
            int tmp = a[i];
            bool could = false;
            if (tmp + 1 < n && sit[tmp + 1]) could = true;
            if (tmp > 0 && sit[tmp - 1]) could = true;
            if (!could) {
                can = false;
                break;
            }
            else {
                sit[tmp] = true;
            }
        }
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}
