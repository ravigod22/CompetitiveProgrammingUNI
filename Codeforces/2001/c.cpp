#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        auto ask = [&] (int a, int b) -> int {
            cout << "? " << a << " " << b << endl;
            int x; cin >> x;
            return x;
        };
        vector<int> v(n);
        map<pair<int, int>, int> exist;
        int cnt = 0;
        int tmp = 1;
        for (int i = 0; i < n; ++i) {
            int e = ask(tmp, i + 1);
            exist[{tmp, i + 1}] = e;
            cnt++;
            v[i] = e;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i + 1 == tmp) continue;
            while (true) {
                int aux;
                if (exist.count({i + 1, v[i]})) {
                    aux = exist[{i + 1, v[i]}];
                }
                else {
                    aux = ask(i + 1, v[i]);
                    exist[{i + 1, v[i]}] = aux;
                }
                cnt++;
                if (aux == i + 1 or aux == tmp) {
                    ans.emplace_back(i + 1, v[i]);
                    break;
                }
                else {
                    v[i] = aux;
                }
            }
        }
        assert(cnt <= 15 * n);
        cout << "!";
        for (auto e : ans) cout << " " <<e.first << " " << e.second;
        cout << endl;
    }
    return 0;
}
