#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int aux = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            vector<int> tmp(x);
            set<int> mex;
            for (int j = 0; j <= x + 1; ++j) mex.emplace(j);
            for (int j = 0; j < x; ++j) {
                cin >> tmp[j];
                mex.erase(tmp[j]);
            }
            aux = max(aux, *mex.begin());
            int tmp2 = *mex.begin();
            mex.erase(tmp2);
            aux = max(aux, *mex.begin());
        }
        long long result = 0;
        assert(aux <= maxn);
        if (aux > m) {
            result = 1LL * (m + 1) * aux;
        }
        else {
            result = 1LL * m * (m + 1) / 2 - 1LL * aux * (aux + 1) / 2;
            result += 1LL * (aux + 1) * aux;
        }
        cout << result << "\n";
    }
    return 0;
}
