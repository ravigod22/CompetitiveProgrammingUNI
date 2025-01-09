#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> pos(n, -1);
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(n, -1, -n);
        int cnt = 1;
        while (!pq.empty()) {
            auto [d, l, r] = pq.top();
            l = -l;
            r = -r;
            pq.pop();
            if (d == 1) {
                pos[l - 1] = cnt++;
                continue;
            }
            int cur;
            if (d & 1) cur = (l + r) / 2;
            else cur = (l + r - 1) / 2;
            pos[cur - 1] = cnt++;
            if (cur == l) {
                pq.emplace(1, -(l + 1), -r);
                continue;
            }
            if (d & 1) {
                pq.emplace(d / 2, -l, -(cur - 1));
                pq.emplace(d / 2, -(cur + 1), -r);
            }
            else {
                pq.emplace(d / 2 - 1, -l, -(cur - 1));
                pq.emplace(d / 2, -(cur + 1), -r);
            }
        }
        for (int i = 0; i < n; ++i) cout << pos[i] << " \n"[i + 1 == n];
    }
    return 0;
}
