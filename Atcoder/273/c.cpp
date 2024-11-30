#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n;
int cnt[maxn];

int main() {
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<int> tms;
    for (int i = 0; i < n; ) {
        int tmp = a[i];
        int aux = 0;
        while (i < n && tmp == a[i]) ++i, aux++;
        tms.emplace_back(aux);
    }
    int k = tms.size();
    for (int i = 0; i < k; ++i) {
        cnt[k - i - 1] += tms[i];
    }
    for (int i = 0; i < n; ++i) cout << cnt[i] << "\n";
    return 0;
}
