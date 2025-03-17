#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<vector<int>> pos(26);
        vector<int> divi;
        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].emplace_back(i);
        }
        for (int i = 1; i * i <= n; ++i) {
            if (n % i) continue;
            divi.emplace_back(i);
            if (n / i != i) divi.emplace_back(n / i);
        }
        vector<pair<int, int>> aux;
        for (int i = 0; i < 26; ++i) aux.emplace_back((int)pos[i].size(), i);
        sort(aux.rbegin(), aux.rend());
        int ans = n;
        string nt = s;
        for (int d : divi) {
            vector<vector<int>> tmp = pos;
            vector<int> bag;
            int ele = n / d;
            if (ele > 26) continue;
            int res = 0;
            for (int i = ele; i < 26; ++i) {
                auto [sz, ind] = aux[i];
                while (!tmp[ind].empty()) {
                    bag.emplace_back(tmp[ind].back());
                    tmp[ind].pop_back();
                }
            }
            for (int i = 0; i < ele; ++i) {
                auto [sz, ind] = aux[i];
                if (d <= sz) {
                    while (tmp[ind].size() > d) {
                        bag.emplace_back(tmp[ind].back());
                        tmp[ind].pop_back();
                    }
                }
                else {
                    res += d - sz;
                    while (tmp[ind].size() < d) {
                        tmp[ind].emplace_back(bag.back());
                        bag.pop_back();
                    }
                }
            }
            if (res < ans) {
                ans = res;
                for (int i = 0; i < 26; ++i) {
                    if (tmp[i].empty()) continue;
                    for (int e : tmp[i]) {
                        nt[e] =  char(i + 'a');
                    }
                }  
            }
        }
        cout << ans << "\n";
        cout << nt << "\n";
    }
    return 0;
}
