#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        vector<int> b2(b.rbegin(), b.rend());
        cout << (a == b || a == b2 ? "Bob\n" : "Alice\n");
    }
    return 0;
}

