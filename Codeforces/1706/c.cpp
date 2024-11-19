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
        auto check = [&] (int i) -> int {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) return 0;
            return max(a[i - 1], a[i + 1]) + 1;
        };
        if (n & 1) {
           
        }
    }
    return 0;
}

