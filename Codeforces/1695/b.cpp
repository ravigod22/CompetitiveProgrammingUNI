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
        if (n & 1) {
            cout << "Mike\n";
        }
        else {
            int minM = 1e9, minJ = 1e9;
            for (int i = 0; i < n; ++i) {
                if (i & 1) minJ = min(minJ, a[i]);
                else minM = min(minM, a[i]);
            }
            if (minM < minJ) {
                cout << "Joe\n";
            }
            else if (minM > minJ) {
                cout << "Mike\n";
            }
            else {
                int posM = n, posJ = n;
                for (int i = 0; i < n; ++i) {
                    if (a[i] != minM) continue;
                    if (i & 1) posJ = min(posJ, i);
                    else posM = min(posM, i);
                }
                if (posM < posJ) cout << "Joe\n";
                else cout << "Mike\n";
            }
        }
    }
    return 0;
}
