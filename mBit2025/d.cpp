#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

pair<int,int> intersect(int l1, int r1, int l2, int r2) {
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    int L = max(l1, l2);
    int R = min(r1, r2);
    return {L, R};
}
int len(int l, int r) {
    return r - l;
}

void solve() {
    int n,s;
    cin >> n >> s;
    vector<pair<int,int>> a(n);
    for (auto &[x,y]: a) cin >> x >> y;
    vector<int> last(n + 1, -1);
    vector<int> nxt(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = a[i];
        if (last[x] != -1) nxt[i] = last[x];
        last[x] = i;
    }
    int cnt = 0;        
    int i = 0;
    while(i < n and nxt[i] == -1) i++;
    int l1 = -1, r1 = -1;
    for (; i < n; i++) {
        if (nxt[i] == -1) continue;
        int l2 = a[i].second;
        int r2 = a[nxt[i]].second;

        if (len(l2, r2) < s) {
            cout << "-1\n";
            return;
        }

        if (l1 == -1) {
            l1 = l2;
            r1 = r2;
            continue;
        }
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        if (r1 <= l2) {
            cnt++;
            l1 = l2;
            r1 = r2;
        } else {
            auto [L, R] = intersect(l1, r1, l2, r2);
            if (len(L, R) >= s) {
                l1 = L;
                r1 = R;
            } else {
                cnt++;
                l1 = r1 = -1;
            }
        }
    }
    cnt += l1 != -1;
    cout << cnt << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

