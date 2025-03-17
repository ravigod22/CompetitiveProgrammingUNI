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
        int one = count(a.begin(), a.end(), 1);
        cout << (one % 2 == 0 ? "Mike" : "Josh") << "\n";
    }
    return 0;
}





