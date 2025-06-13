#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int minG = min(b, d);
    int minF = min(a, c);
    if (minG > minF) {
        cout << "Flower\n";
    }
    else cout << "Gellyfish\n";
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


