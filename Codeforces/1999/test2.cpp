#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;


int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int r; cin >> r;
    return r;
}
int lower_bound(int i, int n){
    int lo = i;
    int hi = n;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(ask(1, mid) == mid) lo = mid+1;
        else hi = mid;
    }
    return lo;
}
void solve() {
    int ans = lower_bound(1, 1000);
    cout << "! " << ans << "\n";
}

int main() {
    fast_io;
    int tt;
    cin >> tt;

    while(tt--){
        solve();
    }
}
