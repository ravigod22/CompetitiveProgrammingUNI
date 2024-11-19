#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

#define pii pair<int, int>

int sqr(int x) {
    return 1LL * x * x;
}
int euclidean(pii a, pii b) {
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

void solve() {
    int n; cin >> n;
    int w, l;
    pii t;
    cin >> w >> l >> t.first >> t.second;
    vector<pii> A;
    vector<pii> R;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        A.emplace_back(x, y);
    }
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        R.emplace_back(x, y);
    }
    vector<int> DA(n);
    vector<int> DR(n);
    for (int i = 0; i < n; ++i) {
        DA[i] = euclidean(A[i], t);
        DR[i] = euclidean(R[i], t);
    }
    sort(DA.begin(), DA.end());
    sort(DR.begin(), DR.end());
    int cntA = 0;
    int cntR = 0;
    for (int i = 0; i < n; ++i) {
        if (DR[0] > DA[i]) cntA++;
        if (DA[0] > DR[i]) cntR++;
    }
    if (cntA > cntR) {
        cout << "A " << cntA << "\n";
    }
    else cout << "R " << cntR << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    while (tt--) {
        solve();
    }
    return 0;
}



