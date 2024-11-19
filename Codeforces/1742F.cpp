#include <bits/stdc++.h>
using namespace std;

long long length_v(vector<long long> &v) {
    long long sum = 0;
    int k = v.size();
    for (int i = 0; i < k; ++i) {
        sum += v[i];
    }
    return sum;
}

void solve() {
    int q;
    cin >> q;
    vector<long long> S(26, 0);
    vector<long long> T(26, 0);
    S[0] = T[0] = 1;
    bool another_S = false;
    bool another_T = false;
    for (int i = 0; i < q; ++i) {
        int d, k;
        string tmp;
        cin >> d >> k >> tmp;
        vector<long long> cnt(27, 0);
        int p = tmp.size();
        if (d == 1) {
            for (int j = 0; j < p; ++j) {
                if (tmp[j] != 'a') another_S = true;
                cnt[tmp[j] - 'a']++;
            }
            for (int j = 0; j < 27; ++j) {
                S[j] += 1ll * k * cnt[j]; 
            }

        }
        else {
            for (int j = 0; j < p; ++j) {
                if (tmp[j] != 'a') another_T = true;
                cnt[tmp[j] - 'a']++;
            }
            for (int j = 0; j < 27; ++j) {
                T[j] += 1ll * k * cnt[j];
            }
        }
        if (another_T) {
            cout << "YES\n";
            continue;
        }
        if (S[0] < T[0]) {
            if (another_S) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
