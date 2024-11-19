#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> element;
vector<int> subset;
void print(vector<int>& v) {
    cout << "{";
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << element[v[i] - 1] << (i + 1 == (int)v.size() ? "" : ",");  
    }
    cout << "}\n";
}

void backtrack() {
    if ((int)subset.size() == k) print(subset);
    int x = 0;
    if (!subset.empty()) {
        x = subset.back();
    }
    for (int y = x + 1; y <= n; ++y) {
        subset.emplace_back(y);
        backtrack();
        subset.pop_back();
    } 
}
void solve() {
    element.clear();
    subset.clear();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        element.emplace_back(x);
    }
    sort(element.begin(), element.end());
    backtrack();
    cout << "---\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
