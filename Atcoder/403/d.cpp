#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int cnt[maxn];

int main() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x] += 1;
    }
    if (d == 0) {
        int ans = 0;
        for (int i = 0; i <= 1e6; ++i) {
            ans += max(0, cnt[i] - 1);
        } 
        cout << ans << "\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < d; ++i) {
        vector<int> aux;
        for (int j = i; j <= 1e6; j += d) {
            if (cnt[j]) {
                aux.emplace_back(j);
            }
        }
        int l = aux.size();
        for (int j = 0; j < l; ) {
            vector<int> tmp;
            tmp.push_back(aux[j]);
            bool jump = false;
            while (j + 1 < l && aux[j] + d == aux[j + 1]) {
                jump = true;
                tmp.push_back(aux[j + 1]);
                j++;
            }
            int odd = 0, even = 0;
            int p = tmp.size();
            for (int k = 0; k < p; k += 2) odd += cnt[tmp[k]];
            for (int k = 1; k < p; k += 2) even += cnt[tmp[k]];
            ans += min(odd, even);
            if (!jump) j++;
        }
    }
    cout << ans << "\n";
    return 0;
}
