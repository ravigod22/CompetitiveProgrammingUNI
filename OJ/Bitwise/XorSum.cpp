#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<i64> v(n);
    for (auto& e : v) cin >> e;
    i64 resXor = 0;
    i64 resOr = 0;
    for (int b = 0; b < 42; ++b) {
        i64 mod = 1LL << b;
        vector<pair<i64, int>> aux;
        for (int i = 0; i < n; ++i) {
            if (v[i] & mod) aux.emplace_back(v[i] % mod, 1);
            else aux.emplace_back(v[i] % mod, 0);
        }
        sort(aux.begin(), aux.end());
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (aux[i].second);
        }
        vector<i64> tmp;
        for (int i = 0; i < n; ++i) tmp.emplace_back(aux[i].first);
        int ansXor = 0, ansOr = 0;
        int j = (int)tmp.size() - 1;
        for (int i = 0; i < n; ++i) {
            int comple1 = 0, comple0 = 0;
            int remain1 = 0, remain0 = 0;
            while (j >= 0 && tmp[i] + tmp[j] >= mod) j--;
            if (i <= j) {
                remain0 = i + 1 - pre[i + 1];
                remain1 = pre[i + 1];
            }
            else {
                remain0 = j + 1 - pre[j + 1];
                remain1 = pre[j + 1];
                comple1 = pre[i + 1] - pre[j + 1];
                comple0 = i - j - comple1;
            }
            if (aux[i].second) {
                ansXor ^= (remain0 % 2) ^ (comple1 % 2);
                if (0 < remain0 || 0 < comple1) ansOr |= 1;
            }
            else {
                ansXor ^= (remain1 % 2) ^ (comple0 % 2);
                if (0 < remain1 || 0 < comple0) ansOr |= 1;
            }
        }
        if (ansXor) resXor |= mod;
        if (ansOr) resOr |= mod;
    }
    cout << resXor << " " << resOr << "\n";
    return 0;
}
