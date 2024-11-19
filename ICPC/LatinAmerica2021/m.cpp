#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> solve1(int n, vector<pair<int, int>>& I) {
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    vector<int> res;
    
    
    return res;
}

vector<int> solve2(int n, vector<pair<int, int>>& I) {
    set<tuple<int, int, int>> s;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        auto [l, d] = I[i];
        s.emplace(d, i + 1, l);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> I;
    set<tuple<int, int, int>> s;
    for (int i = 0; i < n; ++i) {
        int l, d; cin >> l >> d;
        I.emplace_back(l, d);
        s.emplace(d, i + 1, l);
    }
    int d, id, l;
    tie(d, id, l) = *s.begin();
    i64 acc = l;
    vector<int> ans;
    ans.emplace_back(id);
    while (!s.empty()) {
        s.erase(s.begin());
        for (auto [d1, id1, l1] : s) {
            if (acc + 1LL * l1 <= 1LL * d1) {
                acc += l1;
                ans.emplace_back(id1);
                tie(d, id, l) = *s.begin();
                break;
            }
            else {
                cout << "*\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}
