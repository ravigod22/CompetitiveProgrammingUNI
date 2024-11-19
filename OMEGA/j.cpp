#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<tuple<string,char,int>> a;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        char p; cin >> p;
        int x; cin >> x;
        a.emplace_back(s, p, x);
    }
    sort(a.begin(), a.end());
    vector<pair<int, string>> result;
    for (int i = 0; i < n; ) {
        string t = get<0>(a[i]);
        vector<int> points(8, 0);
        while (t == get<0>(a[i]) && i < n) {
            char pro = get<1>(a[i]);
            int score = get<2>(a[i]);
            points[pro - 'A'] = max(points[pro - 'A'], score);
            ++i;
        }
        int total = 0;
        for (int j = 0; j < 8; ++j) total += points[j];
        result.emplace_back(total, t);
    }
    int k = result.size();
    sort(result.rbegin(), result.rend());
    vector<string> repre;
    for (int i = 0; i < k; ) {
        int tmp = result[i].first;
        set<string> l;
        while (i < k && tmp == result[i].first) {
            l.emplace(result[i].second);
            ++i;
        }
        for (string e : l) {
            repre.emplace_back(e);
        }
        l.clear();
    }
    for (int i = 0; i < min(4, k); ++i) {
        cout << repre[i] << "\n";
    }
    return 0;
}
