#include <bits/stdc++.h>
using namespace std;
int n, c, b, a;
const int maxn = 8;
vector<int> l;
int ans;

void solve(int mask, int tipo3) {
    int len = __builtin_popcount(mask);
    if (__builtin_popcount(mask) == 3) {
        vector<int> aux;
        for (int e : l) if (e) aux.push_back(e);
        sort(aux.begin(), aux.end());
        ans = min(ans, 10 * tipo3 + abs(aux[0] - c) + abs(aux[1] - b) + abs(aux[2] - a));
        ans = min(ans, 10 * tipo3 + abs(aux[0] - c) + abs(aux[1] - a) + abs(aux[2] - b));
        ans = min(ans, 10 * tipo3 + abs(aux[0] - b) + abs(aux[1] - a) + abs(aux[2] - c));
        ans = min(ans, 10 * tipo3 + abs(aux[0] - b) + abs(aux[1] - c) + abs(aux[2] - a));
        ans = min(ans, 10 * tipo3 + abs(aux[0] - a) + abs(aux[1] - b) + abs(aux[2] - c));
        ans = min(ans, 10 * tipo3 + abs(aux[0] - a) + abs(aux[1] - c) + abs(aux[2] - b));
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int bit1 = (mask >> i) & 1;
                int bit2 = (mask >> j) & 1;
                int bit3 = (mask >> k) & 1;
                if (bit1 && bit2 && bit3) {
                    ans = min(ans, 10 * tipo3 + abs(l[i] - c) + abs(l[j] - b) + abs(l[k] - a));
                    ans = min(ans, 10 * tipo3 + abs(l[i] - c) + abs(l[j] - a) + abs(l[k] - b));
                    ans = min(ans, 10 * tipo3 + abs(l[i] - a) + abs(l[j] - b) + abs(l[k] - c));
                    ans = min(ans, 10 * tipo3 + abs(l[i] - a) + abs(l[j] - c) + abs(l[k] - b));
                    ans = min(ans, 10 * tipo3 + abs(l[i] - b) + abs(l[j] - a) + abs(l[k] - c));
                    ans = min(ans, 10 * tipo3 + abs(l[i] - b) + abs(l[j] - c) + abs(l[k] - a));
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int bit1 = (mask >> i) & 1;
            int bit2 = (mask >> j) & 1;
            if (bit1 && bit2) {
                int sum = l[i];
                l[j] += sum;
                l[i] = 0;
                mask ^= (1 << i);
                solve(mask, tipo3 + 1);
                l[j] -= sum;
                l[i] += sum;
                mask |= (1 << i);
            }
        }
    }
}

int main() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        l.push_back(x);
    }
    ans = 1e9;
    solve((1 << n) - 1, 0);
    assert(ans != 1e9);
    cout << ans << "\n";
    return 0;
}
