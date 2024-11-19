#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

bool solve() {
    int n, k; cin >> n >> k;
    if (n & 1) {
        int tmp = (k + 1) / 2;
        if (tmp & 1) return false;
        else return true;
    }
    else {
        int tmp = k / 2;
        if (tmp & 1) return false;
        else return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}


