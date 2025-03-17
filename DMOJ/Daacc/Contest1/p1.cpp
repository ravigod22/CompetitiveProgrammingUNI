#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    if (n + 2 <= m) cout << "okay";
    else if (n == m or n + 1 == m) cout << "stressed";
    else cout << "relaxed";
    return 0;
}
