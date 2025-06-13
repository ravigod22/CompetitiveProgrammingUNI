#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int m;
    cin >> m;
    if (m <= 1199) cout << "Plomo";
    else if (m <= 1499) cout << "Verde";
    else if (m <= 1899) cout << "Azul";
    else if (m <= 2199) cout << "Amarillo";
    else cout << "Rojo";
    cout << "\n";
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


