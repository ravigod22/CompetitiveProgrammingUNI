#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


const int mxn = 515;

void solve() {
    int n, t; cin >> n >> t;
    vector<pair<char, double>> c;
    for (int i = 0; i < n; ++i) {
        char p; cin >> p;
        int x; cin >> x;
        c.emplace_back(p, 1.0 * x);
    }
    double ans = 0.0;
    while (true) {
        int cntP = 0;
        int cntNP = 0;
        double accP = DBL_MAX;
        double accNP = DBL_MAX;
        for (int i = 0; i < n; ++i) {
            if (c[i].second <= 0.0) continue;
            if (c[i].first == 'P') {
                accP = min(accP, c[i].second);
                cntP++;
            }
            else {
                accNP = min(accNP, c[i].second); 
                cntNP++;
            }
        }
        if (cntP == 0 && cntNP == 0) break;
        double eachP = 0.75 * t / cntP;
        double eachNP = 0.25 * t / cntNP;
        if (cntP == 0) {
            eachNP = 1.0 * t / cntNP;
            eachP = 0.0;
        }
        else if (cntNP == 0) {
            eachP = 1.0 * t / cntP;
            eachNP = 0.0;
        }
        double tmp = DBL_MAX;
        if (eachP > 0) {
            tmp = min(tmp, accP / eachP);
        }
        if (eachNP > 0) {
            tmp = min(tmp, accNP / eachNP);
        }
        ans += tmp;
        for (int i = 0; i < n; ++i) {
            if (c[i].second <= 0.0) continue;
            if (c[i].first == 'P') c[i].second -= 1.0 * eachP * tmp;
            if (c[i].first == 'N') c[i].second -= 1.0 * eachNP * tmp;
            if (c[i].second <= 0.0) c[i].second = 0;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cout << fixed << setprecision(10);
    while (tt--) {
        solve();
    }
    return 0;
}



