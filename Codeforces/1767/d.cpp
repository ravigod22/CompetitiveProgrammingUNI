#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a((1 << n));
    iota(a.begin(), a.end(), 1);
    string l, r;
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = n - cnt0;
    l = string(cnt1, '1') + string(cnt0, '0');
    r = string(cnt0, '0') + string(cnt1, '1');
    auto check = [&] (string s) -> int {
        vector<int> tmp = a;
        int pos = 0;
        while (tmp.size() != 1) {
            vector<int> aux;
            for (int i = 1; i < tmp.size(); i += 2) {
                if (s[pos] == '1') {
                    aux.push_back(max(tmp[i], tmp[i - 1]));
                }
                else aux.push_back(min(tmp[i], tmp[i - 1]));
            }
            swap(tmp, aux);
            pos++;
        }
        return tmp.back();
    };
    int L = check(l);
    int R = check(r);
    for (int i = L; i <= R; ++i) {
        cout << i << " \n"[i == R];
    }
    return 0;
}
