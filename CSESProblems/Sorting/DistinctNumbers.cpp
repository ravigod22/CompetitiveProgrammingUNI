#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int,int> times;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        times[x]++;
    }

    cout << times.size();

    return 0;
}
