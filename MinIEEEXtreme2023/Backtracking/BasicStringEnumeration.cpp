#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> element;
vector<int> subset;

void print(vector<int>& v) {
    cout << "{";
    int p = v.size();
    for (int i = 0; i < p; ++i) {
        cout << v[i] << (i + 1 == p ? "" : ",");
    }
    cout << "}";
    cout << "\n";
}

void backtracking(int index) {
    if ((int)subset.size() == k) print(subset);
    for (int i = index; i < n; ++i) {
        subset.emplace_back(element[i]);
        backtracking(i + 1);
        subset.pop_back();
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        element.emplace_back(x);
    }
    sort(element.begin(), element.end());
    backtracking(0);
    cout << "---\n";
    element.clear();
    subset.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
