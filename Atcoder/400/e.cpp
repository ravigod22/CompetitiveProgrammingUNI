#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 5;
int lp[N + 1];
vector<int> pr;
vector<int> ans;

void precomputation() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
    for (int i = 2; i <= N; ++i) {
        set<int> s;
        int tmp = i;
        while (tmp != 1) {
            s.emplace(lp[tmp]);
            tmp /= lp[tmp];
        }
        if (s.size() == 2) {
            ans.emplace_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    sort(ans.begin(), ans.end());
    int q; cin >> q;
    while (q--) {
        i64 x; cin >> x;
        i64 root = sqrtl(x);
        int lo = 0;
        int hi = ans.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (1LL * ans[mid] <= root) lo = mid;
            else hi = mid - 1;
        }
        cout << 1LL * ans[lo] * ans[lo] << "\n";
    }
    return 0;
}

