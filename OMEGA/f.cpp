#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    map<string, string> pos;
    map<string, int> cnt;
    vector<pair<string, string>> other;
    for (int i = 0; i < n - 1; ++i) {
        string in; cin >> in;
        string to; cin >> to;
        other.emplace_back(in, to);
        pos[in] = to;
        cnt[in]++;
        cnt[to]++;
    }
    string init;
    string ending;
    for (int i = 0; i < n - 1; ++i) {
        if (cnt[other[i].first] < 2) {
            init = other[i].first;
        }
        if (cnt[other[i].second] < 2) {
            ending = other[i].second;
        }
    }
    vector<string> result;
    result.emplace_back(init);
    string tmp = init;
    while (pos[tmp] != ending) {
        result.emplace_back(pos[tmp]);
        tmp = pos[tmp];
    }
    result.emplace_back(ending);
    reverse(result.begin(), result.end());
    int k = result.size();
    for (int i = 0; i < k; ++i) {
        cout << result[i] << "\n";
    }
    return 0;
}
