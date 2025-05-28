#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> odd, even;
        for (int i = 0; i < n; ++i) {
            if (i & 1) even.push_back(a[i]);
            else odd.push_back(a[i]);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        vector<int> ans(n);
        for (int i = 0; i < odd.size(); ++i) {
            ans[2 * i] = odd[i];
        }
        for (int i = 0; i < even.size(); ++i) {
            ans[2 * i + 1] = even[i];
        }
        for (int i = 0; i < n; ++i) 
            cout << ans[i] << " \n"[i + 1 == n]; 
    }
    return 0;
}
