#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    int prefix[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    int sum = -1e9;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int a = 0; a < i; ++a) {
                for (int b = 0; b < j; ++b) {
                    sum = max(sum, prefix[i][j] - prefix[i][b] - prefix[a][j] + prefix[a][b]);
                }
            }
        }
    }
    cout << sum << "\n";
    return 0;
}
