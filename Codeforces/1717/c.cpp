#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        bool can = true;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) can = false;
            if (a[i] == b[i]) cnt++;
        }
        if (cnt == n) {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (b[i] - b[(i + 1) % n] > 1 && a[i] < b[i]) can = false;
        }   
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}

