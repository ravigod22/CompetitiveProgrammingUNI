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
        sort(a.begin(),a.end());
        cout << (a[n - 1] + a[n - 2]) - (a[0] + a[1]) << "\n";
    }
    return 0;
}

