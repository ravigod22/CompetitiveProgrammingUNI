#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        if (n == 1) {
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        cout << "counter -> \n";
        for (int i = 0, j = n - 1; i < n; ++i, j--) {
            vector<int> aux = a[j];
            reverse(aux.begin(), aux.end());
            for (int p = 0; p < n; ++p) {
                if (a[i][p] != aux[p]) cnt++;
            }
        }
        k -= cnt / 2;
        if (k < 0) cout << "No\n";
        else {
            if (n & 1) cout << "Yes\n";
            else cout << (k % 2 == 0 ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
