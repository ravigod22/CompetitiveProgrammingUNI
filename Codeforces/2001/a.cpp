#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> cnt(n + 1, 0);
        vector<int> a(n);
        for (int& e : a) {
            cin >> e;
            cnt[e]++;
        }
        int maxe = *max_element(cnt.begin(), cnt.end());
        cout << n - maxe << "\n";
    }
    return 0;
}
