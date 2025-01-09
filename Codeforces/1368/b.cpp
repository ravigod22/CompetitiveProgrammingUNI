#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const string tmp = "codeforces";

int main() {
    i64 k; cin >> k;
    vector<int> cnt(10, 1);
    auto f = [&] (vector<int>& cnt) -> i64 {
        i64 res = 1;
        for (int e : cnt) res *= 1LL * e;
        return res;
    };
    int pos = 0;
    while (f(cnt) < k) {
        cnt[pos]++;
        pos = (pos + 1) % 10;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << tmp[i];
        }
    }
    return 0;
}
