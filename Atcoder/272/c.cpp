#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) odd.emplace_back(a[i]);
        else even.emplace_back(a[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int k = even.size();
    int l = odd.size();
    int even_ans = (k > 1 ? even[k - 1] + even[k - 2] : -1);
    int odd_ans = (l > 1 ? odd[l - 1] + odd[l - 2] : -1);
    int ans = max(even_ans, odd_ans);
    cout << ans << "\n";
    return 0;
}

