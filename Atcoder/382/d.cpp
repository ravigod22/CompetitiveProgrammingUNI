#include <bits/stdc++.h>
using namespace std;

int n, m;
int lim[100];
vector<vector<int>> ans;
vector<int> tmp;

void back(int pos) {
    if (pos == n) {
        for (int j = tmp.back() + 10; j <= m; ++j) {
            tmp.emplace_back(j);
            ans.emplace_back(tmp);
            tmp.pop_back();
        }
        return;
    }
    for (int i = (tmp.empty() ? 1 : tmp.back() + 10); i <= lim[pos]; ++i) {
        tmp.emplace_back(i);
        back(pos + 1);
        tmp.pop_back();
    }
}


int main() {
    cin >> n >> m;
    int tmp = m;
    for (int i = n; i > 0; --i) {
        lim[i] = tmp;
        tmp -= 10;
    }
    back(1);
    cout << ans.size() << "\n";
    for (auto e : ans) {
        for (int x : e) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
