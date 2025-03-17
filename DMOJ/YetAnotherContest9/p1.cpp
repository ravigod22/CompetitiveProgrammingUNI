#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int& e : a) cin >> e;
    for (int& e : p) cin >> e;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; ) {
        int cur = a[i];
        int pos_cur = pos[cur];
        while (pos_cur < n && i < n && cur == p[pos_cur]) {
            pos_cur++;
            i++;
            if (i < n) cur = a[i];
        }
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}




