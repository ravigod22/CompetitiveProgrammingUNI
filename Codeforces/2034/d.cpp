#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < 3; ++i) {
        cnt[i] = count(a.begin(), a.end(), i);
    }
    pair<int, int> lim[3];
    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            lim[i].first = 0;
            lim[i].second = cnt[i] - 1;
        }
        else {
            lim[i].first = lim[i - 1].second + 1;
            lim[i].second = lim[i].first + cnt[i] - 1;
        }
    }
    vector<int> block[3][3];
    for (int j = 0; j < 3; ++j) {
        auto [l, r] = lim[j];
        for (int i = l; i <= r; ++i) {
            block[j][a[i]].emplace_back(i);
        }
    }
    auto print = [&](void) -> void {
        for (int i = 0; i < 3; ++i) {
            cout << "bloque -> " << i + 1 << "\n";
            for (int j = 0; j < 3; ++j) {
                cout << "pos "<< j <<" : ";
                for (int e : block[i][j]) {
                    cout << e << " ";
                }
                cout << "\n";
            }
        }
    };
    // print();
    // cout << "=========================\n";
    int steps = n;
    vector<pair<int, int>> ans;
    if (block[2][1].size()) {
        vector<int> &tmp = block[2][1];
        vector<int> &f2 = block[0][2];
        vector<int> &s2 = block[1][2];
        while (!tmp.empty()) {
            int lastI = tmp.back();
            tmp.pop_back();
            if (!f2.empty()) {
                int aux = f2.back();
                f2.pop_back();
                // 2 -> lastI , 0 -> aux 
                ans.emplace_back(lastI, aux);
                steps--;
                block[2][2].emplace_back(lastI);
                block[0][1].emplace_back(aux);
                continue;
            }
            if (!s2.empty()) {
                int aux = s2.back();
                s2.pop_back();
                steps--;
                ans.emplace_back(lastI, aux);
                block[2][2].emplace_back(lastI);
                block[1][1].emplace_back(aux);
            }
        }
    }
    // print();
    // cout << "=============================\n";
    if (block[2][0].size()) {
        vector<int> &tmp = block[2][0];
        while (!tmp.empty()) {
            if (block[1][1].size() && block[0][2].size()) {
                int zeroIII = tmp.back();
                tmp.pop_back();
                int oneII = block[1][1].back();
                block[1][1].pop_back();
                int twoI = block[0][2].back();
                block[0][2].pop_back();
                ans.emplace_back(zeroIII, oneII);
                ans.emplace_back(oneII, twoI);
                ans.emplace_back(zeroIII, oneII);
                block[2][2].emplace_back(zeroIII);
                block[1][1].emplace_back(oneII);
                block[0][0].emplace_back(twoI);
                steps -= 3;
            }   
            else if (block[0][1].size() && block[1][2].size()) {
                int zeroIII = tmp.back();
                tmp.pop_back();
                int oneI = block[0][1].back();
                block[0][1].pop_back();
                int twoII = block[1][2].back();
                block[1][2].pop_back();
                ans.emplace_back(zeroIII, oneI);
                ans.emplace_back(zeroIII, twoII);
                block[2][2].emplace_back(zeroIII);
                block[1][1].emplace_back(twoII);
                block[0][0].emplace_back(oneI);
                steps -= 2;
            }
        }
    }
    assert(block[2][2].size() == cnt[2]);
    if (block[0][1].size()) {
        vector<int> &tmp = block[0][1];
        while (!tmp.empty()) {
            int oneI = tmp.back();
            tmp.pop_back();
            int zeroII = block[1][0].back();
            block[1][0].pop_back();
            ans.emplace_back(zeroII, oneI);
            block[0][0].emplace_back(oneI);
            block[1][1].emplace_back(zeroII);
            steps--;
        }
    }
    assert(block[0][0].size() == cnt[0]);
    assert(block[1][1].size() == cnt[1]);
    // print();
    assert(steps >= 0);
    cout << n - steps << "\n";
    for (auto [l, r] : ans) cout << l + 1 << " " << r + 1 << "\n";
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

