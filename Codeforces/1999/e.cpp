#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int loga[maxn];
int prefix[maxn];
void init() {
    for (int i = 1; i <= 2e5; ++i) {
        int aux = 0;
        int tmp = i;
        while (tmp) {
            tmp /= 3;
            aux++;
        }
        loga[i] = aux;
        prefix[i] = aux + prefix[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt; cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        auto f = [&] (int l, int r, int op) -> int {
            int res = 0;
            int tmp1, tmp2;
            int cnt1 = 0, cnt2 = 0;
            if (op == 1) {
                tmp1 = l + 1;
                tmp2 = l;
                while (tmp1) {
                    tmp1 /= 3;
                    cnt1++;
                }
                while (tmp2) {
                    tmp2 /= 3;
                    cnt2++;
                }
            }
            else if (op == 0) {
                tmp1 = l;
                tmp2 = l + 1;
                while (tmp1) {
                    tmp1 /= 3;
                    cnt1++;
                }
                while (tmp2) {
                    tmp2 /= 3;
                    cnt2++;
                }
            } 
            res = cnt1 * 2 + cnt2;
            return res;
        };
        int ans = min(f(l, r, 0), f(l, r, 1));
        ans += prefix[r] - prefix[l + 1];
        cout << ans << "\n";
    }
    return 0;
}

