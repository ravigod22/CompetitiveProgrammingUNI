#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        string s; cin >> s;
        const int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C') {
                        if (i < j && j < k && j - i == k - j) cnt++; 
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

