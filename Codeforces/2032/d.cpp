#include <bits/stdc++.h>
using namespace std;


#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> p(n, -1);
    p[1] = 0;
    auto ask = [&] (int a, int b) -> int {
        cout << "? " << a << " " << b << endl;
        int x; cin >> x;
        // x -> 0 -> not contain node 0
        // x -> 1 -> contain node 0
        return x;
    };
    vector<int> sec(n);
    for (int i = 2; i < n; ++i) {
        int tmp = ask(1, i);
        if (tmp == 0) {
            p[i] = 1;
            break;
        }
        else {
            p[i] = 0;
            //path.emplace_back(i);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


