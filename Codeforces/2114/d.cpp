#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> cor(n);
    map<int, vector<pair<int, int>>> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> cor[i].first >> cor[i].second;
        x[cor[i].first].emplace_back(cor[i].second, i);
        y[cor[i].second].emplace_back(cor[i].first, i);
    }
    for (auto& [v, e] : x) 
        sort(e.begin(), e.end());
    for (auto& [v, e] : y)
        sort(e.begin(), e.end());
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    int U = x.begin() -> first;
    int D = x.rbegin() -> first;
    int L = y.begin() -> first;
    int R = y.rbegin() -> first;
    auto change = [&] (map<int, vector<pair<int, int>>> A, map<int, vector<pair<int, int>>> B, int c, int tmp) -> i64 {
        auto e = A[c];
        // tmp -> 0 , A -> x, B -> y
        // tmp -> 1, A -> y, B -> x
        if (e.size() == 1) {
            int pos = e.front().second;
            auto [P, Q] = cor[pos];
            if (tmp == 1) swap(P, Q);
            A.erase(A.find(c));
            // x -> 1, y = 0
            // erase too in B
            auto &f = B[Q];
            auto ind = find(B[Q].begin(), B[Q].end(), make_pair(P, pos));
            f.erase(ind);
            if (f.empty()) B.erase(B.find(Q));
            int Up = A.begin() -> first;
            int Do = A.rbegin() -> first;
            int Lo = B.begin() -> first;
            int Ri = B.rbegin() -> first;
            i64 area = 1LL * (Do - Up + 1) * (Ri - Lo + 1);
            if (area == 0LL + n - 1) {
                return min(1LL * (Do - Up + 2) * (Ri - Lo + 1), 1LL * (Do - Up + 1) * (Ri - Lo + 2));
            }
            else return 1LL * (Do - Up + 1) * (Ri - Lo + 1);
        }
        else {
            int Up = A.begin() -> first;
            int Do = A.rbegin() -> first;
            int Lo = B.begin() -> first;
            int Ri = B.rbegin() -> first;
            return 1LL * (Do - Up + 1) * (Ri - Lo + 1);
        }
    };
    i64 res = min(change(x, y, U, 0), change(x, y, D, 0));
    res = min(res, change(y, x, L, 1));
    res = min(res, change(y, x, R, 1));
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


