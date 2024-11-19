#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    set<long long> s;
    auto str = [&] (int t) -> string {
        string tmp(t, '1');
        return tmp;
    };
    auto sum = [&] (string s1, string s2, string s3) -> long long {
        return stoll(s1) + stoll(s2) + stoll(s3);
    };
    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            for (int k = 1; k <= 15; ++k) {
                s.emplace(sum(str(i), str(j), str(k)));
            }
        }
    }
    n--;
    auto it = s.begin();
    for (int i = 0; i < n; ++i) ++it;
    cout << *it << "\n";
    return 0;
}
