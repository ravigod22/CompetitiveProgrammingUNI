#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int maxe = *max_element(a.begin(), a.end());
        int mext = 1;
        sort(a.begin(), a.end());
        for (int e : a) {
            if (e == mext) mext++;
        }
        int ans = min(mext, maxe);
        cout << (ans & 1 ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
