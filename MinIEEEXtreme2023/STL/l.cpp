#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<int> left, right;
    i64 accl = 0, accr = 0;
    i64 remain = 0;
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            remain += b;
            if (left.empty()) {
                left.insert(a);
                accl += a;
            }
            else if (right.empty()) {
                int e = *left.rbegin();
                if (e <= a) {
                    right.insert(a);
                    accr += a;
                }
                else {
                    // e > a
                    left.extract(e);
                    accl -= e;
                    left.insert(a);
                    accl += a;
                    right.insert(e);
                    accr += e;
                }
            }
            else {
                if (right.size() == left.size()) {
                    int median = *left.rbegin();
                    int lastright = *right.begin();
                    if (median <= a) {
                        if (lastright >= a) {
                            left.insert(a);
                            accl += a;
                        }
                        else {
                            right.extract(lastright);
                            accr -= lastright;
                            right.insert(a);
                            accr += a;
                            left.insert(lastright);
                            accl += lastright;
                        }
                    }
                    else {
                        left.insert(a);
                        accl += a;
                    }
                }
                else {
                    int median = *left.rbegin();
                    if (median <= a) {
                        right.insert(a);
                        accr += a;
                    }
                    else {
                        // median > a
                        int lastleft = *left.rbegin();
                        left.extract(lastleft);
                        accl -= lastleft;
                        right.insert(lastleft);
                        accr += lastleft;
                        left.insert(a);
                        accl += a;
                    }
                }
            }
        }
        else {
            int median = *left.rbegin();
            i64 ans = 1LL * median * left.size() - accl + accr - 1LL * median * right.size() + remain;
            cout << median << " " << ans << "\n";
        }
    }
    return 0;
}
