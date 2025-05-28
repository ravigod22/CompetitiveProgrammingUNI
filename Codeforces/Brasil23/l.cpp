#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<char> ans(n);
    for (int i = 0; i < k; ++i) {
        vector<char> tmp;
        for (int j = i; j < n; j += k) {
            tmp.push_back(s[j]);
        }
        sort(tmp.begin(), tmp.end());
        for (int j = i, a = 0; j < n; j += k, a++) {
            ans[j] = tmp[a];
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i];
    cout << "\n";
    return 0;
}
