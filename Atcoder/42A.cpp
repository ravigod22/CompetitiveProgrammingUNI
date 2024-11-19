#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    
    vector<int> cnt(11, 0);
    cnt[a]++, cnt[b]++, cnt[c]++;
    
    cout << (cnt[5] == 2 && cnt[7] == 1 ? "YES" : "NO") << '\n';
    return 0;
}
