#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        reverse(a.begin(), a.end());
        map<int, bool> exist;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (exist.count(a[i])) break;
            exist[a[i]] = true;
            ans++;
        } 
        cout << n - ans << "\n";
    }
    return 0;
}


