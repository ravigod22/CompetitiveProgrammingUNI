#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> d;
set<string> ans;
string s;

void backtracking(int pos, int k) {    
    if (pos > k / 2) {
        string tmp = s;
        set<int> correctitud;
        for (char e : tmp) correctitud.insert(e - '0');
        if (correctitud.size() != n) return;
        int l = tmp.size();
        for (int a = 1; a <= 3; ++a) {
            for (int b = 1; b <= 3; ++b) {
                for (int c = 1; c <= 3; ++c) {
                    int sum = a + b + c;
                    if (1 <= l - sum && l - sum <= 3) {
                        int d = l - sum;
                        string p1 = tmp.substr(0, a), p2 = tmp.substr(a, b);
                        string p3 = tmp.substr(a + b, c), p4 = tmp.substr(a + b + c, d);
                        assert (tmp == p1 + p2 + p3 + p4);
                        int num1 = stoi(p1), num2 = stoi(p2), num3 = stoi(p3), num4 = stoi(p4);
                        string aux = to_string(num1) + to_string(num2) + to_string(num3) + to_string(num4);
                        bool can = true;
                        if (num1 > 255 || num2 > 255 || num3 > 255 || num4 > 255) can = false;
                        for (int j = 0; j < aux.size() / 2; ++j) {
                            if (aux[j] != aux[aux.size() - j - 1]) can = false;
                        }
                        set<int> last;
                        for (char e : aux) last.insert(e - '0');
                        if (last.size() != n) can = false;
                        if (can) {
                            string res = to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4); 
                            ans.insert(res);
                        }
                    } 
                }
            }
        }
        return;
    }
    for (int e : d) {
        s[pos] = char(e + '0');
        s[k - pos - 1] = char(e + '0');
        backtracking(pos + 1, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    d.resize(n);
    for (int& e : d) cin >> e;
    if (n > 6) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 4; i <= 12; ++i) {
        s.resize(i);
        backtracking(0, i);    
    }
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e << "\n";
    return 0;
}
