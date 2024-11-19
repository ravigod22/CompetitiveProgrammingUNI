#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) return 0;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> result(n);
        result[0] = a[0];
        for (int i = 1; i < n; ++i) {
            result[i] = a[i] ^ a[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
