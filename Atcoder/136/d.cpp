#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    const int n = s.size();
    int p = 0;
    vector<int> ans(n, 0);
    while (p < n) {
        int cntR = 0, cntL = 0;
        while (p < n && s[p] == 'R') p++, cntR++;
        int pchange = p;
        while (p < n && s[p] == 'L') p++, cntL++;
        ans[pchange - 1] += (cntR + 1) / 2 + (cntL / 2);
        ans[pchange] += (cntR / 2) + (cntL + 1) / 2;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    return 0;
}
