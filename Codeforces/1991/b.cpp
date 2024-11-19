#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> b(n - 1);
        vector<int> a(n, 0);
        bool could = true;
        for (int& e : b) cin >> e;
        for (int i = 0; i < 30; ++i) {
            vector<int> tmp(n - 1, 0);
            vector<int> result;
            for (int j = 0; j < n - 1; ++j) {
                if (b[j] & (1 << i)) tmp[j] = 1;
            }
            vector<pair<int, int>> times;
            for (int j = 0; j < tmp.size(); ) {
                int aux = tmp[j];
                int cnt = 0;
                while (tmp[j] == aux && j < tmp.size()) {
                    ++j;
                    cnt++;
                }
                times.emplace_back(aux, cnt);
            }
            int k = 0;
            while (times[k].first == 0 && k < times.size()) {
                for (int a = 0; a < times[k].second; ++a) {
                    result.emplace_back(0);
                }
                k++;
            }
            if (k == times.size()) result.emplace_back(0); 
            for (int j = k; j < times.size(); ++j) {
                if (times[j].first == 0) {
                    if (j == times.size() - 1) {
                        for (int a = 0; a < times[j].second; ++a) {
                            result.emplace_back(0);
                        }
                    }
                    else {
                        for (int a = 0; a < times[j].second - 1; ++a) {
                            result.emplace_back(0);
                        }
                    }
                }
                else {
                    for (int a = 0; a <= times[j].second; ++a) {
                        result.emplace_back(times[j].first);
                    }
                }
            }
            auto check = [&] (vector<int>& a, vector<int>& tmp) -> bool {
                int l = a.size();
                for (int b = 1; b < l; ++b) {
                    if ((a[b] & a[b - 1]) != tmp[b - 1]) return false;
                }
                return true;
            };
            assert(result.size() == n);
            if (check(result, tmp)) {
                for (int j = 0; j < result.size(); ++j) {
                    a[j] |= (result[j] << i);
                }
            }
            else {
                could = false;
                break;
            }
        }
        if (could) {
            for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i + 1 == n];
        }
        else cout << -1 << "\n";
    }
    return 0;
}

