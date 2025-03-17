#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& e : a) cin >> e, cnt[e]++;
    set<int> aux;
    int ans = 0;
    for (int e : a) {
        aux.insert(e);
        cnt[e]--;
        if (cnt[e] == 0) cnt.erase(cnt.find(e));
        ans = max(ans, (int)aux.size() + (int)cnt.size());
    }
    cout << ans << "\n";
    return 0;
}


