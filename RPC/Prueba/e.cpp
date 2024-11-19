#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> p;
        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            p.emplace_back(x, y);
        }
        long long sum = 0;
        map<int,vector<int>> paths;
        vector<int> vis(n, false);
        for (int i = 0; i < n - 1; ++i) {
            if (vis[i]) continue;
            auto a = p[i];
            vis[i] = true;
            vector<int> tmp;
            tmp.emplace_back(i);
            for (int j = i + 1; j < n; ++j) {
                auto b = p[j];
                if ((abs(a.first - b.first) + abs(a.second - b.second)) % 2 != 0) continue;
                cout << "i -> " << i << " ,j -> " << j << "\n";
                tmp.emplace_back(j);
                vis[j] = true;
            }
            paths[i] = tmp;
            tmp.clear();
        }
        long long ans = 0;
        for (auto e : paths) {
            vector<int> tmp = e.second;
            int k = tmp.size();
            if (k == 1) continue;
            long long sum = 0;
            cout << "i -> " << e.first << " " << k << "\n";
            k--;
            for (int i = 0; i < (int)tmp.size(); ++i) {
                cout << tmp[i] << " ";
            }
            cout << endl;
            for (int i = 1; i < (int)tmp.size(); ++i) {
                auto a = p[tmp[i]];
                auto b = p[tmp[i - 1]];
                sum += 1ll * max(abs(a.first - b.first), abs(a.second - b.second)) * k;
                k--;
            }
            ans += sum;
        }
        cout << ans << "\n";
    }
    return 0;
}

