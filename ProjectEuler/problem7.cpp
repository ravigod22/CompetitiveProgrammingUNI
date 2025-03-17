#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> ans;
    for (int i = 2; i <= maxn; ++i) {
        if (is_prime(i)) ans.push_back(i); 
    }
    cout << ans.size() << "\n";
    cout << ans[10000] << "\n";
    return 0;
}
