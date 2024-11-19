#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    set<string> remain;
    do {
        remain.emplace(s);
    } while (next_permutation(s.begin(), s.end()));
    auto is_palindromic = [&] (string s) -> bool {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    };
    int cnt = 0;
    for (string e : remain) {
        bool exist = false;
        for (int i = 0; i <= n - k; ++i) {
            string aux = e.substr(i, k);
            if (is_palindromic(aux)) {
                exist = true;
                break;
            }
        }
        cnt += (exist ? 1 : 0);
    }
    cout << (int)remain.size() - cnt << "\n";
    return 0;
}
