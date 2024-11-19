#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; 
        cin >> n >> m;
        string s, c; 
        cin >> s;
        map<int, int> cnt;
        vector<int> pos;
        for (int i = 0; i < m; ++i){
            int x; cin >> x;
            cnt[x]++;
            pos.emplace_back(x);
        }
        sort(pos.begin(), pos.end());
        cin >> c;
        string tmp = c;
        sort(tmp.begin(), tmp.end());
        string ans;
        int p = 0;
        for (auto e: cnt) {
            int k = e.second;
            for (int i = 0; i < k - 1; ++i) {
                char x = tmp.back();
                tmp.pop_back();
                ans += x;
            }
            ans += tmp[p++];
        }
        for (int i = 0; i < m; ++i) {
            int posr = pos[i] - 1;
            s[posr] = ans[i];
        }
        cout << s << "\n";
    }
    return 0;
}

