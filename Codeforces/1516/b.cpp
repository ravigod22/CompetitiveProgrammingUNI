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
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] ^ a[i];
        bool can = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = prefix[n] ^ prefix[i];
            if (tmp == prefix[i]) can = 1;
        }
        for (int i = 1; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = prefix[j] ^ prefix[i];
                int aux = prefix[n] ^ prefix[j];
                if (prefix[i] == tmp && prefix[i] == aux) can = 1;
            }
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
