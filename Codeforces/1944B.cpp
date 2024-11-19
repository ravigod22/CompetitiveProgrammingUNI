#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        std::vector<int> a(n), b(n);
        std::vector<std::vector<int>> times_a(2, std::vector<int> ());
        std::vector<std::vector<int>> times_b(2, std::vector<int> ()); 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && a[i] == a[i + 1]) {
                times_a[1].emplace_back(a[i]);
                times_a[1].emplace_back(a[i]);
                ++i;
            }
            else {
                times_a[0].emplace_back(a[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && b[i] == b[i + 1]) {
                times_b[1].emplace_back(b[i]);
                times_b[1].emplace_back(b[i]);
                ++i;
            }
            else {
                times_b[0].emplace_back(b[i]);
            }
        }
        std::sort(times_a[0].begin(), times_a[0].end());
        std::sort(times_b[0].begin(), times_b[0].end());
        int p = times_a[1].size();
        std::vector<int> result_a, result_b;
        if (2 * k <= p) {
            for (int i = 0; i < 2 * k; i += 2) {
                result_a.emplace_back(times_a[1][i]);
                result_a.emplace_back(times_a[1][i]);
                result_b.emplace_back(times_b[1][i]);
                result_b.emplace_back(times_b[1][i]);
            }
        }
        else {
            for (int i = 0; i < p; i += 2) {
                result_a.emplace_back(times_a[1][i]);
                result_a.emplace_back(times_a[1][i]);
                result_b.emplace_back(times_b[1][i]);
                result_b.emplace_back(times_b[1][i]);
            }
            k *= 2;
            k -= p;
            for (int i = 0; i < k; ++i) {
            	result_a.emplace_back(times_a[0][i]);
            }
            for (int i = 0; i < k; ++i) {
            	result_b.emplace_back(times_b[0][i]);
            }
        }
        for (int i = 0; i < (int)result_a.size(); ++i) {
        	cout << result_a[i] << " \n"[i + 1 == (int)result_a.size()];
        } 
        for (int i = 0; i < (int)result_b.size(); ++i) {
        	cout << result_b[i] << " \n"[i + 1 == (int)result_b.size()];
        }
    }
    return 0;
}

