#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        string odd, even;
        for (int i = 0; i < n; ++i) {
            if (i & 1) odd += s[i];
            else even += s[i];
        }
        sort(s.begin(), s.end());
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        if (k % 2 == 0) cout << s;
        else {
            int p = 0, q = 0;
            for (int i = 0; i < n; ++i) {
                if (i & 1) cout << odd[p++];
                else cout << even[q++];
            }
        }
        cout << "\n";
    }
    return 0;
}
