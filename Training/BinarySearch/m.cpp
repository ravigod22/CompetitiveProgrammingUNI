#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i] >> v[i];
    double lo = 1.0 * (*min_element(p.begin(), p.end()));
    double hi = 1.0 * (*max_element(p.begin(), p.end()));
    auto f = [&] (double mid) -> double {
        double times = 0;
        for (int i = 0; i < n; ++i) {
            double dis = abs(1.0 * p[i] - mid);
            times = max(times, dis / v[i]);
        }
        return times;
    };
    int cnt = 50;
    while (cnt--) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = hi - (hi - lo) / 3;
        if (f(m1) > f(m2)) lo = m1;
        else hi = m2;
    }
    cout << fixed << setprecision(10);
    cout << f(lo) << "\n";
    return 0;
}
