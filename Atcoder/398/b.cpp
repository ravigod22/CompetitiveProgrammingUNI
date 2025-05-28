#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(7);
    for (int& e : a) cin >> e;
    vector<pair<int, int>> p;
    sort(a.begin(), a.end());
    for (int i = 0; i < 7; ) {
        int cur = a[i];
        int cnt = 0;
        while (i < 7 && cur == a[i]) i++, cnt++;
        p.emplace_back(cnt, cur);
    }
    sort(p.rbegin(), p.rend());
    if (p.size() >= 2 && p[0].first >= 3 && p[1].first >= 2) {
        cout << "Yes\n";
    }
    else cout << "No\n";
    return 0;
}

