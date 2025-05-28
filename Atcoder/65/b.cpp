#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int& e : p) cin >> e, e--;
    vector<bool> vis(n, false);
    int cnt = 0;
    bool exist = false;
    for (int i = 0; !vis[i] ; i = p[i]) {
        vis[i] = true;
        cnt += 1;
        if (i == 1) {
            exist = true;
            break;
        }
    }
    if (exist) cout << cnt - 1 << "\n";
    else cout << -1 << "\n";
    return 0;
}
