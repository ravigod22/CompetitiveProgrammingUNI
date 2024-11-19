#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> s;
        int turns = n;
        if (n == 1) {
            cout << 1 << "\n";
            return 0;
        }
        s.emplace_back(a[0]);
        for (int i = 1; i < n; ++i) {
            int tmp = a[i];
            if (tmp != s.back()) {
                s.emplace_back(tmp);
            }
            else {
                int another = tmp;
                while(tmp == s.back()) {
                    /*
                    cout << "i -> " << i << "\n";
                    for (int i = 0; i < s.size(); ++i) cout << s[i] << " ";
                    cout << endl;
                    */
                    s.pop_back();
                    tmp++;
                }
                s.emplace_back(tmp);
            }
        }
        cout << s.size() << "\n";
    }
    return 0;
}

