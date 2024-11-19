#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n, m;
int t[maxn], y[maxn], z[maxn];
vector<int> box_ballon(maxn);

int f(int mid) {
    box_ballon.clear();
    int ballons = 0;
    for (int i = 0; i < n; ++i) {
        int time_ballons = t[i] * y[i];
        int time_total = time_ballons + z[i];
        int boxs = mid / time_total;
        int remainder = mid % time_total;
        if (remainder >= time_ballons) {
            boxs++;
            ballons += y[i] * boxs;
            int n_ballons = y[i] * boxs;
            box_ballon[i] = n_ballons;
        }
        else {
            int tmp = remainder / t[i];
            ballons += y[i] * boxs;
            ballons += tmp;
            int n_ballons = tmp + y[i] * boxs;
            box_ballon[i] = n_ballons;
        }
    }
    return ballons;
}  

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> t[i] >> y[i] >> z[i];
    
    int lo = 1;
    int hi = 2e9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid) >= m) {
            hi = mid;
        }
        else lo = mid + 1;
    }
    cout << lo << "\n";
    int ans = f(lo);
    for (int i = 0; i < n; ++i) {
        cout << box_ballon[i] << " \n"[i + 1 == n];
    }

    return 0;
}
