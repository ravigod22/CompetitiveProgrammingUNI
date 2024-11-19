#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n; cin >> n;
    vector<int> pos;
    for (int i = 0; i < 61; ++i) {
        if (n & (1LL << i)) pos.emplace_back(i);
    }
    int k = pos.size(); 
    int mask = 1 << k;
    for (int i = 0; i < mask; ++i) {
        i64 num = 0;
        for (int j = 0; j < k; ++j) {
            if (i & (1LL << j)) num |= (1LL << pos[j]);
        }
        cout << num << "\n";
    }
    return 0;
}
