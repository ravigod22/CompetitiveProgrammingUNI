#include <bits/stdc++.h>
using namespace std;
const string tmp[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<int> poss[6];
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < 6; ++j) {
                if (s[i] == tmp[j]) poss[j].emplace_back(i + 1);
            }
        }
        for (int i = 0; i < 6; ++i) sort(poss[i].begin(), poss[i].end());
        for (int i = 0; i < q; ++i) {
            int u, v; cin >> u >> v;
            set<char> tmp1;
            for (auto e : s[u - 1]) tmp1.emplace(e);
            for (auto e : s[v - 1]) tmp1.emplace(e);
            auto f1 = [&] (int x, int pos) -> int{
                if (poss[pos].empty()) return -1;
                int lo = 0;
                int hi = poss[pos].size() - 1;
                vector<int> aux = poss[pos];
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (aux[mid] > x) hi = mid;
                    else lo = mid + 1;
                }
                return lo;  
            };
            if (tmp1.size() == 4) {
                int ans = 2e9;
                for (int j = 0; j < 6; ++j) {
                    if (tmp[j] != s[u - 1] && tmp[j] != s[v - 1]) {
                        int in = f1(u, j);
                        if (in == -1) continue;
                        if (in - 1 > 0) {
                            int aux = poss[j][in - 1];
                            ans = min(ans, abs(aux - u) + abs(aux - v)); 
                        }
                        int aux2 = poss[j][in];
                        ans = min(ans, abs(aux2 - u) + abs(aux2 - v));
                    }
                } 
                if (ans == 2e9) ans = -1;
                cout << ans << "\n";
            }
            else if (tmp1.size() <= 3) {
                cout << abs(u - v) << "\n";
            }
        }
    }
    return 0;
}


