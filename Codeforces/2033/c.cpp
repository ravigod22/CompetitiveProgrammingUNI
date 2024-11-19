#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 2) {
        cout << (a[0] == a[1]) << "\n";
        return;
    }
    int cnt = 0;
    for (int i = n / 2 - 1; i >= 0; --i) {
        if (i + 1 == n / 2 && n % 2 == 0) {
            cnt += (a[i] == a[n - i - 1]);
        }
        else {
            int aux1 = (a[i] == a[i + 1]) + (a[n - i - 1] == a[n - i - 2]);
            swap(a[i], a[n - i - 1]);
            int aux2 = (a[i] == a[i + 1]) + (a[n - i - 1] == a[n - i - 2]);
            swap(a[i], a[n - i - 1]);
            if (aux1 <= aux2) cnt += aux1;
            else {
                cnt += aux2;
                swap(a[i], a[n - i - 1]);
            }
        }
    }
    cout << cnt << "\n";
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


