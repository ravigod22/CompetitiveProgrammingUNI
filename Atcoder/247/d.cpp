#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        int q; cin >> q;
        deque<pair<int, i64>> cylinder;
        for (int i = 0; i < q; ++i) {
            int op; cin >> op;
            if (op == 1) {
                int x, c; cin >> x >> c;
                if (cylinder.empty()) {
                    cylinder.emplace_back(x, 1LL * c);
                }
                else {
                    auto e = cylinder.back();
                    if (e.first == x) {
                        i64 tmp = 0LL + e.second + c;
                        cylinder.pop_back();
                        cylinder.emplace_back(x, tmp);
                    }
                    else cylinder.emplace_back(x, c);
                }
            }
            else {
                i64 c; cin >> c;
                i64 sum = 0;
                while (c) {
                    auto e = cylinder.front();
                    if (e.second <= c) {
                        sum += 1LL * e.second * e.first;
                        cylinder.pop_front();
                        c -= e.second;
                    }
                    else {
                        cylinder.pop_front();
                        sum += 1LL * e.first * c;
                        cylinder.emplace_front(e.first, e.second - c);
                        c = 0;
                    }
                }
                cout << sum << "\n";
            }
        }
    }
    return 0;
}

