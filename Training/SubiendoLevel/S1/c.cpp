#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void Jossefus(int n, int res, int add) {
    if (n == 0) return;
    if (n & 1) {
        for (int i = 1; i <= n / 2; ++i) {
            
        }
        ans.push_back(res - 1);
    }
    else {
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(res * i - add);
        }
    }
}

int main() {
    int n; cin >> n;
    Jossefus(n, 2, 0);
    for (int e : ans) cout << e << " ";
    cout << "\n";
    return 0;
}
