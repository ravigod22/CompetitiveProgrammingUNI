#include <bits/stdc++.h>
using namespace std;

int n, x, y;

void solve() {
    cin >> n >> x >> y;
    int d = y - x;
    vector<int> divi;
    for (int i = 1; i * i <= d; ++i) {
        if (d % i == 0) {
            divi.emplace_back(i);
            if (d / i != i) divi.emplace_back(d / i);
        }
    }
    sort(divi.begin(), divi.end());
    vector<int> ans;
    int mx = 1e9;
    for (int i = 0; i < divi.size(); ++i) {
        int tmp = (d / divi[i]) + 1;
        if (tmp > n) continue;
        vector<int> aux;
        for (int j = x; j <= y; j += divi[i]) {
            aux.emplace_back(j);
        }
        int rem = n - tmp;
        int lim = x;
        while (rem && lim - divi[i] > 0) {
            lim -= divi[i];
            rem--;
            aux.emplace_back(lim);
        }
        if (rem > 0) {
            int upp = y;
            while (rem) {
                upp += divi[i];
                aux.emplace_back(upp);
                rem--;
            }
        }
        //cout << divi[i] << "\n";
        //for (int e : aux) cout << e << " ";
        //cout << endl;
        int mxtmp = *max_element(aux.begin(), aux.end());
        if (mxtmp < mx) {
            mx = mxtmp;
            ans = aux;
        }
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

