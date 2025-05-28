#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    multiset<int> s(a.begin(), a.end());
    int ans = -1, best = -1;
    for (int i = 0; i < n; ++i) {
        s.extract(a[i]);
        if (!s.count(a[i])) {
            if (best < a[i]) {
                best = a[i];
                ans = i + 1;
            }
        }
        s.insert(a[i]);
    }
    cout << ans << "\n";
    return 0;
}


