#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<i64> s(k);
        for (auto& e : s) cin >> e;
        vector<i64> a;
        for (int i = 1; i < k; ++i) a.emplace_back(s[i] - s[i - 1]);
        bool can = true;
        for (int i = 1; i + 1 < k; ++i){
            if (a[i] < a[i - 1]) can = false;
        }
        if (k > 1 && s[0] > a[0] * (n - k + 1)) can = false;
        cout << (can ? "Yes" : "No") << "\n";
    }
    return 0;
}

