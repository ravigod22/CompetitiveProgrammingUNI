#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    string s; cin >> s;
    iota(a.begin(), a.end(), 1);
    map<int, int> cnt;
    do {
        vector<int> aux = a;
        int pos = 0;
        while (aux.size() != 1) {
            vector<int> tmp;
            for (int i = 1; i < aux.size(); i += 2) {
                if (s[pos] == '1') {
                    tmp.push_back(max(aux[i], aux[i - 1]));
                }
                else {
                    tmp.push_back(min(aux[i], aux[i - 1]));
                }
            }
            swap(aux, tmp);
            pos++;
        }
        if (aux.back() == 4) {
            for (int e : a) cout << e << " ";
            cout << endl;
            break;
        }
        cnt[aux.back()]++;
    } while (next_permutation(a.begin(), a.end()));
    for (auto [k, v] : cnt) {
        cout << k << " " << v << "\n";
    }
    return 0;
}
