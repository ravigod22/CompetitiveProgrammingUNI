#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        if (a.front() == 0 && a.back() == 0) {
            cout << 3 << "\n";
            cout << n / 2 + 1 << " " << n << "\n";
            cout << 1 << " " << n / 2 << "\n";
            cout << 1 << " " << 2 << "\n";
        }
        else if (a.front() == 0 && a.back() != 0) {
            cout << 2 << "\n";
            cout << 1 << " " << n - 1 << "\n";
            cout << 1 << " " << 2 << "\n";
        }
        else if (a.front() != 0 && a.back() == 0) {
            cout << 2 << "\n";
            cout << 2 << " " << n << "\n";
            cout << 1 << " " << 2 << "\n";
        }
        else {
            int cnt = 0;
            for (int i = 1; i + 1 < n; ++i) cnt += (a[i] == 0);
            if (cnt) {
                cout << 2 << "\n";
                cout << 2 << " " << n - 1 << "\n";
                cout << 1 << " " << 3 << "\n";
            }
            else {
                cout << 1 << "\n";
                cout << 1 << " " << n << "\n";
            }
        }
    }
    return 0;
}

