#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "Yes\n";
            cout << 1 << "\n";
            continue;
        }
        if (n == 2) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector<int> ans;
        set<int> can;
        bool two = false;
        for (int i = 1; i + 1 < n; ++i) {
            can.emplace(2 * i * (i + 1));
        }
        int tmp = 2 * (n - 1);
        if (can.count(tmp)) two = false;
        else two = true;
        if (two) {
            cout << 2 << " ";
            for (int i = 1; i + 1 < n; ++i) cout << 2 * i * (i + 1) << " ";
            cout << tmp << "\n";
        }
        else {
            cout << 3 << " " << 6 << " ";
            for (int i = 1; i + 2 < n; ++i) cout << 2 * i * (i + 1) << " ";
            cout << 2 * (n - 2) << "\n";
        }
    }
    return 0;
}
