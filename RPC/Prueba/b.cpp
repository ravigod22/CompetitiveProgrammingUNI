#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char A[n][n], B[n][n];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> A[i][j];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> B[i][j];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] != B[i][j]) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}

