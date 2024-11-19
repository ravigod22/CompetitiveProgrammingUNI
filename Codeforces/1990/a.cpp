#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (auto e : cnt) {
        if (e.second & 1) return true; 
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes\n" : "No\n");
    }
    return 0;
}

