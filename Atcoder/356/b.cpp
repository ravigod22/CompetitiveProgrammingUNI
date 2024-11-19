#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int& e : a) cin >> e;
    vector<long long> sum(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            sum[j] += 0ll + x; 
        }
    }
    bool could = true;
    for (int i = 0; i < m; ++i) {
        if (1ll * a[i] > sum[i]) could = false;  
    }
    cout << (could ? "Yes\n" : "No\n");
    return 0;
}
