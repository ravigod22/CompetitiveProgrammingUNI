#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (auto& e : a) cin >> e;
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (a[i] & 1) cnt++;
        if (cnt != 0 && cnt != n) {
            cout << -1 << "\n";
            continue;
        }
        if (count(a.begin(), a.end(), 0) == n) {
            cout << 0 << "\n\n";
            continue;
        }
        vector<int> choose;
        while (true) {
            long long tmp = *max_element(a.begin(), a.end());
            long long op = tmp / 2;
            set<long long> s(a.begin(), a.end());
            if (s.size() != 1) {
                choose.emplace_back(op);
                for (int i = 0; i < n; ++i) {
                    a[i] = abs(a[i] - op);
                }
            }
            else {
                long long aux = *s.begin();
                choose.emplace_back(aux);
                break;
            }
        }
        cout << choose.size() << "\n";
        for (int i = 0; i < choose.size(); ++i) cout << choose[i] << " ";
        cout << "\n";
    }
    return 0;
}

